#include <iostream>
using namespace std;

int visited[10][10];
int c,r;
int a[10][10];
int row[]={-1, -1, -1, 0, 0, 1, 1, 1 }; 
int col[]={-1, 0, 1, -1, 1, -1, 0, 1 }; 

bool canAdd(int i,int j)
{
	if(i>=0 && i<r && j>=0 && j<r)
		return true;
	return false;
}
void DFS(int i,int j)
{
	visited[i][j]=1;
	for(int k=0;k<8;k++)
	{
		if(canAdd(i+row[k],j+col[k]) && a[i+row[k]][j+col[k]] && visited[i+row[k]][j+col[k]]==0)
			DFS(i+row[k],j+col[k]);
	}
}
int main()
{
	int count=0;
	cout<<"Enter number of rows and columns: \n";
	cin>>r;
	cin>>c;
	cout<<"Enter 2D matrix: \n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
			visited[i][j]=0;
		}
	}
	cout<<"No of clusters are:\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(visited[i][j]==0 && a[i][j]==1)
			{
				DFS(i,j);
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0; 
}