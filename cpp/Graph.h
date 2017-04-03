#include <bits/stdc++.h>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
  int V;    
  list<int> *adj;
  int parent[100];

  void fillOrder(int v, bool visited[], stack<int> &Stack); 
  void DFS(int v, bool visited[]);  

public:
 
  Graph(int V);
  ~Graph();
 
  void addEdgeU(int u, int v);
  void addEdgeD(int u, int v);

  void printGraph();
  
  void SCC();
  Graph getTranspose();  

  void BFS(int n,int src);
  void find_path(int start,int end,int par[]);  
};

class WGraph
{
  int V;    
  vector<pair<int, int> > *adj;
  
public:

  WGraph(int V);
  ~WGraph();
  
  void addEdgeU(int u, int v, int w);
  void addEdgeD(int u, int v, int w);

  void printGraph();

};
#endif