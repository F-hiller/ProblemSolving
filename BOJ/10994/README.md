[10994번 - 별 찍기 - 19](https://www.acmicpc.net/problem/10994)

## 사고의 흐름

원래는 별찍기 11번을 풀려고 했다. 하지만 삼각형 모양이고 재귀에 익숙하지 않아서 재귀를 이용한 쉬운 버전의 문제인 19번을 풀게 되었다. 그런데 막상 재귀로 풀지 않아서 추가로 설명을 적어보려고 한다.

## 재귀로 푸는 법 - 추가 설명

별 찍기 문제는 대부분 아래 코드와 같이 이중 for문을 사용해서 해당 좌표(i, j)에 별을 찍을 지 여부를 확인하면서 해결하였다. 하지만 char arr[100][100]; 형식처럼 미리 배열을 선언하고 재귀 방식을 이용해서 범위를 줄여나가면서 배열에 별을 넣는 방식으로 진행 후 나중에 배열 전체를 출력해주면 된다. 왜인지는 모르겠지만 별을 항상 바로 cout으로 출력해줘야한다는 고정 관념을 가지고 있었다. 다른 별찍기 문제에서는 배열에 저장해놓고 출력하는 방식으로 풀어보면 좋겠다.

```cpp
int n, m, t, itemp1, itemp2;
int last;

void solution() {
	int i, j, k;
	int last_range = last;
	for (i = 0; i < last; i++)
	{
		for (j = 0; j < last; j++)
		{
			if (i % 2 == 0 && ((i <= j && j < last - i) || (i >= j && j >= last - i))) {
				cout << "*";
				continue;
			}
			if (j % 2 == 0 && ((j <= i && i < last - j) || (j >= i && i >= last - j)))
			{
				cout << "*";
				continue;
			}
			cout << " ";
		}
		cout << endl;
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
	cin >> n;
	last = 4 * n - 3;
}
```
