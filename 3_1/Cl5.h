#pragma once
#include "Base.h"
class Cl5 : public Base
{
public:
	int currentClass = 5;

	Cl5(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 5; };

	//����� ������ �������
	void Signal(string name);
	//����� ������ ��������� �����������
	void Handler(string msg, Base* from);
};

