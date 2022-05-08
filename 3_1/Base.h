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
	
	//�����������
	Base(Base* parent_ptr, string name = "");

	//��������� �����
	void setConnection(SIGNAL(signal), Base* goal, HANDLER(signal));

	//�������� �����
	void deleteConnection(SIGNAL(signal), Base* goal, HANDLER(signal));

	//������ �������
	void getSignal(Base* t, SIGNAL(signal), string msg);

	//����� ������ �������
	virtual void Signal(string name);

	//����� ������ ��������� �����������
	virtual void Handler(string msg, Base* from);

	//����� ����������� ����
	string absolutePath(string name);

	//����� � ����������
	Base* FindDirectory(string path, bool a = false);

	//���������
	void Set(string pathToDirectory);

	//�����
	void Find(string pathToDirectory);

	//��������� �������
	void setState(Base* parent);

	//������������� �������
	void resetState(int status);

	//��������� ����� ��������
	void setParentName(string name);

	//��������� ����� ��������
	string getName();

	//����� ������ ������������ �������� � ������ �������� ����� ������� � ������ ����
	void showChildrenTree(string space = "");

	void showStatusTree(string space = "");

	//����� ��������������� ��������� ������� ��� �������� � ������ ��������
	void resetParent(Base* ptr);

	//����� ��������� ��������� �� �������� ������ �������� �������.
	Base* getParent();

	//����� �� �����
	Base* findName(string name, Base* ptr, bool fl = false);
};

#endif