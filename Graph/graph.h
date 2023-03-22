#include"iostream"
#include <vector>
#include<queue>
using namespace std;

class Graph {
    public:
        Graph(int v);  //图见P357
        int V();  //顶点数
        int E();  //边数
        void addEdge(int v, int w);  //添加边
        vector<int> adj(int V);  //计算顶点的度
        string toString();
    public:
        vector<vector<int>> table;
        int v;
        int e;
};

int degree(Graph G,int V);
int maxDgree(Graph G);
double avgDgree(Graph G);
int numberOfSelfLoops(Graph G);

//-----------------------  search  ---------------------------

vector<bool> mark;
vector<int> egdedto;
void DeepSearch(Graph G,int s);              //找到和起点S联通的所有顶点
void dfs(Graph G,int v);
void wideSearch(Graph G,int s);
void bfs(Graph G,int v);
//-----------------------  path  ---------------------------
//(依赖DeepSearch,起点决定了)
bool haspathto(int v);          //是否存在从s到v的路径
vector<int> pathTo(int s,int v);

//-----------------------  cc  ---------------------------
vector<int> id;
int count;  //how many cc
void cc(Graph G);
bool connected(int s, int v);
int nodeid(int v);

//是否有环：如果此被标记了，但不是上一个来的，就有环

// void DeepSearch(Graph G,int s) {
//     for(){ //全部顶点要搞完，不确定是不是全部相连
//         dfs(G,s,s);
//     }
// }

// void dfs(Graph G,int v,int u) {
//     if(!mark[v]) {
//         cout << v << "--";
//     }
//     mark[v] = true;
//     int size = G.table[v].size();
//     for(int i=0; i<size; i++) {
//         if(!mark[G.table[v][i]]) {
//             dfs(G,G.table[v][i]);
//         }else{
//             if(G.table[v][i] != v) {
//                 //youhuan
//             }
//         }
//     }
// }

