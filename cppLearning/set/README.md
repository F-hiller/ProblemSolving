```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
	/* : set의 특징
	set은 key라고 불리는 원소를 저장하는 유일한 방법으로 insert() 멤버 함수를 제공한다.
	원소 하나하나는 set에서 유일하며 중복을 사용하고 싶다면 밑의 multiset을 사용해야 한다.
	*/
	set<int> s; //기본 정렬 기준은 less(오름차순)으로 정해져있다.

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter) {
		cout << *iter << " ";
	}
	
	/* : set의 활용*/
	set<int, greater<int>> s2; //내림차순 정렬로 set을 생성한다. 이 경우 조건자 또한 <int, greater<int>>로 수정해주어야한다.
	pair<set<int>::iterator, bool> pr;
	pr = s.insert(50); //insert()는 값을 넣은 위치와 중복여부를 pair형태로 반환해준다. 
					   //pr.first는 위치를 가리키는 반복자, pr.second는 중복여부를 bool타입으로 나타낸 것이다. if(true == pr.second)를 통해 활용할 수 있다.
	s.insert(pr.first, 85); //pr.first의 위치부터 85가 들어갈 수 있는 위치를 탐색하여 값을 삽입한다.
	set<int, less<int>>::key_compare l_cmp = s_less.key_comp(); 
	//set의 정렬 조건을 반환하는 조건자로 s_less의 정렬 조건(less<int>)을 l_cmp에 저장한다.l_cmp(10, 20);와 같은 구문을 통해 (10<20-bool타입)연산을 진행할 수 있다.
	//set에서는 key = value의 의미를 가져서 key_compare과 value_compare의 타입이 서로 같다.
	s.count(50); //정수 50이 s안에 몇개있는지 출력한다. set의 경우 결과가 무조건 1 또는 0이지만 연관 컨테이너의 특성상 제공된다.
	iter = s.find(30); //정수 30의 반복자를 반환한다.
	s.key_comp()(30, 50); //s의 정렬기준을 바탕으로 30과 50을 비교하여 bool값을 반환한다.
	iter = s.lower_bound(55); // 정수 55가 시작되는 곳의 위치를 반환한다.
	iter = s.upper_bound(55); // 정수 55가 끝나는 곳의 위치를 반환하며 55 다음 값의 위치와 같다.
	pair<set<int>::iterator, set<int>::iterator> iter_pair; 
	iter_pair = s.equal_range(30); //equal_range()함수는 위의 lower,upper를 통해 제공되는 반복자 쌍을 pair객체로 반환해준다.
								   //iter_pair.first는 lower_bound의 결과값, iter_pair.second는 upper_bound의 결과값을 의미한다.
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter) {
		cout << *iter << " ";
	} //이처럼 [first, second)구간을 탐색할 수 있다.
	

	/* : multiset의 특징
	중복된 원소를 저장할 수 있도록 지원하는 set이다.
	*/
	multiset<int> ms;
	multiset<int>::iterator iter0;
	ms.insert(50);
	iter0 = ms.insert(50); //multiset에서의 insert()는 pair형을 반환하지 않고 iterator로 삽입한 위치가 반환된다.
	ms.find(50); //첫번째로 나오는 정수 50의 위치를 iterator로 반환한다.

	return 0;
}
```
