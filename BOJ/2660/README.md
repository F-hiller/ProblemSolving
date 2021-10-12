[2660번: 회장뽑기](https://www.acmicpc.net/problem/2660)

## 사고의 흐름

network 2차원 배열에 모든 간선들을 저장하고 모든 정점에서 bfs를 실시한다.

bfs에서는 personal 2차원 배열을 이용해 정점 간의 관계를 기록한다. personal[i][j] == personal[j][i]는 항상 참이고 personal[i][j] 값이 1이라면 i노드와 j노드는 친구관계, 2라면 친구의 친구관계..4라면..5..라는 의미이다. 그 후 i의 친구관계 중 가장 큰 것이 i의 점수가 된다.

점수가 가장 작은 사람들을 set에 저장한 후 출력하면 완성이다.

```cpp
int t, n, m, input1, input2;
vector<vector<int>> network;
vector<vector<int>> personal;
void bfs(int member) {
	vector<bool> visited(n + 1);
	queue<pii> q;
	int i, j, k;
	q.push(pii(member, 0));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int topIndex = top.first;
		int value = top.second;
		if (!visited[topIndex])
		{
			visited[topIndex] = 1;
			personal[member][topIndex] = value;
			for (i = 0; i < network[topIndex].size(); i++)
			{
				q.push(pii(network[topIndex][i], value + 1));
			}
		}
	}
}
int main() {
	//init
	FastIO;
	cin >> n;
	int i, j, k;
	network.resize(n+1);
	personal.resize(n+1);
	vector<int> vtemp(n + 1, 987654321);
	for (i = 1; i < n + 1; i++) { personal[i] = vtemp; }
	while (true)
	{
		cin >> input1 >> input2;
		if (input1 == -1 && input2 == -1){break;}
		network[input1].push_back(input2);
		network[input2].push_back(input1);
	}
	for (i = 1; i < n + 1; i++) {
		bfs(i);
	}
	vector<int> v;
	v.push_back(100);
	int score = 100;
	for ( i = 1; i < n + 1; i++)
	{
		int count = 0;
		for ( j = 1; j < n + 1; j++)
		{
			if (personal[i][j] > count)
			{
				count = personal[i][j];
			}
		}
		if (score > count)
		{
			score = count;
		}
		v.push_back(count);
	}
	set<int> s;
	for (i = 1; i < n + 1; i++)
	{
		if (v[i]==score)
		{
			s.insert(i);
		}
	}
	cout << score << " " << s.size() << endl;
	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << " ";
	}
	return 0;
}
```
