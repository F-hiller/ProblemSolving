	string s;
	//solution
	cin >> s;
	for ( i = 0; i < s.size(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
		{
			cout << (char)toupper(s[i]);
			continue;
		}
		cout << (char)tolower(s[i]);
	}
