/*
20174673 한승남
끝말잇기
우선은 영어 버전
플레이어 수 입력 후 플레이어 1 시작으로 제한 시간(넣을 예정)안에 단어를 입력해야한다. 입력후 다른 플레이어들의 통합적 동의를 얻어야함
사실적 동의로 정치가능한 우정 파괴 게임
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int numplayer;
int cnt = 0;

int main(void)
{
	int time = 15;
	cout << "Welcome to WordChain!" << endl;
	Player::Player();
	WordChain::WordChain();
	WordChain wchain;
	wchain.game();
	}



class Player
{
	int temp = 1;
	int pnumber;
public:
	Player()
	{
		cout << "Enter how many players are going to play: ";
		cin >> numplayer;
	}
};


class WordChain : public Player, public Check
{
protected:
	char* start;
	char* nword;
	char last, first;
public:
	WordChain()
	{
		cout << "시작 단어를 입력해주세요 : ";
		cin>> start;
		int length = sizeof(start);
		last = start[length-1];
	}
	void game()
	{
		
		int player=1;
		cout << "시작 단어는" << start << "입니다" << endl;
		while (1)
		{
			cout << "Player" << player << "의 차례입니다>>";
			if (player == numplayer)
				player == 1;
			player += 1;
			cin>> nword;
			Check::Check();
			if (dice == 1)
			{
				cout<< "Pass 다음 선수가 진행하세요" << endl;
			}
			else if (dice == 2)
			{
				if(last = first && sizeof(nword)= 3)
					{
					Check::Agree();
					if (agree == 1) 
					{
						*start = *nword;
						continue;
					}
					else
					{
						cout << player-- << "이 졌습니다" << endl;
						break;
					}
					}
				else
				{
					cout << player-- << "이 졌습니다" << endl;
					break;
				}
			}
			else if (dice == 3)
			{
				if (last = nword[0] && sizeof(nword) == 2)
				{
					Check::Agree();
					if (agree == 1)
					{
						*start = *nword;
						continue;
					}
					else
					{
						cout << player-- << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << player-- << "이 졌습니다" << endl;
					break;
				}
			}
			else
			{
				if (last = nword[0])
				{
					Check::Agree();
					if (agree == 1)
					{
						*start = *nword;
						continue;
					}
					else
					{
						cout << player-- << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << player-- << "이 졌습니다" << endl;
					break;
				}
			}
		}
	}

};

class Dice
{
protected:
	int dice;
public:
	void random() {
		srand((unsigned int)time(NULL));
		dice = rand() % 6 + 1;
	}
	void choice()
	{
		if (dice == 1)
			cout << "Pass" << endl;
		else if (dice == 2)
			cout << "3글자" << endl;
		else if (dice == 3)
			cout << "2글자" << endl;
		else
			cout << "자유롭게" << endl;
	}
	
};

class Check : public Dice
{
protected:
	int agree;
public:
	Check()
	{
		Dice::random();
		Dice::choice();
		
	}
	bool Agree()
	{
		cout << "Agree?\n1.Yes\n2.No" << endl;
		cin >> agree;
		if (agree == 1)
			return true;
		else
			return false;
	}
	

};