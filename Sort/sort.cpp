#include"sort.h"
#include"string.h"
#include"math.h"
using namespace std;

void exch(vector<int> & a,int i,int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

bool Less(int a, int b) {
    if(a <= b) {
        return true;
    }
    return false;
}

void show(vector<int> a) {
    for(int i = 0; i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> & a) {
    int min;
    for(int i = 0; i < a.size(); i++) {
        min = i;
        for(int j = i; j < a.size(); j++){
            if(Less(a[j],a[min])){
                min = j;
            }
        }
        exch(a,min,i);
    }
}

void insertSort(vector<int> & a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j=i; j >= 1; j--){
            if(Less(a[j],a[j-1])) {
                exch(a,j-1,j);
            }else{
                break;
            }
        }
    }
}

void sellSort(vector<int> & a) {
    int lenth = a.size();
    int h = 1;
    while (3*h < lenth)
    {
        h = 3*h + 1; //这个好像可以随意定，书上是3
    }
    while (h >= 1)
    {
        for(int i = h;i < lenth; i++){
            for(int j = i; j >= h; j--){
                if(Less(a[j],a[j-h])) {
                    exch(a,j,j-h);
                }
            }
        }
        h = h/3;
    }
}

//------------------------merge sort--------------------------------

void merge(vector<int> & a, int low, int mid, int hi) {
    vector<int> temp = a;
    int l = low;
    int h = mid + 1;
    for(int i = low; i <= hi; i++){
        if(l > mid) {
            a[i] = temp[h++];
        }else if(h > hi) {
            a[i] = temp[l++];
        }else if(Less(a[l],a[h])){
            a[i] = a[l++];
        }else{
            a[i] = a[h++];
        }
    }
}

void mergesort_top(vector<int> & a, int low, int hi) { //自顶向下
    if(low >= hi){
        return;
    }
    int mid = low + (hi-low)/2;
    mergesort_top(a , low, mid);
    mergesort_top(a , mid+1, hi);
    merge(a,low,mid,hi);
}

void mergesort_low(vector<int> & a) { //自底向上
    int N = a.size();
    for(int sz = 1;sz < N;sz += sz){
        for(int i = 0; i < N - sz ;i += sz + sz){
            merge(a,i,i+sz-1,min(N-1,i+sz+sz-1));
        }
    }
}

//------------------------qiuck sort--------------------------------

int Partition(vector<int> & a,int lo,int hi) {
    int flag = a[lo];
    int i = lo+1;
    int j = hi;
    while(true) {
        while(Less(a[i],flag)) {
            if(i == hi){
                break;
            }
            i++;
        }
        while (Less(flag,a[j])) {
            if(j == lo){
                break;
            }
            j--;
        }
        if(i >= j){
            break;
        }
        exch(a,i,j);
    }
    exch(a,lo,j);
    return j;
}

void quickSort(vector<int> & a, int lo, int hi) {
    if(lo >= hi){
        return;
    }
    int j = Partition(a,lo,hi);
    quickSort(a,lo,j-1);
    quickSort(a,j+1,hi);
}

//------------------------heap  sort--------------------------------

void swim(vector<int> & a, int k) {
    while (k > 1) {
        if(Less(a[k/2],a[k])) { //判断子节点和父节点的大小
            exch(a, k, k/2);
            k = k/2;
        }else {
            break;
        }
    }
}

void sink(vector<int> & a, int k) {
    int size = a.size()-1;
    while (2*k <= size) {
        int j = 2*k;
        if(j < size && Less(a[j],a[j+1])) {  //找到子节点中最大的
            j++;
        }
        if(Less(a[k],a[j])) {
            exch(a,k,j);
            k = j;
        }else{
            break;
        }
    }
}

void addnode(vector<int> & a, int value) {
    if(a.size() != 0){
        a.push_back(value);
    } else {
        a.push_back(0);
        a.push_back(value);
    }
    swim(a,a.size()-1);
}

void popnode(vector<int> & a){
    if(a.size() > 1){
        // cout << "change befor :";
        // show(a);
        exch(a,1,a.size()-1);
        // cout << "change after :";
        // show(a);
        a.pop_back();
        // cout << "pop after    :";
        // show(a);
    }else{
        cout << "heap is null";
        return;
    }
    sink(a,1);
}

void creatheap(vector<int> & a){
    int size = a.size()-1;
    for(int i = size/2; i >= 1; i--) {
        sink(a,i);
    }
    
}

void find_10_min(vector<int> & a, int num) {
    if(a.size() < 11) {
        addnode(a,num);
    } else {
        if(num < a[1]) {
            a[1] = num;
            sink(a,1);
        }
    }
}

int main() {
    vector<int> a;
    // for(int i = 0; i < 100; i++){
    //     a.push_back(rand()%100);
    // }
    // show(a);
    // selectionSort(a);
    // insertSort(a);
    // sellSort(a);
    // mergesort_top(a,0,a.size()-1);
    // mergesort_low(a);
    // quickSort(a,0,a.size()-1);

    // creatheap(a);
    // for(int i = 0; i < 99; i++){
    //     cout << a[1] << " ";
    //     popnode(a);
    // }

    for(int i = 1000; i >= 0; i--){
        find_10_min(a,i);
    }
    show(a);
    return 0;
}