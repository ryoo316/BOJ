#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
const unsigned long long lim = 1111111111111111111;
unsigned long long minVal = UINT64_MAX;
unsigned long long n;
int flag = 1;
unsigned long long min(unsigned long long a,unsigned long long b)
{
  if(a < b)
      return a;
  else  return b;
}
void solution(unsigned long long start)
{
  if(flag == 0)
    return;
  //start가 n으로 나눠진다면 0과 1로만 이루어진 배수이다.
  if(start % n ==0){
    minVal = start;
    flag = 0;
  }
    

  if(start > lim / 10)         //넘어가면 리턴
    return;

  solution(start*10+1);        //오른쪽에 1 붙이기
  solution(start*10);          //오른쪽에 0 붙이기

}
int main()
{
  while(1){
    scanf("%llu",&n);
    flag = 1;
    if(n == 0)//n이 0이면 입력의 끝이므로 break해준다.
      break;
    solution(1);//1부터 시작
    printf("%llu\n",minVal);
    minVal = UINT64_MAX;//minVal은 초기화 시켜준다.
  }
  return 0;
}
