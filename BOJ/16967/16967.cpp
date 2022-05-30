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
