/*右值引用(R-value reference)
* 
* 左值右值的区分：
	lvalue 是 loactor value 的缩写，rvalue 是 read value 的缩写
	左值是指存储在内存中、有明确存储地址（可取地址）的数据；
	右值是指可以提供数据值的数据（不可取地址）；
	可以对表达式取地址（&）就是左值，否则为右值

	右值分为两种：纯右值，将亡值
	纯右值：非引用返回的临时变量、运算表达式产生的临时变量、原始字面量和 lambda 表达式等
	将亡值：与右值引用相关的表达式，比如，T&& 类型函数的返回值、 std::move 的返回值等。

* 右值引用——对一个右值进行引用的类型
语法：数据类型&& 别名 = 右值；
	因为右值是匿名的，只能通过引用的方式找到它
	左值引用和右值引用都要进行初始化，因为引用本身并不拥有对象的内存，只是该对象的一个别名
	右值引用的声明让这个临时值的生命周期得以延长、只要引用的变量还活着，那么该右值将继续存活。

* 右值引用的应用
	进行对象赋值操作的时候，很多情况下会发生对象之间的深拷贝，如果堆内存很大，这个拷贝的代价也就非常大
	在某些情况下，如果想要避免对象的深拷贝，就可以使用右值引用进行性能的优化

* move()可以无条件将左值转变为右值

* 注意
	左值引用可以引用左值
	右值引用可以引用右值
	常量左值引用可以引用左值+右值
	常量右值引用可以引用右值

	**右值引用是一个左值(int&& a = 10, 其中a为左值)
*/

#include<iostream>
#include<string>
#include<vector>
#include <functional>
using namespace std;

class moveRvalue {
public:
	vector<int>* pArray;
	moveRvalue() :pArray(new vector<int>(100)) {
		cout << "默认构造" << endl;
	}
	moveRvalue(moveRvalue& t) {//拷贝构造
		this->pArray = new vector<int>((*t.pArray).size());
		for (int i = 0; i < (*t.pArray).size(); i++) {
			(*this->pArray)[i] = (*t.pArray)[i];
		}
		cout << "拷贝构造" << endl;
	}

	//堆内存很大，利用移动构造避免深拷贝
	//传进来的t是一个右值(纯右值+将亡值)的话才会调用移动构造
	//传进来的t是一个左值仍然调用拷贝构造
	//如果没有定义移动构造，传入右值也会调用拷贝构造
	moveRvalue(moveRvalue&& t) :pArray(t.pArray) {//移动构造
		t.pArray = nullptr;
		cout << "移动构造" << endl;
	}

	~moveRvalue() {
		if (this->pArray != nullptr) {
			delete this->pArray;
			this->pArray = nullptr;
			cout << "析构函数执行释放空间" << endl;
		}
		cout << "析构函数该对象销毁" << endl;
	}
};

moveRvalue getmoveRvalue() {
	moveRvalue tt;
	return tt;
}

void testRvalue1() {
	moveRvalue mm;//默认构造
	moveRvalue nn(mm);//传入的mm是左值，调用拷贝构造
	moveRvalue hh(getmoveRvalue());//传入的getmoveRvalue()是右值，调用移动构造


	//注意
	int a = 10;
	int& b = a;//左值引用可以引用左值
	const int& c= a;//右值引用可以引用右值
	const int& d = 10;//常量左值引用可以引用左值 + 右值
	int&& e = 10;//常量左值引用可以引用左值 + 右值
	//const int&& f = a;//错误，常量右值引用不可以引用左值
	const int&& f = move(a);//move()可以无条件将左值转变为右值
	const int&& g = 10;//常量右值引用可以引用右值

}

void testRvalue2() {//移动语句
	string str = "hello world";
	vector<string> vect;

	// 将使用 push_back(const T&), 即产生拷贝行为
	//str的值不变
	vect.push_back(str);
	cout << "str: " << str << endl;
	cout<< "vect[1]: " << *vect.begin() << endl;

	// 将使用 push_back(const T&&), 不会出现拷贝行为
	// 而整个字符串会被移动到 vector 中，所以有时候 move() 会用来减少拷贝出现的开销
	// 这步操作后, str 中的值会变为空
	vect.push_back(move(str));
	cout << "str: " << str << endl;
	cout << "vect[1]: " << *vect.begin() << endl;
	cout << "vect[2]: " << *(vect.begin()+1) << endl;
}

//void main() {
//	testRvalue1();
//	testRvalue2();
//}