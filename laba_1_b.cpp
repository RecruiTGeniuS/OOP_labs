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
    const std::string model_;

public:
    Car(const std::string& model) : model_{ model }
    {}
    virtual ~Car() {}

    virtual void print() const = 0; // Чисто виртуальный метод print()
};

class Mercedes : public Car
{
public:
    Mercedes(const std::string& model) : Car{ model }
    {}

    void print() const override 
    { 
        std::cout << "Mercedes " << model_ << std::endl;
    }
};

class Toyota : public Car
{
public:
    Toyota(const std::string& model) : Car{ model }
    {}

    void print() const override
    {
        std::cout << "Toyota " << model_ << std::endl;
    }
};

class BMW : public Car
{
public:
    BMW(const std::string& model) : Car{ model }
    {}

    void print() const override
    {
        std::cout << "BMW " << model_ << std::endl;
        
    }
};



int main()
{
    // Окрытие файла
    std::ifstream file;
    file.open("cars.txt");


    std::string carBrand;
    std::string carModel;


    // Хранилище машин
    std::vector<Car*> storage;

    while (!file.eof())
    {
        file >> carBrand;

        if (carBrand == "Mercedes")
        {
            file >> carModel;
            storage.push_back(new Mercedes(carModel));
        }

        else if (carBrand == "BMW")
        {
            file >> carModel;
            storage.push_back(new BMW(carModel));
        }

        else if (carBrand == "Toyota")
        {
            file >> carModel;
            storage.push_back(new Toyota(carModel));
        }
    }
    
    file.close();

    for (int i = 0; i < storage.size(); ++i)
    {
        storage[i]->print();
        delete storage[i];
    }

    return 0;
}
