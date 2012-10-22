#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream fin("in");
ofstream fout("out");

typedef struct _node {
    string name;
    int count, pc;
    struct _node * next[12];
} node;

typedef struct _fptree {
    node *root;
    string ans[100];
    int ansc[100];
    void init() {
        root = new node;
        root->name = "Root";
    }
    void insert(string *strArr, int n) {
        //fout<<"insert: "<<n<<endl;
        node *p = root;
        for(int i = 0; i < n; ++i) {
            bool ok = true;
            for(int j = 0; j < p->pc; ++j) {
                if(p->next[j]->name == strArr[i]) {
                    p = p->next[j];
                    ++(p->count);
                    ok = false;
                    break;
                }
            }
            if(ok) {
                node *t = new node;
                t->name = strArr[i];
                t->count = 1;
                t->next[p->pc] = NULL;
                p->next[p->pc] = t;
                ++(p->pc);
                p = t;
            }
        }
    }
    void ansOut(int n) {
        for(int i = 0; i < n; ++i) {
            fout << ans[i] << ":" << ansc[i];
            if(i != n - 1)
                fout << " -> ";
        }
        fout << endl;
    }
    void find(string key, node *p, int cur = 0) {
        for(int i = 0; i < p->pc; ++i) {
            ans[cur] = p->next[i]->name;
            ansc[cur] = p->next[i]->count;
            if(ans[cur] == key)
                ansOut(cur + 1);
            find(key, p->next[i], cur + 1);
        }
    }
} fptree;



int main() {
    string arr[100], key;
    int m, n;
    fptree T;
    T.init();
    fin >> m;
    while(m--) {
        fin >> n;
        for(int i = 0; i < n; i++)
            fin >> arr[i];
        T.insert(arr, n);
    }
    while(fin >> key) {
        fout << "\nfind: " << key << endl;
        T.find(key, T.root);
    }
    return 0;
}
