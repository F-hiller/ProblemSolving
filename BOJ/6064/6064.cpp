int main() {
	FastIO;
	//init
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll m, n, x, y;
		cin >> m >> n >> x >> y;
		ll big;
		ll bigSub;
		ll small;
		ll smallSub;
		if (m > n)
		{
			big = m;
			bigSub = x;
			small = n;
			smallSub = y;
		}
		else
		{
			big = n;
			bigSub = y;
			small = m;
			smallSub = x;
		}
		if (big == 1)
		{
			cout << 1 << endl;
			continue;
		}
		bool check = 0;
		ll gap = smallSub - 1;
		ll checkY = (bigSub - gap + big) % big;
		ll curY = 1;
		ll year = 1;
		do
		{
			if (curY == checkY)
			{
				cout << year + gap << endl;
				check = 1;
				break;
			}
			curY = (curY + small) % big;
			year += small;
		} while (curY != 1);
		if (!check) { cout << -1 << endl; }
	}
	return 0;
}
