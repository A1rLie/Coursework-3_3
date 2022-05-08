#pragma once
#include "Base.h"
class Cl3 : public Base
{
public:
	int currentClass = 3;

	Cl3(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 3; };

	//����� ������ �������
	void Signal(string name);

	//����� ������ ��������� �����������
	void Handler(string msg, Base* from);
};

