#pragma once
#include "Base.h"
class Cl4 : public Base
{
public:
	Cl4(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 4; };

	//����� ������ �������
	void Signal(string name);
	//����� ������ ��������� �����������
	void Handler(string msg, Base* from);
};

