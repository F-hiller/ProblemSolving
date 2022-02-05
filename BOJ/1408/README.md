[1408번: 24](https://www.acmicpc.net/problem/1408)

### 사고의 흐름

모든 시간 단위를 초 단위로 바꾸어 계산한 뒤 다시 원래 시간 단위로 바꾸어서 출력해주었다.

```jsx
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	string s1, s2;
	int result = 0;
	//solution
	cin >> s1 >> s2;
	int fir = 3600 * stoi(s1.substr(0, 2)) + 60 * stoi(s1.substr(3, 2)) + stoi(s1.substr(6, 2));
	int sec = 3600 * stoi(s2.substr(0, 2)) + 60 * stoi(s2.substr(3, 2)) + stoi(s2.substr(6, 2));
	if (sec > fir)
	{
		result = sec - fir;
	}
	else
	{
		result = 3600 * 24 - (fir - sec);
	}
	int a, b, c;
	a = result / 3600;
	b = (result % 3600) / 60;
	c = result % 60;
	if (a < 10)
	{
		cout << 0;
	}
	cout << a << ":";
	if (b < 10)
	{
		cout << 0;
	}
	cout << b << ":";
	if (c < 10)
	{
		cout << 0;
	}
	cout << c;

	return 0;
}
```
