#include <iostream>
using namespace std;

/*
Reverse first four digits, keep remaining as it is!
*/
int main() 
{
  char n = 166; 
  char result = 0;
  char orig = n;

  n >>= 4;
  
  for(int i = 0; i < 4; ++i)
  {
    result = (result << 1) + ((n >> i) & 1);
  }
  
  result <<= 4;
  orig <<= 4;
  orig >>= 4;
  
  cout << (result | orig) << endl;
  
  return 0;
}
