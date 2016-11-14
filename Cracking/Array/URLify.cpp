#include <iostream>
#include <unordered_map>
using namespace std;

void urlify(string &s, int len)
{
  int space_count = 0;
  for(int i = 0; i < len; ++i)
  {
    if(isspace(s[i]))
       space_count += 1;
  }
       
  int j = len + space_count * 2 - 1;
       
  for(int i = len - 1; i >= 0; --i)
  {
      if(isspace(s[i]))
      {
        s[j--] = '0';
        s[j--] = '2';
        s[j--] = '%';
      }
      else
        s[j--] = s[i];
  }
}


int main() 
{
  string s = "siraj memon  ";
  urlify(s, 11);
    
  cout << s << endl;
  
  return 0;
}
