#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int main()
{
	int op1,op2;	
	cout<<"\nOptions> 1.User defined graph 2.Random graph \nEnter> ";
	cin>>op1;
	cout<<"\nOptions> 1.Undirected 2.Directed 3.Undirected & Weighted 4.Directed & Weighted \nEnter> ";
	cin>>op2;
	cout<<endl;

	if(op1==1)
	{
		if(op2==1 || op2==2)
		{
			int n,e;
			cout<<"number of nodes> ";
			cin>>n;
			cout<<"number of edges> ";
			cin>>e;
			cout<<"edges: \n";

			Graph g(n);			
			
			int e1=e;
			while(e1--)
			{	
				int u,v;
				cin>>u>>v;
				
				if(u>n || v>n)
				{
					cout<<"Invalid Edge, Try Again \n";
					e++;
					continue;
				}
				
				u=u-1;
				v=v-1;
				
				if(op2==1)
					g.addEdgeU(u, v);
				else if(op2==2)
					g.addEdgeD(u, v);
			}

			cout<<"\n(printgraph)\n";
			g.printGraph();
			cout<<"\n(strongly connected components)\n";
			g.SCC();
			cout<<"\n(euler)\n";
			g.Euler(n,e);			
			cout<<"\n(hamilton)\n";
			g.Hamilton(n,e);		
			cout<<"\n(topological sort)\n";
			g.topologicalSort();		
		}
		
		if(op2==3 || op2==4)
		{
			int n,e;
			cout<<"number of nodes> ";
			cin>>n;
			cout<<"number of edges> ";
			cin>>e;
			cout<<"edges and weight: \n";

			WGraph g(n);
			int e1=e;
			while(e1--)
			{	
				int u,v,w;
				cin>>u>>v>>w;

				if(u>n || v>n)
				{
					cout<<"Invalid Edge, Try Again \n";
					e++;
					continue;
				}

				u=u-1;
				v=v-1;
				
				if(op2 == 3)
					g.addEdgeU(u, v, w);
				else if(op2 == 4)
					g.addEdgeD(u, v, w);
			}

			cout<<"\n(printgraph)\n";
			g.printGraph();
			cout<<"\n(Dijkstra)\n";
		    cout<<"Enter source vertex : ";
		    int src;
		    cin>>src;
		    cout<<endl;
			g.Dijkstra(src-1);
		}		
	}
	
	else if(op1==2)
	{
		int n,e;
		cout<<"number of nodes> ";
		cin>>n;

		e = n*(n-1)/2;
		srand(time(NULL));
		e = rand()%e +1;
			
		if(op2==1 || op2==2)
		{
			Graph g(n);
			for(int i=0; i<e; i++)
			{
				int u,v;
				u = rand()%n;
				v = rand()%n;
				
				if(op2==1)
					g.addEdgeU(u, v);
				else if(op2==2)
					g.addEdgeD(u, v);
			}

			cout<<"\n(printgraph)\n";
			g.printGraph();							
		}
		
		if(op2==3 || op2==4)
		{
			WGraph g(n);
			for(int i=0; i<e; i++)
			{
				int u,v,w;
				u = rand()%n;
				v = rand()%n;
				w = rand()%1000;

				if(op2 == 3)
					g.addEdgeU(u, v, w);
				else if(op2 == 4)
					g.addEdgeD(u, v, w);								
			}

			cout<<"\n(printgraph)\n";
			g.printGraph();	
		}
	}
    
return 0;
} 