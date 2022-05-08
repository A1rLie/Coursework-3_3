#include "Cl4.h"

void Cl4::Signal(string name)
{
	cout << "Signal from " << absolutePath(name) << endl;
	for (int i = 0; i < connections.size(); i++)
	{
		connections[i]->classParent = currentClass;
	}
}

void Cl4::Handler(string msg, Base* from)
{
	cout << "Signal to " << absolutePath(this->getName()) << " Text: " << msg << " (class: " << classParent << ")" << endl;
}