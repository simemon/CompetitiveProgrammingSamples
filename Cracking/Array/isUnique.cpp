#include <iostream>
#include <unordered_map>
using namespace std;

bool isUniqueAlpha(const string &s)
{
  int checker = 0;
  for(auto c: s)
  {
    short val = c - 'a';
    if(checker & (1 << val))
      return false;
    checker |= (1 << val);
  }
  return true;
}


bool uniqueString(const string &s)
{
  unordered_map<char,int> charMap;
  for(auto c: s)
  {
    if(charMap.count(c) > 0)
      return false;
    charMap[c] = 1;
  }
  return true;
}

int main() 
{
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << uniqueString(word) << endl;
  }
  
  cout << "ONLY LOWERCASE ALPHABETS" << endl;
  
  auto words2 = {"siraj", "memon"};
  for(const string& word: words2)
  {
    cout << isUniqueAlpha(word) << endl;
  }
  
  return 0;
}
