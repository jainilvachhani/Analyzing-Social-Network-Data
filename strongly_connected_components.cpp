#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;


stack <int> finished;
void dfs_visit(int v, int visited[], vector <vector <int>> adjlist)
{
	visited[v] = 1;
	int i;
	cout<<v<<" ";
	for(i=0;i<adjlist[v].size();i++)
	{
		if(visited[adjlist[v][i]]==0)
		{
			dfs_visit(adjlist[v][i],visited,adjlist);	
		}
	}
}

void dfs(int v, int visited[], vector <vector <int>> adjlist)
{
	visited[v] = 1;
	int i;
	for(i=0;i<adjlist[v].size();i++)
	{
		if(visited[adjlist[v][i]]==0)
		{
			dfs(adjlist[v][i],visited,adjlist);
		}
	}
	finished.push(v);
}

void get_scc(int n, vector <vector <int>> adjlist, vector <vector <int>> adjlist_transpose)
{
	int visited[n];
	int i;
	vector <int> scc;
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(i,visited,adjlist);
		}
	}
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	while(!finished.empty())
	{
		int v = finished.top();
		finished.pop();
		if(visited[v]==0)
		{
			dfs_visit(v,visited,adjlist_transpose);
			cout<<endl;
		}
	}
}

int main() 
{
	int n,m;
	cin>>n>>m;
	vector <vector <int>> adjlist(n);
	vector <vector <int>> adjlist_transpose(n);
	int i,j;
	for(i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adjlist[x].push_back(y);
		adjlist_transpose[y].push_back(x);
	}
	get_scc(n, adjlist,adjlist_transpose);
	return 0;
}