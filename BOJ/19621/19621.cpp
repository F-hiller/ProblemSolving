6
10 40 80
30 60 60
50 80 70
70 100 100
90 120 40
110 140 50

�ο� ���� ����ٸ� 80 60 70 100 40 50�̴�.

ù��° ȸ�Ǵ� �ռ� ȸ�ǰ� �����Ƿ� 80�̴�.

�ι�° ȸ�Ǵ� �ٷ� �� ȸ�Ǹ� ������ ȸ�ǰ� �����Ƿ� 60�̴�.

����° ȸ�Ǵ� �ٷ� �� �ι�° ȸ�Ǹ� ������ ���� ���� �ο��� ���� ȸ�ǰ� 80�̴�. 80�� ����° ȸ�� �ο� 70�� ���� 150�� ����ȴ�.

�׹�° ȸ�Ǵ� �ٷ� �� ����° ȸ�Ǹ� ������ ȸ�Ǵ� 80�̴�. 80+100 = 180�̴�.

�ټ���° ȸ�Ǵ� �׹�°�� �����ϰ� ����° ȸ���� dp���� 150�̴�. 150+40 = 190�̴�.

������° ȸ�Ǵ� �ټ���°�� �����ϰ� �׹�° ȸ���� dp���� 180�̴�. 180+50 = 230�̴�.

6���� dp�� �� ���� ���� ���� 230�̰� ������ �ȴ�. 

�Ʒ��� �ڵ��̴�.

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
