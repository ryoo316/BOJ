#include<iostream>
#define MOD 1000000
using namespace std;

//피사노 주기를 이용해 n번째 피보나치 수를 구한다.
//주기의 길이를 P라고 하면 N번째 피보나치를 MOD로 나눈 나머지는
//N%P번째 피보나치 수를 MOD로 나눈 나머지와 같다.
int p = (MOD/10)*15;//주기의 길이
long long n;
int dp[1500001] = {0,1};

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=2;i<p;i++){
    dp[i] = (dp[i-1] + dp[i-2])%MOD;
  }
  cout << dp[n%p];
  return 0;
}