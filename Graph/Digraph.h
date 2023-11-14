#include"iostream"
#include <vector>
#include<queue>
using namespace std;

class DiGraph {
    public:
        DiGraph(int v);
        int V();  //顶点数
        int E();  //边数
        void addEdge(int v, int w);  //添加边
        vector<int> adj(int V);  //计算顶点的度
        string toString();
        DiGraph reverse();
    public:
        vector<vector<int>> table;
        int v;
        int e;
};


class DirictedDFS {
    public:
        DirictedDFS(DiGraph g, int s);
    public:
        vector<bool> mark;
};