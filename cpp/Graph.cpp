#include "Graph.h"
#include <bits/stdc++.h>
using namespace std;

//Elementary operations

Graph :: Graph(int V)
{ 
	this->V = V;
	adj = new list<int> [V];
}

Graph :: ~Graph()
{
	delete [] adj;  
}

void Graph :: addEdgeU(int u, int v)
{  
	adj[u].push_back(v); 
	adj[v].push_back(u); 
}

void Graph :: addEdgeD(int u, int v)
{  
	adj[u].push_back(v); 
}

void Graph :: printGraph()
{
	list<int>::iterator i;
	for (int n = 0; n < V; ++n)
	{
		cout<<n+1<<" -> ";
		int flag = 0;

		for (i = adj[n].begin(); i != adj[n].end(); ++i)
		{
			if(flag)
				cout<<", ";
			flag = 1;

			int v = *i;
			cout<<v+1;
		}

		cout<<endl;
	}
}

//Finding Strognly Connected Components using DFS

void Graph::DFS(int v, bool visited[])
{
    visited[v] = true;
    cout << v+1 << " ";
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
 
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
 
    Stack.push(v);
}
 
void Graph::SCC()
{
    stack<int> Stack;
 
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
 
    Graph gr = getTranspose();
 
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    while (Stack.empty() == false)
    {
        int v = Stack.top();
        Stack.pop();
 
        if (visited[v] == false)
        {
            gr.DFS(v, visited);
            cout << endl;
        }
    }
}

//Finding path using BFS

void Graph::find_path(int start, int end, int par[])
{
    if(start==end || end==-1)
    {
        cout<<start;
    }
    else    
    {
        find_path(start, par[end],par);
        cout<<"->"<<end;
    }
}

void Graph::BFS(int n, int src)
{
    queue <int> Q;
    Q.push(src);
    int visited[100] = {0};
	int parent[100];

    visited[src] = 0;

    while(!Q.empty())
    {
        int u = Q.front();

		list<int>::iterator i;

		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = *i-1;
            if(!visited[v])
            {
                parent[v] = u+1;
                visited[v] = 1;
                Q.push(v);
			}
		}
		
		Q.pop();
    }    
 
 	int x,y;
	cout<<"Enter Starting vertex and Ending vertex"<<endl;
    cin>>x>>y;
    find_path(x,y,parent);    
}