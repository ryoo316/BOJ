#include<iostream>
#include<stack>
using namespace std;

int main(){
  //스택은 오름차순으로
  stack<int> a;
  int n;
  int ans[1000001] = {};
  int arr[1000001] = {};
  cin >> n;
  if(n == 1){
    cout << -1;
    return 0;
  }
  for(int i=1;i<=n;i++)
    cin >> arr[i];
  for(int i=n;i>=1;i--){
    //스택이 비어있지않고 스택 top이 지금 값보다 작다면
    while(!a.empty() && a.top() <= arr[i]){
      //스택 top이 지금 값보다 작을 때까지 pop한다.
      a.pop();
    }
    //스택 값이 비어있으면 지금 값보다 큰 값이 없다는 것이니 ans = -1
    if(a.empty())
      ans[i] = -1;
    //비어 있지않으면 ans = a.top(지금 값보다 큰 값(오큰수))
    else
      ans[i] = a.top();
    //스택에 값 넣어주기
    a.push(arr[i]);
  }
  ans[n] = -1;
  for(int i=1;i<=n;i++){
    cout << ans[i] << ' ';
  }
  return 0;
}