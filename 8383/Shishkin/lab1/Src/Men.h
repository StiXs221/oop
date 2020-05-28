#pragma once
#include "Warrior.h"

class Men : public Warrior {

public:
	Men();
	~Men();
	void SetBoost(int boost);

private:
	int boost;                   //�������� ���� � ����� �� boost, �������� ����� �� boost

};

//------------------------------------------------------

class Spearman : public Men {        //����������
public:
	Spearman();
	~Spearman();
	int GetCounter();
	void SetCounter(int counter);

private:
	int barbecue;         //���� �� ������ ����� �� ����� ��� ���� ����, �� ���� ��������� �����
	int counter;
};

//------------------------------------------------------

class Wizard : public Men {        // ���
public:
	Wizard();
	~Wizard();
	int GetCounter();
	void SetCounter(int counter);

private:
	int range;         //����� ������� ����, ���������� �� 3, ����� �� ����� ����������
	int counter;
};
