#pragma once
#include "Warrior.h"

class Orcs : public Warrior {

public:
	Orcs();
	~Orcs();
	void SetBoost(int boost);

private:
	int boost;            //�������� �������� � ����� �� �������� boost, � ����� ����� �� (boost + 1)

};

//------------------------------------------------------

class Devourers : public Orcs {        //����������
public:
	Devourers();
	~Devourers();
	int GetCounter();
	void SetCounter(int counter);

private:
	double percent;         //� ������������ x ��� ����� ���� ���������� �� 2 (�.�. ������� � ���� �� ����� ��� ���)
	int counter;
};

//------------------------------------------------------

class Robbers : public Orcs {         //����������
public:
	Robbers();
	~Robbers();
	int GetCounter();
	void SetCounter(int counter);

private:
	int around;            //���� ��������� ������� (� ���� � ���� ����� ������� 2 �����), �� �� ������� ���� ����
	int counter;
};
