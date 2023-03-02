#include"iostream"
#include"unionFind.h"
using namespace std;

UF::UF() {
    for(int i = 0; i < 1000; i++){
        id[i] = i;
        size[i] = 1;
    }
    count = 1000;
}

bool UF::connected(int p,int q){
    if (find(p) == find(q)) {
        return true;
    } else {
        return false;
    }
}

int UF::count() {
    return count;
}

//加权quick-union
int UF::find(int p) {
    while(id[p] != p) {
        p = id[p];
    }
    return p;
}

void UF::Union(int p,int q) {
    int ROOTp = find(p);
    int ROOTq = find(q);
    if(ROOTp == ROOTq) {
        return;
    }
    if(size[ROOTp] <= size[ROOTq]) { //让树变得扁平(这里记录树的深度更好，在等于的时候让根节点深度加一)
        id[ROOTp] = ROOTq;
        size[ROOTq] += size[ROOTp];
    } else {
        id[ROOTq] = ROOTp;
        size[ROOTp] += size[ROOTq];
    }
    count ++;
}