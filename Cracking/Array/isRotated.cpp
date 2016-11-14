#include <iostream>

using namespace std;

bool isRotated(string s, string &t)
{
  if(s.length() == 0 and s.length() == t.length())
    return true;
  if(s.length() != t.length())
    return false;
  
  s += s;
  return (s.find(t) != string::npos);
  
}

int main() 
{
  string s = "waterbottle";
  string t = "ttlewaterbo";
  
  cout << isRotated(s,t) << endl;
  
  return 0;
}
