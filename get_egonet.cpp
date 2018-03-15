#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
using namespace std;

vector <vector <int>> get_egonet(vector <vector<int>> adjlist, int n, int m, int center)
{
	vector <vector <int>> egonet(n);
	int i;
	stack <int> friends;
	map <int, bool> temp;
	for(i=0;i<adjlist[center].size();i++)
	{
		egonet[center].push_back(adjlist[center][i]);
		friends.push(adjlist[center][i]);
		temp[adjlist[center][i]] = true;
		temp[center] = true;
	}
	while(!friends.empty())
	{
		int top = friends.top();
		friends.pop();
		for(i=0;i<adjlist[top].size();i++)
		{
			if(temp[adjlist[top][i]])
			{
				egonet[top].push_back(adjlist[top][i]);
			}
		}
	}
	return egonet;
}

int main() 
{
	int n,m;
	cin>>n>>m;
	vector <vector <int>> adjlist(n);
	int i,j;
	for(i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
	}
	int center;
	cin>>center;
	vector <vector <int>> egonet = get_egonet(adjlist,n,m,center);
	for(i=0;i<n;i++)
	{
		for(j=0;j<egonet[i].size();j++)
		{
			printf("%d %d\n",i, egonet[i][j]);
		}
	}
	return 0;
}