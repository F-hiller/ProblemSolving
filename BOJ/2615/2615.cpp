int main() {
	FastIO;
	//init
	short int arr[19][19];
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (arr[i][j])
			{
				int check = arr[i][j];

				if ((j < 15 && check == arr[i][j + 1] && check == arr[i][j + 2] && check == arr[i][j + 3] && check == arr[i][j + 4])
					&& (j < 1 || check != arr[i][j - 1]) && (j > 13 || check != arr[i][j + 5]))
				{
					cout << check << endl << i + 1 << " " << j + 1;
					return 0;
				}
				if ((i < 15 && check == arr[i + 1][j] && check == arr[i + 2][j] && check == arr[i + 3][j] && check == arr[i + 4][j])
					&& (i < 1 || check != arr[i - 1][j]) && (i > 13 || check != arr[i + 5][j]))
				{
					cout << check << endl << i + 1 << " " << j + 1;
					return 0;
				}
				if (((i < 15 && j < 15) && check == arr[i + 1][j + 1] && check == arr[i + 2][j + 2] && check == arr[i + 3][j + 3] && check == arr[i + 4][j + 4])
					&& ((i < 1 || j < 1) || check != arr[i - 1][j - 1]) && ((i > 13 || j > 13) || check != arr[i + 5][j + 5]))
				{
					cout << check << endl << i + 1 << " " << j + 1;
					return 0;
				}
				if (((i >= 4 && j <= 14) && check == arr[i - 1][j + 1] && check == arr[i - 2][j + 2] && check == arr[i - 3][j + 3] && check == arr[i - 4][j + 4])
					&& ((i >= 18 || j <= 0) || check != arr[i + 1][j - 1]) && ((i <= 0 && j >= 18) || check != arr[i - 5][j + 5]))
				{
					cout << check << endl << i + 1 << " " << j + 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}
