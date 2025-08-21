#include <bits/stdc++.h>
using namespace std;
/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it.
The vacation lasts for N days. On each day i (1 ≤ i ≤ N), 
Taro must choose one of the following three activities:
A: Swim in the sea — gains a₁, a₂, ..., aₙ points of happiness (for each day i).
B: Catch bugs in the mountains — gains b₁, b₂, ..., bₙ points of happiness.
C: Do homework at home — gains c₁, c₂, ..., cₙ points of happiness.
However, since Taro gets bored easily, he cannot do the same activity on two consecutive days.
Your task is to determine the maximum total happiness Taro can achieve over the N days,
following the above constraint.
INPUT:
3
10 40 70
20 50 80
30 60 90

OUTPUT : 210
If Taro does activities in the order C, B, C, 
he will gain 70 + 50 + 90 = 210 points of happiness.
*/
vector<vector<int>> dp;
int n = 0;
int solve(vector<vector<int>>& query, int row, int prevCol) {
  if(row >= n) return 0;
  if(dp[row][prevCol + 1] != -1) {
    return dp[row][prevCol + 1];
  }
  
  int maxValue = 0;
  for(int col = 0; col < 3; col++) {
    if(col != prevCol){
      int temp = query[row][col] + solve(query, row + 1, col);
      maxValue = max(maxValue, temp);
    }      
  }
  
  return dp[row][prevCol + 1] = maxValue;
}
int main() 
{
    cin >> n;
    vector<vector<int>> query(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++) {
        int temp;
        cin >> temp;
        query[i][j] = temp;
      }
    }
    dp.assign(n, vector<int>(4, -1));
    int ans = solve(query, 0, -1);
    cout << ans << endl;
    return 0;
}
