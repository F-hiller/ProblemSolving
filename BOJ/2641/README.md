[2641번: 다각형그리기](https://www.acmicpc.net/problem/2641)

## 사고의 흐름

배열을 shift해서 같다면 조건을 만족하는 모양수열이다.

즉 1411433322이라는 숫자를 밀어서 3221411433이 나오면 둘은 같은 다각형이다.

또하나 고려해줘야하는 것이 반대방향으로 회전하는 것이다. 4411123323이 그 경우인데

이는 원래 숫자인 1411433322을 1↔3 / 2↔4 로 바꾼(1을 3으로, 3을 1로, 2를 4로, 4를 2로) 3233211144의 인덱스를 뒤집은 것과 같다. (n - 1인덱스가 0인덱스로, 0인덱스가 n - 1 인덱스로...)

주어지는 입력의 갯수가 최대 100개고 길이가 50이다. 하나의 입력을 확인하는데 100번의 경우의 수가 나오고 최대 10000개의 경우의 수가 나온다. 이는 1초안에 해결할 수 있으므로 모든 경우를 직접 확인해보는 것이 가능한 구현 문제이다.

```cpp
int t, n, m, input1, input2;
vector<pii> resultInfo;
vector<int> base;
vector<int> reverse_base;
vector<vector<int>> inputVectors;
vector<int> vtemp;
void setting() {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		int itemp = (base[i] + 2) % 4;
		if (!itemp)
		{
			itemp = 4;
		}
		reverse_base[n - 1 - i] = itemp;
	}
}
bool isMatched(vector<int> &a, int moveCnt) {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		if (a[(i+moveCnt)%n] != base[i])
		{
			return 0;
		}
	}
	return 1;
}
bool isReverseMatched(vector<int> &a, int moveCnt) {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		if (a[(i + moveCnt) % n] != reverse_base[i])
		{
			return 0;
		}
	}
	return 1;
}
void print_result(vector<int> &a) {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void solution(int a) {
	int i, j, k;
	for ( i = 0; i < n; i++)
	{
		if (isMatched(inputVectors[a], i) || isReverseMatched(inputVectors[a], i))
		{
			resultInfo.push_back(pii(a, i));
			return;
		}
	}
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;
	reverse_base.resize(n);
	for ( i = 0; i < n; i++)
	{
		cin >> input1;
		base.push_back(input1);
	}
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		for ( j = 0; j < n; j++)
		{
			cin >> input1;
			vtemp.push_back(input1);
		}
		inputVectors.push_back(vtemp);
		vtemp.clear();
	}
	setting();

	for ( i = 0; i < t; i++)
	{
		solution(i);
	}

	cout << resultInfo.size() << endl;
	for ( i = 0; i < resultInfo.size(); i++)
	{
		print_result(inputVectors[resultInfo[i].first]);
	}

	return 0;
}
```
