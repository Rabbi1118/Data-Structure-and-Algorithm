#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair<int,int>

class Graph { //Graph class contains Parents,vector,Find set,functions to Add weighted Edge,Union Set,Print and Kruskal's algorithm.
private:
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T;
    int *parent;
    int V;
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskals();
    void print();
};
Graph::Graph(int V) {
    parent = new int[V];
    for (int i = 0; i < V; i++) //For loop to create Graph.
        parent[i] = i;
    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) { //Function to Add weighted Edge.
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
    if (i == parent[i])
        return i;
    else
     return find_set(parent[i]);
     }

void Graph::union_set(int u, int v) { //Function to Union Set.
    parent[u] = parent[v];
}
void Graph::kruskals() { //Function to Kruskal's algorithm.
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
            T.push_back(G[i]);
            union_set(uRep, vRep);
        }
    }
}
void Graph::print() { //Function to Print.
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " : "
                << T[i].first;
        cout << endl;
    }
}
int main() {
    Graph g(10);
    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 3, 1);
    g.AddWeightedEdge(1, 2, 4);
    g.AddWeightedEdge(1, 9, 10);
    g.AddWeightedEdge(1, 0, 4);
    g.AddWeightedEdge(1, 3, 4);
    g.AddWeightedEdge(2, 1, 4);
    g.AddWeightedEdge(2, 4, 2);
    g.AddWeightedEdge(2, 5, 1);
    g.AddWeightedEdge(3, 0, 1);
    g.AddWeightedEdge(3, 1, 4);
    g.AddWeightedEdge(3, 7, 5);
    g.AddWeightedEdge(3, 9, 6);
    g.AddWeightedEdge(4, 2, 2);
    g.AddWeightedEdge(4, 6, 2);
    g.AddWeightedEdge(5, 2, 1);
    g.AddWeightedEdge(5, 6, 3);
    g.AddWeightedEdge(5, 8, 5);
    g.AddWeightedEdge(6, 4, 2);
    g.AddWeightedEdge(6, 5, 2);
    g.AddWeightedEdge(6, 8, 3);
    g.AddWeightedEdge(6, 9, 4);
    g.AddWeightedEdge(7, 3, 5);
    g.AddWeightedEdge(7, 9, 1);
    g.AddWeightedEdge(8, 5, 5);
    g.AddWeightedEdge(8, 6, 3);
    g.AddWeightedEdge(8, 9, 3);
    g.AddWeightedEdge(9, 1, 10);
    g.AddWeightedEdge(9, 3, 6);
    g.AddWeightedEdge(9, 7, 2);
    g.AddWeightedEdge(9, 6, 4);
    g.AddWeightedEdge(9, 8, 3);


    g.kruskals(); //Print Kruskal's algorithm.
    g.print(); // Print MST.
    return 0;
}

