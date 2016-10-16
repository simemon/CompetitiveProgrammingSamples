#include <iostream>

using namespace std;

int main() {
  string s = "abc";
  int len = 1 << s.size();
  
  for(int i=0; i < len; ++i)  {
    int index = 0;
    for(int k = i; k != 0; k >>= 1)  {
      if((k & 1) == 1)
        cout << s[index];
      index++;
    }
    cout << endl;
  }
  return 0;
}
