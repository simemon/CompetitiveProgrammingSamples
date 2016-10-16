#include <iostream>

using namespace std;


int MinProductUtil(int a, int b)  {
    if(a == 0)
        return 0;
    else if(a == 1)  return b;
  
    int s = a >> 1;
    int side1 = MinProductUtil(s, b);
  
    if(a % 2 == 0)
      return side1 + side1;
    else
      return side1 + side1 + b;
  
}

int MinProduct(int a, int b)  {
  return MinProductUtil(min(a,b),max(a,b));
}

int main() {
  
  int a = 10;
  int b = 5;
  
  
  
  int result = MinProduct(a,b);
  
  cout << result << endl;
  
  
  return 0;
}
