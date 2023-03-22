#include "graph.h"

Graph::Graph(int v){
    this->v = v;
    this->e = 0;
    for(int i = 0; i < v; i++) {
        vector<int> temp;
        this->table.push_back(temp);
        egdedto.push_back(-1);
        id.push_back(i);
        bool temp_bool = false;
        mark.push_back(temp_bool);
    }
}

int Graph::V(){
    return this->v;
}

int Graph::E(){
    return this->e;
}

void Graph::addEdge(int v, int w) {
    this->table[v].insert(table[v].begin(),w);
    this->table[w].insert(table[w].begin(),v);
    this->e ++;
}

vector<int> Graph::adj(int V) {
    return this->table[V];
}

int degree(Graph G,int V){
    return G.adj(V).size();
}

int maxDgree(Graph G) {
    int max = 0;
    for(int i=0;i<G.V();i++) {
        if(degree(G,i) > max) {
            max = degree(G,i);
        }
    }
    return max;
}

double avgDgree(Graph G) {
    return 2*G.E()/G.V();
}

int numberOfSelfLoops(Graph G) {
    int count = 0;
    for(int i = 0;i<G.V();i++) {
        for(int j = 0;j < degree(G,i);j++) {
            if(i == G.adj(i)[j]) {
                count ++;
            }
        }
    }
    return count;
}

void DeepSearch(Graph G,int s) {
    dfs(G,s);
}

void dfs(Graph G,int v) {
    if(!mark[v]) {
        cout << v << "--";
    }
    mark[v] = true;
    int size = G.table[v].size();
    for(int i=0; i<size; i++) {
        if(!mark[G.table[v][i]]) {
            egdedto[G.table[v][i]] = v;
            id[G.table[v][i]] = count;
            dfs(G,G.table[v][i]);
        }
    }
}


void wideSearch(Graph G,int s) {
    bfs(G,s);
}
void bfs(Graph G,int v) {
    queue<int> myqueue;
    myqueue.push(v);
    mark[v] = true;
    while(!myqueue.empty()) {
        int nownode = myqueue.front();
        int size = G.table[nownode].size();
        for(int i = 0; i < size; i++) {
            if(!mark[G.table[nownode][i]]) {
                mark[G.table[nownode][i]] = true;
                myqueue.push(G.table[nownode][i]);
                egdedto[G.table[nownode][i]] = nownode;
            }
        }

        myqueue.pop();
    }
}

void makeGrap(Graph &G) {
    G.addEdge(0,5);
    G.addEdge(2,4);
    G.addEdge(2,3);
    // G.addEdge(1,2);
    // G.addEdge(0,1);
    G.addEdge(3,4);
    G.addEdge(3,5);
    G.addEdge(0,2);
}

bool haspathto(int v) {
    return mark[v];
}

vector<int> pathTo(int s,int v) {
    vector<int> path;
    if(!haspathto(v)) {
        return path;
    }

    for(int i = v; i != s; i = egdedto[i]) {
        path.insert(path.begin(),i);
    }
    path.insert(path.begin(),s);
    for(int i = 0; i<path.size();i++) {
        cout << path[i] << "--";
    }
    return path;
}

void cc(Graph G) {
    int size = G.V();
    for(int i = 0; i < size; i++) {
        if(!mark[i]) {
            dfs(G,i);
            count ++;
        }
    }
}

bool connected(int s, int v) {
    if(id[s] == id[v]) {
        return true;
    }
    return false;
}

int nodeid(int v) {
    return id[v];
}

int main(){
    Graph G(6);
    vector<int> path;
    makeGrap(G);
    // DeepSearch(G,0);
    // wideSearch(G,0);
    cc(G);
    cout << endl;
    // cout << connected(2,4);
    // path = pathTo(0,5);
    return 0;
}