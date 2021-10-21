[10972번: 다음 순열](https://www.acmicpc.net/problem/10972)

## 사고의 흐름

간단한 내용이지만 처음 생각해보는 내용이라서 알아두면 좋을 것 같아서 적게 되었다.

순열이 있을 때 다음에 올 순열을 정하는 방식은 다음과 같다.

1. 순열의 수들 중 가장 마지막 내림차순과 그 앞의 수 x를 찾는다.

ex) 12354가 주어진다면 54가 마지막 내림차순이고 3이 x이다. 1342라면 42가 마지막 내림차순이고 3이 x이다.

1. 내림차순 중 x보다 바로 위 큰 수를 찾아서 x와 교체한다.

ex) 5 4 중 3보다 바로 위 큰 수는 4이다. 4 2 중 3보다 바로 위 큰 수는 4이다. 124~, 14~가된다.

1. x를 포함하여 내림차순에 남은 수들을 오름차순으로 정렬하여 다음 수열을 완성한다.

ex) 3과 내림차순에 남은 수 5를 오름차순 정렬하여 12435가 된다. 3과 남은 수 2를 정렬하여 1423이 된다.

12354 → 123 / 54 → 12 **3** / 5**4** → 12 4 / 5 3 → 124 / 35 → 12435

1342 → 13 / 42 → 1 **3** / **4**2 → 1 4 / 3 2 → 14 / 23 → 1423

```cpp
int t, n, m, input1, input2;
ll sum = 0;
int arr[10000];

void solution() {
	int i, j, k;
	int pre, cur;
	cur = arr[n - 1];
	for ( i = n - 2; i > -1; i--)
	{
		pre = cur;
		cur = arr[i];
		if (cur < pre)
		{
			for ( j = 0; j < i; j++)
			{
				cout << arr[j] << " ";
			}
			vector<int> v;
			for ( j = i + 1; j < n; j++)
			{
				v.push_back(arr[j]);
			}
			sort(v.begin(), v.end());
			for ( j = 0; j < v.size(); j++)
			{
				if (v[j] > cur)
				{
					cout << v[j] << " ";
					v[j] = cur;
					break;
				}
			}
			for (j = 0; j < v.size(); j++)
			{
				cout << v[j] << " ";
			}
			return;
		}
	}
	cout << -1;
}

int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	solution();

	return 0;
}
```
