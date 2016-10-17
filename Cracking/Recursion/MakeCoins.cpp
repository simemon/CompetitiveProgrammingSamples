#include <iostream>
#include <vector>

using namespace std;

int waysAmountUtil(int amt, vector<int> &denom, int index, vector<vector<int> > &map)
{
  if(map[amt][index] > 0)
    return map[amt][index];
  
  if(index >= denom.size() - 1)
    return 1;
  
  int ways = 0;
  int denomAmount  = denom[index];
  
  for(int i = 0 ; i * denomAmount <= amt; ++i)
  {
    int remain = amt - i * denomAmount;
    ways += waysAmountUtil(remain, denom, index + 1, map);
  }
  map[amt][index] = ways;
  return ways;
  
}


int waysAmount(int amt, vector<int> &denom)
{
 if(amt == 0)
   return 0;
 vector<vector<int> > map(amt + 1, vector<int> (denom.size(), 0)); 
 return waysAmountUtil(amt, denom, 0, map);
}

int main() 
{
  
  int amount = 10;  //user input
  vector<int> denom = {25,10,5,1};
  
  int ways  = waysAmount(amount, denom);
  
  cout << ways << endl;
  
  return 0;
}
