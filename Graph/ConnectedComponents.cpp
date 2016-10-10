#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph
{
  int v;
  list<int> *adjlist;
  
  void dfsUtil(int s, vector<bool> &visited)
  {
    visited[s] = true;
    cout << s << " ";
    for(auto n: adjlist[s])
    {
      if(visited[n] == false)
      {
        dfsUtil(n, visited);
      }
    }
  }
  
  public:
  Graph(int v)
  {
    this -> v = v;
    adjlist = new list<int>[v];
  }
  
  void addEdge(int x, int y)
  {
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
  }
  
  void connectedComponents()
  {
    vector<bool> visited(v, false);
    
    for(int i = 0;i < v; ++i)
    {
      if(visited[i] == false)
      {
           dfsUtil(i, visited);
           cout << endl;
      }
    }
  } 
  
};



// Driver Code
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(5, 4);
 
    cout << "Connected Componenets " << endl;
    g.connectedComponents();

  
    return 0;
}