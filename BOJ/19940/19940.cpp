#define INF 987654321
#define SHARING 10000001
#define SHARING2 61

int n, m, t, N, K;

//additional variables
typedef struct _count {
	int value;
	int total_count;
	int count[5];
}custom;
custom sixty[SHARING2];

void bfs() {
	int i, j;
	int counter[] = { 60, 10, -10, 1, -1 };
	custom ctemp;
	queue<custom> q;

	for (i = 0; i < SHARING2; i++)
	{
		sixty[i].total_count = INF;
	}

	ctemp = sixty[0];
	ctemp.total_count = 0;

	q.push(ctemp);

	while (!q.empty())
	{
		custom top = q.front();
		int value = top.value;
		q.pop();
		if (-1 < value && value < SHARING2)
		{
			custom sixty_value = sixty[value];
			if (top.total_count > sixty_value.total_count) { continue; }
			if (top.total_count == sixty_value.total_count)
			{
				bool break_check = 1;
				for (i = 0; i < 5; i++)
				{
					if (top.count[i] > sixty_value.count[i]) { break; }
					if (top.count[i] < sixty_value.count[i]) {
						break_check = 0;
						break;
					}
				}
				if (break_check) { continue; }
			}

			sixty[value] = top;

			for (i = 0; i < 5; i++)
			{
				ctemp = top;
				ctemp.value += counter[i];
				ctemp.total_count++;
				ctemp.count[i]++;
				q.push(ctemp);
			}
		}
	}
}

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int t, i, j, k, itemp;

	//solution
	bfs();

	cin >> t;

	for (i = 0; i < t; i++)
	{
		cin >> n;
		cout << n / 60 + sixty[n % 60].count[0] << " ";
		for (j = 1; j < 5; j++)
		{
			cout << sixty[n % 60].count[j] << " ";
		}
		cout << endl;
	}

	return 0;
}
