#include "Game.h"

//void Game::start() {
Game::Game() {
	int G;
	string st;         //����� ��� ���������� ���������� ���������� ������ ������������

	int numOfOrcs;
	int numOfMens;
	int numOfElfs;

	if (scan(numOfOrcs, numOfMens, numOfElfs, G) == 0) {
		cout << "������!\n";
		system("pause");
		return;
	}

	Base MEb(G, 'm');
	bool isMEbaseExist = false;     //����� �� ��������� ���� ��������
	Base b(G, 'o');
	bool isObaseExist = false;     //����� �� ��������� ���� ��������

	Field f1(G, numOfOrcs);
	f1.init(numOfOrcs, numOfElfs, numOfMens);

	int k = 0;
	//int direction;
	Iterator it(f1.getCell(), G, G);
	do {
		system("cls");
		st.clear();
		f1.print();
		int forAddAndDel = 0;


		//---------------------------------------------------------------------
		//       1-� �����
		//---------------------------------------------------------------------


		if (k % 2 == 0) {
			cout << "1-� �����, ��� ���:\n";
			cout << "������� ��������� �� ������ ��� �����:\n";
			cin >> st;

			if (st == "exit") break;

			else if (st == "add") {
				forAddAndDel = 1;
				if (!addUnit(f1)) continue;
			}

			else if (st == "del") {
				delUnit(f1);
				forAddAndDel = 1;
			}

			else if (st == "base") {
				forAddAndDel = 1;
				cout << "������� \"create\", ����� ������� ����, ���� \"add\", ����� �������� ����� � ����" << endl;
				cin >> st;

				if (st == "create" && !isMEbaseExist) {
					isMEbaseExist = true;
					MEb.createMEBase(G, f1, numOfOrcs);
				}

				else if (st == "add") {
					cout << "������� ����������� ���������, �������� �� ������ ��������:\n";
					string character;
					cin >> character;
					if (character != "MS" && character != "MW" && character != "EA" && character != "EI") {
						cout << "������������ ����������� ���������. �� ����������� ���!\n";
						system("pause");
					}
					else {
						MEb.addInMEBase(character, f1, G);
					}
				}
			}

			else
				while (st[0] == 'O') {
					cout << "�������! �� ������� �� ������ � �����!\n";
					cin >> st;
				}
		}


		//---------------------------------------------------------------------
		//       2-� �����
		//---------------------------------------------------------------------


		else {
			cout << "2-� �����, ��� ���:\n";
			cout << "������� ��������� �� �����:\n";
			cin >> st;
			if (st == "exit") break;
			else if (st == "add") {
				forAddAndDel = 1;
				if (!addUnit(f1)) continue;
			}
			else if (st == "del") {
				forAddAndDel = 1;
				delUnit(f1);
			}
			else if (st == "base") {
				forAddAndDel = 1;
				cout << "������� \"create\", ����� ������� ����, ���� \"add\", ����� �������� ����� � ����" << endl;
				cin >> st;
				if (st == "create" && !isObaseExist) {
					isObaseExist = true;
					b.createOrcsBase(G, f1, numOfOrcs);
				}
				else if (st == "add") {
					cout << "������� ����������� ���������, �������� �� ������ ��������:\n";
					string character;
					cin >> character;
					if (character != "OD" && character != "OR") {
						cout << "������������ ����������� ���������. �� ����������� ���!\n";
						system("pause");
					}
					else {
						b.addInOrcsBase(character, f1, G);
					}
				}
			}
			else
				while (st[0] == 'M' || st[0] == 'E') {
					cout << "�������! �� ������� �� �����!\n";
					cin >> st;
				}
		}

		//       ��� �� �����

		if (forAddAndDel == 0) {
			unitMove(f1, st);

			int numOfMoves = f1.howManyMoves(st);
			for (int l = 0; l < numOfMoves; l++) {
				f1.landscapeEffect();
				f1.neutObjEffect();
				cout << "�� ������ ������� ��� ���� ��� �� ������ ���������\n";
				string ch;
				cin >> ch;
				unitMove(f1, ch);
			}
		}
		f1.landscapeEffect();
		f1.neutObjEffect();

		k++;

		cout << "\n������� \"info\", ����� ������� ���������� � ������ � ����; ������� ��� ������, ����� ������ �� ��������\n";
		cin >> st;
		if (st == "info") {
			it.displayUnitData(f1);
			MEb.printBaseCondition();
			b.printBaseCondition();
			system("pause");
		}
	} while (st != "exit");

}

int Game::scan(int& numOfOrcs, int& numOfMens, int& numOfElfs, int& G) {
	cout << "��� ���������� ������ ���������� �����, ������ � �����.\n";
	cout << "��� ��� � ���� 2 ������: ���� �� �����, � ������ �� ����� � ������, ��\n";
	cout << "���������� ����� � ������ ������ ��������������� ���������� �����.\n";
	cout << "(������ ����� �� ����� � ������, ������ - �� �����. 4 < ���-�� ����� < 10)\n\n";

	cout << "������� ���������� �����:\n";
	cin >> numOfMens;
	if (cin.fail() || numOfMens <= 0) {
		return 0;
	}

	cout << "������� ���������� ������:\n";
	cin >> numOfElfs;
	if (cin.fail() || numOfElfs <= 0) {
		return 0;
	}

	numOfOrcs = numOfElfs + numOfMens;

	if (numOfOrcs <= 4 || numOfOrcs >= 10) return 0;

	cout << "��������� ���� ������������ GxG. ������� G:\n";
	cin >> G;

	if (cin.fail()) {
		return 0;
	}
	while (G <= numOfOrcs + 3) {
		cout << "G ������� �������! ��� ������ ���� ������ " << numOfOrcs + 3 << endl;
		cin >> G;
	}

	return 1;
}

void Game::unitMove(Field& f, string character) {
	int direction = 0;
	getchar();
	cout << "������� �����������:\n";
	string opportunity = f.check(character);

	cin >> direction;

	char tmp = direction + '0';
	int checker = 0;
	for (int i = 0; i < (int)opportunity.length(); i++) {
		if (opportunity[i] == tmp) checker = 1;
	}

	if (checker == 1) f.moving(character, direction);
	else {
		cout << "������ ����������� ���! �� ����������� ���!\n";
	}
}

bool Game::addUnit(Field& f) {
	cout << "������� ����������� ���������, �������� �� ������ ��������:\n";
	string character;
	cin >> character;
	getchar();
	if (character != "OD" && character != "OR" && character != "MS" && character != "MW" && character != "EA" && character != "EI") {
		cout << "������������ ����������� ���������. �� ����������� ���!\n";
		system("pause");
		return false;
	}
	else {
		f.add(character, -30, 0);
	}

	return true;
}

void Game::delUnit(Field& f) {
	cout << "������� ����������� ���������, �������� �� ������ �������:\n";
	string character;
	cin >> character;
	f.del(character);
}
