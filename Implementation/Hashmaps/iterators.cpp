#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    unordered_map<string , int> ourmap;  // creating new map
    ourmap["abc"]  = 1;
    ourmap["abc1"] = 2;   // in unordered maps there is no sequence at all.
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    unordered_map<string,int>::iterator it = ourmap.begin();
    while(it!=ourmap.end()){
        cout<<"key:"<<it->first<<"value:"<<it->second<<endl;
        it++;
    }

    cout<<endl;
    cout<<endl;

    unordered_map<string,int>::iterator it2 = ourmap.find("abc");

    while(it2!= ourmap.end()){
        cout<<"key:"<<it2->first<<"value:"<<it2->second<<endl;
        it2++;

    }

    ourmap.erase(it2 , it2+4);



}
