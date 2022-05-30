int main() {
	//init
	FastIO;

	int n, i, j;
	cin >> n;
	pii result[2][3];
	for (i = 0; i < n; i++)
	{
		short int a, b, c;
		cin >> a >> b >> c;
		//min - 0to0
		result[1][0].second = result[0][0].second + a;
		//min - 0to1
		result[1][1].second = result[0][0].second + b;
		//min - 1to0
		result[1][0].second = min(result[1][0].second, result[0][1].second + a);
		//min - 1to1
		result[1][1].second = min(result[1][1].second, result[0][1].second + b);
		//min - 1to2
		result[1][2].second = result[0][1].second + c;
		//min - 2to1
		result[1][1].second = min(result[1][1].second, result[0][2].second + b);
		//min - 2to2
		result[1][2].second = min(result[1][2].second, result[0][2].second + c);
		//================
		//max - 0to0
		result[1][0].first = result[0][0].first + a;
		//max - 0to1
		result[1][1].first = result[0][0].first + b;
		//max - 1to0
		result[1][0].first = max(result[1][0].first, result[0][1].first + a);
		//max - 1to1
		result[1][1].first = max(result[1][1].first, result[0][1].first + b);
		//max - 1to2
		result[1][2].first = result[0][1].first + c;
		//max - 2to1
		result[1][1].first = max(result[1][1].first, result[0][2].first + b);
		//max - 2to2
		result[1][2].first = max(result[1][2].first, result[0][2].first + c);
		//
		for (j = 0; j < 3; j++) { result[0][j] = result[1][j]; }
	}
	cout << max(max(result[0][0].first, result[0][1].first), result[0][2].first) << " " << min(min(result[0][0].second, result[0][1].second), result[0][2].second);
	return 0;
}
