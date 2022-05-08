#pragma once
#include "Base.h"
class Cl3 : public Base
{
public:
	int currentClass = 3;

	Cl3(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 3; };

	//Метод вывода сигнала
	void Signal(string name);

	//Метод вывода сообщения обработчика
	void Handler(string msg, Base* from);
};

