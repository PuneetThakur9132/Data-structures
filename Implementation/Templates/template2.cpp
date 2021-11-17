#include <iostream>

using namespace std;

template <typename T , typename V>
class Pair{
    T x;
    V y;
public:
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }
    void setY(V y){
        this->y = y;
    }
    V getY(){
        return y;
    }
};

int main(){
    Pair <int , double>p1;
    p1.setX(10);
    p1.setY(1.11);
    Pair<Pair<int,double> , int> p2;

    p2.setX(p1);
    Pair<int,double> ans = p2.getX();
    cout<<ans.getX()<<" "<<ans.getY()<<endl;

    p2.setY(2.2);
    cout<<p2.getY()<<endl;


}
