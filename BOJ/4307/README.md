[4307번: 개미](https://www.acmicpc.net/problem/4307)

### 사고의 흐름

개미는 다른 개미와 만나면 반대 방향을 보고 나아간다. 이를 다르게 이해하여 다른 개미와 만났을 때 왔던 방향 그대로 나아간다고 생각하면 어떨까. 결과는 바뀌지 않는다. 

따라서 아래 두 가지 경우 중 짧은 시간과 긴 시간을 판단하고 다른 개미들과의 비교로 답을 구해낼 수 있다.

1. (개미의 위치)
2. (막대길이 - 개미의 위치)

```cpp
	cin >> t;
	for ( i = 0; i < t; i++)
	{
		cin >> len >> n;
		minvalue = 0;
		maxvalue = 0;
		for ( j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		for ( j = 0; j < n; j++)
		{
			far = max(arr[j], len - arr[j]);
			near = min(arr[j], len - arr[j]);
			result[j] = pii(near, far);
		}
		for ( j = 0; j < n; j++)
		{
			if (result[j].first > minvalue)
			{
				minvalue = result[j].first;
			}
			if (result[j].second > maxvalue)
			{
				maxvalue = result[j].second;
			}
		}
		cout << minvalue << " " << maxvalue << endl;
	}
```
