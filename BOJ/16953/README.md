[16953번: A → B](https://www.acmicpc.net/problem/16953)

## 사고의 흐름

bfs문제이다. 

1. 배열을 이용한 방법은 인덱스가 10^9을 넘어가기에 불가능하다.
2. 이용하는 값이 최대 10^10까지 나올 수 있기에 int를 쓰면 오류가 나므로 long long을 사용해준다.

```cpp
int t, n, m, input1, input2;
ll a, b;

void solution(ll value, ll result) {
	if (value > 1000000000)
	{
		return;
	}
	if (value == b)
	{
		cout << result + 1;
		exit(0);
	}
	solution(2 * value, result + 1);
	solution(10 * value + 1, result + 1);
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> a >> b;
	solution(a, 0);
	cout << -1;
	return 0;
}
```
