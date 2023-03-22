#include"iostream"
#include <vector>
#include<queue>
using namespace std;

class Graph {
    public:
        Graph(int v);  //ͼ��P357
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
void wideSearch(Graph G,int s);
void bfs(Graph G,int v);
//-----------------------  path  ---------------------------
//(����DeepSearch,��������)
bool haspathto(int v);          //�Ƿ���ڴ�s��v��·��
vector<int> pathTo(int s,int v);

//-----------------------  cc  ---------------------------
vector<int> id;
int count;  //how many cc
void cc(Graph G);
bool connected(int s, int v);
int nodeid(int v);

//�Ƿ��л�������˱�����ˣ���������һ�����ģ����л�

// void DeepSearch(Graph G,int s) {
//     for(){ //ȫ������Ҫ���꣬��ȷ���ǲ���ȫ������
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

