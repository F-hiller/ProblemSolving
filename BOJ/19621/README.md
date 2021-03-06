[19621번: 회의실 배정 2](https://www.acmicpc.net/problem/19621)

## 사고의 흐름

간단한 dp문제이다. dp문제는 늘 어떻게 푸는지 생각해내지 못하고 있다. 연습이 필요한 것 같다.

어떤 회의를 할 때 중요한 점은 앞서 했던 회의 중에서 가장 가치가 높은 회의를 이어받아야 한다는 점이다. 바로 앞, 바로 뒤 회의를 제외한 모든 회의와 시간이 곂치지 않는다는 조건으로 인해 이 문제를 푸는 데 회의의 시작 시간과 종료 시간은 고려되지 않는다. 

따라서 바로 앞 회의를 제외한 회의 중 인원 합이 높은 회의에 자신의 회의 인원을 더한 값을 dp에 저장한다. 즉 회의가 진행될 때 마다 dp에 인원이 누적되는 것이다.

예제)

```
6
10 40 80
30 60 60
50 80 70
70 100 100
90 120 40
110 140 50
```

인원 수만 적어본다면 80 60 70 100 40 50이다.

첫번째 회의는 앞선 회의가 없으므로 80이다.

두번째 회의는 바로 앞 회의를 제외한 회의가 없으므로 60이다.

세번째 회의는 바로 앞 두번째 회의를 제외한 가장 높은 인원을 가진 회의가 80이다. 80에 세번째 회의 인원 70을 더한 150이 저장된다.

네번째 회의는 바로 앞 세번째 회의를 제외한 회의는 80이다. 80+100 = 180이다.

다섯번째 회의는 네번째를 제외하고 세번째 회의의 dp값인 150이다. 150+40 = 190이다.

여섯번째 회의는 다섯번째를 제외하고 네번째 회의의 dp값인 180이다. 180+50 = 230이다.

6개의 dp값 중 가장 높은 값은 230이고 정답이 된다. 

아래는 코드이다.

```cpp
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
```
