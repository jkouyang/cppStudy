/*Day01
ע��:
����
������define,const
�ؼ���
��ʶ������ʶ����identifier����ָ������ʶĳ��ʵ���һ�����ţ��ڲ�ͬ��Ӧ�û������в�ͬ�ĺ��塣
        �ڼ������������У���ʶ�����û����ʱʹ�õ����֣����ڸ������������������������������
        �Խ�����������ʹ��֮��Ĺ�ϵ����ʶ��ͨ������ĸ�������Լ������ַ����ɡ�
�������ͣ����壺������������ʵ��ڴ�ռ䣩
    ���ͣ�short 2B (-32768`32767), int 4B, long 4B, long long 8B
    �����ͣ�float 4B (7Ϊ��Ч����)�� double 8B ��15-16λ��Ч���֣�
    �ַ��ͣ�char 1B ���ڴ��д洢����ASCII���룩�������š���������(int)char,���ASCII�룬A:65,a:97
            ת���ַ���\n ���У�\t ˮƽ�Ʊ��(���ã����ˮƽ����)��\\ ��б��
    �ַ����ͣ�char ������[]="�ַ���ֵ"��(C���Է��)
              string ������= "�ַ���ֵ"��(C++���)��Ҫ����ͷ�ļ���#include<string>
    �������ͣ�bool 1B��true(������1)��false(������0)
sizeof��sizeof(��������/����)��ͳ������������ռ�ڴ��С
*/



#include <iostream>//Ԥ����ָ����߱������ڳ�����Ҫ����C++��׼���������ͷ�ļ�
#include <string>//�ַ���ͷ�ļ�
using namespace std;//��׼�����ռ䣬��һЩʵ�壨�����������������ࣩ�������У��Խ��ͬ����ͻ����

#define Month 12 //define����곣���������޸�

void typeData(){

    const int Day = 7; //const���εı���ҲΪ�����������޸�
    cout << "һ����" << Month << "���£�һ����" << Day << "��" << endl;
    //coutΪ��׼�������<<Ϊ�������������endlΪ���������ӣ�������һ�����з���ˢ�����������


    //����
    int a = 0;
    cout << "����������a��" << endl;
    cin >> a;
    cout << "����a=" << a << endl;

    //������
    float f = 3.14f;//���嵥������ʱ����Ӹ�f����ֹ��������Ϊ����һ��˫����������ǿ��ת���ɵ�����
    cout << "�����븡����f��" << endl;
    cin >> f;
    cout << "������f=" << f << endl;

    //�ַ���
    char ch = 97;//ch='a';
    cout << "ch�ĳ�ʼֵ��" <<ch<< endl;
    cout << "�������ַ���ch��" << endl;
    cin >> ch;
    cout << "������ch=" << ch << endl;

    //�ַ�����
    char str0[] = "Hello";
    string str = "hello";
    cout << "str�ĳ�ʼֵ��" << str << endl;
    cout << "�������ַ�����str��" << endl;
    cin >> str;
    cout << "�ַ�����str=" << str << endl;
    cout << "�ַ�����str��ռ�ڴ�ռ�(B)��" << sizeof(str) << endl;


    //������
    bool flag = false;
    cout << "bool���ͳ�ʼֵ flag��"  << flag << endl;
    cout << "������bool���� flag��" << endl;
    cin >> flag;//��������������Ϊ1��true
    cout << "bool���� flag=" << flag << endl;

    system("pause");
}

//int main(){
//    typeData();
//    return 0;
//}