// heap is always a binary tree
// we are working on "max heap", where parent element greater than its both branch elements

#include<iostream>
#include<iomanip>
using namespace std;      

void insert_heap(int H[], int n){   // n is index of element we want to add
    int i=n, temp;
    temp = H[n];

    while(i>1 && temp>H[i/2]){
        H[i] = H[i/2];
        i = i/2;
    }

    H[i] = temp;     // atmost, i will reduce to 1

}

// time: O(logn)

void delete_heap(int H[], int n){ //  only "root" element can be deleted in heap. Here, n = size of heap
    int i, j, x;
    int val = H[1];   // storing root element to be deleted
    x = H[n];
    H[1] = H[n];   // last element takes root position

    i = 1; j = 2*i;

    while(j<n-1){       // last element gets removed. So n-1 elements
        if(H[j]<H[j+1]){    // which branch is greater
            j = j+1;
        }

        if(H[j]>H[i]){
            int temp = H[i];    // swapping
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }

    // cout<<"Deleted element: "<<val<<endl;
    
    H[n] = val;     // storing deleted element at last

}

// time: O(logn)  --> depends on height

int main(){

    // int H[] = {0, 3, 4, 9 , 1, 14, 8, 16};
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};    // this is not yet a heap

    // create_heap
 
    for(int i=2; i<8; i++){       // for creating heap by arranging the elements of array
        insert_heap(H, i);        // we are moving from top to bottom
    }

    // time: O(nlogn)

    cout<<"The heap created using create_heap method:"<<endl;

    for(int i=1; i<8;i++){
        cout<<H[i]<<" ";
    }

    cout<<endl;

    // delete_heap(H,7);

    //  for(int i=1; i<7;i++){
    //     cout<<H[i]<<" ";
    // }

//   -------------------------------------------------

    // HEAP SORT

    for(int i = 7; i>1 ;i--){   // deleting and storing elements at last
        delete_heap(H,i);
    }

    // this will make the array sorted


    cout<<"Sorted array with heap_sort:"<<endl;
    for(int i=1; i<8;i++){
        cout<<H[i]<<" ";
    }

    return 0;
}


// can also create elements by heapify method.
// start from last and check whether with its below elements, it forms heap or not
// then take the previous element of array and check the same
// gradually move upwards towards parent root
// this is faster than create_heap method