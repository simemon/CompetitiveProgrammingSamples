#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void sum(vector<int> &v, int num)
{
  reverse(v.begin(), v.end());
  int carry = 0;
  v[0] += num;
  for(int i = 0; i < v.size(); ++i)
  {
    v[i] += carry;
    if(v[i] >= 10)
    {
      v[i] -= 10;
      carry = 1;
    }
    else
    {
      carry = 0;
      break;
    }
  }
  if(carry)
    v.push_back(carry);
  
  reverse(v.begin(), v.end());
}


int main()
{
  vector<int> v = {9,9,9};
  int n = 5;
  sum(v,n);
  
  for(auto ele : v)
    cout << ele << " ";
  cout << endl;
  
  return 0;
}