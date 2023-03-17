#include"iostream"
#include <vector>
using namespace std;

class Graph {
    public:
        Graph(int v);
        int V();  //������
        int E();  //����
        void addEdge(int v, int w);  //��ӱ�
        vector<int> adj(int V);  //���㶥��Ķ�
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
void DeepSearch(Graph G,int s);              //�ҵ������S��ͨ�����ж���
void dfs(Graph G,int v);

//-----------------------  path  ---------------------------
//(����DeepSearch,��������)
bool haspathto(int v);          //�Ƿ���ڴ�s��v��·��
vector<int> pathTo(int s,int v);
