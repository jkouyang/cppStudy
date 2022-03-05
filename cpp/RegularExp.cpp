/*正则表达式
* 
	特别字符	描述
	$			匹配输入字符串的结尾位置。
	(,)			标记一个子表达式的开始和结束位置。子表达式可以获取供以后使用。
	.			匹配除换行符 \n 之外的任何单字符。
	[			标记一个中括号表达式的开始。
	\			将下一个字符标记为或特殊字符、或原义字符、或向后引用、或八进制转义符。例如，n匹配字符 n。\n 匹配换行符。序列 \\ 匹配 '\' 字符，而 \( 则匹配 '(' 字符。
	ˆ			匹配输入字符串的开始位置，除非在方括号表达式中使用，此时它表示不接受该字符集合。
	{			标记限定符表达式的开始。
	\|			指明两项之间的一个选择。

*
	字符		描述
	*			* 等价于 {0,}，匹配前面的子表达式零次或多次。例如，foo* 能匹配 fo 以及 foooo
	+			+ 等价于 {1,}，匹配前面的子表达式一次或多次。例如，foo+ 能匹配 foo 以及 foooo，但不能匹配fo
	?			? 等价于 {0,1}匹配前面的子表达式零次或一次。例如，Your(s)? 可以匹配 Your 或 Yours 中的Your
	{n}			n 是一个非负整数，匹配确定的 n 次。例如，o{2} 不能匹配 for 中的 o，但是能匹配foo 中的两个 o
	{n,}		n 是一个非负整数。至少匹配 n 次。例如，o{2,} 不能匹配 for 中的 o，但能匹配foooooo 中的所有 o
	{n,m}		m 和 n 均为非负整数，其中 n 小于等于 m。最少匹配 n 次且最多匹配 m 次

* C++11 提供的正则表达式库操作 std::string 对象+模式 std::regex(正则表达式)
	regex_match，正则表达式要匹配整个字符串
		bool regex_match(str, regex);
		bool regex_match(str.beg(), str.end(), regex);
		bool regex_match(str, smatch, regex);
	regex_search，正则表达式可以匹配字符串中的一部分或全部
		bool regex_search(str, regex);
		bool regex_search(str.beg(), str.end(), regex);
		bool regex_search(str, smatch, regex);
		bool regex_search(str.beg(), str.end(), smatch, regex);

	regex_replace，用一个字符串替换源字符串中匹配正则表达式的那部分子串
		string regex_replace(str, regex, replaceStr);

* 利用smatch提取匹配()的字符串
	smatch result中存储[0]([0].first,[0].second),[1],[2]...，prefix()，suffix()
		smatch 的size	未匹配到：0，匹配到：正则表达式中的括号()数+1；
		下标0存放匹配到的整个字符串，下标i存放匹配到正则表达式中第i括号内内容

	result[0]存储匹配到的字字符串(整个正则表达式)
		result[0].first为匹配的字符串(第一个字符)在母字符串中的位置
		result[0].second为匹配的字符串结尾(最后一个字符的下一位)在母字符串中的位置
	result[i]存储正则表达式中第i括号内内容
		result[i].first为匹配的正则表达式中第i括号内内容(第一个字符)在母字符串中的位置
		result[i].second为匹配的正则表达式中第i括号内内容的结尾(最后一个字符的下一位)在母字符串中的位置

	result.prefix()	返回母字符串中在匹配字符前面的字符
	result.suffix()	返回母字符串中在匹配字符后面的字符
*/

#include<iostream>
#include<string>
#include<vector>
#include<regex>
using namespace std;

void testRegularExp_a() {
	string fnames[] = { "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt" };
	//在 C++ 中 \ 会被作为字符串内的转义符，为使 \. 作为正则表达式传递进去生效，需要对 \ 进行二次转义
	//语法：regex	变量名("正则表达式");——定义一个正则表达式变量
	regex txt_regex("[a-z]+\\.txt");//	\也行
	//语法：regex_match(字符串，正则表达式)——匹配返回true，不匹配返回false
	for (auto& fname : fnames){
		cout << fname << ": " << regex_match(fname, txt_regex) << std::endl;
	}
	cout << "==========================" << endl;
}

void testRegularExp_b(){//利用smatch提取匹配()的字符串
	string fnames[] = { "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt" };
	regex base_regex("([a-z]+)\\.(txt)");
	smatch base_match;
	for (const auto& fname : fnames) {
		if (regex_match(fname, base_match, base_regex)) {
			// smatch 的size为0未匹配到，或者正则表达式中的括号()数+1；
			// 下标0存放匹配到的整个字符串，下标i存放匹配到正则表达式中第i括号内内容
			if (base_match.size() == 2 + 1) {
				cout << "sub-match[0]: " << base_match[0].str() << endl;
				cout << "sub-match[1]: " << base_match[1].str() << endl;
				cout << "sub-match[2]: " << base_match[2].str() << endl;
			}
		}
	}
	cout << "==========================" << endl;


	string str = "Hello2022,Hello2021,Hello!";
	smatch result;
	regex pattern("([0-9]{4})");	//匹配四个数字,2022 2021

	//迭代器声明
	string::const_iterator iterStart = str.begin();
	string::const_iterator iterEnd = str.end();
	//将字符串中全面符合匹配的都输出，并记录在母字符串中的位置
	while (regex_search(iterStart, iterEnd, result, pattern)) {
		//smatch result中存储[0]([0].first,[0].second)，prefix()，suffix()
		//result[0]存储匹配到的字符
			//result[0].first为匹配的字符串(第一个字符)在母字符串中的位置
			//result[0].second为匹配的字符串结尾(最后一个字符的下一位)在母字符串中的位置
		//result.prefix()	返回母字符串中在匹配字符前面的字符
		//result.suffix()	返回母字符串中在匹配字符后面的字符
		cout << "Matched String:"<< result[0] << "\t";
		cout << "result.prefix():" << result.prefix() << "\t";
		cout << "result.suffix():" << result.suffix() << "\t";
		cout << "在母字符串中的位置:"<<result[0].first - str.begin() << endl;
		iterStart = result[0].second;//更新搜索起始位置,搜索剩下的字符串
	}
	cout << "==========================" << endl;
}

void testRegularExp_c() {//regex_match，regex_search，regex_replace
	string strEx = "/home/foruok/20160406_153259.log";
	regex re1("/home/.*/[0-9]{8}_[0-9]{6}\\.log");
	bool bMatch = regex_match(strEx, re1); // true
	cout << "regex_match: " << bMatch << '\n';
	bMatch = regex_search(strEx, re1); // true
	cout << "regex_search: " << bMatch << '\n';

	regex re2("[0-9]{8}_[0-9]{6}");
	bMatch = regex_match(strEx, re2); // false
	cout << "regex_match: " << bMatch << '\n';
	bMatch = regex_search(strEx, re2); // true
	cout << "regex_search: " << bMatch << '\n';

	string newStr = regex_replace(strEx, re2, "replaceStr");//匹配到的地方用新的字符串替换，并返回替换后的新字符串
	cout << "newStr: " << newStr << endl;
}

//void main() {
//	testRegularExp_a();
//	testRegularExp_b();
//	testRegularExp_c();
//}