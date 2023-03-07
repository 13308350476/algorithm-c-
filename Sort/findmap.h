#include"sort.h"

using namespace std;

class NODE {
    public:
        NODE(char K, int V):key(K),value(V),next(NULL){};
        char key;
        int value;
        NODE * next;
};
NODE *firstnode = NULL;
void put(char k,int v);
int get(char k);
void show();
void Linked_list_func();

//-------------------------- BST --------------------------------

class BNODE {
    public:
        BNODE(char K, int V, int size_t):key(K),value(V),left(NULL),right(NULL),N(size_t){};
        char key;
        int value;
        BNODE * left,* right;
        int N;
};
BNODE *root = NULL;
int size(BNODE *node);
int size();
void b_put_head(char k,int v);
BNODE *b_put(BNODE *node, char k,int v);
BNODE * b_get_head(char k);
BNODE * b_get(BNODE *node, char k);
void BST_input_func();
int rank_head(char k);
int Brank(BNODE *node,char k);
BNODE * Bselect_head(int rank);
BNODE * Bselect(BNODE *node,int rank);
BNODE * Bmin_head();
BNODE * Bmin(BNODE *node);
void deletmin_head();
BNODE * deletmin(BNODE *node);
void Bdelet_head(char k);
BNODE * Bdelet(BNODE *node, char k);
void print(BNODE *node); //ÖÐÐò±éÀú
vector<char> find_lo_hi(char lo,char hi);
void find_rang(BNODE *node,vector<char> &list,char lo,char hi);