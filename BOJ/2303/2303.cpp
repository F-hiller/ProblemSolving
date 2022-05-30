#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTS 100100
#define max(a, b) (a>b?a:b)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int first;
	int second;
}element;
int main() {
	//init
	int n, itemp;
	int output = -1;
	int outputIndex = 0;
	int arr[1002][5];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) { 
			scanf("%d", &arr[i][j]); 
		}
		int result = -1;
		result = max(result, (arr[i][0] + arr[i][1] + arr[i][2]) % 10);
		result = max(result, (arr[i][0] + arr[i][1] + arr[i][3]) % 10);
		result = max(result, (arr[i][0] + arr[i][1] + arr[i][4]) % 10);
		result = max(result, (arr[i][0] + arr[i][2] + arr[i][3]) % 10);
		result = max(result, (arr[i][0] + arr[i][2] + arr[i][4]) % 10);
		result = max(result, (arr[i][0] + arr[i][3] + arr[i][4]) % 10);
		result = max(result, (arr[i][1] + arr[i][2] + arr[i][3]) % 10);
		result = max(result, (arr[i][1] + arr[i][2] + arr[i][4]) % 10);
		result = max(result, (arr[i][1] + arr[i][3] + arr[i][4]) % 10);
		result = max(result, (arr[i][2] + arr[i][3] + arr[i][4]) % 10);
		if (output <= result)
		{
			output = result;
			outputIndex = i;
		}
	}

	printf("%d", outputIndex + 1);

	return 0;
}

- C++

int main() {
	FastIO;
	//init
	int n, itemp;
	cin >> n;
	vector<int> vtemp;
	int result = -1;
	int resultIndex = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> itemp;
			vtemp.push_back(itemp);
		}
		vector<int> mem;
		mem.push_back((vtemp[0] + vtemp[1] + vtemp[2]) % 10);
		mem.push_back((vtemp[0] + vtemp[1] + vtemp[3]) % 10);
		mem.push_back((vtemp[0] + vtemp[1] + vtemp[4]) % 10);
		mem.push_back((vtemp[1] + vtemp[2] + vtemp[3]) % 10);
		mem.push_back((vtemp[1] + vtemp[2] + vtemp[4]) % 10);
		mem.push_back((vtemp[2] + vtemp[3] + vtemp[4]) % 10);
		mem.push_back((vtemp[0] + vtemp[2] + vtemp[3]) % 10);
		mem.push_back((vtemp[0] + vtemp[2] + vtemp[4]) % 10);
		mem.push_back((vtemp[0] + vtemp[3] + vtemp[4]) % 10);
		mem.push_back((vtemp[1] + vtemp[3] + vtemp[4]) % 10);
		int output = mem[0];
		for (int j = 1; j < mem.size(); j++) { if (mem[j] > output) { output = mem[j]; } }
		if (output>=result)
		{
			result = output;
			resultIndex = i;
		}
		vtemp.clear();
	}
	cout << resultIndex + 1;
	return 0;
}
