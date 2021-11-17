#include <iostream>
#include <string>

using namespace std;

/*String Data type */

int main()
{
    /*string s = "abc";
    string s1;
    s1 = "def";
    cout<<s<<endl;
    cout<<s1<<endl;*/

    /*string *sp = new string; //dynamically
    *sp = "def";
    cout<<sp<<endl;
    cout<<*sp<<endl;*/

    /*string s;
    getline(cin,s);
    cout<<s<<endl;*/

    /*string s = "defdef";
    cout<<s<<endl;

    s[2] = 'c';
    cout<<s<<endl;*/

    /*string s = "defdef";
    string s1 = "coding";

    string s2 = s+s1;

    cout<<s2<<endl;*/

    //************INBUILT FUNCTIONS**********

    string s = "aefdefdef";
    cout<<s.size()<<endl;

    cout<<s.substr(3)<<endl;
    cout<<s.substr(0,3)<<endl;

    cout<<s.find("def")<<endl;

    return 0;
}
