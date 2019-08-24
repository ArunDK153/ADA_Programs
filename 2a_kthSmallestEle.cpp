#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int arr[20],n;
	cout<<"Enter number of elements of array: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int min_index,k;
	cout<<"Enter k: ";
	cin>>k;
	for (int i = 0; i < n-1; i++)
	{
		min_index = i;
		for (int j = i+1; j < n; j++)
			if (arr[j] < arr[min_index])
				min_index = j;  
		swap(arr[min_index], arr[i]);
	}
	cout << "Kth smallest element: "<<arr[k-1]<<"\n";
	return 0;  
}