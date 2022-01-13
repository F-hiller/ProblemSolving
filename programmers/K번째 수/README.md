[코딩테스트 연습 - K번째수](https://programmers.co.kr/learn/courses/30/lessons/42748)

## 사고의 흐름

이중 for문으로 해결했다. 하지만 다른 사람들의 풀이 방식을 보니 vtemp.push_back부분을 없애고 vtemp = array;를 통해 진행하여 for문을 하나 없애는 경우도 있었다. 인덱스를 활용해 이렇게 만들수도 있구나에 대해 배웠다.

```cpp
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> vtemp;
	for (int i = 0; i < commands.size(); i++)
	{
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
		{
			vtemp.push_back(array[j]);
		}
		sort(vtemp.begin(), vtemp.end());
		answer.push_back(vtemp[commands[i][2] - 1]);
		vtemp.clear();
	}

	return answer;
}
```
