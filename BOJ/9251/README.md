[9251번: LCS](https://www.acmicpc.net/problem/9251)

## 사고의 흐름

LCS 유형의 문제를 처음으로 접해봤다. 알고리즘은 다음과 같다. 익숙해진 후 다시 풀어봐야 할 것 같다.

---

문자열 A, B의 길이로 2차원 배열을 만든다.

1부터 각 문자열의 길이의 범위를 가지는 인덱스 i, j에 대해서 2개의 경우가 발생한다. (0은 비워둠.)

1. A[i]와 B[j]가 같은 경우

```cpp
arr[i][j] = arr[i-1][j-1] + 1;
```

ex ) A : abc, B : defc 의 예시

마지막 글자가 c로 같아진 경우가 생겼으므로 ab, def일 때의 LCS에서 1을 더해주면 된다.

1. A[i]와 B[j]가 다른 경우

```cpp
arr[i][j] = max(arr[i-1][j], arr[i][j-1])
```

ex ) A : abc, B : def 의 예시

c와 f는 다른 글자이므로 LCS의 길이가 이전 단계와 변함이 없다. 이전 단계라 함은 어느 한 쪽의 마지막 글자를 확인하기 이전의 LCS의 값인 ab, def의 LCS / abc, de의 LCS 두 개라고 할 수 있다.

```cpp
int n, m, t, N, K, itemp1, itemp2, itemp3;
string s1, s2;
int arr[1001][1001];

void solution() {
	int i, j, k;
	for ( i = 1; i <= s2.size(); i++)
	{
		for ( j = 1; j <= s1.size(); j++)
		{
			if (s2[i-1] != s1[j-1])
			{
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
				continue;
			}
			arr[i][j] = arr[i - 1][j - 1] + 1;
		}
	}
	cout << arr[s2.size()][s1.size()];
	if (DEBUG)
	{
		cout << endl;
		for (i = 1; i <= s2.size(); i++)
		{
			for (j = 1; j <= s1.size(); j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> s1 >> s2;
}
```
