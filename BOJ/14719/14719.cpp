int t, i, j, k, n, m, a, b, c, d, e, itemp1, itemp2;
int h, w, result;
int map[500];
int mem[500];
bool visited[500];

int main() {
	//init
	FastIO;
	cin >> h >> w;
	for (i = 0; i < w; i++)
	{
		cin >> map[i];
	}
	for (i = 1; i < w - 1; i++)
	{
		if (visited[i])
		{
			result += (mem[i] - map[i]);
			continue;
		}
		int left = i;
		int right = i;
		int leftValue = map[i];
		int rightValue = map[i];

		for (j = i - 1; j > -1; j--)
		{
			if (map[j] > leftValue)
			{
				leftValue = map[j];
				left = j;
			}
		}
		for (j = i + 1; j < w; j++)
		{
			if (map[j] > rightValue)
			{
				rightValue = map[j];
				right = j;
				if (map[j] >= leftValue)
				{
					break;
				}
			}
		}
		int value = min(leftValue, rightValue);
		if (value == map[i])
		{
			continue;
		}
		for (j = left + 1; j < right; j++)
		{
			visited[j] = 1;
			mem[j] = value;
		}
		result += (value - map[i]);
	}
	cout << result;
	return 0;
}
