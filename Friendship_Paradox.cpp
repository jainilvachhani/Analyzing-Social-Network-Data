#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int nodes = 14947;
	vector <vector <int>> adjlist(nodes);
	ifstream infile("data/fb_ucsd.txt");
	int a,b,i,j;
	int friends[nodes];
	while (infile>>a>>b)
	{
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for(i=0;i<nodes;i++)
	{
		friends[i] = adjlist[i].size();
	}
	int true_counts = 0;
	vector <int> friendship_paradox;
	for(i=0;i<nodes;i++)
	{
		int _friend = 0;
		for(j=0;j<adjlist[i].size();j++)
		{
			_friend += friends[adjlist[i][j]];
		}
		int avg_friend = _friend/adjlist[i].size();
		if(adjlist[i].size() < avg_friend)
		{
			friendship_paradox.push_back(i);
			true_counts++;
		}
	}
	printf("Friendship paradox holds true for\n");
	for(i=0;i<friendship_paradox.size();i++)
	{
		printf("%d ",friendship_paradox[i]);
	}
	printf("\nIt holds true for total %d persons out of %d persons\n",true_counts,nodes);
	return 0;	
}