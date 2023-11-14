#include "Digraph.h"


DiGraph::DiGraph(int v){
    this->v = v;
    this->e = 0;
    for(int i = 0; i < v; i++) {
        vector<int> temp;
        this->table.push_back(temp);
    }
}

int DiGraph::V(){
    return this->v;
}

int DiGraph::E(){
    return this->e;
}

void DiGraph::addEdge(int v, int w) {
    this->table[v].insert(table[v].begin(),w);
    this->e ++;
}

vector<int> DiGraph::adj(int V) {
    return this->table[V];
}

DiGraph DiGraph::reverse() {
    DiGraph R(v);
    for(int i = 0; i<v; i++) {
        int size = table[i].size();
        for (int j = 0; i<size; j++) {
            R.addEdge(j,i);
        }
    }
    return R;
}



int main() {
    
    return 0;
}