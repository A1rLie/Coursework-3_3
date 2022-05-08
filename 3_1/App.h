#ifndef APP_H
#define APP_H

#include "Base.h"


class App : public Base
{
public:
	App(Base* oldParent_tpr, string name = "") : Base(oldParent_tpr, name) {};

	void builtTree();

	void Exe();

	void Test();
};


#endif