/*线程
* thread本质是定义为一个类class thread
* 创建线程
    thread 线程名(线程函数指针，参数1，参数2，......，接收结果参数)
        例：thread first(GetSumThread_1, largeArrays.begin(),largeArrays.begin() + 2000, ref(result1));
            创建线程first，该线程调用GetSumThread_1()函数，
            largeArrays.begin(),largeArrays.begin() + 2000, ref(result1)为GetSumThread_1()函数的参数
            ref(result1)为引用传递，先在外部创建，然后引用传入接收函数运行结果

    join()      阻塞函数
    detach()    主线程不用等待子线程执行完毕，两者脱离关系，一般用在守护线程上
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
using namespace std;

//线程要做的事情就写在这个线程函数中
void GetSumThread_1(vector<int>::iterator first, vector<int>::iterator last, int& result){
    result = accumulate(first, last, 0); //调用C++标准库算法
}


void testThread_1() {
    vector<int> largeArrays;
    for (int i = 0; i < 10000; i++){
        if (i % 2 == 0)
            largeArrays.push_back(i);
        else
            largeArrays.push_back(-1 * i);
    }

    //不用多线程时的写法
    int res;
    GetSumThread_1(largeArrays.begin(), largeArrays.end(), ref(res));
    cout << "res = " << res << endl;

    //采用多线程时的写法
    int result1, result2, result3, result4, result5;
    thread first(GetSumThread_1, largeArrays.begin(),
        largeArrays.begin() + 2000, ref(result1)); //子线程1
    thread second(GetSumThread_1, largeArrays.begin() + 2000,
        largeArrays.begin() + 4000, ref(result2)); //子线程2
    thread third(GetSumThread_1, largeArrays.begin() + 4000,
        largeArrays.begin() + 6000, ref(result3)); //子线程3
    thread fouth(GetSumThread_1, largeArrays.begin() + 6000,
        largeArrays.begin() + 8000, ref(result4)); //子线程4
    thread fifth(GetSumThread_1, largeArrays.begin() + 8000,
        largeArrays.end(), ref(result5)); //子线程5

    first.join(); //此时主线程(main())被阻塞直至子线程执行结束。
    second.join();
    third.join();
    fouth.join();
    fifth.join();

    int threadSum = result1 + result2 + result3 + result4 + result5; //汇总各个子线程的结果
    cout << "threadSum = " << threadSum << endl;
}

//void main(){ //主线程
//    testThread_1();
//}