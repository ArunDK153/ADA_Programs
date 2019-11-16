#include <iostream>

bool isHeap(int arr[],  int n)
{
    for (int i=0; i<=(n-2)/2; i++)
    {
        if (arr[2*i +1] > arr[i])
                return false;
        if (2*i+2 < n && arr[2*i+2] > arr[i])
                return false;
    }
    return true;
}

int main()
{
    int arr[50],n;	
    std::cout<<"Enter number of elements: ";
    std::cin>>n;
    std::cout<<"Enter elements: ";
    for(int i =0;i<n;i++)	
    {
	std::cin>>arr[i];
    }
    std::cout<<"Is it binary max heap? "<<endl;
    isHeap(arr, n)? std::cout<<"Yes" : std::cout<<"No";
    return 0;
}
