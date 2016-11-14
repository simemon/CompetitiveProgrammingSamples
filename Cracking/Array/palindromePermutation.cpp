#include <iostream>
#include <unordered_set>
using namespace std;

bool permutePalind(string &s)
{
  unordered_set<char> charSet;
  for(auto c: s)
  {
    if(isspace(c))
      continue;
    char ch = tolower(c);
    if(charSet.count(ch) > 0)
      charSet.erase(ch);
    else
      charSet.insert(ch);
  }
  return charSet.size() <= 1;
}

int main() 
{
  string s = "Taco    ecato";
  cout << permutePalind(s) << endl;
  
  return 0;
}
