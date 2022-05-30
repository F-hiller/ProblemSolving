6
10 40 80
30 60 60
50 80 70
70 100 100
90 120 40
110 140 50

인원 수만 적어본다면 80 60 70 100 40 50이다.

첫번째 회의는 앞선 회의가 없으므로 80이다.

두번째 회의는 바로 앞 회의를 제외한 회의가 없으므로 60이다.

세번째 회의는 바로 앞 두번째 회의를 제외한 가장 높은 인원을 가진 회의가 80이다. 80에 세번째 회의 인원 70을 더한 150이 저장된다.

네번째 회의는 바로 앞 세번째 회의를 제외한 회의는 80이다. 80+100 = 180이다.

다섯번째 회의는 네번째를 제외하고 세번째 회의의 dp값인 150이다. 150+40 = 190이다.

여섯번째 회의는 다섯번째를 제외하고 네번째 회의의 dp값인 180이다. 180+50 = 230이다.

6개의 dp값 중 가장 높은 값은 230이고 정답이 된다. 

아래는 코드이다.

int i, j, k, n, m, itemp1, itemp2, itemp3;
custom arr[25];
int result[25];

int main() {
	//init
	FastIO;

	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
	}
	if (n == 1)
	{
		cout << arr[0].c;
		return 0;
	}

	int max_value;
	result[0] = arr[0].c;
	result[1] = arr[1].c;
	for ( i = 2; i < n; i++)
	{
		max_value = result[0];
		for ( j = 1; j < i - 1; j++)
		{
			if (max_value < result[j])
			{
				max_value = result[j];
			}
		}
		result[i] = max_value + arr[i].c;
	}
	max_value = result[0];
	for ( i = 1; i < n; i++)
	{
		if (max_value<result[i])
		{
			max_value = result[i];
		}
	}
	cout << max_value;

	return 0;
}
