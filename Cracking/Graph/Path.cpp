#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
  int v;
  list<int> *adjlist;
  
  bool dfsUtil(int s, vector<bool> &visited, int target)
  {
    cout << s << endl;
    
    if( s == target)
      return true;
    
    visited[s] = true;
    bool ret = false;
    
    for(auto n: adjlist[s])
    {
      if(visited[n] == false)
      {
        ret = dfsUtil(n, visited, target);
        if(ret)
          break;
      }
    }
    return ret;
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
  }
  
  bool isPath(int s, int t)
  {
    vector<bool> visited(v, false);
    return dfsUtil(s, visited, t);
  } 
  
};

// Driver Code
int main()
{
    Graph g(6);
    g.addEdge(0, 5);
    g.addEdge(5, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
 
    cout << "Path: " << g.isPath(0,4) << endl;

  
    return 0;
}