/*无序容器
* unordered_map/unordered_multimap 和 unordered_set/unordered_multiset——哈希表(散列表)实现
  map/set——红黑树实现

*	map/set，这些元素内部通过红黑树进行实现，
	插入和搜索的平均复杂度均为 O(log(size))
	在插入元素时候，会根据 < 操作符比较元素大小并判断元素是否相同，并选择合适的位置插入到容器中
	当对这个容器中的元素进行遍历时，输出结果会按照 < 操作符的顺序来逐个遍历
	而无序容器中的元素是不进行排序的，内部通过 Hash 表实现，插入和搜索元素的平均复杂度为O(constant)
	在不关心容器内部元素顺序时，能够获得显著的性能提升
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void testUnorderedMS() {
	map<int, string> ormap{ {2,"Tom"},{3,"Mary"},{1,"Yang"} };
	unordered_map<int, string> unmap{ {2,"Tom"},{3,"Mary"},{1,"Yang"} };
	cout << "========map========" << endl;
	for (auto&& i : ormap) { cout << i.first << "\t" << i.second << endl; }
	cout << "===unordered_map===" << endl;
	for (auto&& i : unmap) { cout << i.first << "\t" << i.second << endl; }
	unordered_set<int> unset{ 1,3,2,5,4,6,9,7,8,0 };
	cout << unmap.at(2) << endl;
	cout << ormap[2] << endl;



	cout << unset.load_factor() << endl;
	cout << unmap.load_factor() << endl;
	cout << unset.max_load_factor() << endl;

	unset.rehash(32);
	unmap.rehash(20);
	unset.max_load_factor(0.001);
	cout << unset.bucket_count() << endl;
	cout << unmap.bucket_count() << endl;
	unset.rehash(64);
	unmap.rehash(8);
	cout << unset.bucket_count() << endl;
	cout << unmap.bucket_count() << endl;
	//cout << unmap.bucket({2, "Tom"}) << endl;


}

//void main() {
//	testUnorderedMS();
//}
