#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Matrix
{
  int row;
  int col;
  unordered_map<int, unordered_map<int,int> > mat;
  public:
    Matrix(int r, int c)
    {
      row = r;
      col = c;
    }
    void set(int r, int c, int w)
    {
      if(r < 0 or r > row - 1 or c < 0 or c > col - 1)
        return;
      
      unordered_map<int,int> temp;
      temp.insert(pair<int,int>(c, w));
      auto it  = mat.find(r);
      if(it == mat.end())
      {
        mat.insert(pair<int,unordered_map<int,int> >(r, temp));
      }
      else
      {
        (it -> second).insert(pair<int,int>(c, w));
      }
    }
  
    int sum(int r, int c)
    {
      int total = 0;
      if(r >= row or c >= col or r < 0 or c < 0)
      {
        return 0;
      }
      for(auto rind : mat)
      {
       if(rind.first < r)
        {
          for(auto cind : rind.second)
          {
             if(cind.first < c)
             {
               cout << rind.first << " " << cind.first << " " << cind.second << endl;
               total += cind.second;
             }
            
          }
        }
      }
      return total;
    }
};

int main()
{
  int r = 10;
  int c = 8;
  Matrix m(r,c);
  
  vector<int> rvec = {2,3,0,6,4,2,2,2,4,7};
  vector<int> cvec = {3,1,4,2,1,5,6,7,0,8};
  vector<int> weight = {3,1,4,2,1,5,5,7,0,8};
  
  for(int i =0; i < 10; ++i)
  {
    m.set(rvec[i], cvec[i], weight[i]);
  }
  
  cout << "Total: " << m.sum(5,6) << endl;
  
  return 0;
}