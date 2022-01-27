#include <iostream>
#include <vector>
#include <list>

#define SIZE 8

using namespace std;

class Node; //Node class contain color,vector and initial time.
enum Color {White =1 ,Gray,Black};
vector<Node> NQ;
static int time = 0;

struct Node //Node structure containing vertex,discovery time & Finish time.
{
    int vertex;
    Color curr_color;
    int discovery_time;
    int finish_time;
};

class Graph //Graph class contain functions to Add Edge, printing adjacent list.
{
public:
    Graph();
    list<int> *adj;
    void addEdge(int x, int y);
    void printAjacentList();
};

Graph::Graph()
{
    adj = new list<int> [SIZE];
}

void Graph::printAjacentList() //Function to print the Adjacency list.
{
    cout<< "Adjacent Node : "<< endl;
    for(int i=0;i<SIZE; i++) //For loop to print Adjacent nodes.
    {
        cout<< i << "\t[";
        for(list<int>::iterator it=adj[i].begin(); it != adj[i].end(); it++) //Nested For loop with iterator to traverse the list.
        {
            cout<< *it << ",";
        }
        cout<< "]"<<endl;
    }
    cout<< "-------------------------------------"<< endl;
}

void Graph::addEdge(int x, int y) //Function to Add Edge.
{
    adj[x].push_back(y);
}

void DFSVisit(Graph G, Node u) //Function to DFS Visit.
{
    u.curr_color = Gray;
    u.discovery_time = ++time;
    cout<<u.vertex << " ";
    for(list<int>::iterator it=(G.adj[u.vertex]).begin(); it != (G.adj[u.vertex]).end(); it++ ) //For loop with iterator to traverse the vertex if the color is white. Time increases if the color is gray or black.
    {
        if(NQ[*it].curr_color == White)
        {
            DFSVisit(G, NQ[*it]);
        }
    }
    u.curr_color = Black;
    u.finish_time = ++time;
}

void DFS(Graph G, int startNode) //Function to Depth-first search.
{
    if(NQ[startNode].curr_color == White) //If the color is white the node will traveled till it's not black.
    {
        DFSVisit(G, NQ[startNode]);
        cout<<endl;
    }
}

int main()
{
    for(int i=0;i<SIZE; i++) //For loop to create vertex with user's input.
    {
        int v = i;
        Node tmp;
        tmp.vertex = v;
        tmp.curr_color = White;
        tmp.discovery_time = 0;//If the color is white discovery time will be set to 0.
        tmp.finish_time = 0;//If the color is white finish time will be set to 0.

        NQ.push_back(tmp);
    }

    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(3,6);
    g.addEdge(3,7);

    g.printAjacentList(); //Printing Adjacency list.

    DFS(g, 3);
    return 0;
}
