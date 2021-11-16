[23038번: 박스 그림 문자](https://www.acmicpc.net/problem/23038)

## 사고의 흐름

문제의 조건이 명확하지 않아서 헷갈렸는데 무조건 주어진 기호를 사용하여 문제의 "아름다운 모양"을 만들 수 있는 경우만 제시된다고 가정하고 풀었다.

```cpp
int t, n, m, input1, input2;
string arr[1000];
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> m;
	for ( i = 0; i < 3*n; i++)
	{
		cin >> arr[i];
	}
	int y, x;
	int rangeY = 3 * n;
	int rangeX = 3 * m;
	for ( i = 0; i < rangeY; i++)
	{
		for ( j = 0; j < rangeX; j++)
		{
			if (4 < i + j && (i + j + 1) % 6 == 0 && (i % 3 == 1 && j % 3 == 1))
			{
				y = i - 2;
				x = j;
				if ((-1 < y && y < rangeY && -1 < x && x < rangeX) && arr[y][x] =='#')
				{
					y++;
					arr[y][x] = '#';
				}
				y = i;
				x = j + 2;
				if ((-1 < y && y < rangeY && -1 < x && x < rangeX) && arr[y][x] == '#')
				{
					x--;
					arr[y][x] = '#';
				}
				y = i + 2;
				x = j;
				if ((-1 < y && y < rangeY && -1 < x && x < rangeX) && arr[y][x] == '#')
				{
					y--;
					arr[y][x] = '#';
				}
				y = i;
				x = j - 2;
				if ((-1 < y && y < rangeY && -1 < x && x < rangeX) && arr[y][x] == '#')
				{
					x++;
					arr[y][x] = '#';
				}
				arr[i][j] = '#';
			}
		}
	}
	for (i = 0; i < rangeY; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}
```
