#pragma once
#include "Base.h"
class Cl2 : public Base
{
public:

	Cl2(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 2; };

	//Метод вывода сигнала
	void Signal(string name);

	//Метод вывода сообщения обработчика
	void Handler(string msg, Base* from);
};

