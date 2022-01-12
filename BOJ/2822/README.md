[2822번: 점수 계산](https://www.acmicpc.net/problem/2822)

## 사고의 흐름

정렬해서 상위 가장 높은 점수를 받은 5문제의 점수 합과 문제 번호를 출력하는 문제이다.

입력받은 순서(문제 번호)와 점수 두가지 데이터를 바탕으로 정답을 내면 된다.

vector<pair>에 넣고 sort()를 이용해서 끝에서 5문제의 점수 합과 문제 번호를 출력해도 되지만 priority queue를 사용해봤다.

```cpp
int n, m, t, itemp1, itemp2;
vector<int> v;
int result = 0;

struct pred {
	bool operator()(pii a, pii b) {
		return a.first < b.first;
	}
};
priority_queue<pii, vector<pii>, pred> pq;

void solution() {
	int i, j, k;
	for ( i = 0; i < 5; i++)
	{
		pii top = pq.top();
		pq.pop();
		result += top.first;
		v.push_back(top.second);
	}
	sort(v.begin(), v.end());
	cout << result << endl;
	for ( i = 0; i < 5; i++)
	{
		cout << v[i] << " ";
	}
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	for ( i = 0; i < 8; i++)
	{
		cin >> itemp1;
		pq.push(pii(itemp1, i + 1));
	}
}
```
