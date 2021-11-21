```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	/*
	벡터와 유사한 성격을 가지는 string컨테이너
	*/
	string t("hello"); //임시 문자열
	string s;
  
	/*
	'\0'문자를 요구하지 않는다.

	s를 선언할 때 다음과 같은 경우들로 나뉜다.
	1) s(sz); //sz = 문자열
	2) s(sz, n); //문자열의 n번째까지만 저장
	3) s(n, c); //문자c를 n번 반복하여 저장
	4) s(iter1, iter2); //구간을 저장
	5) s(p1, p2); //포인터 p1과 p2저장
	*/

	s.append(t); //t는 string
	s.append(t, 0, 4); //t문자열의 0번째에서 길이4만큼 추가
	s.append(sz);
	s.append(sz, n);
	s.append(iter1, iter2);
	s.append(p1, p2);
	s.append(n, c);
	s += t;
	s += sz;
	s.push_back(c);

	s.assign()과 '='기호는 위에서 append, +=기호와 비슷한 방식으로 쓰인다.

	const char* sz;
	const char* buf;
	sz = s.c_str(); // '\0'이 포함되어있는 문자열
	buf = s.data(); // '\0'이 없는 문자열 배열. 인덱스를 사용한다.
	
	string s1("ABCDE");
	string s2("AKABC");
	//compare은 전체 문자열비교도 가능하지만 부분 문자열을 비교할 수 있는 특징이 있다.
	s1.compare(s2); //s1>s2, s1<s2, s1==s2의 경우에 따라 각각 1, -1, 0을 반환한다.
	s1.compare(2, 3, s2); //s1의 2번째 인덱스에서 길이 3만큼을 s2와 비교.(아마?)
	s1.compare(0, 3, s2, 2, 3); 
	s1.compare(sz);
	s1.compare(2, 3, sz);
	s1.compare(0, 1, sz, 1);

	//copy()또한 널문자를 포함하지 않는다.
	//length()는 size()와 같다.
	char buf[100];
	s.copy(buf, s.length());
	buf[s.length] = '\0'; //널문자를 직접 추가해줘야 한다.
	s.copy(buf, 4, 2); //2인덱스에서 길이 4만큼을 buf로 복사
	
	const char *sz = "~~~Randy~~~", "~~~~~~";
	string t("Randy");
	string s = sz;
	s.find(c);
	s.find(c, 250); //250은 시작위치
	s.find(sz);
	s.find(sz, 0); //0은 시작위치
	s.find(sz, 0, 1);
	s.find(t, 0);
	string::size_type pos = s.find("Not found");
	if() string::npos != pos //npos는 검색하는 문자나 문자열이 없다면 -1을 가진다.
	s.rfind('I'); //rfind()는 역방향 검색

	s.insert(1, sz); //s의 안덱스 1에 insert
	s.insert(1, sz, 2); //sz의 길이 2만큼을 insert
	s.insert(1, t); //다른 객체
	s.insert(1, t, 0, 2); //t의 0에서 길이 2
	s.insert(1, 3, c); // 인덱스 1에 c를 3번
	s.insert(iter); //아마 공백이 들어가는 것 같음
	s.insert(iter, c); //iter위치에 c를 넣음
	s.insert(iter, 3, c); //3번 반복하여 insert
	s.insert(iter, iter1, iter2); //iter위치에 1~2를 insert

	s1.replace(0, 3, sz); //s1의 인덱스0부터 길이3만큼 sz를 insert
	s1.replace(0, 3, t); 
	s1.replace(0, 3, sz, 2); //s1의 인덱스0부터 sz를 길이2만큼 insert
	s1.replace(0, 3, t, 0, 2); //t의 0에서 길이2만큼
	s1.replace(0, 3, 2, c); // c를 2번
	s1.replace(iter1, iter2, sz); //1~2구간을 sz로
	s1.replace(iter1, iter2, s); //s를
	s1.replace(iter1, iter2, sz, 2); //sz를 길이2만큼
	s1.replace(iter1, iter2, 3, c); //c를 3번
	s1.replace(iter1, iter2, iter3, iter4); //1~2에 3~4를

	string s;
	s = t.substr(0); //0~끝 문자열 추출
	s = t.substr(0, string::npos); //동일
	s = t.substr(0, 2); //0부터 2개
	s = t.substr(2, 3);
	s = t.substr(2, string::npos); //2부터 끝까지

	getlines(cin, s1); //한 줄 입력받는다.
	getline(cin, s1, '\n'); //'\n'문자가 나오면 종료한다.


	return 0;
}
```
