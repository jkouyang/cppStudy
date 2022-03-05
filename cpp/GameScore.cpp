/*案例——评委打分
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
*/

#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<stdlib.h>
#include <time.h>
using namespace std;

class GamePlayer {
public:
	string myName;
	deque<int> scores;
	double AveScore;
	GamePlayer() {}
	GamePlayer(string name, deque<int> scores) {
		this->myName = name;
		this->scores = scores;
		calAllScore();
	}
	double calAllScore() {
		sort(this->scores.begin(),this->scores.end());
		int allscore = 0;
		scores.pop_front();
		scores.pop_back();
		for (int i= 0; i < this->scores.size(); i++) {
			allscore += this->scores[i];
		}
		this->AveScore= double(allscore) / this->scores.size();
		return allscore;
	}

	double getAveScore() {
		return this->AveScore;
	}
};

vector<GamePlayer> Inf;

deque<int> Scoring(int a) {
	deque<int> deq;
	for (int i=0; i < 10; i++) {
		deq.push_back(rand()%41 + a);
		if (deq[i] > 100) {
			deq[i] = 100;
		}
	}
	return deq;
}

void myPrintGameScore(const deque<int>& deq) {//加const让引用传进来的容器只读，对应的迭代器也要改为const_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	//cout << endl;
}

void GeneratePlayer() {
	string str = "ABCDE";
	string name = "姓名";
	for (int i = 0; i < 5; i++) {
		
		GamePlayer temp_player(name+ str[i], Scoring(40+5*i));
		Inf.push_back(temp_player);
	}
}

void testGameScore() {
	srand((unsigned)time(NULL));
	GeneratePlayer();
	for (int i = 0; i < 5; i++) {
		cout << Inf[i].myName;
		cout << "\t各得分：";
		myPrintGameScore(Inf[i].scores);
		cout<< "\t平均得分：" << Inf[i].getAveScore() << endl;
	}
	
}

//void main() {
//	testGameScore();
//}
