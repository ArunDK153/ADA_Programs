#include<iostream> 

using namespace std; 

int main()  
{      
    int x,ans,start=1;
    cout<<"Enter the number: ";
    cin>>x;
    int end=x/2;
    if(x<0)
    {
    	 cout <<endl<<"Sqaure root: Undefined"<< endl;
    	 return 0; 
    }
    if(x==0||x==1)
    ans = x;
    else
    {
    	  while(start<=end)
    	  {
    	  	  int mid= (start+end)/2;
    	  	  if(mid*mid==x)
    	  	  {
    	  	  	ans= mid;
    	  	  	break;
    	  	  }
    	  	  else if (mid*mid<x)
    	  	  {
    	  	  	 start= mid+1;
    	  	  	 ans=mid;
    	  	  }
    	  	  else
    	  	  {
    	  	  	  end=mid-1;
    	  	  }
    	  }
    }
    cout <<endl<<"Sqaure root: "<<ans<< endl; 
    return 0; 
} 
