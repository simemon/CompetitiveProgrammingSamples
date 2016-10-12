#include <iostream>
#include <vector>
using namespace std;

void print(string s, vector<string> &res, unsigned int index)
{
  if(s.length() == index)
  {
    res.push_back(s);
    return;
  }
  if(s[index] == '?')
  {
    s[index] = '0';
    print(s, res, index + 1);
    
    s[index] = '1';
    print(s, res, index + 1);
  }
  else
  {
    print(s, res, index + 1);
  }
}


int main() 
{
  //string s = "1?00?101";
  string s = "???";
  vector<string> res;
  print(s, res, 0);
  for(auto r : res)
    cout << r << endl;
  
  return 0;
}
