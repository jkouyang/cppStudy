/*��������
* unordered_map/unordered_multimap �� unordered_set/unordered_multiset������ϣ��(ɢ�б�)ʵ��
  map/set���������ʵ��

*	map/set����ЩԪ���ڲ�ͨ�����������ʵ�֣�
	�����������ƽ�����ӶȾ�Ϊ O(log(size))
	�ڲ���Ԫ��ʱ�򣬻���� < �������Ƚ�Ԫ�ش�С���ж�Ԫ���Ƿ���ͬ����ѡ����ʵ�λ�ò��뵽������
	������������е�Ԫ�ؽ��б���ʱ���������ᰴ�� < ��������˳�����������
	�����������е�Ԫ���ǲ���������ģ��ڲ�ͨ�� Hash ��ʵ�֣����������Ԫ�ص�ƽ�����Ӷ�ΪO(constant)
	�ڲ����������ڲ�Ԫ��˳��ʱ���ܹ������������������
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void testUnorderedMS() {
	map<int, string> ormap{ {2,"Tom"},{3,"Mary"},{1,"Yang"} };
	unordered_map<int, string> unmap{ {2,"Tom"},{3,"Mary"},{1,"Yang"} };
	cout << "========map========" << endl;
	for (auto&& i : ormap) { cout << i.first << "\t" << i.second << endl; }
	cout << "===unordered_map===" << endl;
	for (auto&& i : unmap) { cout << i.first << "\t" << i.second << endl; }
	unordered_set<int> unset{ 1,3,2,5,4,6,9,7,8,0 };
	cout << unmap.at(2) << endl;
	cout << ormap[2] << endl;



	cout << unset.load_factor() << endl;
	cout << unmap.load_factor() << endl;
	cout << unset.max_load_factor() << endl;

	unset.rehash(32);
	unmap.rehash(20);
	unset.max_load_factor(0.001);
	cout << unset.bucket_count() << endl;
	cout << unmap.bucket_count() << endl;
	unset.rehash(64);
	unmap.rehash(8);
	cout << unset.bucket_count() << endl;
	cout << unmap.bucket_count() << endl;
	//cout << unmap.bucket({2, "Tom"}) << endl;


}

//void main() {
//	testUnorderedMS();
//}
