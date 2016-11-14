#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

bool isOneEditAway(string &s, string t)
{
  if(abs(s.length() - t. length()) > 1)
    return false;
  int i = 0;
  int j = 0;
  bool flagEdit = false;
  
  while(i < s.length() and j < t.length())
  {
    if(s[i] == t[j])
    {
      i++; j++; continue;
    }
    if(flagEdit)
      return false;
    if(s.length() > t.length())
      i++;
    else if(s.length() < t.length())
      j++;
    else
    {
      i++; j++;
    }
    flagEdit = true;
  }
  return true;
}

int main() 
{
  string s[] = {"pale", "pales", "pale", "pale"};
  string t[] = {"ple", "pale", "bale", "bake"};
  
  for(int i=0;i < 4; ++i)
    cout << isOneEditAway(s[i], t[i]) << endl;
  return 0;
}
