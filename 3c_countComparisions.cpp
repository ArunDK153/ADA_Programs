#include<bits/stdc++.h>
int mcount = 0;
using namespace std;

void swap(int* a, int* b)  
{
	int temp = *a;  
	*a = *b;  
	*b = temp;  
}  

int countBubbleSort(int arr[], int n)  
{ 
	int count = 0;
	for (int i=0;i<n-1;i++) 
		for (int j=0;j<n-i-1;j++)  
		{	
			count++;
			if(arr[j]>arr[j+1])  
				swap(&arr[j], &arr[j+1]);
		}
	return count;
}

int countSelectionSort(int arr[], int n)  
{
	int min_index, count = 0;
	for (int i=0;i<n-1;i++)  
	{ 
		min_index = i;  
		for (int j=i+1;j<n;j++)  
		{
			count++;
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		swap(&arr[min_index], &arr[i]);  
	}
	return count;
}

void merge(int arr[], int l, int m, int r) 
{
	int n1 = m-l+1, n2 = r-m, count = 0; 
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
		mcount++;
		if(left[i]<=right[j]) 
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

void countMergeSort(int arr[], int l, int r) 
{
	if(l<r) 
	{
		int m = l+(r-l)/2; 
		countMergeSort(arr, l, m); 
		countMergeSort(arr, m+1, r); 
		merge(arr, l, m, r);
	}
}

int main()
{
	int n,arr[50],arr1[50],arr2[50],arr3[50];
	cout<<"Enter no. of elements: ";
	cin>>n;
	cout<<"Enter elements of array: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	copy(begin(arr), end(arr), begin(arr1));
	copy(begin(arr), end(arr), begin(arr2));
	copy(begin(arr), end(arr), begin(arr3));
	int bubbleSortCount = countBubbleSort(arr1,n);
	int selectionSortCount = countSelectionSort(arr2,n);
	countMergeSort(arr3,0,n-1);
	cout<<"Sorted array is: \n";
	for(int i=0;i<n;i++)
	{
		cout<<arr3[i]<<" ";
	}
	cout<<"\n";
	cout<<"Number of comparisions in \n";
	cout<<"Bubble Sort: "<<bubbleSortCount<<"\n";
	cout<<"Selection Sort: "<<selectionSortCount<<"\n";
	cout<<"Merge Sort: "<<mcount<<"\n";
	return 0;
}
