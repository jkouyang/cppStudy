/*Day10
���һ��Բ�࣬һ�����࣬�жϵ��Բ�Ĺ�ϵ
*/

#include<iostream>
#include"math.h"
using namespace std;
class Point_10 {//����
private:
	double x;
	double y;
public:
	double getX() {//��ȡx
		return this->x;
	}
	double getY() {//��ȡy
		return this->y;
	}
	void setX(double x) {//����x
		this->x = x;
	}
	void setY(double y) {//����y
		this->y = y;
	}
};

class Circle_10 {//Բ��
private:
	double r;//�뾶
	Point_10 PointCenter;//Բ��
public:
	double getR() {//��ȡ�뾶
		return r;
	}
	Point_10 getPointCenter() {//��ȡԲ��
		return PointCenter;
	}
	void setR(double r) {//���ð뾶
		this->r = r;
	}
	void setPointCenter(Point_10 PointCenter) {//����Բ��
		this->PointCenter = PointCenter;
	}
};

int isonCircle(Point_10 &a,Circle_10 &b) {//�жϵ��Բ�Ĺ�ϵ
	double a_point_x = a.getX();
	double a_point_y = a.getY();
	double b_point_x = b.getPointCenter().getX();
	double b_point_y = b.getPointCenter().getY();
	double distance = sqrt(pow((a_point_x - b_point_x), 2) + pow((a_point_y - b_point_y), 2));//�����������
	if (distance > b.getR()) {
		cout << "����Բ��" << endl;
		return -1;//Բ��
	}
	else if(distance < b.getR()) {
		cout << "����Բ��" << endl;
		return 1;//Բ��
	}
	else {
		cout << "����Բ��" << endl;
		return 0;//Բ��
	}
}

//void main() {
//	//ʵ������
//	Point_10 point;
//	point.setX(13);
//	point.setY(14);
//	//ʵ����Բ
//	Circle_10 circle;
//	circle.setR(5);
//	Point_10 pointceter;
//	pointceter.setX(10);
//	pointceter.setY(10);
//	circle.setPointCenter(pointceter);
//	//�жϵ��Բ�Ĺ�ϵ
//	int set = isonCircle(point, circle);
//	
//}
