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