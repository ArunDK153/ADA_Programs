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
		for (int j = 0; j < n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
	cout << "k largest elements: ";
	for(int i=n-k;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;  
}