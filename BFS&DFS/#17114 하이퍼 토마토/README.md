# <img width="20px"  src="https://d2gd6pc034wcta.cloudfront.net/tier/15.svg" class="solvedac-tier"> [하이퍼 토마토](https://www.acmicpc.net/problem/17114) 

| 제출 번호 | 닉네임 | 채점 결과 | 메모리 | 시간 | 언어 | 코드 길이 |
|---|---|---|---|---|---|---|
|60055513| ryoo316|맞았습니다!! 맞았습니다!!|166132KB|596ms|C++17|B|

## 문제
<p>시프트의 토마토 농장은 아래 그림과 같이 토마토를 보관하는 큰 11차원 창고를 가지고 있다. 창고는 <em>m </em>×<em> n </em>×<em> o </em>×<em> p </em>×<em> q </em>×<em> r </em>×<em> s </em>×<em> t </em>×<em> u </em>×<em> v </em>×<em> w</em> 의 격자 모양이고, 각 칸에 토마토를 하나씩 보관할 수 있다.</p>

<p> </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ca30bf59-2a40-4eff-909f-532bc9df8840/-/preview/"></p>

<p> </p>

<p>창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토에 인접한 곳은 $\begin{bmatrix} \pm 1 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0\\ \pm 1 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ \pm 1 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ \pm 1 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ 0 \\ \pm 1 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ \pm 1 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ \pm 1 \\ 0 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ \pm 1 \\ 0 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ \pm 1 \\ 0 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ \pm 1 \\ 0 \end{bmatrix}$, $\begin{bmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ \pm 1 \end{bmatrix}$의 스물 두 방향에 인접해 있는 토마토를 의미한다. 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 시프트는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.</p>

<p><em>m</em>,<em> n</em>,<em> o</em>,<em> p</em>,<em> q</em>,<em> r</em>,<em> s</em>,<em> t</em>,<em> u</em>,<em> v</em>,<em> w</em> 와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 창고의 일부 칸에는 토마토가 들어있지 않을 수도 있다.</p>

## 입력
<p>첫 줄에는 문제의 설명에서 창고의 크기를 나타내는 자연수 <em>m</em>,<em> n</em>,<em> o</em>,<em> p</em>,<em> q</em>,<em> r</em>,<em> s</em>,<em> t</em>,<em> u</em>,<em> v</em>,<em> w</em>가 주어진다. 단, 1 ≤ <em>mnopqrstuvw</em> ≤ 10<sup>6</sup> 이다.</p>

<p>둘째 줄부터는 창고에 저장된 토마토들의 정보가 주어진다. 창고 안의 격자 공간을 (1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)부터 (<em>m</em>,<em> n</em>,<em> o</em>,<em> p</em>,<em> q</em>,<em> r</em>,<em> s</em>,<em> t</em>,<em> u</em>,<em> v</em>,<em> w</em>)까지의 좌표로 나타낸다고 하면,</p>

<ul>
	<li>둘째 줄에는 (1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)부터 (<em>m</em>, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)까지에 들어 있는 토마토 <em>m</em>개의 정보가 주어지고,</li>
	<li>이러한 줄이 <em>n</em>번 반복되어  (1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)부터 (<em>m</em>, <em>n</em>, 1, 1, 1, 1, 1, 1, 1, 1, 1)까지에 들어 있는 토마토 <em>mn</em>개의 정보가 주어지고,</li>
	<li>이러한 <em>n</em>개의 줄이 <em>o</em>번 반복되어 (<em>m</em>, <em>n</em>, <em>o</em>, 1, 1, 1, 1, 1, 1, 1, 1)까지에 들어 있는 토마토 <em>mno</em>개의 정보가 주어지고,</li>
	<li>이러한 <em>no</em>개의 줄이 <em>p</em>번 반복되어 (<em>m</em>, <em>n</em>, <em>o</em>, <em>p</em>, 1, 1, 1, 1, 1, 1, 1)까지에 들어 있는 토마토 <em>mnop</em>개의 정보가 주어지고,</li>
	<li>⋯ 이와 같은 방법으로 <em>nopqrstuvw</em>개의 줄에 걸쳐 (<em>m</em>,<em> n</em>,<em> o</em>,<em> p</em>,<em> q</em>,<em> r</em>,<em> s</em>,<em> t</em>,<em> u</em>,<em> v</em>,<em> w</em>)까지에 들어 있는 토마토 <em>mnopqrstuvw</em>개의 정보가 모두 주어진다.</li>
</ul>

<p>정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.</p>

## 출력
<p>토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해 출력한다. 만약 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.</p>

