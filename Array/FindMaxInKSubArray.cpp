#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> findKMaximum(vector<int> &input, int k)
{
  vector<int> output;
  int n = input.size();
  
  if(k > n)
  {
    return output;
  }
  deque<int> q;
  
  for(int i=0;i<k;++i)
  {
    while(!q.empty() and input[i] >= input[q.back()] )
      q.pop_back();
    q.push_back(i);
  }
  
  for(int i = k; i < n; ++i)
  {
    output.push_back(input[q.front()]);
    while(!q.empty() and input[i] >= input[q.back()] )
      q.pop_back();
    
    while(!q.empty() and q.front() <= i - k)
      q.pop_front();
    
    q.push_back(i);
  }
  
  
  return output;
}

int main()
{
  vector<int> input = {11, 3, 7, -2, 1, 0};
  int k = 3;
  vector<int> output = findKMaximum(input,k);
  
  
  
  for(auto o: output)
    cout << o << endl;
  
  return 0;
}