#include <iostream>
using namespace std;

class Car{
public:
    string marka;
    int model;

};
int main(){
    Car ferrari;
    ferrari.marka="Ferrari";
    ferrari.model=2022;
    cout<<"Bu arabanın modeli ve markası "<<ferrari.model<<ferrari.marka;
    return 0;
}