#include <iostream>
#include <unordered_set>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

int countDigit(int num)
{
  int count = 0;
  while(num != 0)
  {
    num /= 10;
    count++;
  }
  return count;
}

string numToStr(int num)
{
  ostringstream oss;
  oss << num;
  return oss.str();
}

void strCompress(string &orig)
{
  int i = 0;
  int total = 0;
  int count = 0;
  while(i < orig.length())
  {
    count++;
    if(i + 1 >= orig.length() or  orig[i] != orig[i+1])
    {
      total += countDigit(count) + 1;
      count = 0;
    }
    i++;
  }
  if(total >= orig.length())
    return;
  
  i = 1;
  int j = 0;
  count = 1;
  char last = orig[0];
  while(i < orig.length())
  {
    if(orig[i] == last)
       count++;
    else 
    {
      orig[j++] = last;
      for(auto s:  numToStr(count))   
        orig[j++] = s;
      last = orig[i];
      count = 1;
    }
    i++;
  }
  orig[j++] = last;
  for(auto s:  numToStr(count))   
        orig[j++] = s;
  orig.erase(orig.begin() + j, orig.end());
}



int main() 
{
  string s = "aaavvvssaab";
  strCompress(s);
  cout << s << endl;
  return 0;
}
