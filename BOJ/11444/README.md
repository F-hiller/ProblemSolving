[11444번: 피보나치 수 6](https://www.acmicpc.net/problem/11444)

## 사고의 흐름

행렬을 사용하여 푸는 방식은 모든 풀이법을 통틀어 처음이라서 생소했다. 익혀둬서 나중에 사용할 수 있도록 하자. 

피보나치 수는 아래와 같은 방식으로 점화식을 표현할 수 있다고 한다. 

그에 따라 Fn을 {{1, 1}, {1, 0}}의 n승으로 구할 수 있게 되는데 

n승은 2로 나눠가면서 계산 횟수를 줄일 수 있다.

예를 들어 n이 17이라면

17 = 1 + 16

16 = 8*2

8 = 4*2

4 = 2*2

2 = 1*2 

1 = 1으로 5번의 계산으로 17에 도달할 수 있다.

$$
\left( {Fn+2\atop Fn+1}\right) = \left( {1\atop 1} {1\atop 0} \right)\left( {Fn+1\atop Fn}\right)
$$

$$\left( {Fn+1\atop Fn} {Fn\atop Fn-1} \right) = \left( {1\atop 1} {1\atop 0} \right)^n$$

```cpp
int t, n, m, input1, input2;
ll input;
vector<vector<long long>> arr = { {1, 1}, {1, 0} };
vector<vector<long long>> base = { {1, 0}, {0, 1} };
void comple(vector<vector<long long>>& a) {
	vector<vector<long long>> c(2, vector<long long>(2));
	c[0][0] = ((a[0][0] * arr[0][0]) % MAX_VALUE + (a[0][1] * arr[1][0]) % MAX_VALUE) % MAX_VALUE;
	c[0][1] = ((a[0][0] * arr[0][1]) % MAX_VALUE + (a[0][1] * arr[1][1]) % MAX_VALUE) % MAX_VALUE;
	c[1][0] = ((a[1][0] * arr[0][0]) % MAX_VALUE + (a[1][1] * arr[1][0]) % MAX_VALUE) % MAX_VALUE;
	c[1][1] = ((a[1][0] * arr[0][1]) % MAX_VALUE + (a[1][1] * arr[1][1]) % MAX_VALUE) % MAX_VALUE;
	a = c;
}
int main() {
	//init
	FastIO;
	cin >> input;
	while (input)
	{
		if (input % 2){comple(base);}
		comple(arr);
		input /= 2;
	}
	cout << base[0][1] << '\n';
	return 0;
}
```
