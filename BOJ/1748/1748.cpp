ll t, n, m, input1, input2;
ll arr[11];
int main() {
	//init
	FastIO;
	ll i, j, k;
	cin >> n;
	
	ll value = 9;
	for ( i = 1; i <= 9; i++)
	{
		arr[i] = value * i;
		value *= 10;
	}

	ll comp = 10;
	ll cnt;
	for (i = 1; i <= 9; i++)
	{
		if (n < comp)
		{
			cnt = i;
			break;
		}
		comp *= 10;
	}

	ll result = 0;
	for (i = 1; i < cnt; i++)
	{
		result += arr[i];
	}

	comp /= 10;
	comp--;
	result += (n - comp)*cnt;

	cout << result;

	return 0;
}
