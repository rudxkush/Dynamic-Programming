#include <bits/stdc++.h>
using namespace std;
/*
There are N stones, numbered 1,2,…,N. For each i : ( 1 ≤ i ≤ N), 
the height of Stone i is h_i. There is a frog who is initially on Stone 1.
He will repeat the following action some number of times to reach Stone N: 
If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. 
Here, a cost of |h_i - h_j| is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.
INPUT :
4
10 30 40 20
OUTPUT : 
30
*/
vector<int> dp;
int minimumCost(vector<int>& arr, int i) {
  // base case
  if(i <= 0) return 0;
  // if already computed !
  if(dp[i] != -1) return dp[i];
  
  // chooses to jump one block in an array.
  int jumpOnce = abs(arr[i] - arr[i - 1]) + minimumCost(arr, i - 1);
  
  // chooses to jump two blocks in an array.
  int jumpTwice = abs(arr[i] - arr[i - 1]) + minimumCost(arr, i - 2);
  
  // return for every sub problem its minimum cost incurred and finally for the required.
  return dp[i] = min(jumpOnce, jumpTwice);
}
int main() 
{
  int num;
  vector<int> arr;
  while (cin >> num) {
      arr.push_back(num);
  }
  int n = arr.size();
  dp.assign(n, -1);
  cout << "The minimum possible total cost incurred before the frog reaches Stone N: " << endl;
  cout << minimumCost(arr, n - 1) << endl;
  return 0;
}
