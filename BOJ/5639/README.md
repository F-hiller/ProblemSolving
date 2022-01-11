[5639번: 이진 검색 트리](https://www.acmicpc.net/problem/5639)

## 사고의 흐름

재귀를 사용하여 이진 트리의 전위 표기를 후위 표기로 바꾸어 출력하는 문제이다.

first와 last를 통해 L부분 R부분 V부분을 구분짓고 재귀함수를 호출하는 방식을 사용하였다.

주의해야 할 점은 오른쪽 자식 트리가 없는 경우이다. solution함수의 마지막 부분을 해당 경우로 구분지어서 진행하였다.

```cpp
int n, m, itemp1, itemp2, itemp3;
vector<int> v;

void solution(int first, int last) {
	//cout << "first and last : " << first << " " << last << endl;
	int i, j, k;
	if (first >= last)
	{
		if (first == last)
		{
			cout << v[first] << endl;
		}
		return;
	}
	for (i = first + 1; i <= last; i++)
	{
		if (v[i] > v[first])
		{
			solution(first + 1, i - 1);
			solution(i, last);
			cout << v[first] << endl;
			return;
		}
	}
	solution(first + 1, last);
	cout << v[first] << endl;
}

int main() {
	//init
	FastIO;
	int i, j, k;

	//input
	init();

	solution(1, v.size() - 1);

	return 0;
}
void init() {
	int i, j, k;
	v.push_back(-1);
	if (DEBUG)
	{
		cin >> n;
		while (n)
		{
			v.push_back(n);
			cin >> n;
		}
		return;
	}
	while (cin >> n) {
		v.push_back(n);
	}
}
```
