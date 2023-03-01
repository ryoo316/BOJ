#include<iostream>
#include<algorithm>
#define Max 100000
using namespace std;

int min_dp[3] = {};
int max_dp[3] = {};
int Matrix[3] = {};
int temp[3] = {};

int n, ans_min, ans_max;
bool flag = 0;

void Solution(int i){
  if(flag){
    max_dp[0] = Matrix[0];
    max_dp[1] = Matrix[1];
    max_dp[2] = Matrix[2];
    min_dp[0] = Matrix[0];
    min_dp[1] = Matrix[1];
    min_dp[2] = Matrix[2];
    flag = 1;
    return;
  }
  temp[0] = max(max_dp[0], max_dp[1]) + Matrix[0];
  temp[1] = max(max_dp[0], max(max_dp[1], max_dp[2])) + Matrix[1];
  temp[2] = max(max_dp[1], max_dp[2]) + Matrix[2];

  max_dp[0] = temp[0];
  max_dp[1] = temp[1];
  max_dp[2] = temp[2];
  
  temp[0] = min(min_dp[0], min_dp[1]) + Matrix[0];
  temp[1] = min(min_dp[0], min(min_dp[1], min_dp[2])) + Matrix[1];
  temp[2] = min(min_dp[1], min_dp[2]) + Matrix[2];

  min_dp[0] = temp[0];
  min_dp[1] = temp[1];
  min_dp[2] = temp[2];
}

void Input(){
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
      cin >> Matrix[j];
    }
    Solution(i);
  }
}

void Solve(){
  Input();
  ans_max = max(max_dp[0], max(max_dp[1], max_dp[2]));
  ans_min = min(min_dp[0], min(min_dp[1], min_dp[2]));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solve();

  cout << ans_max << " " << ans_min;
  return 0;
}