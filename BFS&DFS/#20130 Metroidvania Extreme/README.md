# <img width="20px"  src="https://d2gd6pc034wcta.cloudfront.net/tier/15.svg" class="solvedac-tier"> [Metroidvania Extreme](https://www.acmicpc.net/problem/20130) 

| 제출 번호 | 닉네임 | 채점 결과 | 메모리 | 시간 | 언어 | 코드 길이 |
|---|---|---|---|---|---|---|
|56174205| ryoo316|맞았습니다!! 맞았습니다!!|3024KB|4ms|C++17|2709B|

## 문제
<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d3bd96c0-dc9e-48aa-b6f5-c997b0d5ba1d/-/preview/" style="height: 600px; width: 588px;"></p>

<p style="text-align: center;">[그림] 슈퍼 메트로이드(1994) 지도</p>

<p>메트로베니아는 액션 게임의 하위 장르로, 메트로이드 + 캐슬배니아가 어원으로 이전에도 던전 탐색이 위주인 게임은 있었으나 그 기틀이 제대로 잡히고 대중의 인식에 각인된 것이 메트로이드와 악마성 시리즈이기에 이렇게 불린다. 메트로이드가 장르를 창시하였고, 캐슬배니아가 월하의 야상곡부터 메트로이드의 스타일을 이어받아 장르를 확립시켰기 때문이다. 게임 플레이에서는 평소에는 통과할 수 없던 지역과 샛길 등을 주인공의 성장과 능력 획득을 통해 그 탐색 활동의 저변을 확장하는 데에서 독특한 재미를 얻을 수 있도록 하는 데에, 게임 개발 측의 입장에서는 한정된 용량과 배경을 몇 배로 효율적으로 활용하면서 그러한 방식의 디자인을 설득력 있고 지루하지 않게 구조화하는 데에 의의가 있다.</p>

<p>국렬이는 메트로베니아를 정말로 좋아하기 때문에 택희 선배의 RPG Extreme의 후속작으로 Metroidvania Extreme을 제작하려고 한다. 다만 걱정할 것 없다. 전작이 너무 어려웠던 나머지 국렬이는 난도를 어마어마하게 낮추었다.</p>

<p>지도는 <em>N</em> × <em>M</em>으로 구성되어 있으며 각 문자는 다음을 의미한다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>#</code></span> : 지나갈 수 없는 벽</li>
	<li><span style="color:#e74c3c;"><code>@</code></span> : 시작점</li>
	<li><span style="color:#e74c3c;"><code>*</code></span> : 아무 것도 없는 곳</li>
	<li><span style="color:#e74c3c;"><code>!</code></span> : 최종 목표 지점</li>
	<li><span style="color:#e74c3c;"><code>a-z</code></span> : 열쇠 아이템으로 해당 아이템이 있어야만 특정 구역에 진입할 수 있다. 해당 아이템을 획득할 시에 해당 알파벳의 대문자로 표기된 곳으로 이동할 수 있다.</li>
	<li><span style="color:#e74c3c;"><code>A-Z</code></span> : 자물쇠가 있는 지역이다. 해당 알파벳의 소문자로 표기된 열쇠 아이템을 얻어야 갈 수 있다.</li>
</ul>

<p>Metroidvania Extreme의 규칙은 다음과 같다.</p>

<ul>
	<li>주인공은 상하좌우로 인접한 곳으로 이동할 수 있다.</li>
	<li>주인공이 이전에 지나갔던 곳들은 순간이동을 통해서 바로 이동할 수 있다.</li>
	<li>벽이 있는 곳은 그 어떠한 경우에도 이동할 수 없다.</li>
	<li>맵 가장자리는 무조건 벽이다. 즉, 맵 밖으로 나갈 수 없다.</li>
	<li>최종 목표 지점에 도착하는 순간 지금까지 얻은 아이템의 개수와 전혀 상관없이 게임을 마무리 짓는다.</li>
	<li>아이템은 영구 아이템으로 절대로 소비하지 않는다. 즉, <span style="color:#e74c3c;"><code>a</code></span>라는 아이템을 1개만 획득하면 영구적으로 <span style="color:#e74c3c;"><code>A</code></span> 지역으로 이동할 수 있다.</li>
	<li>출발 지점과 목표 지점은 정확히 1개 있으며, 출발 지점에서 시작해 목표 지점까지 이동할 수 있음이 보장된다.</li>
</ul>

<p>맵의 맨 왼쪽 위 칸을 (1,1), 오른쪽 아래 칸을 (<em>N</em>,<em>M</em>)으로 나타냈으며 판의 <em>x</em>번째 행, <em>y</em>번째 열에 위치한 곳을 (<em>x</em>,<em>y</em>)로 지칭한다.</p>

<p>Metroidvania Extreme을 시작했을 때, 끝날 때 까지 이동한 장소의 좌표를 순서대로 기록을 할 것이다. 단, 이전에 방문한 장소를 다시 방문했을 때는 다시 기록하지 않는다. 최종 목표 지점에 도달한 시점에서 최종 목표 지점의 좌표를 기록하고 마무리를 짓는다.</p>

<p>당신은 게임을 시작하려고 한다. 게임이 끝날 때 기록된 좌표들을 출력하여라. 답이 여러 개라면 아무 것이나 출력하여라.</p>

## 입력
<p>다음과 같이 입력이 주어진다.</p>

<div style="background:#eeeeee;border:1px solid #cccccc;padding:5px 10px;"><em>N</em> <em>M</em><br>
<em>a<sub>1,1</sub></em> . . . <em>a<sub>1,M</sub></em><br>
. . . . . .<br>
<em>a<sub>N,1</sub></em> . . . <em>a<sub>N,M</sub></em></div>

## 출력
<p>첫 번째 줄에는 지금까지 기록한 좌표의 수 <i>k</i>을 출력한다. 이후 <em>k</em>개의 줄에 걸쳐 기록한 순서대로 방문한 칸의 행 번호와 열 번호를 공백으로 구분하여 출력한다.</p>

