//#pragma once
#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
//#include "Warrior.h"
#include "Field.h"
#include "BaseIObserver.h"
#include "BaseFlyWeight.h"

class Base : public IObserver{
public:
	Base(int size, char type, LoggerProxy* logger);
	~Base();
	void createOrcsBase(int G, Field& f1);   //�� ��������� ������� ����� �����������
	void addInOrcsBase(string& character, Field& f1, int G);
	void createMEBase(int G, Field& f1); //�� ��������� ������� ������ ��������
	void addInMEBase(string& character, Field& f1, int G);
	void updateNotify(Subject* s) override;
	void printBaseCondition();      //������ ��������� ����

private:
	std::vector <Warrior> vOrcs;
	std::vector <Warrior> vME;
	char typeOfBase;   // 'o' - ���� �����, 'm' - ���� ����� � ������
	int sizeOfField;
	int baseHealth;
	int max;
	int currentOrcsNum;
	int currentMEnum;
	FlyweightUnitFactory fuf;
	LoggerProxy* logger;
};

#endif