#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() 
{
  priority_queue<int, vector<int>, greater<int> > q;
  vector<int> v = {12,3,4,8,10,7};
  int k = 10;
  int i;
  int n = v.size();
  
  for(i = 0; i < k; ++i)
  {
    q.push(v[i]);
  }
  
  for(; i < n; ++i)
  {
    if(v[i] > q.top())
    {
      q.pop();
      q.push(v[i]);
    }
  }
  
  cout << q.top() << endl;
  
  return 0;
}
