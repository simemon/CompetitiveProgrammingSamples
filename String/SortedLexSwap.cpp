/*
  Find Lexicographically largest string, if array of pairs given which are allowed to sort
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

string SortedLexSwap(string str, vector<pair<int,int> > &pairs)
{
  queue<pair<int,int> > q;
  string result = str;
  for(auto p : pairs)
  {
    q.push(p);
  }
  while(!q.empty())
  {
    set<int> s;
    pair<int,int> current;
    int l = q.size();
    while(l--)
    {
      current = q.front();
      q.pop();
      if(s.size() == 0 or s.find(current.first) != s.end() or s.find(current.second) != s.end())
      {
        s.insert(current.first);
        s.insert(current.second);
        l = q.size();
        continue;
      }
      q.push(current);
    }
    vector<char> c;
    for(auto entry : s)
    {
      c.push_back(result[entry-1]);
    }
    
    sort(c.begin(), c.end(), greater<char>());
    int i = 0;
    
    for(auto entry : s)
    {
      result[entry - 1] = c[i++];
    }
  }
  return result;
}

int main() 
{
  string str = "abdc";
  vector<pair<int,int> > pairs;
  pairs.push_back(pair<int,int> (1,4));
  pairs.push_back(pair<int,int> (3,4));
  
  string result = SortedLexSwap(str, pairs);
  
  cout << result << endl;
  return 0;
}
