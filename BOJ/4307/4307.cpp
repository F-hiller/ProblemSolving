	cin >> t;
	for ( i = 0; i < t; i++)
	{
		cin >> len >> n;
		minvalue = 0;
		maxvalue = 0;
		for ( j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		for ( j = 0; j < n; j++)
		{
			far = max(arr[j], len - arr[j]);
			near = min(arr[j], len - arr[j]);
			result[j] = pii(near, far);
		}
		for ( j = 0; j < n; j++)
		{
			if (result[j].first > minvalue)
			{
				minvalue = result[j].first;
			}
			if (result[j].second > maxvalue)
			{
				maxvalue = result[j].second;
			}
		}
		cout << minvalue << " " << maxvalue << endl;
	}
