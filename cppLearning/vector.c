```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;//생성자를 통해 0(기본값)으로 초기화된 size가 5인 컨테이너 생성
	vector<int> v2(5, 2); //생성자를 통해 2로 초기화된 size가 5인 컨테이너 생성
	//vector<int> v2(v); //복사 생성자를 통해 v가 v2로 복사된다.

	//v.reserve(8);//언급한 만큼의 공간을 미리 할당. 넘어가면 현재 공간의 1/2 만큼의 추가 공간을 할당해줌.(컴파일러마다 다르다)

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	for (vector<int>::size_type i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	/* : 반복자 클래스(iterator)와 객체 +포인터와 비슷하다.*/
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " ";
	}
	*iter = 100; //이처럼 직접 수정도 가능하다.
	iter2 = v.insert(iter, 100); //iter2는 100이 저장된 위치를 가리킨다. iter위치에 정수 100이 들어간다.
	v.insert(iter, 3, 100); //정수 100이 iter위치부터 3개 들어간다.
	v.erase(iter); //iter위치의 값이 하나 사라지고 다음 위치를 반환한다.
	v.erase(v.begin()+1, v.end()); //1번 인덱스부터 end앞까지 원소를 지우고 end 위치를 반환한다.
	vector<int> v3(v.begin(), v.end()); //v의 begin부터 end까지의 값으로 v3를 초기화한다.
	v3.assign(v.begin(), v.end()); //위의 초기화 대신 할당한다.
	

	/* : resize()*/
	v.resize(10); //vector공간 추가 할당 또는 축소. v.capacity()는 증가할 수는 있어도 수치상 줄지는 않는다.
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	/* : 다양한 벡터 활용*/
	cout << typeid(vector<int>::size_type).name() << endl; //v.size()가 unsigned int를 반환하는 것을 해결하기 위한 내용.
	cout << v.size() << endl; //벡터의 크기
	cout << v.capacity() << endl; //벡터에 할당된 메모리 크기
	cout << v.max_size() << endl; //벡터의 최대 크기
	v.clear(); //벡터 비우기
	v.empty(); //벡터가 비었는지 확인 후 0과 1 반환.
	v.swap(v2);//두 벡터를 교체
	v.front() = 100; //v.front()자체로 첫번째 원소의 값을 가지지만 =연산자를 통해 값을 변경할 수 있다.
	v.at(n); //인덱스n의 값 참조. 속도는 느리지만 인덱스 범위를 미리 확인하여 오류(throw-catch)를 확인할 수 있기에 
			 // 인덱스 범위를 초과하여 프로그램이 터지는 걸 막을 수 있다.
	v.back(); //v.front()와 마찬가지이다. 
	v.assign(5, 2); //초기자 이외의 방식으로 값을 할당할 수 있다. n개 원소에 x값 저장. 나머지는 없어진다?.
	// 벡터에서의 비교연산은 값 전체의 비교이다. ==과 !=의 경우는 값 전체의 비교이고,
	// 부등호>의 경우는 같은 순서의 원소끼리 비교하며 답이 나올 수 있을 때 그 답을 출력한다.
	// vector는 배열의 앞을 이용하는 것의 효율이 낮다. 따라서 그 반대인 push_back(), pop_back()등이 제공된다.
	
	/* : Deque란 무엇인가
	deque는 vector와 거의 유사하며 차이점은 메모리 방식의 차이이다.
	vector 보다 효율적인 부분이 있으며 vector가 지원하지 않는 push_front(), pop_front()를 지원한다.
	*/
	return 0;
}
```
