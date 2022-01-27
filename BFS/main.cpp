#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>

using namespace std;

enum Color {White = 1, Gray, Black}; //Color

struct node //Node structure containing vertex,color and discovery time.
{
    int vertex;
    Color curr_color;
    int discovery_time;
    list<int> *adj = new list<int>;
};

vector<node> Node_list;

void makeAdjacency(int num_of_vertex) //Function to make adjacency list, entering -1 will cause the list to end.
{
    cout<< "Enter Adjacency Lists\n";
    cout<< "****** Enter a '-1' to end the list of a node *******"<< endl;
    for(int i=0;i<num_of_vertex;i++) //For loop to create Adjacency list.
    {
        cout<< "Vertex " << i << endl;
        int adjacent;
        while(1)
        {
            cin>> adjacent;
            if(adjacent == -1)
                break;
            Node_list[i].adj->push_back(adjacent);
        }
        cout<< endl;
    }
}

void printAdjacency(int num_of_vertex) //Function to print the Adjacency list.
{
    cout<< " -------------------- Adjacency List --------------------"<<endl;
    cout<< "Vertex adjacent"<<endl;
    for(int i=0;i<num_of_vertex;i++) //For loop to traverse the adjacency vertex with the help of iterator.
    {
        cout<< i << "\t [";
        for(list<int>::iterator it = Node_list[i].adj->begin(); it != Node_list[i].adj->end(); it++)
        {
            cout<< *it << ",";
        }
        cout<< "]" << endl;
    }
}

void BFS(int startNode) //Function to Breadth-first search.
{
    queue<node> Q;

    Q.push(Node_list[startNode]);
    node currentNode;

    while(!Q.empty())
    {
        currentNode = Q.front();
        for(list<int>::iterator it=currentNode.adj->begin(); it != currentNode.adj->end(); it++) //For loop to traverse from current node to adjacent node if the condition is true and time will increase by 1 if the color changes from white to gray.
        {
            if(Node_list[*it].curr_color == White)
            {
                Node_list[*it].curr_color = Gray;
                Node_list[*it].discovery_time = currentNode.discovery_time + 1;
                Q.push(Node_list[*it]);
            }
        }

        cout<< "Current Node: "<< currentNode.vertex << endl;
        cout<< "Discovery Time: "<< currentNode.discovery_time << endl;
        currentNode.curr_color = Black;
        Q.pop();
    }
}

int main()
{
    int num_of_vertex;
    int i;
    cout<< "Enter number of vertex: ";
    cin>> num_of_vertex;

    for(i=0;i<num_of_vertex;i++) //For loop to create vertex with user's input.
    {
        node tmp;
        tmp.vertex = i;
        tmp.curr_color = White;
        tmp.discovery_time = 0; //If the color is white discovery time will be set to 0.
        Node_list.push_back(tmp);
    }
    makeAdjacency(num_of_vertex); //Make Adjacency.
    printAdjacency(num_of_vertex); //Print Adjacency.

    cout<< "Enter the starting node for BFS visit"<<endl;
    int startNode;
    cin>> startNode;
    BFS(startNode); //Find the BFS taking starting node from user's input.
    return 0;
}
