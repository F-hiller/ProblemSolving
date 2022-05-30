void init();

typedef struct _dice {
	int y, x;
	int left, right;
	int middle[4];
}dice_offset;
int n, m, itemp1, itemp2, itemp3;
int command_cnt;
int command_line[1000];
dice_offset dice;
int map[MAX_SIZE][MAX_SIZE];

void print_map(int dir) {
	int i, j, k;
	cout << "===================\n";
	cout << "dir : " << dir << endl;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << dice.left << " " << dice.right<<endl;
	for ( i = 0; i < 4; i++)
	{
		cout << dice.middle[i] << " ";
	}
	cout << endl;
	cout << "===================\n";
}
void dice_copy() {
	if (map[dice.x][dice.y] == 0)
	{
		map[dice.x][dice.y] = dice.middle[3];
		return;
	}
	dice.middle[3] = map[dice.x][dice.y];
	map[dice.x][dice.y] = 0;
}
void right() {
	dice.y++;
	int itemp = dice.middle[3];
	dice.middle[3] = dice.right;
	dice.right = dice.middle[1];
	dice.middle[1] = dice.left;
	dice.left = itemp;
	dice_copy();
}
void left() {
	dice.y--;
	int itemp = dice.middle[3];
	dice.middle[3] = dice.left;
	dice.left = dice.middle[1];
	dice.middle[1] = dice.right;
	dice.right = itemp;
	dice_copy();
}
void up() {
	dice.x--;
	int itemp = dice.middle[3];
	dice.middle[3] = dice.middle[0];
	dice.middle[0] = dice.middle[1];
	dice.middle[1] = dice.middle[2];
	dice.middle[2] = itemp;
	dice_copy();
}
void down() {
	dice.x++;
	int itemp = dice.middle[3];
	dice.middle[3] = dice.middle[2];
	dice.middle[2] = dice.middle[1];
	dice.middle[1] = dice.middle[0];
	dice.middle[0] = itemp;
	dice_copy();
}
void move(int dir) {
	if (dir == 1 && dice.y + 1 < m)
	{
		right();
	}
	else if (dir == 2 && dice.y > 0)
	{
		left();
	}
	else if (dir == 3 && dice.x > 0)
	{
		up();
	}
	else if (dir == 4 && dice.x + 1 < n)
	{
		down();
	}
	else
	{
		return;
	}
	cout << dice.middle[1] << endl;
}
void roll_dice() {
	int i, j, k;
	for (i = 0; i < command_cnt; i++)
	{
		move(command_line[i]);
		if (DEBUG)
		{
			print_map(command_line[i]);
		}
	}
}

int main() {
	//init
	FastIO;
	int i, j, k;
	init();
	//input
	cin >> n >> m >> dice.x >> dice.y >> command_cnt;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (i = 0; i < command_cnt; i++)
	{
		cin >> command_line[i];
	}

	roll_dice();

	return 0;
}
void init() {
	int i, j, k;
	dice.left = 0;
	dice.right = 0;
	for (i = 0; i < 4; i++)
	{
		dice.middle[i] = 0;
	}
}
