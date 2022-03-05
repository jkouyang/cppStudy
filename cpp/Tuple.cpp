/*tuple	Ԫ�顪��������Ŷ����ͬ���͵�����(��ǿ��pair)

make_tuple: ����Ԫ��
get: ���Ԫ��ĳ��λ�õ�ֵ
tie: Ԫ����


1.tuple��ʼ��
	tuple<T1,T2,...Tn> tup;
	tuple<T1,T2,...Tn> tup(v1,v2,...vn);
	tuple(T1&) tup(tup1);
	make_tuple(v1,v2,...vn);

2.tuple�Ĳ���
	��ȡԪ�أ�
		2.1 get<ith>(tup)//��ȡ�±�Ϊi��Ԫ�أ�Ҫ��ithΪ������ֵ
		2.2 get<T>(tup)//��ȡ��������ΪT��Ԫ�أ�Ҫ��Ԫ����T����������ֻ��һ��
		2.3 tie(elem1,elem2,...elemn)=tup;//�����Ԫ����ÿ��Ԫ�ض�����
		2.4 tie(elem1,ignore,ignore,...)=tup;//�����������յ�Ԫ�ؿ���ignore
		2.5 tuple_cat(tup1,tup2);//�ϲ�����Ԫ��
		2.6 tuple_size<decltype(tup)>::value//��ȡtup���м�������
		2.7 tuple_element<1, decltype(tup)>::type//��ȡtuo���±�Ϊi�����ݽ��
*/

#include<iostream>
#include<string>
#include<tuple>
#include<variant>
using namespace std;

void testTuple() {
//1.Ԫ���ʼ��
	tuple<int, double, string> tup1;
	tuple<int, double, string> tup2(1,1.5,"hello");//С����()�ʹ�����{}����
	tuple<int, double, string> tup3(tup2);
	tuple<int, double, string> tup4 = make_tuple(1, 1.5, "hello");

//2.tuple�Ĳ���
	//2.1 get<ith>(tup)//��ȡ�±�Ϊi��Ԫ�أ�Ҫ��ithΪ������ֵ
	cout << "get<2>(tup2): " << get<2>(tup2) << endl;
		//int i=2;get<i>(tup2);//����
	
	//2.2 get<T>(tup)//��ȡ��������ΪT��Ԫ�أ�Ҫ��Ԫ����T����������ֻ��һ��
	cout << "get<double>(tup2): " << get<double>(tup2) << endl;

	//2.3 tie(elem1, elem2, ...elemn) = tup;//�����Ԫ����ÿ��Ԫ�ض�����
	int a; double b; string c;
	tie(a, b, c) = tup2;
	cout << a << " " << b << " "<< c << endl;

	//2.4 tie(elem1, ignore, ignore, ...) = tup;//�����������յ�Ԫ�ؿ���ignore
	int d; double e = 0.0; string f;
	tie(d, ignore, f) = tup2;
	cout << d << " " << e << " " << f << endl;

	//2.5 tuple_cat(tup1, tup2);//�ϲ����Ԫ��
	auto tup = tuple_cat(tup1, tup2, tup3, tup3);

	//2.6 tuple_size<decltype(tup)>::value//��ȡtup���м�������
	cout << "tup����" << tuple_size<decltype(tup)>::value << "������" << endl;
	
	//2.7 tuple_element<1, decltype(tup)>::type
	tuple_element<1, decltype(tup1)>::type aa;//��ȡtuo���±�Ϊi�����ݽṹ
	decltype(get<1>(tup1)) bb = aa;//get<1>(tup1)Ϊ���ʽ����õ�Ϊ��λ�õ���������
}

//void main() {
//	testTuple();
//}
