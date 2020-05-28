#pragma once
#include "Warrior.h"

class Elfs : public Warrior {

public:
	Elfs();
	~Elfs();
	void SetBoost(int boost);

private:
	int boost;                   //�������� ���� �� boost + 1, ����� ����� �� boost, �������� ��������� ����������

};

//------------------------------------------------------

class Archer : public Elfs {        //������
public:
	Archer();
	~Archer();
	int GetCounter();
	void SetCounter(int counter);

private:
	int arr;                 //������� ���� �����, ������������ �������� ����� 2 ������ �� �������
	int counter;
};

//------------------------------------------------------

class Invisible : public Elfs {        //���������
public:
	Invisible();
	~Invisible();
	int GetCounter();
	void SetCounter(int counter);

private:
	int invis;             //���������� ��������� �� 1 ��� (����� ���� ������ ������ � �� ���� ������ ��������)
	int counter;
};