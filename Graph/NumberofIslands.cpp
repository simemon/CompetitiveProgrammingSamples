#include <iostream>
#include <vector>

using namespace std;

class Graph
{
  int n,m;
  vector<vector<int> > matrix;
  
  void dfsUtil(vector<vector<bool> > &visited, int r, int c)
  {
    if((r >= 0) and (r < n) and (c >= 0) and (c < m) and (matrix[r][c] == 1) and (visited[r][c] == false))
    {
      visited[r][c] = true;
      dfsUtil(visited, r-1, c);
      dfsUtil(visited, r+1, c);
      dfsUtil(visited, r-1, c-1);
      dfsUtil(visited, r, c-1);
      dfsUtil(visited, r+1, c-1);
      dfsUtil(visited, r-1, c+1);
      dfsUtil(visited, r, c+1);
      dfsUtil(visited, r+1, c+1);
      
    }
  }
  
  public:
  Graph(int n, int m)
  {
    for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
      {
        cin >> matrix[i][j];
      }
    }
    this -> n = n;
    this -> m = m;
    
     /*
     matrix = 
     {
      {1, 1, 0, 0, 0},
      {0, 1, 0, 0, 1},
      {1, 0, 0, 1, 1},
      {0, 0, 0, 0, 0},
      {1, 0, 1, 0, 1}
     };
     */
    
  }
  
  int NumberOfIslands()
  {
    vector<vector<bool> > visited(n, vector<bool> (m, false));
    int count  = 0;
    
    for(int i =0 ; i < n; ++i)
    {
      for(int j = 0; j < m; ++j)
      {
        if(matrix[i][j] == 1 and visited[i][j] == false)
        {
          dfsUtil(visited, i, j);
          count++;
        }
      }
    }
    return count;     
  }
  
};



// Driver Code
int main()
{
    Graph g(5,5);
 
    cout << "Number of Componenets " << g.NumberOfIslands() << endl;

  
    return 0;
}