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
    //bool chekNameAndAuthor = 0; 

    // Конструктор для инициализации 
    Book(const std::string& author, const std::string& bookName, Type bookType) :
        author_{ author }, bookName_{ bookName }, bookType_{ bookType } {}

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


class Library
{
public:
    // Метод для добавления книги в бибилиотеку 
    void addBook(const std::string& author, const std::string& bookName, const Type bookType)
    {
        if (author.empty() || bookName.empty())
        {
            std::cout << "Error! Book name or author was not found.\n";
        }
        else
        {
            Book book = Book(author, bookName, bookType);
            _library.push_back(book);
        }
    }

    // Метод из пункта Б подсчёт switch 
    void countSwitch()
    {
        short countArt = 0;
        short countTech = 0;

        for (const Book& book : _library)
        {
            const Type bookType = book.getType();

            switch (bookType)
            {
            case Type::Art:
                countArt += 1;
                break;
            case Type::Tech:
                countTech += 1;
                break;
            }
        }

        std::cout << "----------------------\n";
        std::cout << "num switch Art: " << countArt << std::endl;
        std::cout << "----------------------\n";
        std::cout << "num switch Tech: " << countTech << std::endl;
        std::cout << "----------------------\n";
    }

    // Метод из пункта B подсчёт if 
    void countIf()
    {
        short countArt = 0;
        short countTech = 0;

        for (const Book& book : _library)
        {
            const Type bookType = book.getType();

            if (bookType == Type::Art)
            {
                countArt += 1;
            }
            if (bookType == Type::Tech)
            {
                countTech += 1;
            }
        }

        std::cout << "----------------------\n";
        std::cout << "num if Art: " << countArt << std::endl;
        std::cout << "----------------------\n";
        std::cout << "num if Tech: " << countTech << std::endl;
        std::cout << "----------------------\n";
    }

private:
    std::vector<Book> _library;
};

int main()
{
    // Сама библиотека 
    Library library;

    // Добавление книг в библиотеку 
    library.addBook("Jack London", "Martin Iden", Type::Art);
    library.addBook("F. Scott Fidzgerald", "Great Gatsby", Type::Art);
    library.addBook("O. Henry", "Stories", Type::Art);
    library.addBook("Bjarne Stroustrup", "The C++ Programming Language", Type::Tech);
    library.addBook("M. I. Skanavi", "Collection of problems in mathematics", Type::Tech);
    library.addBook("", "K", Type::Art);
    library.addBook("J", "", Type::Tech);

    // Подсчёт через Swtich и If 
    library.countSwitch();
    std::cout << std::endl;
    library.countIf();

    return 0;
}
