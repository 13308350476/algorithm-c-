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

//��Ȩquick-union
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
    if(size[ROOTp] <= size[ROOTq]) { //������ñ�ƽ(�����¼������ȸ��ã��ڵ��ڵ�ʱ���ø��ڵ���ȼ�һ)
        id[ROOTp] = ROOTq;
        size[ROOTq] += size[ROOTp];
    } else {
        id[ROOTq] = ROOTp;
        size[ROOTp] += size[ROOTq];
    }
    count ++;
}