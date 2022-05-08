#ifndef CHILD_H
#define CHILD_H
#include "Base.h"
class Child : public Base
{
public:
	Child(Base* ptr, string name = "") : Base(ptr, name) {};
};

#endif