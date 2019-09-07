#include<iostream> 
#include <list> 

using namespace std; 

class Graph 
{
	int V; 
	list<int> *adjacent; 
	void DFSUtil(int v, bool visited[]); 
	public: Graph(int V)
	{
		this->V = V; 
		adjacent = new list<int>[V]; 
	} 
	void addEdge(int v, int w); 
	void connectedComponents(); 
}; 

void Graph::connectedComponents() 
{
	bool *visited = new bool[V]; 
	for(int v = 0; v < V; v++) 
		visited[v] = false; 
	for (int v=0; v<V; v++)
	{
		if (visited[v] == false) 
		{
			DFSUtil(v, visited); 
			cout << "\n"; 
		}
	} 
} 

void Graph::DFSUtil(int v, bool visited[]) 
{
	visited[v] = true; 
	cout << v << " "; 
	list<int>::iterator i; 
	for(i = adjacent[v].begin(); i != adjacent[v].end(); ++i) 
		if(!visited[*i]) 
			DFSUtil(*i, visited); 
}

void Graph::addEdge(int v, int w) 
{ 
	adjacent[v].push_back(w); 
	adjacent[w].push_back(v); 
}

int main() 
{
	int n,adjArr[50][50];
	cout<<"Enter number of vertices: ";
	cin>>n;
	Graph g(n);
	cout<<"Enter adjacency matrix: ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>adjArr[i][j];
			if(adjArr[i][j]==1)
			{
				g.addEdge(i,j);
			}
		}
	}
	cout << "Following are the connected components: \n"; 
	g.connectedComponents(); 
	return 0; 
} 