#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph
{
  int v;
  vector<list<int> > adjlist;
  unordered_map <string, int> map1;
  unordered_map <int, string> map2;
  
  void dfsUtil(int s, vector<bool> &visited)
  {
    visited[s] = true;
    cout << getText(s) << " ";
    for(auto n: adjlist[s])
    {
      if(visited[n] == false)
      {
        dfsUtil(n, visited);
      }
    }
  }
  
  public:
  Graph()
  {
    v = 0;
  }

  string getText(int c)
  {
    return map2[c];
  }
  
  int getNumber(string text)
  {
    if(map1.count(text) > 0)
    {
      return map1[text];
    }
    else
    {
        map1[text] = v;
        map2[v] = text;
        v++;
        return v - 1;
    }
  }
  
  void addEdge(string x, string y)
  {
    int u = getNumber(x);
    int v = getNumber(y);
    
    if((int) adjlist.size() == u)
    {
      list<int> temp;
      temp.push_back(v);
      adjlist.push_back(temp);
    }
    else
    {
      adjlist[u].push_back(v);
    }
    
    if((int) adjlist.size() == v)
    {
      list<int> temp;
      adjlist.push_back(temp);
    }  
  }

  void DFS(string s)
  {
    vector<bool> visited(v, false);
    
    dfsUtil(getNumber(s), visited);
    
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
      cout << getText(current) << " ";
      
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
               
  
  void BFS(string s)
  {
    vector<bool> visited(v, false);
    BFSUtil(getNumber(s), visited);
    
    for(int i = 0;i < v; ++i)
    {
      if(visited[i] == false)
      {
           BFSUtil(i, visited);
      }
    }
    
    cout << endl;
    
  }
  
  int findVertex()
  {
    for(int i=0; i<v;++i)
    {
      if(adjlist[i].size() == 0)
        return i;
    }
    return -1;
  }
  
  void topological()
  {
    vector<int> indegree(v, 0);
    for(int i = 0; i < v; ++i)
    {
      for(auto n: adjlist[i])
      {
        indegree[n] += 1;
      }
    }
    
    queue<int> q;
    
    for(unsigned int i =0; i < indegree.size(); ++i)
    {
      if(indegree[i] == 0)
      {
        q.push(i);
      }
    }
    
    vector<int> order;
    
    while(!q.empty())
    {
      int current = q.front(); q.pop();
      order.push_back(current);
      
      for(auto n: adjlist[current])
      {
        indegree[n] -= 1;
        if(indegree[n] == 0)
          q.push(n);
      }
    }
    
    if((int) order.size() != v)
    {
      cout << "Not possible" << endl;
      return ;
    }
    
    for(auto element: order)
    {
      cout << getText(element) << " " << endl;
    }
  }
  
};

int main()
{
    Graph g;
    g.addEdge("b", "a");
    g.addEdge("c", "a");
    g.addEdge("d", "a");
    g.addEdge("e","c");
    g.addEdge("f", "d");
    g.addEdge("f", "e");
    g.addEdge("g", "h");
  
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS("g");
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS("g");
  
  	cout << "Topological Sort: " << endl;
    g.topological();
    return 0;
}