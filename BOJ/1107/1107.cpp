int t, n, m, a, b, c, d, e, itemp1, itemp2;
bool button[11];
int channel[1000000];
string stemp;
int result;

int make_result(int result, int value) {
	//ÀÚ¸´¼ö¸¦ ´õÇØÁÜ
	if (value == 0) { return result + 1; }
	while (value)
	{
		result++;
		value /= 10;
	}
	return result;
}
void solution(int first, int second) {
	int i, j, k;
	for (i = n; i < first; i++)
	{
		stemp = to_string(i);
		bool check = 0;
		for (j = 0; j < stemp.size(); j++)
		{
			if (button[stemp[j] - '0'])
			{
				check = 1;
				break;
			}
		}
		if (!check)
		{
			if (result > make_result(i - n, i)) {
				result = make_result(i - n, i);
			}
			break;
		}
	}
	for (i = n - 1; i > second; i--)
	{
		stemp = to_string(i);
		bool check = 0;
		for (j = 0; j < stemp.size(); j++)
		{
			if (button[stemp[j] - '0'])
			{
				check = 1;
				break;
			}
		}
		if (!check)
		{
			if (result > make_result(n - i, i)) {
				result = make_result(n - i, i);
			}
			break;
		}
	}
	cout << result;
}
int main() {
	//init
	FastIO;
	cin >> n >> m;
	int i, j, k;
	for (i = 0; i < m; i++)
	{
		cin >> itemp1;
		button[itemp1] = 1;
	}
	if (n == 100)
	{
		cout << 0;
		return 0;
	}
	if (n < 100)
	{
		result = 100 - n;
		solution(100, -1);
		return 0;
	}
	result = n - 100;
	solution(2 * n - 99, 100);
	return 0;
}
