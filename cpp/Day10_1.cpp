/*Day10
设计一个圆类，一个点类，判断点和圆的关系
*/

#include<iostream>
#include"math.h"
using namespace std;
class Point_10 {//点类
private:
	double x;
	double y;
public:
	double getX() {//获取x
		return this->x;
	}
	double getY() {//获取y
		return this->y;
	}
	void setX(double x) {//设置x
		this->x = x;
	}
	void setY(double y) {//设置y
		this->y = y;
	}
};

class Circle_10 {//圆类
private:
	double r;//半径
	Point_10 PointCenter;//圆心
public:
	double getR() {//获取半径
		return r;
	}
	Point_10 getPointCenter() {//获取圆心
		return PointCenter;
	}
	void setR(double r) {//设置半径
		this->r = r;
	}
	void setPointCenter(Point_10 PointCenter) {//设置圆心
		this->PointCenter = PointCenter;
	}
};

int isonCircle(Point_10 &a,Circle_10 &b) {//判断点和圆的关系
	double a_point_x = a.getX();
	double a_point_y = a.getY();
	double b_point_x = b.getPointCenter().getX();
	double b_point_y = b.getPointCenter().getY();
	double distance = sqrt(pow((a_point_x - b_point_x), 2) + pow((a_point_y - b_point_y), 2));//计算两点距离
	if (distance > b.getR()) {
		cout << "点在圆外" << endl;
		return -1;//圆外
	}
	else if(distance < b.getR()) {
		cout << "点在圆内" << endl;
		return 1;//圆内
	}
	else {
		cout << "点在圆上" << endl;
		return 0;//圆上
	}
}

//void main() {
//	//实例化点
//	Point_10 point;
//	point.setX(13);
//	point.setY(14);
//	//实例化圆
//	Circle_10 circle;
//	circle.setR(5);
//	Point_10 pointceter;
//	pointceter.setX(10);
//	pointceter.setY(10);
//	circle.setPointCenter(pointceter);
//	//判断点和圆的关系
//	int set = isonCircle(point, circle);
//	
//}
