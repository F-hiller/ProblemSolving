[10815번: 숫자 카드](https://www.acmicpc.net/problem/10815)

## 사고의 흐름

50만개의 숫자들 중에서 어떤 숫자 하나가 있는지 찾아보려면 모든 경우를 비교할 때 50만번이 걸린다. 이러한 탐색을 50만번 한다면 2초안에 해결하지 못하므로 주어진 50만개의 숫자들을 정렬하고 이분 탐색으로 하나씩 찾아나가는 것이 빠르다.

```cpp
int t, n, m, input1, input2;
vector<int> v;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> input1;
		v.push_back(input1);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for ( i = 0; i < m; i++)
	{
		cin >> input1;
		cout << binary_search(v.begin(), v.end(), input1) << " ";
	}
	return 0;
}
```
