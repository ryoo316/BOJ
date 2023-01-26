# <img width="20px"  src="https://d2gd6pc034wcta.cloudfront.net/tier/12.svg" class="solvedac-tier"> [오큰수](https://www.acmicpc.net/problem/17298) 

| 제출 번호 | 닉네임 | 채점 결과 | 메모리 | 시간 | 언어 | 코드 길이 |
|---|---|---|---|---|---|---|
|54745491| ryoo316|맞았습니다!! 맞았습니다!!|12256KB|620ms|C++17|895B|

## 문제
<p>크기가 N인 수열 A = A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 있다. 수열의 각 원소 A<sub>i</sub>에 대해서 오큰수 NGE(i)를 구하려고 한다. A<sub>i</sub>의 오큰수는 오른쪽에 있으면서 A<sub>i</sub>보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.</p>

<p>예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.</p>

## 입력
<p>첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에 수열 A의 원소 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub> (1 ≤ A<sub>i</sub> ≤ 1,000,000)이 주어진다.</p>

## 출력
<p>총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.</p>

