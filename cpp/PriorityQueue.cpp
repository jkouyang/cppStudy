/*priority_queue	���ȶ���
��ʵ�֣�
	less<>��Ӧ�󶥶�
	greater<>��ӦС����

��Ͷ��л���������ͬ:
	top() ���ʶ�ͷԪ��
	empty() �����Ƿ�Ϊ��
	size() ���ض�����Ԫ�ظ���
	push() ����Ԫ�ص���β (������)
	emplace() ԭ�ع���һ��Ԫ�ز��������
	pop() ������ͷԪ��
	swap() ��������

���壺
	priority_queue<Type, Container, Functional>
		Type �����������ͣ�Container �����������ͣ�Functional���ǱȽϵķ�ʽ(Ĭ�ϴ󶥶ѣ���������)

*/

#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;
typedef pair<int, int> pii;

void testPriorityQueue() {
	//Ĭ�ϴ󶥶ѣ���������
	priority_queue<int> pq;
	pq.push(10);
	pq.push(7);
	pq.push(11);
	cout << pq.top() << " "; pq.pop();
	cout << pq.top() << " ";pq.pop();
	cout << pq.top() << endl;pq.pop();
	cout << endl;

	//greater<>С����
	priority_queue<pii, vector<pii>, greater<pii>> store;
	store.push(make_pair(10, 1));
	store.push(make_pair(7, 1));
	store.push(make_pair(11, 1));
	cout << store.top().first << " " << store.top().second << endl; store.pop();
	cout << store.top().first << " " << store.top().second << endl; store.pop();
	cout << store.top().first << " " << store.top().second << endl; store.pop();
	cout << endl;

	//�Զ�������
	function<bool(pii, pii)> mycomp = [](pii a, pii b) {return a.first > b.first; };
	priority_queue<pii, vector<pii>, function<bool(pii, pii)>> fque(mycomp);//�Զ�������
	/*	��������auto, decltype�������Ƶ�
	auto mycomp = [](pii a, pii b) {return a.first > b.first; };
	priority_queue<pii, vector<pii>, decltype(mycomp)> fque(mycomp);//�Զ�������
	*/
	fque.push(make_pair(10, 1));
	fque.push(make_pair(7, 1));
	fque.push(make_pair(11, 1));
	cout << fque.top().first << " " << fque.top().second << endl; fque.pop();
	cout << fque.top().first << " " << fque.top().second << endl; fque.pop();
	cout << fque.top().first << " " << fque.top().second << endl; fque.pop();
	
	//�Զ����������ͣ�����"<"��">"�������Զ����������
}

//int main() {
//	testPriorityQueue();
//	return 0;
//}