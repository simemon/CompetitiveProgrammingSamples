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
  
  void DFS(int s)
  {
    vector<bool> visited(v, false);
    
    dfsUtil(s, visited);
    
    for(int i = 0;i < v; ++i)
    {
      if(visited[i] == false)
      {
           dfsUtil(i, visited);
      }
    }
    cout << endl;
  } 
  
  void BFSUtil(int s, vector<bool> &visited)
  {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty())
    {
      int current = q.front();
      
      q.pop();
      cout << current << " ";
      
      for(auto n : adjlist[current])
      {
        if(visited[n] == false)
        {
          visited[n] = true;
          q.push(n);
        }
      }
      
    }
  }
               
  
  void BFS(int s)
  {
    vector<bool> visited(v, false);
    BFSUtil(s, visited);
    
    for(int i = 0;i < v; ++i)
    {
      if(visited[i] == false)
      {
           BFSUtil(i, visited);
      }
    }
    
    cout << endl;
    
  }
  
};



// Driver Code
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(0, 4);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
  
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
  
    return 0;
}