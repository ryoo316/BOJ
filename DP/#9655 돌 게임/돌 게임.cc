#include<iostream>
#define Max 1001
using namespace std;
bool memo[Max];
int dp(int n){
  if(memo[n]) return memo[n];
  if(n == 1) return true;
  if(n == 2) return false;
  if(n > 2) return memo[n] = dp(n-2);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if(dp(n))
    cout << "SK";
  else
    cout << "CY";
  return 0;
}