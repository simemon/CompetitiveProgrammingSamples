#include <iostream>
#define BITS 8
using namespace std;

/*
Reverse first four digits, keep remaining as it is!
*/
int main() 
{
  unsigned short n = 15125; 
  //0011101100010101
  //1101110000010101
  
  unsigned short result = 0;
  
  unsigned short orig = n;
  n >>= BITS;
  
  for(int i = 0; i < BITS; ++i)
  {
    result = (result << 1) + ((n >> i) & 1);
  }
  
  result <<= BITS; 
  result |=  (orig & ((1 << BITS)- 1));
  
  cout << result << endl;
  
  return 0;
}
