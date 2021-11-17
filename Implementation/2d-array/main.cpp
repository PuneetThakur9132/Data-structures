#include <iostream>

using namespace std;

/* Implementation of 2D array */

int main()
{
   int input[100][100];
   int m , n;
   cin>>m>>n;

   //Taking input
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>input[i][j];
    }
   }
   //Printing array
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<input[i][j]<<" ";
    }
    cout<<endl;
   }
    return 0;
}
