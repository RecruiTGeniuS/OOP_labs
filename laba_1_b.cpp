/*
* ---------------------------------------------------------------------------------------------- *
    Вручнную создать текстовый файл со следующей информацией(в две колонки разделяя пробелом):
    марка машины _ модель (например Мерседес 320)
    Всего 10 строк в файле, марка и модель могут повторяться
    В программе загрузить файл, распределяя данные по объектам, тип которых соответсвует
    марке автомобиля, а модель - член данных в базовом классе.
    Храниться классы должны совместно, используя vector.
    Вывести данные о моделии марке каждого автомобиля при выходе из программы
    (Подсказка: в деструкторах)
    Файл "cars.txt" создавался через VS в Source Files
* ---------------------------------------------------------------------------------------------- *
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

// Для проверки утечек памяти
struct Leaks
{
    ~Leaks()
    {
        _CrtDumpMemoryLeaks();
    }
}_leaks;

// Иерархия наследования
class Car
{
protected:
    std::string model_;

public:
    Car() {}
    virtual ~Car() {}
};

class Mercedes : public Car
{
public:
    Mercedes(const std::string& model)
    {
        model_ = model;
    }
    ~Mercedes()
    {
        std::cout << "Mercedes " << model_ << std::endl;
    }
};

class Toyota : public Car
{
public:
    Toyota(const std::string& model)
    {
        model_ = model;
    }
    ~Toyota()
    {
        std::cout << "Toyota " << model_ << std::endl;
    }
};

class BMW : public Car
{
public:
    BMW(const std::string& model)
    {
        model_ = model;
    }
    ~BMW()
    {
        std::cout << "BMW " << model_ << std::endl;
    }
};

class Lada : public Car
{
public:
    Lada(const std::string& model)
    {
        model_ = model;
    }
    ~Lada()
    {
        std::cout << "Lada " << model_ << std::endl;
    }
};


int main()
{
    std::string carBrand;
    std::string carModel;

    std::vector<Car*> storage;

    std::ifstream file("cars.txt");

    while (!file.eof())
    {
        file >> carBrand;
        if (carBrand == "Mercedes")
        {
            file >> carModel;
            storage.push_back(new Mercedes(carModel));
        }
        else if (carBrand == "Toyota")
        {
            file >> carModel;
            storage.push_back(new Toyota(carModel));
        }
        else if (carBrand == "BMW")
        {
            file >> carModel;
            storage.push_back(new BMW(carModel));
        }
        else if (carBrand == "Lada")
        {
            file >> carModel;
            storage.push_back(new Lada(carModel));
        }
    }

    for (int i = 0; i < storage.size(); ++i)
    {
        delete storage[i];
    }


    return 0;
}