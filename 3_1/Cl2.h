#pragma once
#include "Base.h"
class Cl2 : public Base
{
public:

	Cl2(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 2; };

	//����� ������ �������
	void Signal(string name);

	//����� ������ ��������� �����������
	void Handler(string msg, Base* from);
};

