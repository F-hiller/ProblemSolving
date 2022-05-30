	cin >> n;
	queue<pii> q;
	for ( i = 0; i < n; i++)
	{
		cin >> itemp;
		q.push(pii(i, itemp));
	}
	int t = 1;
	while (!q.empty())
	{
		pii front_value = q.front();
		q.pop();
		if (front_value.second != 1)
		{
			q.push(pii(front_value.first, front_value.second - 1));
		}
		else
		{
			ans[front_value.first] = t;
		}
		t++;
	}
	for ( i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
