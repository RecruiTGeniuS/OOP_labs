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


// Иерархия наследования
class Class1
{
public:
	Class1 () {}
	virtual ~Class1 () {}

	// Метод для клонирования объекта
	virtual Class1* clone()
	{
		Class1* copyObj = new Class1(*this);
		return copyObj;
	}
};

class Class2 : public Class1
{
public:
	Class2 () {}
	~Class2 () {}

	// Метод для клонирования объекта
	Class1* clone()
	{
		Class1* copyObj = new Class2(*this);
		return copyObj;
	}
};

// Функция из условия
void my_copy(Class1* obj, std::vector<Class1*>& dB)
{
	Class1* copyObject = obj->clone();
	dB.push_back(copyObject);
}

int main()
{
	// Создание автоматических объектов
	Class1* obj1 = new Class1(); 
	Class1* obj2 = new Class2(); 


	// База данных
	std::vector<Class1*> dataBase;

	// Копирование при помощи функции из условия
	my_copy(obj1, dataBase);
	my_copy(obj2, dataBase);


	// Вывод информации и очистка вектора
	for (int i = 0; i < dataBase.size(); ++i)
	{
		std::cout << typeid(*(dataBase[i])).name() << std::endl;
		delete dataBase[i];
	}

	delete obj1;
	delete obj2;

	return 0;
}
