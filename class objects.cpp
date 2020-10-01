#include<iostream>
using namespace std;
class binary{
    int a,b;
 public:
     void get(int ab,int bc)
{
    a=ab;b=bc;
}

     void put()
     {
       cout<<a<<" "<<b;
     }

};



int main()
{

  binary sd;
  sd.get(2,4);sd.put();
    return 0;
}
