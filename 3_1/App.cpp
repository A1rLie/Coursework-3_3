#include "App.h"
#include "Child.h"
#include "Cl2.h"
#include "Cl3.h"
#include "Cl4.h"
#include "Cl5.h"
#include "Cl6.h"

void App::builtTree()
{
	string pathToObject, nameObject;
	int classObject;
	cin >> nameObject;
	this->name = nameObject;
	//Построение дерева
	while (true)
	{
		cin >> pathToObject;
		if (pathToObject == "endtree") break;
		if (pathToObject == "/") pathToObject = this->name;
		cin >> nameObject >> classObject;
		if (this->getName() == pathToObject)
		{
			if (classObject == 2) this->children.push_back(new Cl2(this, nameObject));
			else if (classObject == 3) this->children.push_back(new Cl3(this, nameObject));
			else if (classObject == 4) this->children.push_back(new Cl4(this, nameObject));
			else if (classObject == 5) this->children.push_back(new Cl5(this, nameObject));
			else if (classObject == 6) this->children.push_back(new Cl6(this, nameObject));
		}
		else
		{
			Base* temp = FindDirectory(pathToObject, true);
			if (temp != nullptr)
			{
				if (classObject == 2) temp->children.push_back(new Cl2(temp, nameObject));
				else if (classObject == 3) temp->children.push_back(new Cl3(temp, nameObject));
				else if (classObject == 4) temp->children.push_back(new Cl4(temp, nameObject));
				else if (classObject == 5) temp->children.push_back(new Cl5(temp, nameObject));
				else if (classObject == 6) temp->children.push_back(new Cl6(temp, nameObject));
			}
			else
			{
				reason_of_the_error = pathToObject;
				break;
			}
		}
	}

	string outSignal, goalSignal;
	//Построение связей
	while (true)
	{
		cin >> outSignal;
		if (outSignal == "end_of_connections") break;
		cin >> goalSignal;
		Base* ptr = FindDirectory(outSignal);
		if (FindDirectory(goalSignal) != nullptr) ptr->connections.push_back(FindDirectory(goalSignal));
	}
}

void App::Test()
{
	this->status = 1;
	setState(this);
	showChildrenTree();
	string command;
	while (true)
	{
		cin >> command;
		if (command == "END") break;
		else if (command == "EMIT")
		{
			string path, msg;
			cin >> path;
			getline(cin, msg);
			getSignal(FindDirectory(path), &Base::Signal, msg);
		}
		else if (command == "SET_CONNECT")
		{
			string objectFrom, objectTo;
			cin >> objectFrom >> objectTo;
			FindDirectory(objectFrom)->setConnection(&Base::Signal, FindDirectory(objectTo), &Base::Handler);
		}
		else if (command == "DELETE_CONNECT")
		{
			string objectFrom, objectTo;
			cin >> objectFrom >> objectTo;
			FindDirectory(objectFrom)->deleteConnection(&Base::Signal, FindDirectory(objectTo), &Base::Handler);
		}
		else if (command == "SET_CONDITION")
		{
			int numStatus;
			string objectFrom;
			cin >> objectFrom >> numStatus;
			FindDirectory(objectFrom)->status = numStatus;
			FindDirectory(objectFrom)->resetState(numStatus);
		}
	}
}

void App::Exe()
{
    showChildrenTree();
	if (reason_of_the_error != "")
	{
		cout << "The head object " << reason_of_the_error << " is not found";
		return;
	}
	string command, object;
	while (true == true)
	{
		cin >> command;
		if (command == "END") break;
		cin >> object;
		if (command == "SET") Set(object);
		else if (command == "FIND") Find(object);
	}
}
