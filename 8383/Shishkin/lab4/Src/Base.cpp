#include "Base.h"

Base::Base(int size, char type, LoggerProxy* logger) {
	baseHealth = 0;
	max = 4;
	currentOrcsNum = 0;
	currentMEnum = 0;
	sizeOfField = size;
	typeOfBase = type;
	this->logger = logger;
}

Base::~Base() {

}

void Base::addInOrcsBase(string& character, Field& f1, int G) {
	if (currentOrcsNum >= max) {
		cout << "�� ���� ������������ ���������� ������!\n";
		system("pause");
		return;
	}

	Warrior w;
	for (int i = G - 3; i < G; i++) {
		bool isBreak = false;

		for (int j = G - 3; j < G; j++) {
			if (f1.isCellFree(i, j)) {
				w = f1.add(character, i, j);
				isBreak = true;
				break;
			}
		}

		if (isBreak) break;
	}

	*logger << "#BASE: ���������� �� ���� ����� ����� \"" << character << "\"" << Logger::Endl();

	w.addObserver(this);
	w.un = fuf.getUnitNum(vOrcs.size() - 1);
	vOrcs.push_back(w);

	baseHealth += 30;       //��� ���������� ������ ����� �������� ���� ������������� �� 30
	currentOrcsNum++;
}

void Base::createOrcsBase(int G, Field& f1) {
	string z = "###";
	for (int i = G - 4; i < G; i++) {
		f1.changeCell(z, i, G - 4);
	}
	for (int j = G - 3; j < G; j++) {
		f1.changeCell(z, G - 4, j);
	}

	*logger << "#BASE: ��������� ���� �����" << Logger::Endl();

	Warrior w;
	string ch = "OR";

	w = f1.add(ch, G - 1, G - 1);
	w.addObserver(this);
	w.un = fuf.getUnitNum(vOrcs.size() - 1);
	vOrcs.push_back(w);

	w = f1.add(ch, G - 2, G - 1);
	w.addObserver(this);
	w.un = fuf.getUnitNum(vOrcs.size() - 1);
	vOrcs.push_back(w);
	baseHealth = 80;     //����������� �� ���� = 20 + 2 ����� = 20 + 30*2 = 80 ��
	currentOrcsNum = 2;
	typeOfBase = 'o';
}

void Base::addInMEBase(string& character, Field& f1, int G) {
	if (currentMEnum >= max) {
		cout << "�� ���� ������������ ���������� ������!\n";
		system("pause");
		return;
	}

	Warrior w;

	for (int i = G - 3; i < G; i++) {
		bool isBreak = false;
		for (int j = 0; j < G - (G - 2); j++) {
			if (f1.isCellFree(i, j)) {
				w = f1.add(character, i, j);
				isBreak = true;
				break;
			}
		}

		if (isBreak) break;
	}

	*logger << "#BASE: ���������� �� ���� ����� � ������ ����� \"" << character << "\"" << Logger::Endl();

	w.addObserver(this);
	w.un = fuf.getUnitNum(vME.size() - 1);
	vME.push_back(w);

	baseHealth += 30;       //��� ���������� ������ ����� �������� ���� ������������� �� 30
	currentMEnum++;
}

void Base::createMEBase(int G, Field& f1) {
	string z = "###";
	for (int i = G - 4; i < G; i++) {
		f1.changeCell(z, i, G - (G - 3));
	}
	for (int j = 0; j < G - (G - 3); j++) {
		f1.changeCell(z, G - 4, j);
	}

	Warrior w;
	string ch = "EA";

	*logger << "#BASE: ��������� ���� ����� � ������" << Logger::Endl();

	w = f1.add(ch, G - 1, 0);
	w.addObserver(this);
	w.un = fuf.getUnitNum(vME.size() - 1);
	vME.push_back(w);

	w = f1.add(ch, G - 2, 0);
	w.addObserver(this);
	w.un = fuf.getUnitNum(vME.size() - 1);
	vME.push_back(w);
	baseHealth = 80;
	currentMEnum = 2;
	typeOfBase = 'm';
}

void Base::updateNotify(Subject* s) {
	for (int i = 0; i < vOrcs.size(); i++) {
		if (s == &(vOrcs[i])) {
			vOrcs.erase(vOrcs.begin() + i);
			currentOrcsNum--;
			s->removeObserver(this);
			return;
		}
	}

	for (int i = 0; i < vME.size(); i++) {
		if (s == &(vME[i])) {
			vME.erase(vME.begin() + i);
			currentMEnum--;
			s->removeObserver(this);
			return;
		}
	}
}

void Base::printBaseCondition() {
	if (baseHealth == 0) {
		if (currentMEnum == 0 && typeOfBase == 'm') cout << "���� ����� � ������ ���\n";
		else if (currentOrcsNum == 0 && typeOfBase == 'o') cout << "���� ����� ���\n";
	}

	if (currentMEnum != 0 && typeOfBase == 'm') {
		cout << "�������� ���� ����� � ������: " << baseHealth << " HP\n";
		cout << "�� ���� " << currentMEnum << " ����� � ������:\n";
		for (int i = 0; i < vME.size(); i++) {
			cout << "�������� �� ���� " << vME[i].GetValue() << ": �������� - " << vME[i].GetHealth() <<
				", ����� - " << vME[i].GetArmor() << ", ���� - " << vME[i].GetDamage() << endl;
		}
	}

	if (currentOrcsNum != 0 && typeOfBase == 'o') {
		cout << "�������� ���� �����: " << baseHealth << " HP\n";
		cout << "�� ���� " << currentOrcsNum << " �����:\n";
		for (int i = 0; i < vOrcs.size(); i++) {
			cout << "�������� �� ���� " << vOrcs[i].GetValue() << ": �������� - " << vOrcs[i].GetHealth() <<
				", ����� - " << vOrcs[i].GetArmor() << ", ���� - " << vOrcs[i].GetDamage() << endl;
		}
	}
}
