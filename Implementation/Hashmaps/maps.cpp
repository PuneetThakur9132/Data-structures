#include <iostream>
#include <unordered_map>  // implemented through hash-table time complexity O(1)
#include <utility>
using namespace std;

int main(){
    unordered_map<string,int> ourmap;

    pair<string , int> p;
    p.first = "abc";
    p.second = 1;

    ourmap.insert(p);  // this is the first method to insert into map

    // we can also do like how we do in array.
    ourmap["def"] = 2;

    cout<<ourmap["def"]<<endl; // for printing the value at this key

    //another way to print in hashmaps
    cout<<ourmap.at("def")<<endl; // will get the same value as of previous one.

    //what if we try to print something which is not even does exist in ourmap.
   //Bubble Sort is implemented on a vector was , the user wants to know that vec[i] compared with which other element in a single iteration? cout<<ourmap.at("ghi")<<endl; // in this case we will get an error

    cout<<ourmap["ghi"]<<endl; // it will not show any error but print the value by assigning zero to it.

    cout<<"size:" <<ourmap.size()<<endl;

    //CHECK PRESENCE

    if(ourmap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }

    //To delete

    ourmap.erase("ghi");

    if(ourmap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    else{
        cout<<"ghi is not present"<<endl;
    }




}
