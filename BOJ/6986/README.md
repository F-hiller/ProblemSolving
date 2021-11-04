[6986번: 절사평균](https://www.acmicpc.net/problem/6986)

## 사고의 흐름

실수에 대해 제대로 알고 있는지 묻는 문제이다. 나는 제대로 몰랐고 틀렸다.

이 문제는 실수의 반올림을 제대로 해주어야하는데 실수는 1.3이라고 입력하여도 실제 값이 1.3으로 저장되지 않을 수 있다. 1.29999999999999처럼 근사에 가까운 값이 저장될 수 있다. 따라서 이를 확인하고 보정해주는 함수가 halfup 함수이다.

halfup을 사용하지 않는 경우에 다음과 같은 일이 벌어질 수 있다. 만약 실제 값이 1.235가 나왔지만 계산한 값이 1.23499999999가 나온다면 %.2lf는 1.23으로 출력한다. 따라서 halfup함수는 이를 제대로 반올림해주는 역할을 한다.

```cpp
int t, n, m, input1, input2;
int N, K;
double dtemp, sum;
vector<double> v;
double halfup(double value) {
	int itemp = (double)100 * value;
	if (((double)100 * value - (double)itemp) * (double)10 >= 5)
	{
		return (double)(itemp + 1) / (double)100;
	}
	return value;
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> dtemp;
		v.push_back(dtemp);
	}

	sort(v.begin(), v.end());
	sum = 0;

	for (i = K; i < N - K; i++)
	{
		sum += v[i];
	}

	//절사 평균
	double result1 = sum / (N - 2 * K);

	double fir = v[K];
	double sec = v[N - K - 1];
	sum += (fir + sec)*K;

	//보정 평균
	double result2 = sum /= N;

	result1 = halfup(result1);
	result2 = halfup(result2);

	printf("%.2lf\n%.2lf", result1, result2);

	return 0;
}
```
