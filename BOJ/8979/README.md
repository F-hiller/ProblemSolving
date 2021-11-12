[8979번: 올림픽](https://www.acmicpc.net/problem/8979)

## 사고의 흐름

순위를 매기는 방식은 간단하다. 자신보다 잘한 사람의 수 만큼 자신의 등수를 늘려주면 된다.

즉 잘한사람이 4명 있으면 5등, 6명 있으면 7등이 된다.

비기는 경우는 공동으로 같은 등수가 되므로 상관없다.

```cpp
typedef struct nation{
	int num, gold, silver, bronze;
};

int t, n, m, input1, input2;
nation arr[1001];
nation ntemp;
bool isLose(int i) {
	nation comp = arr[i];
	if (comp.gold > ntemp.gold)
	{
		return 1;
	}
	if (comp.gold < ntemp.gold)
	{
		return 0;
	}
	if (comp.silver > ntemp.silver)
	{
		return 1;
	}
	if (comp.silver < ntemp.silver)
	{
		return 0;
	}
	if (comp.bronze > ntemp.bronze)
	{
		return 1;
	}
	if (comp.bronze < ntemp.bronze)
	{
		return 0;
	}
	return 0;
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> k;
	for ( i = 0; i < n; i++)
	{
		cin >> ntemp.num >> ntemp.gold >> ntemp.silver >> ntemp.bronze;
		arr[ntemp.num] = ntemp;
	}
	int result = 1;
	ntemp = arr[k];
	for ( i = 1; i <= n; i++)
	{
		if (i == k)
		{
			continue;
		}
		if (isLose(i))
		{
			result++;
		}
	}
	cout << result;
	return 0;
}
```
