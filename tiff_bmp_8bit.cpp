#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class bmp {
public:
    bmp (const char *);
    fstream file;
};

bmp::bmp(const char *name) {
    file.open(name, ios::out | ios::binary);
    if(!file)
        cout << "bmp file error" << endl;
}

class tiff {
public:
    tiff (const char *);
    int readValue(int);
    void writeValue(fstream &, int, int);
    void toBmp(const char *);
    fstream file;
    char buf[16];
    int width, height;
};

tiff::tiff(const char  *name) {
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

void tiff::toBmp(const char*name) {
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
    bfp.write(buf, 2); //BM
    int add = 1024;
    writeValue(bfp, size * 1 + 54 + add); //file size
    writeValue(bfp, 0); //reserved 0
    writeValue(bfp, 54 + add); //Data offset
    writeValue(bfp, 40); //header size
    writeValue(bfp, width);
    writeValue(bfp, height);
    writeValue(bfp, 1, 2);
    writeValue(bfp, 8, 2);//bit per pixel
    writeValue(bfp, 0); //compress
    writeValue(bfp, size * 1);
    writeValue(bfp, 0);
    writeValue(bfp, 0);
    writeValue(bfp, 0); //colors
    writeValue(bfp, 0); //palette
    for(int i = 0; i < 256; ++i) { // color board
        writeValue(bfp, i, 1);
        writeValue(bfp, i, 1);
        writeValue(bfp, i, 1);
        writeValue(bfp, 0, 1);
    }
    file.seekg(offset, ios::beg);
    char **mat = new char*[height];
    int count[258];
    double M = 0;
    memset(count, 0, sizeof(count));
    for(int i = 0; i < height; ++i) {
        mat[i] = new char[width];
        for(int j = 0; j < width; ++j) {
            file.read(&mat[i][j], 1);
        }
    }
    for(int i = height - 1; i >= 0; --i)
        for(int j = 0; j < width; ++j)
            writeValue(bfp, (unsigned char)mat[i][j], 1);
    delete []mat;
    bfp.close();
    //finish
    cout << "done....   " <<endl;
}

int main(int argc,char *argv[]) {
    if(argc<2){
        cout<<"need TIFF file name!"<<endl;
        return 0;
    }
    string filename=argv[1];
    tiff T(filename.data());
    filename.append(".bmp");
    T.toBmp(filename.data());
    return 0;
}

