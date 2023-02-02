# <img width="20px"  src="https://d2gd6pc034wcta.cloudfront.net/tier/12.svg" class="solvedac-tier"> [Mooyo Mooyo](https://www.acmicpc.net/problem/16768) 

| 제출 번호 | 닉네임 | 채점 결과 | 메모리 | 시간 | 언어 | 코드 길이 |
|---|---|---|---|---|---|---|
|55150302| ryoo316|맞았습니다!! 맞았습니다!!|2028KB|0ms|C++17|3842B|

## 문제
<p>With plenty of free time on their hands (or rather, hooves), the cows on Farmer John's farm often pass the time by playing video games. One of their favorites is based on a popular human video game called Puyo Puyo; the cow version is of course called Mooyo Mooyo.</p>

<p>The game of Mooyo Mooyo is played on a tall narrow grid $N$ cells tall ($1 \leq N \leq 100$) and 10 cells wide. Here is an example with $N = 6$:</p>

<pre>0000000000
0000000300
0054000300
1054502230
2211122220
1111111223
</pre>

<p>Each cell is either empty (indicated by a 0), or a haybale in one of nine different colors (indicated by characters 1..9). Gravity causes haybales to fall downward, so there is never a 0 cell below a haybale.</p>

<p>Two cells belong to the same connected region if they are directly adjacent either horizontally or vertically, and they have the same nonzero color. Any time a connected region exists with at least $K$ cells, its haybales all disappear, turning into zeros. If multiple such connected regions exist at the same time, they all disappear simultaneously. Afterwards, gravity might cause haybales to fall downward to fill some of the resulting cells that became zeros. In the resulting configuration, there may again be connected regions of size at least $K$ cells. If so, they also disappear (simultaneously, if there are multiple such regions), then gravity pulls the remaining cells downward, and the process repeats until no connected regions of size at least $K$ exist.</p>

<p>Given the state of a Mooyo Mooyo board, please output a final picture of the board after these operations have occurred.</p>

## 입력
<p>The first line of input contains $N$ and $K$ ($1 \leq K \leq 10N$). The remaining $N$ lines specify the initial state of the board.</p>

## 출력
Please output $N$ lines, describing a picture of the final board state.

