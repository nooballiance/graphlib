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
  
  void Euler(int n, int e);
  
  void Hamilton(int n, int e);
  bool check_graph(int v);
  void dfs(int v);
  void topsort();
  int nodeCount, cycle_start = -1;  
  vector<vector<int>> gr;
  vector<bool> used;
  vector<int> beat;  
  vector<int> color;

  void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
  void topologicalSort();
  
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
  
  void Dijkstra(int s);

};
#endif