#include <iostream>
#include <iomanip>
#include "Warrior.h"
#include "Orcs.h"
#include "Men.h"
#include "Elfs.h"
#include "Field.h"
#include "Iterator.h"

using namespace std;

int scan(int& numOfOrcs, int& numOfMens, int& numOfElfs, int& G);

int main() {
	setlocale(LC_ALL, "RUS");

	int G;
	string st;

	int numOfOrcs;
	int numOfMens;
	int numOfElfs;

	if (scan(numOfOrcs, numOfMens, numOfElfs, G) == 0) {
		cout << "������!\n";
		system("pause");
		return 0;
	}
	cout << numOfOrcs << endl << numOfMens << endl << numOfElfs << endl << G << endl;

	Field f1(G);
	f1.init(numOfOrcs, numOfElfs, numOfMens);

	int k = 0;
	int direction;
	do {
		system("cls");
		st.clear();
		f1.print();
		int forAddAndDel = 0;
		if (k % 2 == 0) {
			cout << "1-� �����, ��� ���:\n";
			cout << "������� ��������� �� ������ ��� �����:\n";
			cin >> st;
			if (st == "exit") break;
			else if (st == "add") {
				forAddAndDel = 1;
				cout << "������� ����������� ���������, �������� �� ������ ��������:\n";
				string character;
				cin >> character;
				if (character != "OD" && character != "OR" && character != "MS" && character != "MW" && character != "EA" && character != "EI") {
					cout << "������������ ����������� ���������. �� ����������� ���!\n";
					system("pause");
				}
				else {
					f1.add(character);
				}
			}
			else if (st == "del") {
				forAddAndDel = 1;
				cout << "������� ����������� ���������, �������� �� ������ �������:\n";
				string character;
				cin >> character;
				f1.del(character);
			}
			else
			while (st[0] == 'O') {
				cout << "�������! �� ������� �� ������ � �����!\n";
				cin >> st;
			}
		}
		else {
			cout << "2-� �����, ��� ���:\n";
			cout << "������� ��������� �� �����:\n";
			cin >> st;
			if (st == "exit") break;
			else if (st == "add") {
				forAddAndDel = 1;
			}
			else if (st == "del") {
				forAddAndDel = 1;
				cout << "������� ����������� ���������, �������� �� ������ �������:\n";
				string character;
				cin >> character;
				f1.del(character);
			}
			else
			while (st[0] == 'M' || st[0] == 'E') {
				cout << "�������! �� ������� �� �����!\n";
				cin >> st;
			}
		}
		if (forAddAndDel == 0) {
			getchar();
			cout << "������� �����������:\n";
			string opportunity = f1.check(st);
			cin >> direction;

			char tmp = direction + '0';
			int checker = 0;
			for (int i = 0; i < opportunity.length(); i++) {
				if (opportunity[i] == tmp) checker = 1;
			}

			if (checker == 1) f1.moving(st, direction);
			else {
				cout << "������ ����������� ���! �� ����������� ���!\n";
				system("pause");
			}
		}
		k++;
	} while (st != "exit");

	system("pause");
	return 0;

}

int scan(int& numOfOrcs, int& numOfMens, int& numOfElfs, int& G) {
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
	while (G <= numOfOrcs - 1) {
		cout << "G ������� �������! ��� ������ ���� ������ " << numOfOrcs - 1 << endl;
		cin >> G;
	}

	return 1;
}
