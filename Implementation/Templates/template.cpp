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

int main()
{
    Pair<int , double> p1;
    p1.setX(2);
    cout<<p1.getX()<<endl;

    p1.setY(2.33);
    cout<<p1.getY()<<endl;
    return 0;
}
