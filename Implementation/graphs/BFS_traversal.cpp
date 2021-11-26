#include <iostream>
#include <queue>
using namespace std;

void print(int** , int  , int , bool*);
int main(){
    int n; // no of vertices
    int e; // no of edges

    cin>>n>>e;

    int**edges = new int*[n];
    for(int i=0 ; i<n ; i++){
        edges[i] = new int[n];

        for(int j=0 ; j<n ; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0 ; i<e ;i++){
        int f ,s;
        cin>>f>>s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool*visited = new bool[n];   // maintaining the visited array to check whether we've visited vertex or not.
    for(int i=0 ; i<n ; i++){
        visited[i] = false;
    }

    print(edges , n , 0 , visited);

    delete[] visited;

    for(int i =0 ;i<n ;i++){
        delete edges[i];
    }

    delete[] edges;
}

void print(int**edges , int n , int sv , bool*visited){
    queue<int> pendingvertices;
    pendingvertices.push(sv);

    visited[sv]  = true;

    while(pendingvertices.size()!=0){
        int currentVertex = pendingvertices.front();
        pendingvertices.pop();

        cout<<currentVertex<<" ";

        for(int i=0;i<n;i++){
            if(i== currentVertex){
                continue;
            }
            if(edges[currentVertex][i]==1 && !visited[i]){
                pendingvertices.push(i);
                visited[i] = true;
            }
        }
    }
}

