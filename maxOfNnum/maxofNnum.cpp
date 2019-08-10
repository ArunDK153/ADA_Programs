#include <iostream>

using namespace std;

int main()
{
	cout<<"Enter the number of integers: ";
	int n;
	cin>>n;
	int max;
	int *arr;
	arr = new int[n];
	cout<<"Enter the numbers: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(i==0)
		{
			max=arr[i];
		}
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	cout<<"Maximum: "<<max<<endl;
	return 0;
}
