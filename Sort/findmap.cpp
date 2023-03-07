#include"findmap.h"

using namespace std;

void put(char k,int v) {
    NODE *select = firstnode;
    while(NULL != select){
        if(select->key == k) {
            select->value = v;
            return;
        }
        select = select->next;
    }
    NODE *newnode = new NODE(k,v);
    newnode->next = firstnode;
    firstnode = newnode;
}

int get(char k) {
    NODE *select = firstnode;
    while(NULL != select){
        if(select->key == k) {
            return select->value;
        }
        select = select->next;
    }
    return -1;
}

void show() {
    NODE *select = firstnode;
    while (NULL != select)
    {
        cout << select->key <<"|" << select->value << "-->"; 
        select = select->next;
    }
    cout << endl;
    
}

void Linked_list_func() {
    put('S',0);
    show();
    put('E',1);
    show();
    put('A',2);
    show();
    put('R',3);
    show();
    put('C',4);
    show();
    put('H',5);
    show();
    put('E',6);
    show();
}

//-------------------------- BST --------------------------------

int size(BNODE *node) {
    if(NULL == node) {
        return 0;
    } else {
        return node->N;
    }
}

int size(){
    return(size(root));
}

void b_put_head(char k,int v) {
    root = b_put(root,k,v);
}

BNODE *b_put(BNODE *node, char k,int v) {
    BNODE *newnode;
    if(NULL == node) {
        newnode = new BNODE(k,v,1);
        node = newnode;
        return node;
    }
    if(k < node->key) {
        node->left = b_put(node->left,k,v); //这两边的等号可以只在最终子节点赋予一下值就可以了
    }else if(k > node->key) {
        node->right = b_put(node->right,k,v);
    }else{
        node->value = v;
        // return node;
        //这里加不加return都可以
    }
    node->N = size(node->left) + size(node->right) + 1;
    return node;
}

BNODE * b_get_head(char k) {
    return b_get(root,k);
}

BNODE * b_get(BNODE *node, char k) {
    if(NULL == node) {
        return NULL;
    }
    if(k > node->key) {
        return b_get(node->right,k);
    }else if(k < node->key) {
        return b_get(node->left,k);
    }else{
        return node;
    }
}

void BST_input_func() {
    cout << size() << endl;
    b_put_head('S',0);
    cout << size() << endl;
    b_put_head('E',1);
    cout << size() << endl;
    b_put_head('A',2);
    cout << size() << endl;
    b_put_head('R',3);
    cout << size() << endl;
    b_put_head('C',4);
    cout << size() << endl;
    b_put_head('H',5);
    cout << size() << endl;
    b_put_head('E',6);
    cout << size() << endl;
    // b_put_head('P',6);
    // cout << size() << endl;
}

int rank_head(char k) {
    return Brank(root,k);
}

int Brank(BNODE *node,char k) {
    if(NULL == node) {
        return 0;
    }
    if(k < node->key) {
        return Brank(node->left,k);
    }else if(k > node->key) {
        return 1+ size(node->left) + Brank(node->right,k);
    }else {
        return 1 + size(node->left);
    }

}

BNODE * Bselect_head(int rank) {
    return Bselect(root,rank);
}

BNODE * Bselect(BNODE *node,int rank) {
    if(rank > size(node)){
        cout << "error input" << endl;
        return NULL;
    }
    if(1 + size(node->left) == rank){
        return node;
    }else if(rank < size(node->left) + 1){
        return Bselect(node->left,rank);
    }else{
        rank = rank- size(node->left) - 1;
        return Bselect(node->right,rank);
    }
}

BNODE * Bmin_head() {
    return Bmin(root);
}

BNODE * Bmin(BNODE *node) {
    if(NULL == node->left){
        return node;
    }
    return(Bmin(node->left));
}

void deletmin_head() {
    root = deletmin(root);
}

BNODE * deletmin(BNODE *node) {
    if(NULL == node) {
        cout << "deletmin: node is NULL" << endl;
        return NULL;
    }
    if(NULL == node->left) {
        BNODE *temp = node->right;
        delete node;
        return temp;
    }
    node->left = deletmin(node->left);
    node->N = size(node->left) + size(node->right) + 1;
    return node;
}

void Bdelet_head(char k) {
    root = Bdelet(root,k);
}

BNODE * Bdelet(BNODE *node, char k) {
    if(NULL == node) {
        cout << "error key" << endl;
        return NULL;
    }else if(k < node->key){
        node->left = Bdelet(node->left,k);
    }else if(k > node->key) {
        node->right = Bdelet(node->right,k);
    }else{
        if(NULL == node->left){
            BNODE *temp = node->right;
            delete node;
            return temp;
        }
        if(NULL == node->right) {
            BNODE *temp = node->left;
            delete node;
            return temp;
        }
        BNODE *min = Bmin(node->right);
        node->key = min->key;
        node->value = min->value;
        node->right = deletmin(node->right);
    }
    node->N = size(node->left) + size(node->right) + 1;//不要忘记加1
    return node;
}

void print(BNODE *node) {
    if(NULL == node) {
        return;
    }
    print(node->left);
    cout << node->key << " ";
    print(node->right);
}

vector<char> find_lo_hi(char lo,char hi) {
    vector<char> temp;
    find_rang(root,temp,lo,hi);
    return temp;
}

void find_rang(BNODE *node,vector<char> &list,char lo,char hi) {
    if(NULL == node){
        return;
    }
    if(node->key > lo) {
        find_rang(node->left,list,lo,hi);
    }
    if(lo <= node->key && node->key <= hi) {
        list.push_back(node->key);
        cout << node->key << " ";
    }
    if(node->key < hi){
        find_rang(node->right,list,lo,hi);
    }
}

int main() {
    // Linked_list_func();
    BST_input_func();
    // cout << b_get_head('H')->value; //要判断是否为空
    // cout << rank_head('S') << endl;
    // cout << Bselect_head(6)->key << endl; //要判断是否为空
    // cout << Bmin_head()->key;
    // deletmin_head();
    // Bdelet_head('E');
    // print(root);
    find_lo_hi('A','S');
    return 0;
}