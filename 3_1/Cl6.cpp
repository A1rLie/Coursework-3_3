#include "Cl6.h"

void Cl6::Signal(string name)
{
	cout << "Signal from " << absolutePath(name) << endl;
	for (int i = 0; i < connections.size(); i++)
	{
		connections[i]->classParent = currentClass;
	}
}

void Cl6::Handler(string msg, Base* from)
{
	cout << "Signal to " << absolutePath(this->getName()) << " Text: " << msg << " (class: " << classParent << ")" << endl;
}
