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
#include <cstlib>

using namespace std;

int numplayer;
int cnt = 0;

int main(void)
{
	int time = 15;
	cout << "Welcome to WordChain!" << endl;
	
	
	


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
	string start, nword;
	char last, start;
public:
	WordChain()
	{
		cout << "���� �ܾ �Է����ּ��� : ";
		getline(cin, start);
		int length = start.length;
		last = start[length-1];
	}
	void game()
	{
		
		int player=1;
		cout << "���� �ܾ��" << start << "�Դϴ�" << endl;
		while (1)
		{
			cout << "Player" << player << "�� �����Դϴ�>>";
			if (player == numplayer)
				player == 1;
			player += 1;
			getline(cin, nword);
			Check::Check();
			if (dice == 1)
			{
				cout<< "Pass ���� ������ �����ϼ���" << endl;
			}
			else if (dice == 2)
			{
				if(last = nword[0] && nword.length == 3)
					{
					Check::Agree();
					start = nword;	
					continue;
					}
				else
				{
					cout << player-- << "�� �����ϴ�" << endl;
					break;
				}
			}
			else if (dice == 3)
			{
				if (last = nword[0] && nword.length == 2)
				{
					start = nword;
					continue;
				}
				else
				{
					cout << player-- << "�� �����ϴ�" << endl;
					break;
				}
			}
			else
			{
				if (last = nword[0])
				{
					start = nword;
					continue;
				}
				else
				{
					cout << player-- << "�� �����ϴ�" << endl;
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
			cout << "3����" << endl;
		else if (dice == 3)
			cout << "2����" << endl;
		else
			cout << "�����Ӱ�" << endl;
	}
	
};

class Check : public Dice
{
public:
	Check()
	{
		Dice::random();
		Dice::choice();
		
	}
	bool Agree()
	{
		int agree;
		cout << "Agree?\n1.Yes\n2.No" << endl;
		cin >> agree;
		if (agree == 1)
			return true;
		else
			return false;
	}
	

};