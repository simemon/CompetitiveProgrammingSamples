#include <iostream>
#include <vector>
#include <set>
using namespace std;

int firstFind(vector<int> &num, int i, int j, int n)
{
  int first = -1;
  int mid;
  while(i <= j)
  {
    mid = (i + j) / 2;
    if(num[mid] < n)
      i = mid + 1;
    else
      if(num[mid] == n)
        first = mid;
      j = mid - 1;
  }
  return first;
}

int lastFind(vector<int> &num, int i, int j, int n)
{
  int last = -1;
  int mid;
  while(i <= j)
  {
    mid = (i + j) / 2;
    if(num[mid] > n)
      j = mid - 1;
    else
      if(num[mid] == n)
        last = mid;
      i = mid + 1;
  }
  return last;
}

set<int> findPopular(vector<int> &num)
{
  int n = num.size();
  cout << n << endl;
  int part = ceil(n / 4);
  cout << "part: " << part << endl;
  vector<int> ind = {part , part*2  , part*3  , part*4};
  vector<int> vec;
  set<int> res;
  
  
  for(auto r : ind)
  {
    cout << r  << endl;
  }
  
  for(int i = 0; i < 4; ++i)
  {
    vec.push_back(num[ind[i]]);
  }
  
  for(auto r : vec)
  {
    cout << r  << endl;
  }
  
  for(int i = 0; i < 4; ++i)
  {
    int a = i > 0 ? ind[i-1] : 0;
    int b = i + 1 < n ? ind[i+1]: n - 1;
    
    cout << "a: " << a << ", b: " << b  << ", ind: " << ind[i] << endl;
    
    int first = firstFind(num, a, ind[i], vec[i]);
    int last =  lastFind(num, ind[i], b, vec[i]);
    if(last - first + 1 >= part)
    {
      res.insert(vec[i]);
    }
  }
  return res;
}



int main() 
{
  
  vector<int> num = {0,1,1,1,2,2,2,2,2,2,3,4,4,4,4};
  set<int> res = findPopular(num);
  
  cout << "RESULT " << endl;
  for(auto r : res)
  {
    cout << r  << endl;
  }
  
  
  return 0;
}
