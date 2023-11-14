#include"iostream"
#include <vector>
#include<queue>
using namespace std;

class DiGraph {
    public:
        DiGraph(int v);
        int V();  //������
        int E();  //����
        void addEdge(int v, int w);  //��ӱ�
        vector<int> adj(int V);  //���㶥��Ķ�
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