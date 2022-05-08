#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
#include <string>


#define SIGNAL(signal) void (Base::* Signal)(string signal)
#define HANDLER(signal) void (Base::* Handler)(string msg, Base* from)

using namespace std;

class Base
{
public:
	string name;
	string reason_of_the_error = "";
	string msg;
	Base* parent_ptr;
	Base* current_ptr;
	vector<Base*> children;
	vector<Base*> connections;
	int status;
	int classParent;
	int currentClass;
	
	//Конструктор
	Base(Base* parent_ptr, string name = "");

	//Установка связи
	void setConnection(SIGNAL(signal), Base* goal, HANDLER(signal));

	//Удаление связи
	void deleteConnection(SIGNAL(signal), Base* goal, HANDLER(signal));

	//Выдача сигнала
	void getSignal(Base* t, SIGNAL(signal), string msg);

	//Метод вывода сигнала
	virtual void Signal(string name);

	//Метод вывода сообщения обработчика
	virtual void Handler(string msg, Base* from);

	//Вывод абсолютного пути
	string absolutePath(string name);

	//Поиск в директории
	Base* FindDirectory(string path, bool a = false);

	//Установка
	void Set(string pathToDirectory);

	//Поиск
	void Find(string pathToDirectory);

	//Установка статуса
	void setState(Base* parent);

	//Переустановка статуса
	void resetState(int status);

	//Установка имени родителя
	void setParentName(string name);

	//Получение имени родителя
	string getName();

	//Метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз
	void showChildrenTree(string space = "");

	void showStatusTree(string space = "");

	//Метод переопределения головного объекта для текущего в дереве иерархии
	void resetParent(Base* ptr);

	//Метод получения указателя на головной объект текущего объекта.
	Base* getParent();

	//Поиск по имени
	Base* findName(string name, Base* ptr, bool fl = false);
};

#endif