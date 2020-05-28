#include "GameSingleton.h"

void GameSingleton::startGame() {
	int typeOfGame = 0;
	int size = 0;
	int numOfMen = 0;
	int numOfElfs = 0;
	int numOfOrcs = 0;
	bool isNewGame = false;
	do {
		system("cls");
		isNewGame = false;

		cout << "����� ��� ���� ��� ���������?\n1 - ���� ��� ���\n2 - ���� � ������\n";
		cin >> typeOfGame;
		if (cin.fail() || (typeOfGame != 1 && typeOfGame != 2)) {
			cout << "������ � ���������� ���� ����\n";
			return;
		}

		cout << "��� ���������� ������ ���������� �����, ������ � �����.\n";
		cout << "��� ��� � ���� 2 ������: ���� �� �����, � ������ �� ����� � ������, ��\n";
		cout << "���������� ����� � ������ ������ ��������������� ���������� �����.\n";
		if (typeOfGame == 2)
			cout << "(������ ����� �� ����� � ������, ������ - �� �����. 4 < ���-�� ����� < 10)\n\n";
		else if (typeOfGame == 1)
			cout << "(������ ����� �� ����� � ������, ������ - �� �����. 2 < ���-�� ����� < 10)\n\n";

		cout << "������� ���������� �����:\n";
		cin >> numOfMen;
		if (cin.fail() || numOfMen < 0) {
			cout << "������ � ���������� ���������� �����\n";
			return;
		}

		cout << "������� ���������� ������:\n";
		cin >> numOfElfs;
		if (cin.fail() || numOfElfs < 0) {
			cout << "������ � ���������� ���������� ������\n";
			return;
		}

		numOfOrcs = numOfElfs + numOfMen;

		if (typeOfGame == 2 && (numOfOrcs <= 4 || numOfOrcs >= 10)) {
			cout << "������ � ���������� ������\n";
			return;
		}
		else if (typeOfGame == 1 && (numOfOrcs <= 2 || numOfOrcs >= 10)) {
			cout << "������ � ���������� ������\n";
			return;
		}

		cout << "��������� ���� ������������ GxG. ������� G:\n";
		cin >> size;

		if (cin.fail()) {
			cout << "������ � ���������� ����������� ����\n";
			return;
		}
		if (typeOfGame == 2) {
			while (size <= numOfOrcs + 3) {
				cout << "G ������� �������! ��� ������ ���� ������ " << numOfOrcs + 3 << endl;
				cin >> size;
			}
		}
		else if (typeOfGame == 1) {
			while (size <= numOfOrcs + 1) {
				cout << "G ������� �������! ��� ������ ���� ������ " << numOfOrcs + 1<< endl;
				cin >> size;
			}
		}

		if (typeOfGame == 1) {
			RuleWithout* rule1 = new RuleWithout();
			gameWithout = new Game<RuleWithout>(numOfOrcs, numOfMen, numOfElfs, size, *rule1);
			delete gameWithout;
		}
		else if (typeOfGame == 2) {
			RuleWith* rule2 = new RuleWith();
			gameWith = new Game<RuleWith>(numOfOrcs, numOfMen, numOfElfs, size, *rule2);
			delete gameWith;
		}

		cout << "������ ����� ����?\n1 - ��\n2 - ���\n";
		int tmp = 0;
		cin >> tmp;
		if (cin.fail()) {
			cout << "������ ��� ������\n";
			return;
		}
		if (tmp == 1) {
			isNewGame = true;
		}
	} while (isNewGame);
}