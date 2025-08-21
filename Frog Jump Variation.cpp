#include <bits/stdc++.h>
using namespace std;
/*
There are N stones, numbered 1, 2, ..., N. For each i (1 ≤ i ≤ N),
the height of Stone i is hᵢ. There is a frog who is initially on Stone 1. 
He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, he can jump to one of the following: 
Stone i+1, i+2, ..., i+K. Here, a cost of |hᵢ − hⱼ| is incurred, 
where j is the stone to land on.

Goal: Find the minimum possible total cost incurred before the frog reaches Stone N.
INPUT : 
4
40 10 20 70 80 10 20 70 80 60
OUTPUT EXPLANATION: 
If we follow the path 1 → 4 → 8 → 10, 
the total cost incurred would be |40−70|+|70−70|+|70−60| = 40.
*/
int n = 0;
vector<int> dp;
int solve(vector<int>& arr, int i, int k) {
  // base case
  if(i >= n - 1) return 0;
  if(dp[i] != -1) return dp[i];
  
  // setting the optimal variable value.
  int minimumRequired = INT_MAX;
  for(int j = 1; j <= k && i + j < n; j++) {
    minimumRequired = min(
                            abs(arr[i] - arr[i + j]) + solve(arr, i + j, k),
                            minimumRequired
                         );
  }
  return dp[i] = minimumRequired;
}
int main() 
{
  int hopRadius;
  cin >> hopRadius;
  int num;
  vector<int> arr;
  while(cin >> num) {
    arr.push_back(num);
  }
  n = arr.size();
  dp.assign(n, -1);
  cout << solve(arr, 0, hopRadius) << endl;
  return 0;
}
