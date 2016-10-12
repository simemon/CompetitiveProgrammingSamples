#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
  public:
  int src;
  int dest;
  int weight;
  
  Edge()
  {
  }
  
  Edge(int s, int d, int w)
  {
    src = s;
    dest = d;
    weight = w;
  }
  friend class Graph;
};

struct subset
{
  int rank;
  int parent;
};

class Graph
{
  int v;
  int e;
  vector<Edge> edges;
  Edge edge;
  vector<subset> mysubset;
  
  public:
    
  Graph(int lv, int le)
  {
    v = lv;
    e = le;
    edges = vector<Edge>(e);
    
    /*
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 10;

    // add edges 0-2
    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 6;

    // add edges 0-3
    edges[2].src = 0;
    edges[2].dest = 3;
    edges[2].weight = 5;

    // add edges 1-3
    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 15;

    // add edges 2-3
    edges[4].src = 2;
    edges[4].dest = 3;
    edges[4].weight = 4;
    */
    
    for(int i = 0; i < e; ++i)
    {
      cin >> edge.src;
      cin >> edge.dest;
      cin >> edge.weight;
      edges.push_back(edge);
    }
   
    for(int i = 0; i < e; ++i)
    {
      subset temp;
      temp.parent = i;
      temp.rank = 0;
      mysubset.push_back(temp);
    }
  
  }

  void print()
  {
    for(int i = 0; i < e; ++i)
    {
      cout << edges[i].src << " " << edges[i].dest << " " << edges[i].weight << endl;
    }
  }
  
  int find(int i)
  {
    if(mysubset[i].parent != i)
      mysubset[i].parent = find(mysubset[i].parent);
    return mysubset[i].parent;
  }
  
  void Union(int x, int y)
  {
    int xroot = find(x);
    int yroot = find(y);
    
    if(mysubset[xroot].rank < mysubset[yroot].rank)
      mysubset[xroot].parent = mysubset[yroot].parent;
    else if(mysubset[xroot].rank > mysubset[yroot].rank)
      mysubset[yroot].parent = mysubset[xroot].parent;
    else
    {
      mysubset[yroot].parent = mysubset[xroot].parent;
      mysubset[xroot].rank += 1;
    }   
  }
  
  static int comparator(Edge e1, Edge e2)
  {
    return e1.weight < e2.weight;
  }
  
  void Kruskal()
  {
    sort(edges.begin(), edges.end(), comparator);
    
   
    vector<Edge> result;
    
    int i = 0;
    int edge_ind = 0;
    while(i < v - 1)
    {
      Edge next_edge = edges.at(edge_ind++);
      int x = find(next_edge.src);
      int y = find(next_edge.dest);
      
      if(x != y)
      {
        result.push_back(next_edge);
        Union(x, y);
        i++;
      }
    }
    
    for(auto r : result)
    {
      cout << r.src << " - " << r.dest << " : " << r.weight << endl;
    }
  }
  
  
};

int main() 
{
  int V = 4;
  int E = 5;
  
  Graph g (V, E);
  
  g.Kruskal();
  
  
  
  return 0;
}
