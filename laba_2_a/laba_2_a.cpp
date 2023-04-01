/*
* ------------------------------------------------------------------------------------------------------------ *
	Открыть консольное приложение.
	Задать два не абстрактных класса, связанных в полиморфную иерархию: Class1 (базовый) и Class2. 
	В главной функции программы создать несколько автоматических объектов этих типов. 
	Затем посредством вызова функции my_copy скопировать эти объекты в базу данных (использовать vector), 
	т. е. в базе данных должны оказаться копии созданных автоматических объектов.
	Далее, вывести на консоль информацию о типах хранимых в БД объектах, используя typeid.
	Исключить утечку памяти.
 * ------------------------------------------------------------------------------------------------------------ *
*/

#include <iostream>
#include <vector>
#include <typeinfo>

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

// Проверка утечек памяти
struct Leaks
{
	~Leaks()
	{
		_CrtDumpMemoryLeaks();
	}
}_leaks;


// Иерархия классов
class Class1
{
public:
	Class1 () {}
	virtual ~Class1() {}
};

class Class2 : public Class1
{
public:
	Class2() {}
	~Class2() {}
};


//Функия копирования из условия
void my_copy(Class1* obj, std::vector<Class1*>& dataBase)
{
	dataBase.push_back(obj);
}


int main()
{
	// Создание автоматических объектов классов
	Class1* obj1 = new Class1();
	Class1* obj2 = new Class1();
	Class1* obj3 = new Class2();
	Class1* obj4 = new Class2();

	// База данных
	std::vector<Class1*> dataBase;


	// Копирование в базу данных
	my_copy(obj1, dataBase);
	my_copy(obj2, dataBase);
	my_copy(obj3, dataBase);
	my_copy(obj4, dataBase);

	

	// Вывод информации из dataBase и одновременная очистка памяти
	for (int i = 0; i < dataBase.size(); ++i)
	{
		std::cout << typeid(*dataBase[i]).name() << std::endl;
		delete dataBase[i];
	}

	return 0;
}