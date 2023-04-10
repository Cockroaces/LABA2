#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class Andriy {
private:
    set<char> mnojina;//Множина чар
public:

    Andriy(const string& kopipasta) 
    {
        for_each(kopipasta.begin(), kopipasta.end(), [this](char papametr) 
            { 
                this->mnojina.insert(papametr); 
            });
    }//Конструктор копіювання

    void dodatu(char papametr) 
    {
        mnojina.insert(papametr);// insert - записати в
    }//Метод додавання елементів в множину чар

    void vudalutu(char papametr) 
    {
        mnojina.erase(papametr);// erase - видалити
    }//Метод видалення елементів з множини чар

    void vivestu() const 
    {
        cout << "{ ";
        for_each(mnojina.begin(), mnojina.end(), [](char papametr) 
            {
            cout << papametr << " ";
            });
        cout << "}\n";
    }//Метод виведення всіх елементів 

    Andriy operator+(char papametr) const 
    {
        Andriy result(*this);
        result.dodatu(papametr);
        return result;
    }//Метод перевантаження оператора “+” − додати елемент в множину

    Andriy operator+(const Andriy& insha) const
    {
        Andriy result(*this);
        for_each(insha.mnojina.begin(), insha.mnojina.end(), [&result](char papametr) 
            {
            result.dodatu(papametr);
            });
        return result;
    }//Метод перевантаження оператора “+” − об'єднання множин

    bool operator==(const Andriy& insha) const 
    {
        return mnojina == insha.mnojina;
    }//Метод перевантаження оператора “==” − перевірка множин на рівність
};

int main() 
{
    setlocale(LC_ALL, "ukr");
    Andriy sho("abc");//Створення першого об'єкту(множина символів яка записується в set<char> data)
    Andriy kyda("abc");//Створення другого об'єкту(множина символів яка записується в set<char> data)

    (sho + 'f').vivestu();//Використання перевантаженого оператора “+” − додати елемент в множину
                          // { a b c d e f }

    (sho + kyda).vivestu();//Використання перевантаженого оператора “+” − об'єднання множин
                            // { a b c d e f g h }

    cout << (sho == kyda) << endl;//Використання перевантаженого оператора “==” − перевірка множин на рівність
                                     //Результат: false

    Andriy hto("abc");//Створення третього об'єкту(множина символів яка записується в set<char> data)
    cout << (sho == hto) << endl;//Використання перевантаженого оператора “==” − перевірка множин на рівність
                                     //Результат: true

    return 0;

}