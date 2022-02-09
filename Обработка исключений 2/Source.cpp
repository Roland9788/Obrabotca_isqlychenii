//#include <iostream>
//using namespace std;
//
////void Some()
////{
////	int a;
////	int b;
////	try
////	{
////		cout << "\nВведите a\n";
////		cin >> a;
////		cout << "\nВведите b\n";
////		cin >> b;
////		if (b == 0)
////		{
////			throw " Ноль!!!\n";
////		}
////	}
////	catch (const char* s)//-Зависит от значения в throw
////	{
////		cout << "\nОшибка!!! " << s << "\n\n";
////	}
////}
//
////class Error
////{
////public:
////	void showerror()
////	{
////		cout << "\nОшибка\n";
////	}
////};
////
////class f
////{
////	int a;
////	int b;
////
////public:
////
////	void func()
////	{
////		Error error;
////		cout << "\nВведите a\n";
////		cin >> a;
////		cout << "\nВведите b\n";
////		cin >> b;
////		if (b == 0)
////		{
////			throw error;
////		}
////	}
////
////
////};
////
////
////void Some()
////{
////	f frac;
////	try
////	{
////		frac.func();
////
////	}
////	catch (Error s)//-Зависит от значения в throw
////	{
////		cout << "\nОшибка!!! \n";
////	}
////}
//
////void Test(int t)
////{
////	cout << "\nРабота функции Test\n";
////	if (t == 2)
////	{
////		throw "\nОшибка t = 2\n";
////	}
////	else if (t == 3)
////	{
////		throw "\nОшибка t = 3\n";
////	}
////}
//
////void Test()
////{
////
////	try
////	{
////		throw "\nHello!!!\n";
////	}
////	catch (const char* s)
////	{
////		cout << "\nИсключение!\n";
////		throw;
////	}
////}
//
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//
//	//try
//	//{
//	//	Test(4);
//	//	Test(2);
//	//}
//	//catch (const char* s)
//	//{
//	//	cout << "\n\n" << s << "\n\n";
//	//}
//
//	//Some();
//
//	//cout << "\nНачало работы программы\n";
//	//try
//	//{
//	//	Test();
//	//}
//	//catch (const char* p)
//	//{
//	//	cout << p;
//	//}
//
//
//
//	return 0;
//}

#include<iostream>
#include <string>
#include <stdio.h> 
#include <time.h>
using namespace std;

struct Node
{
	int data;
	Node* next = 0;
	Node* prev = 0;
};

class List
{
	Node* Head;
	Node* Tail;
	int Count = 0;

public:
	List();
	List(const List& L);
	~List();
	void Print();
	void Print2(int pos);
	void AddHead(int n);
	void AddTail(int n);
	void Add(int data);
	void Insert(int index);
	Node* GetEment(int pos);
	void Del();
	void Delpos(int pos);
	void DellAll();
	int GetCount();
	List operator +(const List& L)
	{
		List Result(*this);
		Node* temp = L.Head;
		while (temp != 0)
		{
			Result.AddTail(temp->data);
			temp = temp->next;
		}
		return Result;
	}

	List operator=(const List& L)
	{
		if (this == &L)
		{
			return *this;
		}
		this->~List();
		Node* temp = L.Head;
		while (temp != 0)
		{
			AddTail(temp->data);
			temp = temp->next;
		}
		return *this;
	}

	bool operator ==(const List& L)
	{
		if (Count != L.Count)
		{
			return false;
		}
		Node* t1;
		Node* t2;
		t1 = Head;
		t2 = L.Head;
		while (t1 != 0)
		{
			//if (t1->data != t2->data)
			//{
			//	return false;
			//}
			//t1 = t1->next;
			//t2 = t2->next;

			if (t1->data == t2->data)
			{
				return true;
			}
			else
			{
				t1 = t1->next;
				t2 = t2->next;
			}
		}
		return true;
	}

	bool operator !=(const List& L)
	{
		return !(*this == L);
	}

	bool operator >=(const List& L)
	{
		if (Count > L.Count)
		{
			return true;
		}
		if (*this == L)
		{
			return true;
		}
		return false;
	}

	bool operator <=(const List& L)
	{
		if (Count < L.Count)
		{
			return true;
		}
		if (*this == L)
		{
			return true;
		}
		return false;
	}

	bool operator >(const List& L)
	{
		if (Count > L.Count)
		{
			return true;
		}
		return false;
	}

	bool operator <(const List& L)
	{
		if (Count < L.Count)
		{
			return true;
		}
		return false;
	}

	List operator - ()
	{
		List Result;
		Node* temp = Head;
		while (temp != 0)
		{
			Result.AddHead(temp->data);
			temp = temp->next;
		}
		return Result;
	}


};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::List(const List& L)
{
	Head = Tail = NULL;
	Count = 0;
	//Голова списка из которого копируем
	Node* temp = L.Head;
	while (temp != 0)
	{
		//Передача данных
		AddTail(temp->data);
		temp = temp->next;
	}
}

List::~List()
{
	DellAll();
}

void List::Print()
{
	Node* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n\n";
}

void List::Print2(int pos)
{
	if (pos<1 && pos>Count)
	{
		cout << "\nНеверный ввод\n";
		return;
	}
	Node* temp;

	//int i = 1;
	//while (i < pos)
	//{
	//	temp = temp->next;
	//	i++;
	//}
	//if (i == pos)
	//{
	//	cout << temp->data;
	//}

	if (pos <= Count / 2)
	{
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		temp = Tail;
		int i = 1;
		while (i <= Count - pos)
		{
			temp = temp->prev;
			i++;
		}

	}
	cout << "\nПозиция " << pos;
	cout << " Элемент - " << temp->data;

}

