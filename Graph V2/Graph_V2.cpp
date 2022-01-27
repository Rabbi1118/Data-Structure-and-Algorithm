#include<iostream>
using namespace std;

string ver_list[8]={"A","B","C","D","E","F","G","H"}; //List of vertices of the graph.
int A[8][8]=  {{0,1,1,1,0,0,0,0}, //2-D adjacency array.
               {1,0,0,0,1,1,0,0},
               {1,0,0,0,0,0,1,0},
               {1,0,0,0,0,0,0,1},
               {0,1,0,0,0,0,0,1},
               {0,1,0,0,0,0,0,1},
               {0,0,1,0,0,0,0,1},
               {0,0,0,1,1,1,1,0}};

int main()
{
    for(int i=0;i<8;i++) //For loop to print vertices list.
    {
        cout<< ver_list[i] << " --> " ;
        for(int j=0;j<8;j++)
        {
            if(A[i][j] == 1)
                cout<< ver_list[j] << " ";
        }
        cout<<endl;
    }

    cout<<endl;
    string a;
    cout<<"Enter A Vertex To Find it's Connected Vertices: ";
    cin>>a;
    cout<<"The Vertex "<<a<<" is connected to ";

    for(int i=0;i<8;i++) //For loop to print the connected vertices of the vartex taken through user's input.
    {
        if(a == ver_list[i])
        {
            for(int j=0;j<8;j++)
                {
                if(A[i][j] == 1)
                    cout<< ver_list[j] << " ";
                }
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"***Vertex Connection Check***";
    cout<<endl;
    cout<<endl;
    cout<<"Enter name of a vertex:";
    string p;
    cin>>p;
    cout<<"Enter name of another vertex:";
    string q;
    cin>>q;

    for(int i=0;i<8;i++) //For loop for checking if two vertex are connected to each other.These two vertex are taken through user input.
    {
        if(ver_list[i]==p)
            {
                for(int j=0;j<8;j++)
                if(ver_list[j]==q){
                if(A[i][j] == 1 )
                     cout<< "Connected";
                else
                    cout<<"Not Connected";
                }
            }
    }

    return 0;
}
