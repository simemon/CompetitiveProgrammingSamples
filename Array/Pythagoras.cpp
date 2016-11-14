#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int temp;
        for(int i=0; i < n; ++i)
        {
            cin >> temp;
            v.push_back(pow(temp,2));
        }
        
        sort(v.begin(),v.end());
        bool flag = false;
        
        for(int i = v.size() - 1; i >=2; i--)
        {
            int j = 0;
            int k = i - 1;
            while(j < k)
            {
                if(v[i] == v[j] + v[k])
                {
                    flag = true;
                    goto label;
                }
                if(v[i] > v[j] + v[k])
                    j++;
                else
                    k--;
            }
        }
        label:
        flag ? cout << "Yes" : cout << "No";
        cout << endl;
    }
	return 0;
}