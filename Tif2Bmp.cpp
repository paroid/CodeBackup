#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;

class bmp {
public:
    bmp (char *);
    fstream file;
};

bmp::bmp(char *name) {
    file.open(name, ios::out | ios::binary);
    if(!file)
        cout << "bmp file error" << endl;
}

class tiff {
public:
    tiff (char *);
    int readValue(int);
    void writeValue(fstream &, int, int);
    void toBmp(char *);
    fstream file;
    char buf[16];
    int width, height;
};

tiff::tiff(char  *name) {
    file.open(name, ios::in | ios::binary);
    if(!file)
        cout << "tiff file error" << endl;
}

int tiff::readValue(int len = 4) {
    int ret = 0;
    file.read(buf, len);
    for(int i = len - 1; i >= 0; --i) {
        ret = (ret << 8) | (unsigned char)buf[i];
    }
    return ret;
}
void tiff::writeValue(fstream &fp, int val, int len = 4) {
    for(int i = 0; i < len; ++i) {
        buf[i] = val >> (8 * i);
    }
    fp.write(buf, len);
}
//for Round Off
int roundOff(double v) {
    if(v - int(v) < 0.5)
        return int(v);
    return int(v) + 1;
}


void tiff::toBmp(char*name) {
    bmp ret(name);
    file.read(buf, 4);
    if(buf[0] != 'I') {
        cout << "byte order error!" << endl;
        return;
    }
    if(buf[2] != 0x2a || buf[3] != 0) {
        cout << "fileType error!" << endl;
        return;
    }
    int offset = readValue();
    file.seekg(offset, ios::beg);
    int entryNum = readValue(2);
    cout << "entryNum: " << entryNum << endl;
    for(int i = 0; i < entryNum; ++i) {
        int tag = readValue(2);
        cout << "tag: " << hex << tag << endl;
        switch(tag) {
        case 0x100:
            file.ignore(6);
            width = readValue();
            break;
        case 0x101:
            file.ignore(6);
            height = readValue();
            break;
        case 0x102:
            file.ignore(6);
            int bps = readValue();
            if(bps != 8) {
                cout << "bps error!" << endl;
                return;
            }
            break;
        case 0x111:
            file.ignore(6);
            offset = readValue();
            break;
        default:
            file.ignore(10);
        }
    }
    int over = readValue();
    if(over) {
        cout << "IFD > 1 error!" << endl;
        return;
    }
    int size = width * height;
    cout << "size: " << dec << size << "  " << width << "*" << height << endl;
    if(!size)
        cout << "size error!" << endl;
    fstream &bfp = ret.file;
    buf[0] = 0x42;
    buf[1] = 0x4d;
    bfp.write(buf, 2);
    writeValue(bfp, size * 3 + 54);
    writeValue(bfp, 0);
    writeValue(bfp, 54);
    writeValue(bfp, 40);
    writeValue(bfp, width);
    writeValue(bfp, height);
    writeValue(bfp, 1, 2);
    writeValue(bfp, 24, 2);
    writeValue(bfp, 0);
    writeValue(bfp, size * 3);
    writeValue(bfp, 0);
    writeValue(bfp, 0);
    writeValue(bfp, 0);
    writeValue(bfp, 0);
    file.seekg(offset, ios::beg);
    char **mat = new char*[height];
    unsigned char **matB = new unsigned char*[height];
    unsigned char **matC = new unsigned char*[height];
    int count[258];
    double M = 0;
    memset(count, 0, sizeof(count));
    for(int i = 0; i < height; ++i) {
        mat[i] = new char[width];
        matB[i] = new unsigned char[width];
        matC[i] = new unsigned char[width];
        memset(matC[i], 0, sizeof(matC[i]));
        for(int j = 0; j < width; ++j) {
            file.read(&mat[i][j], 1);
            ++count[(unsigned char)mat[i][j]];//counting
        }
    }
//clock start
    long start = clock();
    //equalizing
    double ratio = 0.9;
    double addRatio = 0.2;
    for(int i = 0; i < 30; ++i) {
        int sub = (int)(count[i] * addRatio);
        count[i] += sub;
        size += sub;
    }
    for(int i = 220; i < 256; ++i) {
        int sub = (int)(count[i] * ratio);
        count[i] -= sub;
        size -= sub;
    }
    for(int i = 1; i < 256; ++i)
        count[i] += count[i - 1];
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j) {
            int val = roundOff(count[(int)(unsigned char)mat[height - 1 - i][j]] * 255 / (double)size);
            val = (val > 200) ? 255 : val; //sharp
            matB[i][j] = val;
            M += val;
            /*writeValue(bfp,val,1);
              writeValue(bfp,val,1);
              writeValue(bfp,val,1);*/
        }
    //normalizing
    size = width * height;
    M /= size;
    double VAR = 0, Mo = 150, VARo = 2000;
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j) {
            VAR += (matB[i][j] - M) * (matB[i][j] - M);
        }
    VAR /= size;
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j) {
            matB[i][j] = (unsigned char)(matB[i][j] > M ? (Mo + sqrt(VARo * (matB[i][j] - M) * (matB[i][j] - M) / VAR)) : (Mo - sqrt(VARo * (matB[i][j] - M) * (matB[i][j] - M) / VAR)));
            int val = matB[i][j];
            /*writeValue(bfp,val,1);
            writeValue(bfp,val,1);
            writeValue(bfp,val,1);*/
        }
    //segmentation
    const int W = 16;
    for(int i = 0; i < height; i += W)
        for(int j = 0; j < width; j += W) {
            int h = i + W <= height ? (i + W) : height;
            int w = j + W <= width ? (j + W) : width;
            double M = 0, VAR = 0, U = 60;
            for(int row = i; row < h; ++row)
                for(int col = j; col < w; ++col) {
                    M += matB[row][col];
                }
            M /= (h - i) * (w - j);
            for(int row = i; row < h; ++row)
                for(int col = j; col < w; ++col) {
                    VAR += (matB[row][col] - M) * (matB[row][col] - M);
                }
            VAR /= (h - i) * (w - j);
            if(VAR > U) {
                for(int row = i; row < h; ++row)
                    for(int col = j; col < w; ++col) {
                        matC[row][col] = 255;
                    }
            }
        }
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j) {
            int val = matC[i][j] ? matB[i][j] : 255;
            writeValue(bfp, val, 1);
            writeValue(bfp, val, 1);
            writeValue(bfp, val, 1);
        }
    delete []mat;
    delete []matB;
    delete []matC;
    bfp.close();
    //finish
    long finish = clock();
    cout << "done....   " << (finish - start) << "  ms" << endl;
}

int main() {
    tiff T("B:/2_5.tif");
    T.toBmp("B:/1_2b.bmp");
    return 0;
}
