#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int arr[50], size, insert, i, pos;
	cout<<"Enter Size : ";
	cin>>size;
	cout<<"Enter elements : ";
	for(i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter element to be insert : ";
	cin>>insert;
	cout<<"Enter index number";
	cin>>pos;

	for(i=size; i>pos; i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos]=insert;
	cout<<"Element inserted\n";
	cout<<"Array Presently : \n";
	for(i=0; i<size+1; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
