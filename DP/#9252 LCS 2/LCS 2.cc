#include<iostream>
#include<algorithm>
#include<cstring>
#define Max 1001
using namespace std;

int dp[Max][Max] = {};

int main(){
  char seq1[Max] = {}, seq2[Max] = {};
  char res[Max] = {};
  cin >> seq1 >> seq2;
  
  int len1 = strlen(seq1);
  int len2 = strlen(seq2);
  
  for(int i=1;i<=len1;i++){
    for(int j=1;j<=len2;j++){
      if(seq1[i-1] == seq2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  // for(int i=0;i<=len1;i++){
  //   for(int j=0;j<=len2;j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  cout << dp[len1][len2] << "\n";
  int i = len1, j = len2, k = 0;
  while(i > 0 && j > 0){
    if(dp[i][j] == 0)
      break;
    if(dp[i][j] == dp[i-1][j])
      i--;
    else if(dp[i][j] == dp[i][j-1])
      j--;
    else{
      res[k++] = seq1[i-1];
      i--;
      j--;
    }
  }
  
  for(int i=k-1;i>=0;i--)
    cout << res[i];
  return 0;
}