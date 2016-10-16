#include <iostream>
#include <vector>

using namespace std;

void getPermutationsUtil(string perm, string input, vector<string> &result)
{
  if(input.length() == 0)
  {
    result.push_back(perm);
  }
  
  for(unsigned int i = 0 ; i < input.length(); ++i)
  {
    getPermutationsUtil(perm + input[i], input.substr(0,i) + input.substr(i + 1, (input.length() - 1) - i + 1), result);
  }
  
}

vector<string> getPermutations(string input)
{
  vector<string> result;
  getPermutationsUtil("", input, result);
  return result;
}


int main() {
  
  string s = "abc";
  
  vector<string> res = getPermutations("abc");
  
  for(auto r : res)
    cout << r << endl;
  
  return 0;
}
