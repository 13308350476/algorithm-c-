#include"sort.h"

#define RED    true
#define BLACK  false
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
        BNODE(char K, int V, int size_t):key(K),value(V),left(NULL),
        right(NULL),N(size_t),color(BLACK){};
        char key;
        int value;
        BNODE * left,* right;
        int N;
        bool color;
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
void print(BNODE *node); //中序遍历
vector<char> find_lo_hi(char lo,char hi);
void find_rang(BNODE *node,vector<char> &list,char lo,char hi);

//--------------------------RED BLACK BST --------------------------------
BNODE * rotateleft(BNODE *node);
BNODE * rotateright(BNODE *node);
bool isred(BNODE *node);
void filpcolors(BNODE *node);
void RBput_head(char k,int value);
BNODE *RBpu(BNODE *node,char k,int value);
void RBput_func();
//删除节点有点难，需要之后再来探索