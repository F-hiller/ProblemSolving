int t, n, m, a, b, c, d, e, itemp1, itemp2;
string str;
stack<char> s;
int main() {
	//init
	FastIO;
	cin >> str;
	int i, j, k;
	for (i = 0; i < str.size(); i++)
	{
		char ctemp = str[i];
		if (('A' <= ctemp && ctemp <= 'Z'))
		{
			cout << ctemp;
			continue;
		}
		if (ctemp == '(')
		{
			s.push(ctemp);
			continue;
		}
		if (ctemp == ')')
		{
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
			continue;
		}
		if ((ctemp == '+' || ctemp == '-'))
		{
			while (!s.empty())
			{
				if (s.top() == '(') {
					break;
				}
				cout << s.top();
				s.pop();
			}
			s.push(ctemp);
			continue;
		}
		if ((ctemp == '*' || ctemp == '/'))
		{
			while (!s.empty() && (s.top() != '+' && s.top() != '-' && s.top() != '('))
			{
				cout << s.top();
				s.pop();
			}
			s.push(ctemp);
			continue;
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}
