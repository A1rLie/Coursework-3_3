#pragma once
#include "Base.h"
class Cl6 : public Base
{
public:
	int currentClass = 6;

	Cl6(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 6; };

	//Метод вывода сигнала
	void Signal(string name);
	//Метод вывода сообщения обработчика
	void Handler(string msg, Base* from);
};

