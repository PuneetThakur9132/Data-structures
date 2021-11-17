#include <iostream>

using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int **p = new int*[m];
    for(int i=0;i<m;i++){
        p[i] = new int[n];
    }
    //Taking input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    }
    //Printing 2D array
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    //Deleting 2D array
    for(int i=0;i<m;i++){
        delete[] p[i];
    }
    delete[] p;
    return 0;
}
