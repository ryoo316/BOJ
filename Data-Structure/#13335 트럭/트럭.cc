#include<iostream>
#include<deque>
#define Max 1001
using namespace std;

int n, W, L;
int arr[Max] = {};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> W >> L;

  for(int i=1;i<=n;i++)
    cin >> arr[i];

  deque<int> d;
  for(int i=0;i<W;i++)
    d.push_front(0);//다리의 길이만큼 큐에 빈 공간 넣어주기

  //시간, 인덱스, 덱의 합
  int t = 0, i = 1, sum_d = 0;

  //모든 트럭이 지나갈 때까지 반복한다.
  while(!d.empty()){
    t++;//시간이 지난다.
    
    sum_d -= d.front();  //덱의 합 갱신
    d.pop_front();       //다리 앞에부터 하나씩 줄이기

    //트럭이 남아있다면
    if(n > 0){
      //다리의 합과 지금 트럭의 합이 다리의 최대하중보다 낮다면
      if(arr[i] + sum_d > L)
        d.push_back(0);//뒤에 빈공간 추가
      //아니면
      else{
        d.push_back({arr[i]});//트럭을 덱에 push해준다.
        sum_d += arr[i];      //덱의 합 갱신
        i++;                  //인덱스 + 1
        n--;                  //트럭의 수 - 1
      }
    }
  }
  //답(시간) 출력
  cout << t;
  return 0;
}