#pragma once
#include "Base.h"
class Cl5 : public Base
{
public:
	int currentClass = 5;

	Cl5(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 5; };

	//Метод вывода сигнала
	void Signal(string name);
	//Метод вывода сообщения обработчика
	void Handler(string msg, Base* from);
};

