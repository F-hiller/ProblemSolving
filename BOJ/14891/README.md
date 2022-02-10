[14891번: 톱니바퀴](https://www.acmicpc.net/problem/14891)

### 사고의 흐름

돌려야하는 톱니바퀴를 기준으로 왼쪽이나 오른쪽에 톱니바퀴가 있다면 해당 톱니바퀴와 맞물리는 부분의 극 상태를 확인해주고 톱니바퀴를 돌려주는 형식으로 진행하였다.

톱니바퀴를 돌리는 것은 Gear구조체의 circular_count로 구현하였다. 시작으로 입력받았던 톱니바퀴 상태에서 circular_count만큼 돌리면 현재 톱니바퀴의 상태라는 것을 정보로 저장하였다.

```jsx
//additional variables
typedef struct Gear {
	string init_state;
	int circular_count;
};
Gear gears[4];

void cycle(int index, int dir, int move_dir) {
	int pre = index - 1;
	int next = index + 1;
	if ((move_dir == 0 || move_dir == -1)&&!(pre < 0 || pre>3) && 
		gears[pre].init_state[(gears[pre].circular_count + 2) % 8] != gears[index].init_state[(gears[index].circular_count + 6) % 8])
	{
		cycle(pre, dir == 1 ? -1 : 1, -1);
	}
	if ((move_dir == 0 || move_dir == 1) && !(next < 0 || next>3) &&
		gears[next].init_state[(gears[next].circular_count + 6) % 8] != gears[index].init_state[(gears[index].circular_count + 2) % 8])
	{
		cycle(next, dir == 1 ? -1 : 1, 1);
	}
	gears[index].circular_count = (gears[index].circular_count + 8 - dir) % 8;
}

//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k;
	int gear_num, dir;
	//solution
	for (i = 0; i < 4; i++)
	{
		cin >> gears[i].init_state;
		gears[i].circular_count = 0;
	}
	cin >> K;
	for (i = 0; i < K; i++)
	{
		cin >> gear_num >> dir;
		gear_num--;
		cycle(gear_num, dir, 0);
	}
	int multi = 1;
	int result = 0;
	for ( i = 0; i < 4; i++)
	{
		if (gears[i].init_state[(gears[i].circular_count + 8) % 8] == '1')
		{
			result += multi;
		}
		multi *= 2;
	}
	cout << result;
	return 0;
}
```
