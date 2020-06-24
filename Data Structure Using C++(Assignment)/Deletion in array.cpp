#include <iostream>
using namespace std;

int main() {
 
   
   int a[100], size, pos, i, count = 0;

   cout << "Enter size \n";
   cin  >> size;
   
   cout << "Enter Elements\n";
   
   
   for (i = 0; i < size; i++) {
    cin >> a[i];
   }
   
   
   cout << "Enter the position to be deleted\n";
   cin  >> pos;

   //Shift element from i+1 to i
   for(i = pos-1; i < size; i++) {

      a[i] = a[i+1];
   }

  
   size--;            

  
  for(i = 0; i < size; i++) {
   
    cout<<a[i]<<" ";
    
  }

  return 0;
}
