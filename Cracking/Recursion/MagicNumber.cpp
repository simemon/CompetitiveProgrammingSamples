#include <iostream>
#include <vector>

using namespace std;



int magicFastUtil(vector<int> &v, int l ,int h)  {
  if(h < l)
    return -1;
  int mid = l + (h - l)/2;
  if(v[mid] == mid)
    return mid;
  
  int leftIndex = min(mid - 1, v[mid]);
  int left = magicFastUtil(v, l, leftIndex);
  if(left >= 0)
    return left;
  
  int rightIndex = max(mid + 1, v[mid]);
  int right =  magicFastUtil(v, rightIndex, h);
    return right; 
  
  return -1;
}

int magicFast(vector<int> &v)  {
  return magicFastUtil(v, 0, v.size() - 1);
}

int main() {
  
  vector<int> v = {-10,-5,2,2,2,3,4,7,9,12,13};
  
  cout << magicFast(v) << endl;
  
  
  
  return 0;
}
