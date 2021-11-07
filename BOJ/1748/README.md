[1748번: 수 이어 쓰기 1](https://www.acmicpc.net/problem/1748)

## 사고의 흐름

시간 제한이 0.15초로 짧고 수의 범위는 10^8까지이므로 모든 경우를 하나하나 해보면 시간초과가 난다.

따라서 자릿수가 같은 수들은 더해지는 숫자가 동일하므로 자릿수 별로 값을 묶어서 계산하면 빠르다. arr[i]는 자릿수가 i인 수들의 값의 합이다. 즉 arr[1]은 1에서 9까지 자릿수의 합이므로 9, arr[2]는 10에서 99까지의 합이므로 180..이다.

```cpp
ll t, n, m, input1, input2;
ll arr[11];
int main() {
	//init
	FastIO;
	ll i, j, k;
	cin >> n;
	
	ll value = 9;
	for ( i = 1; i <= 9; i++)
	{
		arr[i] = value * i;
		value *= 10;
	}

	ll comp = 10;
	ll cnt;
	for (i = 1; i <= 9; i++)
	{
		if (n < comp)
		{
			cnt = i;
			break;
		}
		comp *= 10;
	}

	ll result = 0;
	for (i = 1; i < cnt; i++)
	{
		result += arr[i];
	}

	comp /= 10;
	comp--;
	result += (n - comp)*cnt;

	cout << result;

	return 0;
}
```
