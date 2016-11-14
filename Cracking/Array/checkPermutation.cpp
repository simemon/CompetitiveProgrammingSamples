#include <iostream>
#include <unordered_map>
using namespace std;

bool isPermute(string &s, string &t)
{
  unordered_map<char,int> charMap;
  for(auto c: s)
    charMap[c] += 1;
  for(auto c: t)
  {
    if(charMap.count(c) == 0)
      return false;
    charMap[c]--;
    if(charMap[c] == 0) charMap.erase(c);
  }
  return charMap.empty();
}


int main() 
{
  string s = "sirajm";
  string t = "jasri";
  
  cout << isPermute(s,t) << endl;
  
  return 0;
}
