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

//Euler

void Graph :: Euler(int n, int e)
{
	#define NMAX 100005
	#define MMAX 700005

	vector<int> G[ NMAX ];
	stack<int> STACK;

	int degree[ NMAX ],
	sol[ MMAX ],
	num_nodes = n, 
	num_edges = e,
	i,
	x,
	y,
	a,
	b;

	for (i = 0; i < V; ++i)
	{
		x = i+1;

		list<int>::iterator it;
		for (it = adj[i].begin(); it != adj[i].end(); ++it)
		{
			y = *it;
			y = y+1;

			G[ x ].push_back( y );  
			G[ y ].push_back( x );

			degree[ x ]++;
			degree[ y ]++;			
		}
	}

	for(i = 1; i <= num_nodes; i++) 
	{
		if(degree[ i ] % 2) 
		{
		   cout<<"euler path not found \n";
		   return;
		}
	}

	STACK.push( 1 );

	while(!STACK.empty()) 
	{
		a = STACK.top();

	   if(!degree[ a ]) 
	   {
	       sol[++sol[0]] = a;
	       STACK.pop();
	       continue;  
	   }

	   b = G[ a ].back();

	   G[ a ].pop_back();           

	   degree[ a ]--;
	   degree[ b ]--;

	   STACK.push( b ); 

	   for(vector<int>::iterator it = G[ b ].begin(); it != G[ b ].end(); ++it) 
	   {
	       if(*it == a) 
	       {
	           G[ b ].erase( it );
	           break;
	       }   
	   } 
	}

	for(i = 1; i <= num_edges; i++) 
	cout<<sol[ i ]<<" ";
	cout<<endl; 
}

//Hamilton

bool Graph :: check_graph(int v) 
{
    color[v] = 1;
    for (size_t i = 0; i < gr[v].size(); ++i) 
    {
        int to = gr[v][i];
        if (color[to] == 0) 
        {
            if (check_graph(to))
                return true;
        }
        else if (color[to] == 1) 
        {
            cycle_start = to;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
  
void Graph :: dfs(int v) 
{
    used[v] = true;
    for (size_t i = 0; i < gr[v].size(); ++i) 
    {
        int to = gr[v][i];
        if (!used[to])
            dfs(to);
    }
    beat.push_back(v);
}
  
void Graph :: topsort() 
{
    for (int i = 0; i < nodeCount; ++i)
        used[i] = false;
    beat.clear();
    for (int i = 0; i < nodeCount; ++i)
        if (!used[i])
            dfs(i);
    reverse(beat.begin(), beat.end());
}
  
void Graph :: Hamilton(int n, int e)
{  
    int edgeCount;  
    int primaryNode;
    int secondaryNode;
  
    nodeCount = n;
    edgeCount = e;
  
    vector<int> tmp;
    gr.assign((unsigned long) nodeCount, tmp);
    color.assign((unsigned long) nodeCount, 0);
    used.assign((unsigned long) nodeCount, false);

	for (int i = 0; i < V; ++i)
	{
		primaryNode = i;

		list<int>::iterator it;
		for (it = adj[i].begin(); it != adj[i].end(); ++it)
		{
			secondaryNode = *it;

	        gr[primaryNode].push_back(secondaryNode);			
		}
	}
  
    for (int i = 0; i < nodeCount; ++i)
        if (check_graph(i))
            break;
  
    bool exist = false;
    if (cycle_start == -1) 
    {
        topsort();
        for (int i = 0; i < beat.size() - 1; i++) 
        {
            for (int j = 0; j < gr[beat[i]].size(); j++) 
            {
                if (gr[beat[i]][j] == beat[i+1]) 
                {
                    exist = true;
                    break;
                }
            };
            if (!exist) 
            {
                cout << "not hamiltonian" << endl;
                return;
            };
            exist = false;
        };
  
        cout << "yes, hamiltonian" << endl;
        return;
    } 
    else 
    {
        cout << "not hamiltonian" << endl;
        return;
    }
  
}

//Topological Sort

void Graph::topologicalSortUtil(int v, bool visited[], 
                                stack<int> &Stack)
{
    visited[v] = true;
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    Stack.push(v);
}
 
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    while (Stack.empty() == false)
    {
        cout << Stack.top()+1 << " ";
        Stack.pop();
    }
    cout << endl;
}