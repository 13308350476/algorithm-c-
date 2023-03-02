#include"iostream"
#include <vector>
using namespace std;

void exch(vector<int> & a,int i,int j);
void show(vector<int> a);
bool issorted(vector<int> a);
bool Less(int a, int b);
void selectionSort(vector<int> & a);
void insertSort(vector<int> & a);
void sellSort(vector<int> & a);
//------------------------merge sort--------------------------------
void merge(vector<int> & a, int low, int mid, int hi);
void mergesort_top(vector<int> & a, int low, int hi);
void mergesort_low(vector<int> & a);
//------------------------qiuck sort--------------------------------
int Partition(vector<int> & a,int lo,int hi);
void quickSort(vector<int> & a, int lo, int hi);
//------------------------heap  sort--------------------------------
void swim(vector<int> & a, int k);
void sink(vector<int> & a, int k);
void addnode(vector<int> & a, int value);
void popnode(vector<int> & a);
void creatheap(vector<int> & a);
void find_10_min(vector<int> & a, int num);
