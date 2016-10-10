#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
  int v;
  list<int>* adjlist;
  public:
    Graph(int x)
    {
      v = x;
      adjlist = new list<int>[v];
    }
  
    bool isEdge(int u, int v)
    {
      for(auto x : adjlist[u])
        if(x == v)
          return true;
      
      return false;
    }
    
    void addEdge(int u, int v)
    {
      adjlist[u].push_back(v);
      adjlist[v].push_back(u);
    }
    
    bool isCyclicUtil(int x, vector<bool> &visited, int parent)
    {
      visited[x] = true;
      for(auto n : adjlist[x])
      {
        if(visited[n] == true and n != parent)
        {
          return true;
        }
        else if(visited[n] == false)
        {
          return isCyclicUtil(n, visited, x);
        }
      }
      return false;
    }
  
    bool isCyclic()
    {
      vector<bool> visited(v,false);
      for(int i =0 ; i<v;++i)
      {
        if(visited[i] == false)
        {
          if(isCyclicUtil(i, visited, i) == true)
            return true;
        }
      }
      return false;
    }  
  
};

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}
