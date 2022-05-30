//additional variables
string s;
stack<double> stk;
double fir, sec, input;
int abc[27];

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k, itemp;
	//solution
	cin >> n>>s;
	for ( i = 0; i < n; i++)
	{
		cin >> abc[i];
	}
	for ( i = 0; i < s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			stk.push(abc[s[i] - 'A']);
			continue;
		}
		sec = stk.top();
		stk.pop();
		fir = stk.top();
		stk.pop();
		if (s[i] == '*')
		{
			input = fir * sec;
		}
		else if (s[i] == '/')
		{
			input = fir / sec;
		}
		else if (s[i] == '+')
		{
			input = fir + sec;
		}
		else if (s[i] == '-')
		{
			input = fir - sec;
		}
		stk.push(input);
	}
	printf("%.2lf", stk.top());

	return 0;
}
