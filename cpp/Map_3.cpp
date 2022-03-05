/*Map�����ɾ��

����ԭ�ͣ�
	1.insert(elem);//�������в���Ԫ��
		map[key] = value;//Ҳ�ɲ���Ԫ�أ�������
	2.erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
	3.erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�����
	4.erase(key);//ɾ��������ֵΪkey��Ԫ��
	5.clear();//�������Ԫ��
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void myPrintMap_3(map<int, string>& m) {
	for (map<int, string>::iterator pBegin = m.begin(); pBegin != m.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

void testMap_3() {
	map<int, string> m;
	//1.insert(elem);//�������в���Ԫ��
		//insert()�����ַ�ʽ���룬��Ҫ�ǶԵ�д�ķ�ʽ��ͬ
		// �Ƽ���1��2��
	//��һ�ַ�ʽ����
	m.insert(pair<int, string>(1, "��ɮ"));
	//�ڶ��ַ�ʽ����
	m.insert(make_pair(2, "�����"));
	//�����ַ�ʽ����
	m.insert(map<int, string>::value_type(3, "��˽�"));
	//�����ַ�ʽ����
	m[4] = "ɳɮ";//������ʹ��[]�ķ�ʽ���룬����map������key=4�����ݣ��Ḳ��ԭ��������
	
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//�ڶ��β���ͬ��ֵ������
	//���ֲ��뷽ʽֻ�е����ֻḲ��ԭ����ֵ�������Ķ����벻��ȥ(������)
	//[]�����������ݣ���ò�Ҫ������������
	//[]��������û�иü�ֵ��Ԫ��ʱ�������ü�ֵ
	m.insert(pair<int, string>(1, "ѾѾ"));
	m.insert(make_pair(2, "ѾѾ"));
	m.insert(map<int, string>::value_type(3, "ѾѾ"));
	m[4] = "ѾѾ";
	cout << m[10] << endl;//����key=10(û�иü�ֵ)������Ĭ��valueΪ��
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//2.erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
	m.erase(m.begin());
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//3.erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�����
	m.erase(m.begin(), ++m.begin());
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//4.erase(key);//ɾ��������ֵΪkey��Ԫ��
	m.erase(4);
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//5.clear();//�������Ԫ��
	m.clear();
	myPrintMap_3(m);
}

//void main() {
//	testMap_3();
//}
