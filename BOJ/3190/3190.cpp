//additional variables
int board[101][101];
pair<int, char> movingInfo[101];
typedef struct Snake {
	deque<pii> body;
	int dir;
};

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	int x;
	char c;
	Snake snake;
	pii head, tail, ptemp, nextPos;
	int info_index = 0;
	//solution
	cin >> n;
	cin >> K;
	for ( i = 0; i < K; i++)
	{
		cin >> ptemp.first >> ptemp.second;
		board[ptemp.first][ptemp.second] = 2;
	}
	cin >> m;
	for ( i = 0; i < m; i++)
	{
		cin >> x >> c;
		movingInfo[i] = pair<int, char>(x, c);
	}
	snake.body.push_back(pii(1, 1));
	head = snake.body[0];
	tail = snake.body[snake.body.size() - 1];
	snake.dir = 1;
	board[1][1] = 1;
	//simulation
	t = 1;
	while (true)
	{
		//직진 가능 여부 확인 후 직진
		nextPos.first = head.first + dirY[snake.dir];
		nextPos.second = head.second + dirX[snake.dir];
		if (!(0 < nextPos.first&&nextPos.first <= n && 0 < nextPos.second&&nextPos.second <= n))
		{
			cout << t;
			break;
		}
		snake.body.push_front(nextPos);
		head = snake.body[0];
		if (board[head.first][head.second] == 1)
		{
			cout << t;
			break;
		}
		if (board[head.first][head.second] == 0)
		{
			snake.body.pop_back();
			board[tail.first][tail.second] = 0;
			tail = snake.body[snake.body.size() - 1];
		}
		board[head.first][head.second] = 1;
		//방향 전환
		if (info_index < m && t == movingInfo[info_index].first)
		{
			if (movingInfo[info_index].second == 'L')
			{
				snake.dir = (snake.dir + 3) % 4;
			}
			else
			{
				snake.dir = (snake.dir + 1) % 4;
			}
			info_index++;
		}
		if (DEBUG)
		{
			cout << "=================================" << endl;
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					cout << board[i][j];
				}
				cout << endl;
			}
			cout << "dir : " << snake.dir << endl;
			cout << "time : " << t << endl;
			cout << "=================================" << endl;
		}
		t++;
	}
	
	return 0;
}
