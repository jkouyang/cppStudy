/*Day03
�������̽ṹ
    ˳��ṹ
    ѡ��ṹ��
            if��else if��else

            ��Ŀ���㣺���ʽ1?���ʽ2:���ʽ3     ������ʽ1Ϊ�棬ִ�б��ʽ2���������������ʽ1Ϊ�٣�ִ�б��ʽ3�����ؽ��

            switch��ע�ⲻ��breakʱswitch����ӵ�һ����ȷ��case��������ִ�С�
                    switchִ��ʱ�жϵ�ֻ�������ͻ����ַ��ͣ�������һ������
                    switch��ִ��Ч�ʱ�if��
                    switch(���ʽ){
                        case ���1��ִ�����;break;
                        case ���2��ִ�����;break;
                        case ���3��ִ�����;break;
                        default:ִ�����;break;

                    }

    ѭ���ṹ��
            while
                while(ѭ������){
                    ѭ�����}  //ѭ������Ϊ��ʱ��һֱִ��

            do while
                do{
                ѭ�����}
                while(ѭ������)��//��ִ��ѭ����䣬���ж�ѭ��������ע��while��Ҫ�ӷֺţ�

            for
                for(��ʼ���ʽ��ѭ��������ĩβѭ����){ѭ�����}
    
    ��ת��䣺break; ����ѭ���ṹ��switchѡ��ṹ
              continue;��ѭ���������������ѭ����������δִ�е���䣬����ִ����һ��ѭ��
              goto;�����ǵ����ƴ��ڣ�ִ�е�goto���ʱ������ת����ǵ�λ��

*/

#include <iostream>
#include <string>
using namespace std;

void Day03_if()
{
    int a = 10;
    int b = 0;
    cout << "������b" << endl;
    cin >> b;
    if (a > b){
        cout << "�ϴ������" << a << endl;
    }
    else {
        cout << "�ϴ������" << b << endl;    
    }
    int c = a > b ? a: b;//��Ŀ����
    cout << "c��" << c << endl;


}

void Day03_for_continue() {
    //�����ͼ
    cout << endl << "�����ͼ" << endl;
    for (int i = 0; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        for (int j = 0; j <= i; j++) {
            cout << " *";
        }
        cout << endl;
    }
}


void Day03_goto() {
    cout << "1.xx" << endl;
    cout << "2.xx" << endl; 
    goto flag;//����ת����ǵ�λ�ý���ִ��
    cout << "3.xx" << endl;
    cout << "4.xx" << endl;
    flag:
    cout << "5.xx" << endl;
    cout << "6.xx" << endl;

}

//void main()
//{
//    //Day03_if();
//    //Day03_for_continue();
//    Day03_goto();
//}