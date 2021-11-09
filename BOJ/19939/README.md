[19939번: 박 터뜨리기](https://www.acmicpc.net/problem/19939)

## 사고의 흐름

수학의 규칙 찾기 문제는 언제나 어려워하는 것 같다.

일단 바구니에 조건을 만족하며 가장 적게 넣을 수 있는 공의 갯수는 K*(K+1)/2이다. 즉 이 숫자보다 작으면 -1을 출력하면 된다.

이제 가능한 경우를 살펴보면 되는데 여기서는 처음부터 쌓아나가는 방식으로 진행하면 편하다.

처음에 바구니에는 1~K개의 공을 넣어둔다. 그러면 K*(K+1)/2의 공을 사용한 상태이다. 이때 남은 공이 K개 이상이라면 모든 바구니에 공을 한개씩 더 넣어준다. 그러면 남은 공은 K개가 줄고 가장 작은 공의 갯수와 큰 공의 갯수 차이는 여전히 K-1개이다. 

만약 K개보다 작다면 가장 큰 바구니부터 하나씩 넣어주면 된다. 즉 a개의 공이 남았다면 K번째 바구니부터 K-a번째 바구니까지 하나씩 넣어준다. 그러면 모든 공을 바구니에 집어넣게되고 공의 갯수 차이는 K개가 된다.

```cpp
int t, n, m, input1, input2;
int N, K;
void solution() {
	int fir = 1;
	int last = K;
	int num = N - K * (K + 1) / 2;
	while (num >= K)
	{
		fir++;
		last++;
		num -= K;
	}
	if ( num == 0)
	{
		cout << K - 1;
		return;
	}
	cout << K;
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> N >> K;
	if (N < K*(K + 1) / 2)
	{
		cout << -1;
		return 0;
	}

	solution();

	return 0;
}
```
