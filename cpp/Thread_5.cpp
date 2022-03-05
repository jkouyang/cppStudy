/*ԭ�Ӳ���	automic

	ԭ�Ӳ���ָ�����ɷָ�Ĳ�������Ҳ����˵���ֲ���״̬Ҫô����ɵģ�Ҫô��û��ɵ�
	�������ļ���һ�������һ������Σ���ԭ�Ӳ�����Ե�һ�㶼��һ������
	automic��һ��ģ���࣬ʹ�ø�ģ����ʵ�����Ķ����ṩ��һЩ��֤ԭ���Եĳ�Ա������ʵ�ֹ������ݵĳ��ò���
*/

#include <atomic>
#include <thread>
#include <iostream>
//using namespace std;

std::atomic<int> count = { 0 };
void testThread_5() {
	std::thread t1([]() {
		count.fetch_add(1);
	});
	std::thread t2([]() {
		count++; // �ȼ��� fetch_add
		count += 1; // �ȼ��� fetch_add
	});
	t1.join();
	t2.join();
	std::cout << count << std::endl;
}

//void main() {
//	testThread_5();
//}
