#include <iostream>
#include <vector>

using namespace std;

void Addparens(vector<string> &res, int lparen, int rparen, string &str, int count)
{
  if(lparen < 0 || rparen < lparen)
    return;
  if(lparen == 0 and rparen == 0)
    res.push_back(str);
  else
  {
      str[count] = '(';
      Addparens(res, lparen - 1, rparen, str, count + 1);

      str[count] = ')';
      Addparens(res, lparen, rparen - 1, str, count + 1);
  }
}

vector<string> generateParens(int count)
{
  string str(count * 2, '*');
  vector<string> res;
  Addparens(res, count, count, str, 0); 
  
  cout << res.size() << endl;
  
  return res;
}


int main() 
{
  
  int count = 3;  //user input
  
  vector<string> res = generateParens(count);
  
  for(auto r : res)
    cout << r << endl;
  
  return 0;
}
