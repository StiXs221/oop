//#pragma once
#ifndef NEUTRALOBJECT_H
#define NEUTRALOBJECT_H

#include "Field.h"

using namespace std;

enum NeutralObject_ID { Health_ID = 0, Armor_ID, Killer_ID, Freezer_ID, NO_ID };

class NeutralObject {
public:
	virtual ~NeutralObject() = default;
	virtual void operator+=(Warrior* w) = 0;
	virtual string getNeutObjType() = 0;
	NeutralObject* create(NeutralObject_ID id);     //��������� �����
};

class HealthReplenishment : public NeutralObject {      //���������� ��������
public:
	string getNeutObjType() override;
	void operator+=(Warrior* w) override;

};

class ArmorReplenishment : public NeutralObject {  //���������� �����
public:
	string getNeutObjType() override;
	void operator+=(Warrior* w) override;

};

class Killer : public NeutralObject {  //�������� �������� �� ���� ����� ����� ���������� ����� 5
public:
	string getNeutObjType() override;
	void operator+=(Warrior* w) override;

};

class Freezer : public NeutralObject {  //���� �� ����� ��������� �� ���������� 2 �����
public:
	string getNeutObjType() override;
	void operator+=(Warrior* w) override;

};

#endif