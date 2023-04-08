/*
* ---------------------------------------------------------------------------------------------------------------------------- *
    Библиотека, в ней хранятся два вида книг. Художественные и технические. Создать программу, в которой:
    А) Наполнить библиотеку несколькими разными книгами
        Примечание 1: у пользовательского конструктора класса дложно быть 3 параметра - для указания автора, названия, типа
        Примечание 2: в библиотеке не должно быть книг без автора и названия
    Б) В отдельной процедуре вывести на консоль, использую switch, кол-во художественной литературы и технической
    В) В дополнительной процедуре сделать тоже самое, на без switch
    Следить за утечками.
* ---------------------------------------------------------------------------------------------------------------------------- *
*/


#include <iostream>
#include <vector>
#include <string>


// Перечисление для определения типа книги
enum class Type
{
    Art, Tech
};


// Класс книга
class Book
{
public:
    // Для проверки на отсутствие названия и автора книги
    bool chekNameAndAuthor = 0;

    // Конструктор для инициализации
    Book(const std::string& author, const std::string& bookName, const Type& bookType) :
        author_{ author }, bookName_{ bookName }, bookType_{ bookType }
    {
        if (author.empty() || bookName.empty())
        {
            std::cout << "Error! Book name or author was not found.\n";
            chekNameAndAuthor = 1;
        }
    }

    // Метод для взятия типа книги
    const Type getType() const
    {
        return bookType_;
    }

private:
    const std::string author_;
    const std::string bookName_;
    const Type bookType_;
};


// Процедура из пункта Б
void countSwitch(const std::vector<Book>& v)
{
    short countArt = 0;
    short countTech = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        const Type bType = v[i].getType();

        switch (bType)
        {
        case Type::Art:
            countArt += 1;
            break;

        case Type::Tech:
            countTech += 1;
            break;
        }
    }

    std::cout << "Number of Art Books:\t" << countArt << "\n";
    std::cout << "Number of Tech Books:\t" << countTech << "\n";
}


// Процедура из пункта В
void countIf(const std::vector<Book>& v)
{
    short countArt = 0;
    short countTech = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        const Type bType = v[i].getType();

        if (bType == Type::Art)
        {
            countArt += 1;
        }
        if (bType == Type::Tech)
        {
            countTech += 1;
        }
    }

    std::cout << "Number of Art Books:\t" << countArt << "\n";
    std::cout << "Number of Tech Books:\t" << countTech << "\n";
}


int main()
{
    // Сама библиотека
    std::vector<Book> library;

    // Промежуточная библиотека, нужная для отсеивания книг без авторов и названий
    std::vector<Book> libCheck;

    // Создание книг
    Book b1 = Book("Jack London", "Martin Iden", Type::Art);
    Book b2 = Book("F. Scott Fidzgerald", "Great Gatsby", Type::Art);
    Book b3 = Book("O. Henry", "Stories", Type::Art);
    Book b4 = Book("Bjarne Stroustrup", "The C++ Programming Language", Type::Tech);
    Book b5 = Book("M. I. Skanavi", "Collection of problems in mathematics", Type::Tech);
    // Объекты для теста
    Book b6 = Book("", "K", Type::Art);
    Book b7 = Book("J", "", Type::Tech);


    // Добавление книг в Промежуточную библиотеку
    libCheck.push_back(b1);
    libCheck.push_back(b2);
    libCheck.push_back(b3);
    libCheck.push_back(b4);
    libCheck.push_back(b5);
    libCheck.push_back(b6);
    libCheck.push_back(b7);


    // Добавление в  Основную библитеку книг, имеющих автора и название
    for (int i = 0; i < libCheck.size(); ++i)
    {
        if (libCheck[i].chekNameAndAuthor != 1)
        {
            library.push_back(libCheck[i]);
        }
    }


    // Подсчёт тех./худ. лит-ры
    std::cout << "----------------------\n";
    countSwitch(library);
    std::cout << "----------------------\n";
    countIf(library);
    std::cout << "----------------------\n";


    return 0;
}