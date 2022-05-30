int t, n, m, a, b, c, d, e, itemp1, itemp2;
vector<int> vtemp;
vector<vector<int>> v;
int result = -1;
bool indexCheck(int first, int second) {
	if ((-1 < first&&first < n) && (-1 < second&&second < m))
	{
		return true;
	}
	return false;
}
void resultCompare(pii pos0, pii pos1, pii pos2, pii pos3) {
	int itemp;
	if (indexCheck(pos1.first, pos1.second) && indexCheck(pos2.first, pos2.second) && indexCheck(pos3.first, pos3.second))
	{
		itemp = (v[pos0.first][pos0.second] + v[pos1.first][pos1.second] + v[pos2.first][pos2.second] + v[pos3.first][pos3.second]);
		if (itemp > result) { result = itemp; }
	}
}
void solution(int y, int x) {
	pii pos0, pos1, pos2, pos3;
	pos0.first = y;
	pos0.second = x;
	//1
	pos1.first = y;
	pos1.second = x + 1;
	pos2.first = y;
	pos2.second = x + 2;
	pos3.first = y;
	pos3.second = x + 3;
	resultCompare(pos0, pos1, pos2, pos3);
	//2
	pos1.first = y + 1;
	pos1.second = x;
	pos2.first = y + 2;
	pos2.second = x;
	pos3.first = y + 3;
	pos3.second = x;
	resultCompare(pos0, pos1, pos2, pos3);
	//3, 4, 5...
	//19까지 있지만 길어져서 생략
}
int main() {
	//init
	FastIO;
	cin >> n >> m;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> itemp1;
			vtemp.push_back(itemp1);
		}
		v.push_back(vtemp);
		vtemp.clear();
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			solution(i, j);
		}
	}
	cout << result;
	return 0;
}
