/*原子操作	automic

	原子操作指“不可分割的操作”；也就是说这种操作状态要么是完成的，要么是没完成的
	互斥量的加锁一般是针对一个代码段，而原子操作针对的一般都是一个变量
	automic是一个模板类，使用该模板类实例化的对象，提供了一些保证原子性的成员函数来实现共享数据的常用操作
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
		count++; // 等价于 fetch_add
		count += 1; // 等价于 fetch_add
	});
	t1.join();
	t2.join();
	std::cout << count << std::endl;
}

//void main() {
//	testThread_5();
//}
