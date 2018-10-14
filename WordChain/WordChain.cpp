/*
20174673 �ѽ³�
�����ձ�
�켱�� ���� ����
�÷��̾� �� �Է� �� �÷��̾� 1 �������� ���� �ð�(���� ����)�ȿ� �ܾ �Է��ؾ��Ѵ�. �Է��� �ٸ� �÷��̾���� ������ ���Ǹ� ������
����� ���Ƿ� ��ġ������ ���� �ı� ����
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int numplayer;

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
		
		if (dice == 2)
			cout << "2����" << endl;
		else if (dice == 3)
			cout << "3����" << endl;
		else if (dice == 4)
			cout << "4����" << endl;
		else
			cout << "�����Ӱ�" << endl;
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

class Player
{
public:
	void playernum()
	{
		cout << "Enter how many players are going to play: ";
		cin >> numplayer;
	}
};

class WordChain : public Player, public Check
{
	wstring start;
	wstring nword;
	char last;
	char first;
public:
	void startWordChain()
	{
		Player::playernum();
		cout << "���� �ܾ �Է����ּ��� : ";
		wcin>> start;
	}
	void game()
	{
		
		int player=1;
		wcout << "���� �ܾ�� " << start << "�Դϴ�" << endl;
		while (1)
		{
			cout << "Player" << player << "�� �����Դϴ�>>";
			Check::Check();
			wcin >>nword;
			int length = start.length();
			if (dice == 2)
			{
				if( start.at(length-2)== nword.at(0) && start.at(length-1) == nword.at(1) && nword.length() == 4)
					{
					Check::Agree();
					if (agree == 1) 
					{
						start= nword;
						player++;
						continue;
					}
					else
					{
						cout << player << "�� �����ϴ�" << endl;
						break;
					}
					}
				else
				{
					cout << player << "�� �����ϴ�" << endl;
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
						cout << player << "�� �����ϴ�" << endl;
						break;
					}
				}
				else
				{
					cout << player << "�� �����ϴ�" << endl;
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
						cout << player << "�� �����ϴ�" << endl;
						break;
					}
				}
				else
				{
					cout << player << "�� �����ϴ�" << endl;
					break;
				}
			}
			else
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
						cout << player << "�� �����ϴ�" << endl;
						break;
					}
				}
				else
				{
					cout << player << "�� �����ϴ�" << endl;
					break;
				}
			}
			if (player == numplayer)
				player = 1;
		}
	}

};

int main(void)
{
	cout << "Welcome to WordChain!" << endl;
	WordChain word;
	word.startWordChain();
	word.game();
	return 0;
}