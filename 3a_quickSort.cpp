#include <bits/stdc++.h> 

using namespace std;  

void swap(int* a, int* b)  
{
	int temp = *a;  
	*a = *b;  
	*b = temp;  
}  

int partition (int arr[], int low, int high)  
{  
	int pivot = arr[high];  
	int i = low-1;
	for (int j=low; j<= high-1; j++)  
	{ 
		if (arr[j]<pivot)  
		{
			i++;
			swap(&arr[i], &arr[j]);  
		}  
	}  
	swap(&arr[i+1], &arr[high]);  
	return (i+1);  
}

void quickSort(int arr[], int low, int high)  
{  
	if (low<high)  
	{
		int pindex = partition(arr, low, high);  
		quickSort(arr, low, pindex-1);  
		quickSort(arr, pindex+1, high);  
	}
}

int main()  
{
	int n,arr[50];
	cout<<"Enter no. of elements: ";
	cin>>n;
	cout<<"Enter elements of array: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quickSort(arr, 0, n-1);  
	cout << "Sorted array: \n";  
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}  
	return 0;  
}  
