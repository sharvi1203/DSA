#include <iostream>
using namespace std;
class Vehicle{
    public:
    Vehicle(){
        cout<<"Vehicle's Constructor"<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle's Destructor"<<endl;
    }
    void print(){
        cout<<"Vehicle"<<endl;
    }
};
//Virtual iliye add kiya kyunki Vehicle ki do do copies bnegi truck aur car ke
//andr virtual add krne se ab bus ke pass direct acces aajega Vehicle ka
class Car:virtual public Vehicle{
     public:
    Car(){
        cout<<"Car's Constructor"<<endl;
    }
    ~Car(){
        cout<<"Car's Destructor"<<endl;
    }
    void print(){
        cout<<"Car"<<endl;
    }
};
class Truck:virtual public Vehicle{
     public:
    Truck(){
        cout<<"Truck's Constructor"<<endl;
    }
    ~Truck(){
        cout<<"Truck's Destructor"<<endl;
    }
    // void print(){
    //     cout<<"Truck"<<endl;
    // }
};
class Bus:public Car,public Truck{
     public:
    Bus(){
        cout<<"Bus's Constructor"<<endl;
    }
    ~Bus(){
        cout<<"Bus's Destructor"<<endl;
    }
    // void print(){
    //     cout<<"Bus"<<endl;
    // }
};
int main() {
	Bus b; 
	b.Truck::print();
	return 0;
}
/*
          A
         / \
         B C
         \ /
          D
*/
