#include <iostream>
#include <vector>
#include<algorithm>

#define mypair pair<int,int>

using namespace std;

bool comparator(mypair p1, mypair p2)
{
  return p1.first < p2.first;
}

bool isOverlap(mypair p1, mypair p2)
{
  return p1.second > p2.first;
}

vector<mypair> merge(vector<mypair> &v1, vector<mypair> &v2)
{
  vector<mypair> result;
  for(auto ele : v1)
    result.push_back(ele);
  
  for(auto ele : v2)
    result.push_back(ele);
  
  sort(result.begin(), result.end(), comparator);
  
  mypair prev = result[0];
  int k = 0;
  
  for(unsigned int i = 1; i < result.size(); ++i)
  {
    if(isOverlap(prev, result[i]))
    {
      mypair temp;
      temp.first = prev.first;
      temp.second = max(prev.second, result[i].second);
      prev = temp;
    }
    else
    {
      mypair temp = prev;
      prev = result[i];
      result[k++] = temp;
    }
  }
  result[k++] = prev;
  result.erase(result.begin() + k, result.end());
  
  return result;
}

int main()
{
  vector<mypair> v1 = {mypair(3,11),mypair(17,25),mypair(58,73)};
  vector<mypair> v2 = {mypair(6,18),mypair(40,47)};
  vector<mypair> result;

  result = merge(v1,v2);
  
  for(auto ele : result)
    cout << ele.first << ":" << ele.second << endl;
  
  return 0;
}