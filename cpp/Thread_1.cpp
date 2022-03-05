/*�߳�
* thread�����Ƕ���Ϊһ����class thread
* �����߳�
    thread �߳���(�̺߳���ָ�룬����1������2��......�����ս������)
        ����thread first(GetSumThread_1, largeArrays.begin(),largeArrays.begin() + 2000, ref(result1));
            �����߳�first�����̵߳���GetSumThread_1()������
            largeArrays.begin(),largeArrays.begin() + 2000, ref(result1)ΪGetSumThread_1()�����Ĳ���
            ref(result1)Ϊ���ô��ݣ������ⲿ������Ȼ�����ô�����պ������н��

    join()      ��������
    detach()    ���̲߳��õȴ����߳�ִ����ϣ����������ϵ��һ�������ػ��߳���
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
using namespace std;

//�߳�Ҫ���������д������̺߳�����
void GetSumThread_1(vector<int>::iterator first, vector<int>::iterator last, int& result){
    result = accumulate(first, last, 0); //����C++��׼���㷨
}


void testThread_1() {
    vector<int> largeArrays;
    for (int i = 0; i < 10000; i++){
        if (i % 2 == 0)
            largeArrays.push_back(i);
        else
            largeArrays.push_back(-1 * i);
    }

    //���ö��߳�ʱ��д��
    int res;
    GetSumThread_1(largeArrays.begin(), largeArrays.end(), ref(res));
    cout << "res = " << res << endl;

    //���ö��߳�ʱ��д��
    int result1, result2, result3, result4, result5;
    thread first(GetSumThread_1, largeArrays.begin(),
        largeArrays.begin() + 2000, ref(result1)); //���߳�1
    thread second(GetSumThread_1, largeArrays.begin() + 2000,
        largeArrays.begin() + 4000, ref(result2)); //���߳�2
    thread third(GetSumThread_1, largeArrays.begin() + 4000,
        largeArrays.begin() + 6000, ref(result3)); //���߳�3
    thread fouth(GetSumThread_1, largeArrays.begin() + 6000,
        largeArrays.begin() + 8000, ref(result4)); //���߳�4
    thread fifth(GetSumThread_1, largeArrays.begin() + 8000,
        largeArrays.end(), ref(result5)); //���߳�5

    first.join(); //��ʱ���߳�(main())������ֱ�����߳�ִ�н�����
    second.join();
    third.join();
    fouth.join();
    fifth.join();

    int threadSum = result1 + result2 + result3 + result4 + result5; //���ܸ������̵߳Ľ��
    cout << "threadSum = " << threadSum << endl;
}

//void main(){ //���߳�
//    testThread_1();
//}