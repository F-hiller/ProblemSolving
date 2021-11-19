[11365번: !밀비 급일](https://www.acmicpc.net/problem/11365)

## 사고의 흐름

공백을 포함한 한 줄 입력을 아는지 묻는 문제이다. 

getline(cin, str);을 사용하여 해결했다.

```cpp
int t, n, m, input1, input2;
string stemp;
int main() {
	//init
	FastIO;
	int i, j, k;
	getline(cin, stemp);
	while (stemp != "END")
	{
		for ( i = stemp.size() - 1; i > -1; i--)
		{
			cout << stemp[i];
		}
		cout << endl;
		getline(cin, stemp);
	}

	return 0;
}
```
