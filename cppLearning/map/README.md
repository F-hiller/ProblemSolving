```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
	/* : map의 특징
	map은 파이썬의 dictionary와 유사하다.
	set과 함께 연관 컨테이너에 속한다.
	map은 (key, value)의 pair객체를 원소를 가지며 모든 key는 유일하다는 특징이 있다. first는 key, second는 value를 저장한다.
	정렬은 기본적으로 key의 값을 기준으로 less정렬된다.
	*/
  
	map<int, int> m;
	m.insert(pair<int, int>(5, 100)); //임시 pair객체를 생성 후 m에 저장하게 된다.

	pair<int, int> pr(9, 50);
	m.insert(pr); //임시 객체 대신 pr 객체를 생성 후 저장하는 방식도 가능하다.
	/* : map의 활용*/
	pair<map<int, int>::iterator, bool> pr2; 
	pr2 = m.insert(pair<int, int>(5, 100)); //set의 insert()반환값과 유사하다.
	m[5] = 30; //[]연산자를 통해 key에 접근하고 =를  통해 value의 값을 변경할 수 있다.
	//iter가 가리키는 내용이 객체라면(여기의 경우 pair객체) ->연산자를 통해 first, second와 같은 곳에 접근할 수 있다.
	map<int, int, greater<int>> m; //이 경우 key의 값을 기준으로 greater정렬된다.
	//find(), lower_bound(), upper~(), equal_range()모두 set에서의 동작과 유사하다.
	

	/* : multimap의 특징
	중복된 키(key)를 저장할 수 있도록 지원하는 map이다.
	*/
	multimap<int, int> mm;
	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(5, 70)); //key값은 같지만 value가 다르다.
	//multi라는 점에서 set과 multiset의 관계를 가지고 있다.
	return 0;
}
```
