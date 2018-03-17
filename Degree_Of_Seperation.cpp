#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int bfs(vector <vector <int>> adjlist, int n, int source)
{
	int distance[n],visited[n];
	int i;
	for(i=0;i<n;i++)
	{
		distance[i] = INT_MAX;
		visited[i] = 0;
	}
	distance[source] = 0;
	visited[source] = 1;
	queue <int> bfsq;
	bfsq.push(source);
	while(!bfsq.empty())
	{
		int u = bfsq.front();
		bfsq.pop();
		for(int v: adjlist[u])
		{
			if(visited[v]==0)
			{
				visited[v] = 1;
				distance[v] = distance[u] + 1;
				bfsq.push(v);
			}
		}
	}
	int avg=0,node_count=0;
	for(i=0;i<n;i++)
	{
		if(distance[i] != INT_MAX)
		{
			avg += distance[i];
			node_count++;
		}
	}
	return avg/node_count;
}

int main()
{
	int nodes = 14947;
	vector <vector <int>> adjlist(nodes);
	ifstream infile("data/fb_ucsd.txt");
	int a,b,i,j;
	while (infile>>a>>b)
	{
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int avg_seperation[nodes];
	for(i=0;i<nodes;i++)
	{
			avg_seperation[i] = bfs(adjlist, nodes, i);
			printf("Average degree of seperation for %d is %d\n",i,avg_seperation[i]);
	}
	int total_avg = 0;
	for(i=0;i<nodes;i++)
	{
			total_avg += avg_seperation[i];
	}
	total_avg /= nodes;
	cout<<total_avg;
}