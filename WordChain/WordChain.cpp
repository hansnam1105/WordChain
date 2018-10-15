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
int dice;

class Dice
{
public:
	void random() {
		dice = rand() % 6 + 1;
	}
	void choice()
	{
		if (dice == 1)
			cout << "주사위 값 : " << dice << "PASS 다음 플레이어 진행" << endl;
		else if (dice == 2)
			cout << "주사위 값 : " << dice << "2글자" << endl;
		else if (dice == 3)
			cout << "주사위 값 : " << dice << "3글자"<< endl;
		else if (dice == 4)
			cout << "주사위 값 : " << dice << "4글자"<<endl;
		else
			cout << "주사위 값 : " << dice << "자유롭게"<< endl;
	}

};

class Check : public Dice
{
protected:
	int agree;
public:
	Check()
	{
	}
	void Diceroll()
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

class Player
{
public:
	void playernum()
	{
		cout << "몇명이 플레이 할지 입력해주세요:  ";
		cin >> numplayer;
	}
};

class WordChain : public Player, public Check
{
protected:
	wstring start;
	wstring nword;
public:
	void startWordChain()
	{
		Player::playernum();
		cout << "시작 단어를 입력해주세요 : ";
		wcin >> start;
	}
	void game()
	{
		int player = 1;
		wcout << "시작 단어는 " << start << "입니다" << endl;
		while (1)
		{
			if (player > numplayer)
				player = 1;
			cout << "Player" << player << "의 차례입니다>>" << endl;
			Check::Diceroll();
			if (dice == 1)
			{
				player++;
				continue;
			}
			fflush(stdin);
			wcin >> nword;
			int length = start.length();
			if (dice == 2)
			{
				if (start.at(length - 2) == nword.at(0) && start.at(length - 1) == nword.at(1) && nword.length() == 4)
				{
					Check::Agree();
					if (agree == 1)
					{
						start = nword;
						player++;
						continue;
					}
					else
					{
						cout << player << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << player << "이 졌습니다" << endl;
					break;
				}
			}
			else if (dice == 3)
			{
				if (start.at(length - 2) == nword.at(0) && start.at(length - 1) == nword.at(1) && nword.length() == 6)
				{
					Check::Agree();
					if (agree == 1)
					{
						start = nword;
						player++;
						continue;
					}
					else
					{
						cout << player << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << player << "이 졌습니다" << endl;
					break;
				}
			}
			else if (dice == 4)
			{
				if (start.at(length - 2) == nword.at(0) && start.at(length - 1) == nword.at(1) && nword.length() == 8)
				{
					Check::Agree();
					if (agree == 1)
					{
						start = nword;
						player++;
						continue;
					}
					else
					{
						cout << player << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << player << "이 졌습니다" << endl;
					break;
				}
			}
			else if(dice ==5 || dice ==6)
			{
				if (start.at(length - 2) == nword.at(0) && start.at(length - 1) == nword.at(1))
				{
					Check::Agree();
					if (agree == 1)
					{
						start = nword;
						player++;
						continue;
					}
					else
					{
						cout << player << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << player << "이 졌습니다" << endl;
					break;
				}
			}
		
		}
	}

};

int main(void)
{
	srand((unsigned int)time(NULL));
	cout << "한글 끝말잇기  시작~~!" << endl;
	WordChain word;
	word.startWordChain();
	word.game();
	return 0;
}