#include <bits/stdc++.h> 

using namespace std; 

void merge(int arr[], int l, int m, int r) 
{
	int n1 = m-l+1; 
	int n2 = r-m; 
	int left[n1], right[n2],i,j,k; 
	for (i=0;i<n1;i++) 
		left[i] = arr[l + i]; 
	for (j=0;j<n2;j++) 
		right[j] = arr[m+1+j]; 
	i = 0;
	j = 0;
	k = l;
	while(i<n1 && j<n2) 
	{
		if (left[i]<=right[j]) 
		{
			arr[k] = left[i]; 
			i++; 
		} 
		else
		{
			arr[k] = right[j]; 
			j++; 
		}
		k++; 
	}
	while(i<n1) 
    {
		arr[k] = left[i]; 
		i++; 
		k++; 
	} 
	while(j<n2) 
	{ 
		arr[k] = right[j]; 
		j++; 
		k++; 
	}
}

void mergeSort(int arr[], int l, int r) 
{ 
	if (l<r) 
	{
		int m = l+(r-l)/2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 
		merge(arr, l, m, r); 
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
	mergeSort(arr, 0, n-1); 
	cout<<"Sorted array is \n"; 
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0; 
}