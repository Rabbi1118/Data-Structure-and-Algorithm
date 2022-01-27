#include<iostream>
using namespace std;

class EDGE //Class contain primary node,it's connected node and the cost of exploring the connected node.
{
    public:
    char StartNode; //Primary or initial node.
    char EndNode; //Connected with initial node.
    int Weight; //cost of traveling to the adjacent node.

};


int main()
{
    char Vartex []={'A','B','C','D','E','F','G','H'}; //Vertices of the Graph.
    EDGE edge_list[10]; //Number of edges.


	edge_list[0].StartNode='A';
	edge_list[0].EndNode='B';
	edge_list[0].Weight=2;

	edge_list[1].StartNode='A';
	edge_list[1].EndNode='C';
	edge_list[1].Weight=5;

	edge_list[2].StartNode='A';
	edge_list[2].EndNode='D';
	edge_list[2].Weight=3;

    edge_list[3].StartNode='B';
	edge_list[3].EndNode='E';
	edge_list[3].Weight=7;

    edge_list[4].StartNode='C';
	edge_list[4].EndNode='F';
	edge_list[4].Weight=11;

    edge_list[5].StartNode='C';
	edge_list[5].EndNode='G';
	edge_list[5].Weight=5;

    edge_list[6].StartNode='D';
	edge_list[6].EndNode='H';
	edge_list[6].Weight=9;

    edge_list[7].StartNode='E';
	edge_list[7].EndNode='F';
	edge_list[7].Weight=4;

    edge_list[8].StartNode='F';
	edge_list[8].EndNode='H';
	edge_list[8].Weight=1;

    edge_list[9].StartNode='G';
	edge_list[9].EndNode='H';
	edge_list[9].Weight=2;


	for(int i=0;i<10;i++) //For loop for printing the StartNode,EndNode and weight.
    {
        cout<< edge_list[i].StartNode<<"--->"<<edge_list[i].EndNode<<"--->"<<edge_list[i].Weight<<endl;
	}
    cout<<endl;

    cout<<"Find the Adjecent vertices of :"<<endl; //Searching for adjacent vertices of a vartex taken through user input.
    char x;
    cin>>x;

	cout<<endl;
    cout<< x << " : ";

    for(int i=0;i<10;i++) //For loop to search matched vertex and printing the adjacent vertices.
        {
        if(x==edge_list[i].StartNode)
            cout<<edge_list[i].EndNode<<"  ";
        if(x==edge_list[i].EndNode)
            cout<<edge_list[i].StartNode<<"\t";
        }

	return 0;
}






