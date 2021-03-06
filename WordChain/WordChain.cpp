#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int numplayer;
int dice;

class Dice
{
	int select;
public:
	Dice()
	{
		cout << "주사위 종류를 선택해주세요>> " << endl;
		cout << "1.기본주사위(6)\n2.8면주사위" << endl;
		cin >> select;
	}

	void random() {
		if (select == 1) {
			dice = rand() % 6 + 1;
		}
		else if (select == 2)
		{
			dice = rand() % 8 + 1;
		}
	}

	void choice()
	{
		if (dice == 1)
			cout << "주사위 값 : " << dice << " | PASS 다음 플레이어 진행" << endl;
		else if (dice == 2)
			cout << "주사위 값 : " << dice << " | 2글자 입력" << endl;
		else if (dice == 3)
			cout << "주사위 값 : " << dice << " | 3글자 입력" << endl;
		else if (dice == 4)
			cout << "주사위 값 : " << dice << " | 4글자 입력" << endl;
		else if (dice == 5 || dice == 6)
			cout << "주사위 값 : " << dice << "자유롭게" << endl;
		else if (dice == 7)
			cout << "주사위 값 : " << dice << "조건없이 사자성어" << endl;
		else
			cout << "주사위 값 : " << dice << "아무 속담이나 적어주세요" << endl;
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
	string *pname;
public:
	void playernum()
	{
		cout << "몇명이 플레이 할지 입력해주세요:  ";
		cin >> numplayer;
	}

	void playeradd()
	{
		pname = new string[numplayer];
		for (int i = 0; i < numplayer; i++)
		{
			cout << "참가자의 이름을 입력해주세요>>";
			cin >> pname[i];
		}
	}

	void print()
	{
		cout << "시작 단어를 입력해주세요 : ";
	}
};

class WordChain : public Player, public Check
{
public:
	wstring start;
	wstring nword;
	int player = 1;
public:
	void startWordChain()
	{
		Player::playernum();
		Player::playeradd();
		Player::print();
		wcin >> start;
	}

	void continuegame()
	{
		wcout << "시작 단어는 " << start << "입니다" << endl;
		while (1)
		{
			if (player > numplayer)
				player = 1;
			cout << "Player" << pname[player-1] << "의 차례입니다>>" << endl;
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
						cout << pname[player - 1] << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "이 졌습니다" << endl;
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
						cout << pname[player - 1] << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "이 졌습니다" << endl;
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
						cout << pname[player - 1] << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "이 졌습니다" << endl;
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
						cout << pname[player - 1] << "이 졌습니다" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "이 졌습니다" << endl;
					break;
				}
			}

			else if (dice == 7 || dice ==8)
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
						cout << pname[player - 1] << "이 졌습니다" << endl;
						break;
					}
			}
		
		}
	}

};

class Penalty
{
	int penalnum;
	string *penalty;
	int penal;
public:
	
	void listofPenalty()
	{
		cout << "벌칙 리스트" << endl;
		cout << "몇개의 벌칙을 만들지 입력해주세요 >>";
		cin >> penalnum;
		cin.ignore();
		penalty = new string[penalnum];
		cout << "벌칙들을 입력해주세요" << endl;
		for (int i = 0; i < penalnum; i++)
		{
			cout << "벌칙" << i + 1 << ": ";
			getline(cin, penalty[i]);
		}
	}

	void print()
	{
		cout << "패배자의 벌칙은 \n: ";
		penal = rand() % penalnum;
		cout << penal+1 << "번 벌칙: " << penalty[penal];
	}
};

int main(void)
{
	int dlc;
	int penalt;
	srand((unsigned int)time(NULL));
	cout << "한글 끝말잇기  시작~~!" << endl;
	cout << "끝말잇기 DLC 추가 (설명을 원하신다면 1, 필요 없으시면 0을 입력해주세요)" << endl;
	cin >> dlc;

	if (dlc == 1)
	{
		cout << "----------------------------------------------------------" << endl;
		cout << "이번 DLC에는 8면 주사위를 추가했습니다!" << endl;
		cout << "주사위 7이 나올시 사자성어를 입력해야 합니다\n주사위 8이 나올시 속담 입력" << endl;
		cout << "----------------------------------------------------------" << endl;
	}

	cout << "벌칙을 추가하시겠습니까?" << endl;
	cout << "1.YES\t2.NO\t>>";
	cin >> penalt;
	Penalty p;

	if (penalt == 1)
	{
		p.listofPenalty();
	}

	WordChain word;
	word.startWordChain();
	word.continuegame();
	if (penalt == 1)
	{
		p.print();
	}
	return 0;
}