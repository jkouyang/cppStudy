/*����������ί���
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
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

void myPrintGameScore(const deque<int>& deq) {//��const�����ô�����������ֻ������Ӧ�ĵ�����ҲҪ��Ϊconst_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	//cout << endl;
}

void GeneratePlayer() {
	string str = "ABCDE";
	string name = "����";
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
		cout << "\t���÷֣�";
		myPrintGameScore(Inf[i].scores);
		cout<< "\tƽ���÷֣�" << Inf[i].getAveScore() << endl;
	}
	
}

//void main() {
//	testGameScore();
//}
