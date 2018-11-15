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
int dice;

class Dice
{
	int select;
public:
	Dice()
	{
		cout << "�ֻ��� ������ �������ּ���>> " << endl;
		cout << "1.�⺻�ֻ���(6)\n2.8���ֻ���" << endl;
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
			cout << "�ֻ��� �� : " << dice << " | PASS ���� �÷��̾� ����" << endl;
		else if (dice == 2)
			cout << "�ֻ��� �� : " << dice << " | 2���� �Է�" << endl;
		else if (dice == 3)
			cout << "�ֻ��� �� : " << dice << " | 3���� �Է�" << endl;
		else if (dice == 4)
			cout << "�ֻ��� �� : " << dice << " | 4���� �Է�" << endl;
		else if (dice == 5 || dice == 6)
			cout << "�ֻ��� �� : " << dice << "�����Ӱ�" << endl;
		else if (dice == 7)
			cout << "�ֻ��� �� : " << dice << "���Ǿ��� ���ڼ���" << endl;
		else
			cout << "�ֻ��� �� : " << dice << "�ƹ� �Ӵ��̳� �����ּ���" << endl;
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
		cout << "����� �÷��� ���� �Է����ּ���:  ";
		cin >> numplayer;
	}

	void playeradd()
	{
		pname = new string[numplayer];
		for (int i = 0; i < numplayer; i++)
		{
			cout << "�������� �̸��� �Է����ּ���>>";
			cin >> pname[i];
		}
	}

	void print()
	{
		cout << "���� �ܾ �Է����ּ��� : ";
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
		wcout << "���� �ܾ�� " << start << "�Դϴ�" << endl;
		while (1)
		{
			if (player > numplayer)
				player = 1;
			cout << "Player" << pname[player-1] << "�� �����Դϴ�>>" << endl;
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
						cout << pname[player - 1] << "�� �����ϴ�" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "�� �����ϴ�" << endl;
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
						cout << pname[player - 1] << "�� �����ϴ�" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "�� �����ϴ�" << endl;
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
						cout << pname[player - 1] << "�� �����ϴ�" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "�� �����ϴ�" << endl;
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
						cout << pname[player - 1] << "�� �����ϴ�" << endl;
						break;
					}
				}
				else
				{
					cout << pname[player - 1] << "�� �����ϴ�" << endl;
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
						cout << pname[player - 1] << "�� �����ϴ�" << endl;
						break;
					}
			}
		
		}
	}

};

class Penalty :public Player
{
	int penalnum;
	string *penalty;
	int penal;
public:
	
	void listofPenalty()
	{
		cout << "��Ģ ����Ʈ" << endl;
		cout << "��� ��Ģ�� ������ �Է����ּ��� >>";
		cin >> penalnum;
		penalty = new string[penalnum];
		cout << "��Ģ���� �Է����ּ���" << endl;
		for (int i = 0; i < penalnum; i++)
		{
			cout << "��Ģ" << i + 1 << ": ";
			cin >> penalty[i];
		}
	}

	void print()
	{
		cout << "�й����� ��Ģ�� \n: ";
		penal = rand() % penalnum;
		cout << penal+1 << "�� ��Ģ: " << penalty[penal];
	}
};

int main(void)
{
	int dlc;
	int penalt;
	srand((unsigned int)time(NULL));
	cout << "�ѱ� �����ձ�  ����~~!" << endl;
	cout << "�����ձ� DLC �߰� (������ ���ϽŴٸ� 1, �ʿ� �����ø� 0�� �Է����ּ���)" << endl;
	cin >> dlc;

	if (dlc == 1)
	{
		cout << "----------------------------------------------------------" << endl;
		cout << "�̹� DLC���� 8�� �ֻ����� �߰��߽��ϴ�!" << endl;
		cout << "�ֻ��� 7�� ���ý� ���ڼ�� �Է��ؾ� �մϴ�\n�ֻ��� 8�� ���ý� �Ӵ� �Է�" << endl;
		cout << "----------------------------------------------------------" << endl;
	}

	cout << "��Ģ�� �߰��Ͻðڽ��ϱ�?" << endl;
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