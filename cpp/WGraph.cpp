#include "Graph.h"
#include <bits/stdc++.h>
using namespace std;

//Elementary operations

WGraph :: WGraph(int V)
{ 
	this->V = V;
	adj = new vector<pair<int, int> > [V];
}

WGraph :: ~WGraph()
{
	delete [] adj;  
}

void WGraph :: addEdgeU(int u, int v, int w)
{  
	adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void WGraph :: addEdgeD(int u, int v, int w)
{  
	adj[u].push_back(make_pair(v, w));
}

void WGraph :: printGraph()
{    
	for (int u = 0; u < V; ++u)
	{
		cout<<u+1<<" -> ";
		int flag = 0;

		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if(flag)
				cout<<", ";
			flag = 1;

			int v = i->first;
			int w = i->second;
			cout<<v+1<<"("<<w<<")";
		}

		cout<<endl;
	}    
}

void WGraph :: Dijkstra(int s)
{
const int N = 1e5 + 5;
const long long inf = 1e16 + 16;
int n , k , x , m;
long long dist[N];

	for(int i = 0 ; i <= n ; ++i)
		dist[i] = inf;
	
	dist[s] = 0;
	priority_queue < pair < long long , int > > pq;
	
	while(!pq.empty())
		pq.pop();
	
	pq.push({0 , s});
	while(!pq.empty())
	{
		int node = pq.top().second;
		long long cost = -pq.top().first;
		pq.pop();
		
		if(dist[node] < cost)
			continue;
			
		for(auto it : adj[node])
		{
			int next = it.first;
			long long nd = it.second + cost;
			
			if(dist[next] > nd)
			{
				dist[next] = nd;
				pq.push({-nd , next});
			}
		}
	}
	
	for(int i = 0 ; i < V ; ++i)
		cout<<s+1<<" -> "<<i+1<<" : "<<dist[i]<<endl;
		
}