[23306번: binary는 호남선](https://www.acmicpc.net/problem/23306)

## 사고의 흐름

처음 풀어보는 형태의 문제였다. 인터랙티브형 문제라고 해서 cout으로 어떤 내용을 출력하면 그 내용을 바탕으로 서버가 cin으로 입력해주는 형태의 문제였다. 문제 자체는 간단했다. 처음과 끝의 높이가 같다면 그 사이의 내리막과 오르막의 횟수가 같다는 의미를 지닌다. 즉, 처음과 끝의 높이 관계가 오르막과 내리막의 대소 관계로 이어진다는 것이다. 

```cpp
int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;

	cout << "? " << n << endl;
	cout << std::flush;
	cin >> input1;

	cout << "? " << 1 << endl;
	cout << std::flush;
	cin >> input2;

	cout << "! " << ((input1 == input2) ? 0 : (input1 > input2) ? 1 : -1) << endl;
	cout << std::flush;

	return 0;
}
```
