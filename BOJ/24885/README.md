[24885번: 주식](https://www.acmicpc.net/problem/24885)

## 사고의 흐름

/*
1. 매수
2. 매도
3. 매도 -> 매수
4. 아무것도 안하기
*/

4가지 경우에 맞춰 재귀로 해결하였다.

```cpp
//additional variables
ll p[11];
ll stock_temp, loan_temp, money_temp;

ll sol(ll day, ll stock, ll loan, ll money) {
	if (day == n - 1)
	{
		return stock * p[day] + money;
	}
	ll max_val = money;
	//1
	if (loan == 0)
	{
		stock_temp = stock + (money * (K + 1)) / p[day];
		if (stock_temp) {
			loan_temp = money * K;
			money_temp = (money * (K + 1)) % p[day];
			max_val = max(max_val, sol(day + 1, stock_temp, loan_temp, money_temp));
		}
	}
	else
	{
		if (money >= loan)
		{
			stock_temp = stock + ((money - loan) * (K + 1)) / p[day];
			if (stock_temp) {
				loan_temp = (money - loan) * K;
				money_temp = ((money - loan) * (K + 1)) % p[day];
				max_val = max(max_val, sol(day + 1, stock_temp, loan_temp, money_temp));
			}
		}
	}
	//2
	stock_temp = 0;
	loan_temp = loan;
	money_temp = money + stock * p[day];
	max_val = max(max_val, sol(day + 1, stock_temp, loan_temp, money_temp));
	//3
	if (loan == 0)
	{
		stock_temp = ((money + stock * p[day]) * (K + 1)) / p[day];
		if (stock_temp) {
			loan_temp = (money + stock * p[day]) * K;
			money_temp = ((money + stock * p[day]) * (K + 1)) % p[day];
			max_val = max(max_val, sol(day + 1, stock_temp, loan_temp, money_temp));
		}
	}
	else
	{
		if ((money + stock * p[day]) >= loan)
		{
			stock_temp = (((money + stock * p[day]) - loan) * (K + 1)) / p[day];
			if (stock_temp) {
				loan_temp = ((money + stock * p[day]) - loan) * K;
				money_temp = (((money + stock * p[day]) - loan) * (K + 1)) % p[day];
				max_val = max(max_val, sol(day + 1, stock_temp, loan_temp, money_temp));
			}
		}
	}
	//4
	max_val = max(max_val, sol(day + 1, stock, loan, money));

	return max_val;
}

//main function
int main() {
	//init
	FastIO;
	ll i, j, k;

	//solution
	cin >> n >> m >> K;
	for (i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	cout << sol(0, 0, 0, m);

	return 0;
}
```
