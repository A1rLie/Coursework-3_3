#include "Base.h"

Base::Base(Base* parent_ptr, string name)
{
	this->parent_ptr = parent_ptr;
	this->name = name;
	current_ptr = this;
	currentClass = 1;
}

void Base::getSignal(Base* t, SIGNAL(signal), string msg)
{
	if (t->status == 0) return;

	(t->*Signal)(t->getName());
	for (int i = 0; i < t->connections.size(); i++)
	{
		t->connections[i]->Handler(msg, t->connections[i]);
	}
}

void Base::setConnection(SIGNAL(signal), Base* goal, HANDLER(signal))
{
	(this->*Signal)(getName());
	this->connections.push_back(goal);
}

void Base::deleteConnection(SIGNAL(signal), Base* goal, HANDLER(signal))
{
	for (int i = 0; i < connections.size(); i++)
	{
		if (connections[i] == goal)
		{
			connections.erase(connections.begin() + i);
			break;
		}
	}
}

//Метод вывода сигнала
void Base::Signal(string name)
{
	cout << "Signal from " << absolutePath(name) << endl;
	for (int i = 0; i < connections.size(); i++)
	{
		connections[i]->classParent = currentClass;
	}
}

//Метод вывода сообщения обработчика
void Base::Handler(string msg, Base* from)
{
	cout << "Signal to / Text: " << msg << " (class: " << classParent << ")" << endl;
}

string Base::absolutePath(string name)
{
	Base* ptr = findName(name, this->getParent());
	if (ptr == nullptr) return "";

	string path = '/' + name;
	while (ptr->getParent()->getParent() != nullptr) //Двойной вызов метода getParent, чтобы не попасть в корневой объект
	{
		path = '/' + ptr->getParent()->name + path;
		ptr = ptr->getParent();
	}
	return path;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Base::showChildrenTree(string space)
{
	if (space == "")  cout << "Object tree" << endl << space << this->getName();
	for (int i = 0; i < this->children.size(); i++)
	{
		cout << endl << space + "    " << children[i]->getName();
		if (!children[i]->children.empty()) this->children[i]->showChildrenTree(space + "    ");
	}
	if (space == "") cout << endl;
}

Base* Base::FindDirectory(string path, bool a)
{
	string text = "";
	Base* temp = nullptr;
	if (path == "/") return this;
	if (path[0] == '/' and path[1] == '/')
	{
		path.erase(path.begin() + 0);
		path.erase(path.begin() + 0);
		return findName(path, this);
	}
	else
	{
		Base* temp2 = current_ptr;
		for (int i = 0; i < path.size(); i++)
		{
			if (path[i] == '/' or i == path.size() - 1)
			{
				if (text != "")
				{
					if (path[i] != '/') text += path[i];
					temp2 = findName(text, temp2, true);
					if (temp2 == nullptr) return nullptr;
					if (i == path.size() - 1) return temp2;
					text = "";
				}
			}
			else text += path[i];
		}
		return nullptr;
	}
}

void Base::Set(string pathToDirectory)
{
	if (FindDirectory(pathToDirectory) != nullptr)
	{
		current_ptr = FindDirectory(pathToDirectory);
		cout << endl <<"Object is set: " << current_ptr->getName();
	}
	else cout << endl << "Object is not found: " << pathToDirectory;
}

void Base::Find(string pathToDirectory)
{
	cout << endl << pathToDirectory << "    ";
	if (pathToDirectory != ".")
	{
		Base* temp = FindDirectory(pathToDirectory);
		if (temp != nullptr) cout << "Object name: " << temp->getName();
		else cout << pathToDirectory << " Object is not found";
	}
	else cout << "Object name: " << current_ptr->getName();
}

void Base::setState(Base* parent)
{
	for (int i = 0; i < parent->children.size(); i++)
	{
		parent->children[i]->status = 1;
		if (!parent->children[i]->children.empty()) setState(parent->children[i]);
	}
}

void Base::resetState(int status)
{
	for (int i = 0; i < this->children.size(); i++)
	{
		children[i]->status = status;
		if (status == 0) children[i]->resetState(status);
	}
}

void Base::showStatusTree(string space)
{
	if (space == "")
	{
		cout << endl << getName();
		if (status == 0) cout << " is not ready";
		else cout << " is ready";
	}
	for (int i = 0; i < this->children.size(); i++)
	{
		cout << endl << space + "    " << children[i]->getName();
		if (children[i]->status == 0) cout << " is not ready";
		else cout << " is ready";
		if (!children[i]->children.empty()) children[i]->showStatusTree(space + "    ");
	}
}

Base* Base::findName(string name, Base* ptr, bool fl)
{
	if (fl == false)
	{
		if (ptr != nullptr)
		{
			Base* temp;
			for (int i = 0; i < ptr->children.size(); i++)
			{
				temp = ptr->children[i];
				if (temp->getName() == name) return temp;
				else if (temp->children.size() > 0)
				{
					if (findName(name, temp) != nullptr)
					{
						return findName(name, temp);
						break;
					}
				}
			}
			return nullptr;
		}
		return ptr;
	}
	else
	{
		for (int i = 0; i < ptr->children.size(); i++)
		{
			if (ptr->children[i]->getName() == name) return ptr->children[i];
		}
		return nullptr;
	}
}

void Base::resetParent(Base* ptr)
{
	parent_ptr = ptr;
}

Base* Base::getParent()
{
	return parent_ptr;
}

void Base::setParentName(string name)
{
	this->name = name;
}

string Base::getName()
{
	return name;
}