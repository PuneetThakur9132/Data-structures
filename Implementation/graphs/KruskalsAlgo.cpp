#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


class Edge{
public:
    int source;  // for the source vertex
    int dest;    // for the destination vertex
    int weight;  // for the weight of edge b/w source and destination vertex
};


void Kruskals(Edge* , int  , int );
bool compare(Edge  , Edge );
int findParent(int  , int*);
void printMST(Edge* , int );


int main(){
    int n , E;  //n:no of vertices , E:no of Edges
    cin>>n>>E;

    Edge*input = new Edge[E];

    for(int i=0 ; i<E ; i++){
        int s ,d ,w;
        cin>>s>>d>>w;

        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    Kruskals(input , n , E);
}

void Kruskals(Edge*input , int n , int E){
    sort(input , input+E , compare); // sorting according to weight because each time we want to pick min weighted edge.
    Edge*output = new Edge[n-1]; // output array for storing MST.
    int*parent = new int[n];
    for(int i=0 ; i<n ; i++){
        parent[i] = i;
    }

    int count =0 , i=0;

    while(count!=n-1){
        Edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source , parent);
        int destParent = findParent(currentEdge.dest , parent);

        if(sourceParent != destParent){ // we will only include edge in our mst if they are not in connected component.
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
     printMST(output , n);

}

bool compare(Edge e1 , Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v , int*parent){
    if(parent[v] == v){  // if parent of vertex is it itself then we'll return.
        return v;
    }

    return findParent(parent[v] , parent);  // otherwise call recursion we want to find topmost parent.
}

void printMST(Edge*output , int n)
{
    for(int i =0 ; i<n-1 ; i++)
    {
        cout<<min(output[i].source , output[i].dest)<<" ";
        cout<<max(output[i].source , output[i].dest)<<" ";
        cout<<output[i].weight<<endl;

    }

}
