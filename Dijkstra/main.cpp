#include<bits/stdc++.h>

using namespace std;

template<typename T> //Creating a template which will tell the type of the variable.
class Graph //Graph class contain function for Add edge, print Adjacent Nodes & Dijkstra algorithm.
{
    unordered_map<T, list<pair<T,int>>> m; //For storing the key value and the mapped value.
public:
    void addEdge(T u, T v, int dist) //Function to Add Edge.
    {
        m[u].push_back(make_pair(v,dist));
    }
    void printAdjacentNodes() //Function to print Adjacent Nodes.
    {
        for(auto j:m) //For loop for printing first and second adjacent nodes.
        {
            cout<<j.first << " --> ";
            for(auto i: j.second)
            {
                cout<<"(" <<i.first<<","<<i.second << ")";
            }
            cout<<endl;
        }
    }

    void Dijkstra(T src) //Function to Dijkstra algorithm.
    {
        unordered_map<T,int> dist;
        for(auto j:m) //For loop to determine maximum and minimum value and comparing them.
            dist[j.first] = INT_MAX;

        dist[src] = 0;

        set<pair<int, T>> s;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for(auto childPair: m[node]) //For loop to calculate total cost to travel the distance.
            {
                if(nodeDist + childPair.second < dist[childPair.first])
                {
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f != s.end())
                    {
                       s.erase(f);
                    }
                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }

            for(auto d:dist){ //For loop to determining the path with minimum cost.
                cout<< "Shortest path cost from "<< src << " --> "<<d.first << " is " << d.second <<endl;
                cout<<src;
                for(auto it = dist.begin(); it!=dist.end() ;it++){ //Nested for loop to break the loop if the condition is true.
                    if(d.first==src){
                        break;
                    }
                   if((*it).first!=src &&(*it).first!=d.first)
                    {
                        cout<<"-->"<<(*it).first;

                    }
                    else if((*it).first!=src){

                        cout<<"-->"<<(*it).first;
                        break;
                    }
                }cout<<endl;
            }
        }
};

int main()
{
    Graph<string> G;
    int vertex, edge;
    freopen("g1.txt","r", stdin);
    cin>> vertex >> edge;

    string u,v;
    int d;
    for(int i=0;i<edge;i++) //For loop to add edge taking user's input.
    {
        cin>> u >> v >> d;
        G.addEdge(u,v,d);
    }

    G.printAdjacentNodes(); //Print Adjacent Nodes.
    G.Dijkstra("A"); // print Dijkstra algorithm and shortest path.
    return 0;
}
