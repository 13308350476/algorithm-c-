#include"iostream"
#include <vector>
using namespace std;

class Graph {
    public:
        Graph(int v);
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

//-----------------------  path  ---------------------------
//(依赖DeepSearch,起点决定了)
bool haspathto(int v);          //是否存在从s到v的路径
vector<int> pathTo(int s,int v);
