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

void merge(vector<int> &A, int mid, int low, int high){
    int n = high - low+1;
    // cout<<n;
    int i = low;
    int j = mid+1;
    int k=0;
    vector<int> B(n);
    while(i<=mid && j<= high){         // low, low+1, ... , mid, (partition), mid+1, ... , high
        if(A[i]<A[j]){                 //      (sorted arr1)                   (sorted arr2)
            B[k]=A[i];
            k++; i++;
        }
        else if(A[i]>A[j]){
            B[k]= A[j];
            j++; k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        k++; i++;
    }
    while(j<=high){
        B[k]=A[j];
        k++; j++;
    }
    
    int m=0;
    for(int l=low; l<=high; l++){
        A[l] = B[m];
        m++;
    }
}

void mergesort(vector<int> &A , int low, int high){    // pass by reference
    int mid = (low+high)/2;
    if(low<high){
    mergesort(A, low, mid);
    mergesort(A, mid+1, high);
    
    merge(A, mid, low, high);
  
    }
}



int main(){
    fio
    vector<int> A;
    int arr[] = {5, 3, 8, 9, 1, 7, 0, 2, 6, 4};
    A.assign(arr, arr+10);

    mergesort(A, 0, 9);
    printarray(A);
    return 0;
}

// runtime: O( nlogn )
// total steps = logn  (base 2)

// Master method:
// T(n) = aT(n/b) + O(n^d)
// a = number of recursive calls per recursion
// b = shrinkage factor
// d = runtime dependency power of n
// for MergeSort: a = 2, b = 2, d = 1
