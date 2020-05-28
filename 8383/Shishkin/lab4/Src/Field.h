//#pragma once
#ifndef FIELD_H
#define FIELD_H

//#include "Warrior.h"
#include "Orcs.h"
#include "Men.h"
#include "Elfs.h"
#include "NeutralObject.h"
//#include "Landscape.h"
#include "UnitFactory.h"
#include "Cell.h"
#include "Proxy.h"
#include "Mediator.h"
//#include "Command.h"
#include "LoggerProxy.h"

class Proxy;
class Command;

using namespace std;

class Field {
public:
	Field();
	Field(int a, int numOfUnitsOnEachSide, LoggerProxy* logger);
	~Field();        //����������
	Field(const Field& f);        //����������� �����������
	Field(Field&& f);           //����������� �����������
	void mas();          //������� ������ cell
	void print();             //�������� ����
	void init(int numOfOrcs, int numOfElfs, int numOfMens);     //�������������� ����
	void moving(string& character, int direction);     //������� ���� character � ����������� direction
	string check(string& character);            //�������� �� ��, � ������� ����������� ����� ������ ���� character
	void unitsSpecAbil(int dir, Warrior w, int x, int y);    //����������� ����������� ������ � �����
	Warrior add(string& character, int coordx, int coordy);      //�������� ����
	void del(string& character);          //������� ����
	void changeCell(string& valuee, int x, int y);      //�������� �������� � ������ � ����������� (x; y)
	bool isCellFree(int x, int y);       //������ �� ������ � ����������� (x; y)
	string getValueInCell(int x, int y);   //���������� ��������, ���������� � cell[x][y]
	Cell** getCell();            //���������� ������
	int howManyMoves(string character);       //���������� ���������� �����, ������� ����� ������� ������
	void landscapeEffect();     //������ "����������� ������"
	void neutObjEffect();      //������ ����������� ��������
	int getSizeOfField();    //���������� ������ ����

private:
	int size;
	Cell** cell;

	Devourers dev;
	Robbers rob;

	Spearman sp;
	Wizard wiz;

	Archer ar;
	Invisible inv;

	int current1stPlayerUnits;         //������� ���������� ������ � 1-�� ������
	int current2ndPlayerUnits;         //������� ���������� ������ � 2-�� ������
	Mediator* med;
	LoggerProxy* logger;
};


#endif
