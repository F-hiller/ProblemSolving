```cpp
#include <iostream>
#include <list>
using namespace std;

bool Predicate1(int n) { // lt.remove_if(Predicate1)에 사용되는 bool타입 함수류이다. 조건자로 사용된다.
	return 10 <= n && 30 >= n;
}

bool Predicate2(int first, int second) { // lt.unique(Predicate2)에 사용. first는 현재 원소이다.
	return second-first<=0;
}

//*********************************************
bool Predicate3(int left, int right) { // lt.sort(Predicate3)에 사용. 책에서는 struct Greater{}를 만들어서 사용하던데 질문하고 싶다!!!
									   // lt1.merge(lt2, Predicate3)에서도 사용.
	return left > right;
} 
//*********************************************

int main() {
	/* : list의 특징
	리스트는 벡터와 마찬가지로 push_~(), pop_~(), front(), back(), insert(), erase()등을 지원한다.
	하지만 at()과 []를 지원하지 않아서 반복자의 연산(++ or --)을 통해 원소를 탐색할 수 있다.
	*/

	list<int> lt;
	lt.push_back(40);
	lt.push_back(30);
	lt.push_back(20);
	lt.push_back(10);
	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter) {
		cout << *iter << " ";
	}

	/* : list함수의 이용*/
	lt.remove(10); // list중 모든 정수 10의 값을 가지는 노드를 순차적으로 삭제한다. list만이 가지고 있다.
	lt.remove_if(); //predicate(단항 조건자)가 참인 모든 원소를 제거한다. 조건자는 bool타입의 함수류(함수, 함수 객체, 함수 포인터)를 포함한다.
	lt.remove_if(Predicate1);
	lt1.splice(iter, lt2); //lt1의 iter위치에 lt2를 삽입한다. 그 결과 lt2가 lt1으로 연결되면서 lt2는 비어있게된다.
	lt1.splice(iter1, lt2, iter2); //lt1의 iter1위치에 lt2의 iter2위치의 값을 삽입한다.
	lt1.splice(lt.end(), lt2, lt2.begin(), lt2.end()); //argument들을 차례대로 1~4라고 지칭한다면 1이 가리키는 위치에 2의 [3,4) 리스트를 잘라 붙인다.
	lt.reverse(); //생략
	lt.unique(); //인접한 원소들을 유일하게 만든다. ex) 10, 10, 10, 20, 30, 10, 40  -> 10, 20, 30, 10, 40
	lt.unique(Predicate2); //일반적이 unique와 다르게 Predicate2는 이항 조건자를 받으며 조건자가 참이면 원소를 유일하게 하는 것이 아니라 제거하는 특징이 있다.
	lt.sort(); //오름차순 정렬
	lt.sort(Predicate3); //조건자의 결과가 거짓이면 두 값을 교체한다. Predicate3와 같은 사용자 정의와 함께 greater<int>(), less<int>()도 사용가능하다.
	lt1.merge(lt2); //lt2를 lt1으로 오름차순 합병된다. 합병의 전제 조건이 lt1과 lt2 모두 오름차순으로 정렬되어있음을 가정하므로 정렬되어있지 않으면 오류가 난다.
					//lt2는 splice()와 마찬가지로 비어있게된다.
	lt1.merge(lt2, Predicate3); //합병을 Predicate3의 기준에 따라 합병한다. 전제도 lt1과 lt2 모두 Predicate3의 방식으로 정렬되있음을 가정한다.
								//sort()와 마찬가지로 Predicate3와 같은 사용자 정의와 함께 greater<int>(), less<int>()도 사용가능하다.
	
	return 0;
}
```
