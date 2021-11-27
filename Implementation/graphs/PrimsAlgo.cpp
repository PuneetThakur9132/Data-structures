#include <iostream>
#include <cmath>

using namespace std;

void prims(int** , int);
int findminVertex(int* , bool* , int );

int main(){
    int n , e;
    cin>>n>>e;

    int**edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];

        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0 ; i<e ; i++){
        int f,s,weight;
        cin>>f>>s>>weight;

        edges[s][f] = weight;
        edges[f][s] = weight;
    }

    prims(edges , n);
}

void prims(int**edges , int n){
    int*parents = new int[n];
    int*weights = new int[n];
    bool*visited = new bool[n];

    for(int i=0;i<n ; i++){
        weights[i] = INT_MAX;
        visited[i] = false;
    }

    weights[0] = 0;
    parents[0] = -1;

    for(int i=0 ; i<n-1 ; i++){

       int minVertex = findminVertex(weights,visited,n);
       visited[minVertex] = true;

       for(int j=0 ; j<n ; j++){
        if(edges[minVertex][j]!=0 && !visited[j]){
            if(edges[minVertex][j] < weights[j]){
                weights[j] = edges[minVertex][j];
                parents[j] = minVertex;

            }
        }
       }
    }
    // printing the MST
    for(int i = 1 ; i<n-1 ; i++)
    {
        if(parents[i]<i)
        {
            cout<<parents[i]<<" "<<i<<" "<<weights[i]<<endl;
        }
        else
            cout<<i<<" "<<parents[i]<<" "<<weights[i]<<endl;
    }
}

int findminVertex(int*weights , bool*visited , int n){
    int minVertex = -1;

    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex==-1 || weights[i]<weights[minVertex])){
            minVertex = i;
        }
    }

    return minVertex;
}
