#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


void printarray(vector<int> &A){      // pass by reference
    for(int i=0; i< A.size(); i++){
        cout<<A[i]<<" ";
    }
}

int partition(vector<int> &A, int low, int high){       // pivot  , i , ... , j
    int pivot = A[low];                                 // choosing first element as pivot 
    int i = low+1;                                      // i increases till it finds larger element than pivot
    int j = high;                                       // j decreases till it find smaller element than pivot
    do{
        while(A[i]<=pivot && i<high){
            i++;
        }
        while(A[j]>pivot && j>low){
            j--;
        }
        if( i<j){
            int swap = A[i];
            A[i]= A[j];
            A[j]= swap;
        }
    }while(i<j);                 // results in pivot , ( < pivot ), ( > pivot )

    int term = A[low];
    A[low] = A[j];
    A[j] = term;                 // results in ( < pivot ) , pivot , ( > pivot )

    return j; 

}

void quicksort(vector<int> &A, int low, int high){            // ( < pivot ), pivot element, ( > pivot )
    if(low<high){                                             // ( ... )  ==> for recursive call
        int pivot = partition(A, low, high);
        quicksort(A, low , pivot-1);
        quicksort(A, pivot+1, high);
    }
}



int main(){
    fio
    vector<int> A;
    int arr[] = {6,3,3445, 76, 73, 54, 29, 95, 45};
    A.assign(arr, arr+9);

    quicksort(A, 0, 8);
    printarray(A);
    return 0;
}


// Worst case: when an array is already sorted and we choose first element as pivot point ==> O(n^2)
// Best case: If somehow, we always get partititon at the middle of array ==> O(nlogn)
// not stable

// Average run time varies between ( O(nlogn) , O(n^2) ), which at most of times has nearly best case results

// Probability analysis: Expected size of first recursive call = (n-1)/2
// E(size) = 0/n + 1/n + 2/n + ... + (n-1)/n = (n-1)/2


// COURSERA answer: The best case is when the algorithm always picks the median as a pivot,
// in which case the recursion is essentially identical to that in MergeSort. 
// In the worst case the min or the max is always chosen as the pivot, resulting in linear depth.