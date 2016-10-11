#include <iostream>
#include <unordered_map>

using namespace std;

/*
Find a substring which has atmost k unique characters
*/

int lengthSubString(string &s, int k)
{
  int max_len = k;
  int len = k;
  int i = 0;
  int j = k;
  
  unordered_map<int,int> mymap;
  
  for(int i = 0; i < k; ++i)
  {
    auto ret = mymap.insert(pair<int,int>(s[i], 1));
    if(ret.second == false)
    {
      ret.first -> second += 1;
    }
  }
  
  while(j < s.length())
  {
    auto ret = mymap.insert(pair<int,int>(s[j],1));
    
    
    if(ret.second == false)  //that value is already present
    {
      ret.first -> second += 1;
      len += 1;
    }
    else  //if not found
    {
      if(mymap.size() <= k)
      {
        len += 1;
      }
      else  //increment i part
      {
        if(len > max_len)
          max_len = len;
        while(mymap.size() > k)
        {
          mymap[s[i]] -= 1;
          if(mymap[s[i]] == 0)
          {
            mymap.erase(s[i]);
          }
          i++;
        }
        len = j - i + 1;
      }
    }
    j++;
  }
  return max_len;
}

//driver code
int main() 
{
  
  string s = "ababbcdcacdcefg";
  int k = 3;
  int len = lengthSubString(s, k);
  cout << "Length: " << len << endl;
  
  return 0;
}
