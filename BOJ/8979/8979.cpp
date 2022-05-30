typedef struct nation{
	int num, gold, silver, bronze;
};

int t, n, m, input1, input2;
nation arr[1001];
nation ntemp;
bool isLose(int i) {
	nation comp = arr[i];
	if (comp.gold > ntemp.gold)
	{
		return 1;
	}
	if (comp.gold < ntemp.gold)
	{
		return 0;
	}
	if (comp.silver > ntemp.silver)
	{
		return 1;
	}
	if (comp.silver < ntemp.silver)
	{
		return 0;
	}
	if (comp.bronze > ntemp.bronze)
	{
		return 1;
	}
	if (comp.bronze < ntemp.bronze)
	{
		return 0;
	}
	return 0;
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n >> k;
	for ( i = 0; i < n; i++)
	{
		cin >> ntemp.num >> ntemp.gold >> ntemp.silver >> ntemp.bronze;
		arr[ntemp.num] = ntemp;
	}
	int result = 1;
	ntemp = arr[k];
	for ( i = 1; i <= n; i++)
	{
		if (i == k)
		{
			continue;
		}
		if (isLose(i))
		{
			result++;
		}
	}
	cout << result;
	return 0;
}
