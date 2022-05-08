#pragma once
#include "Base.h"
class Cl4 : public Base
{
public:
	Cl4(Base* parent_ptr, string name) : Base(parent_ptr, name) { currentClass = 4; };

	//Метод вывода сигнала
	void Signal(string name);
	//Метод вывода сообщения обработчика
	void Handler(string msg, Base* from);
};

