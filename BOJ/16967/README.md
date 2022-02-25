[16967번: 배열 복원하기](https://www.acmicpc.net/problem/16967)

### 사고의 흐름

문제에도 서술되어 있듯이 배열 A로 배열 B를 구성하는 경우는 3가지이다.

1. 움직이지 않은 A의 영역
2. 움직인 후의 A의 영역
3. 1, 2번의 영역이 겹치는 영역

여기서 1, 2번은 그냥 구하면 되고 3번의 경우를 다음과 같은 식으로 표현할 수 있다.

영역의 좌표 (i, j) 에 대해 B[i][j] = A[i-X][j-Y] + A[i][j] 이다. 

따라서 A[i][j] = B[i][j] - A[i - X][j - Y]; 로 식을 적어주면 된다.

```cpp
//additional variables
int H, W, X, Y, H_B, W_B;
int A[605][605];
int B[605][605];

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k, itemp;
	int cnt = 0;
	//solution
	cin >> H >> W >> X >> Y;
	H_B = H + X;
	W_B = W + Y;
	for (i = 0; i < H_B; i++)
	{
		for (j = 0; j < W_B; j++)
		{
			cin >> B[i][j];
		}
	}
	for (i = 0; i < H_B; i++)
	{
		for (j = 0; j < W_B; j++)
		{
			if (X <= i && i <= H && Y <= j && j <= W)
			{
				A[i][j] = B[i][j] - A[i - X][j - Y];
				continue;
			}
			if (i <= H && j <= W)
			{
				A[i][j] = B[i][j];
				continue;
			}
			if (X <= i && Y <= j)
			{
				A[i - X][j - Y] = B[i][j];
				continue;
			}
		}
	}
	for ( i = 0; i < H; i++)
	{
		for ( j = 0; j < W; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
```
