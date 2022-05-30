int i, j, k, n, m, t, itemp1, itemp2;
string str;
char cmd, ctemp;
stack<char> s, result;

int main() {
	//init
	FastIO;
	//init
	init();

	cin >> str;
	for ( i = 0; i < str.size(); i++)
	{
		s.push(str[i]);
	}
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == 'P')
		{
			cin >> ctemp;
			s.push(ctemp);
		}
		else if (cmd == 'L' && !s.empty())
		{
			result.push(s.top());
			s.pop();
		}
		else if (cmd == 'D' && !result.empty())
		{
			s.push(result.top());
			result.pop();
		}
		else if (cmd == 'B' && !s.empty())
		{
			s.pop();
		}
	}
	while (!s.empty())
	{
		result.push(s.top());
		s.pop();
	}
	while (!result.empty())
	{
		cout << result.top();
		result.pop();
	}
	return 0;
}
