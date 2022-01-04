[2512번: 예산](https://www.acmicpc.net/problem/2512)

## 사고의 흐름

처음 문제를 접했을 때 수가 1,000,000,000으로 많고 하나씩 해보기에는 수가 너무 많다는 점에서 dp와 완전탐색과 같은 방식은 제외했다. 다른 방식으로 최댓값을 찾는 방법을 생각하다가 이분 탐색을 생각하게되었고 코드를 작성하게 되었다.

자주하는 실수로 if문의 분기를 전부 표시하지 않는다. if x<1 과 if x>1의 경우를 적었으면 if x == 1인 경우를 주석으로라도 적어두는 습관을 들이자.

```cpp
int i, j, k, n, m, t, itemp1, itemp2;
int budget, limit, result;
int max_value = 0;
vector<int> v;
void solution() {
	int i, j, k;
	int left = 1, right = max_value, middle;
	int sum;
	while (left<=right)
	{
		middle = (left + right) / 2;
		sum = 0;

		for ( i = 0; i < n; i++)
		{
			if (v[i] > middle)
			{
				sum += middle;
			}
			else
			{
				sum += v[i];
			}
			if (sum > budget)
			{
				break;
			}
		}

		if (sum > budget)
		{
			right = middle - 1;
		}
		if (sum <= budget)
		{
			result = middle;
			left = middle + 1;
		}
	}
	cout << result;
}

int main() {
	//init
	FastIO;
	//init
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp1;
		if (itemp1 > max_value)
		{
			max_value = itemp1;
		}
		v.push_back(itemp1);
	}
	cin >> budget;
}
```