void List::AddHead(int n)
{
	try
	{
		Node* temp = new Node;
		temp->prev = 0;
		temp->data = n;
		if (sizeof(temp->data) > sizeof(int))
		{
			throw "\nОшибка\n";
		}
		temp->next = Head;
		if (Head != 0)
		{
			Head->prev = temp;
		}
		if (Count == 0)
		{
			Head = Tail = temp;
		}
		else
		{
			Head = temp;
		}
		Count++;
	}
	catch (const char* s)
	{
		cout << s << "\nНехватка памяти\n";
	}
}

void List::AddTail(int n)
{
	try
	{
		Node* temp = new Node;
		temp->prev = 0;
		temp->data = n;
		if (sizeof(temp->data) > sizeof(int))
		{
			throw "\nОшибка\n";
		}
		temp->prev = Tail;

		if (Tail != 0)
		{
			Tail->next = temp;
		}
		if (Count == 0)
		{
			Head = Tail = temp;
		}
		else
		{
			Tail = temp;
		}
		Count++;
	}
	catch (const char* s)
	{
		cout <<s<< "\nНехватка памяти\n";
	}
}

void List::Add(int data)
{
	try
	{


		Node* temp = new Node;
		temp->data = data;
		if (sizeof(temp->data) > sizeof(int))
		{
			throw "\nОшибка!\n";
		}
		temp->next = NULL;
		if (Head != NULL)
		{
			Tail->next = temp;
			Tail = temp;
		}
		else
		{
			Head = Tail = temp;
		}
	}
	catch (const char* s)
	{
		cout << s <<"\nНехватка памяти!\n";
	}
}

void List::Insert(int index = 0)
{
	if (index == 0)
	{
		cout << "\nВведите позицию\n";
		cin >> index;
	}
	if (index<1 || index>Count + 1)
	{
		cout << "\nНеверный ввод!\n";
		return;
	}
	if (index == Count + 1)
	{
		int data;
		cout << "\nВведите значение\n";
		cin >> data;
		AddTail(data);
		return;
	}
	else if (index == 1)
	{
		int data;
		cout << "\nВведите значение\n";
		cin >> data;
		AddHead(data);
		return;

	}
	int i = 1;
	Node* Ins = Head;
	while (i < index)
	{
		Ins = Ins->next;
		i++;
	}
	Node* PrevIns = Ins->prev;
	Node* temp = new Node;
	cout << "\nВведите данные\n";
	cin >> temp->data;

	if (PrevIns != 0 && Count != 1)
	{
		PrevIns->next = temp;
	}
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;
	Count++;
}

//Возвращает адрес элемента
Node* List::GetEment(int pos)
{
	Node* temp = Head;
	if (pos<1 || pos>Count + 1)
	{
		cout << "\nНеверный ввод!\n";
		return 0;
	}
	int i = 1;
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
	{
		return 0;
	}
	else
	{
		return temp;
	}
}

void List::Delpos(int pos = 0)
{
	try
	{


		if (pos == 0)
		{
			cout << "\nВведите позицию\n";
			cin >> pos;
		}
		if (pos<1 || pos>Count)
		{
			cout << "\nНеверный ввод\n";
			return;
		}
		int i = 1;
		Node* Del = Head;
		if (Del == NULL)
		{
			throw "\nОшибка\n";
		}
		while (i < pos)
		{
			Del = Del->next;
			i++;
		}
		Node* PrevDel = Del->prev;
		Node* AfterDel = Del->next;
		if (PrevDel != 0 && Count != 1)
		{
			PrevDel->next = AfterDel;
		}
		if (AfterDel != 0 && Count != 1)
		{
			AfterDel->prev = PrevDel;
		}
		if (pos == 1)
		{
			Head = AfterDel;
		}
		if (pos == Count)
		{
			Tail = PrevDel;
		}
		delete Del;
		Count--;
	}
	catch (const char* s)
	{
		cout << s << "\nУдаление из пустого списка\n";
	}
}

void List::Del()
{
	try
	{
		Node* temp = Head;
		if (temp == NULL)
		{
			throw "\nОшибка!\n";
		}
		Head = Head->next;
		delete[]temp;
	}
	catch (const char* s)
	{
		cout << s << "\nПопытка удаления из пустого списка!\n";
	}
}

void List::DellAll()
{
	while (Head != 0)
	{
		Del();
	}
}
int List::GetCount()
{
	return Count;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");


	List list;
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			list.AddHead(a[i]);
		}
		else
		{
			list.AddTail(a[i]);
		}
	}

	//list.Add(12345678911213342234);


	cout << "\nСписок: \n";
	list.Print();
	list.Insert();
	cout << "\nСписок: \n";
	list.Print();
	list.Print2(2);
	list.Print2(8);
	List Temp;
	Temp = list;
	cout << "\nСписок 2: \n";
	Temp.Print();
	cout << "\nСписок 1 + Список 2\n";
	List Sum = -list + Temp;
	Sum.Print();
	cout << "\nСписок 2: \n";
	Sum.Delpos(5);
	Sum.Print();
	cout << "\n\n\n\n";

	cout << Sum.GetEment(3);

	//Sum.DellAll();
	//Sum.Del();

	Sum.DellAll();
	Sum.Delpos();


	return 0;
}