/* 
Короткевич Л. В.
М8О-208Б-19
github.com/anxieuse/oop_exercise_05
Вариант 14:
    Контейнер: список
    Фигура: пятиугольник
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include "List.hpp"
#include "Point.hpp"
#include "Polygon.hpp"

void help()
{
    std::cout << "1. Добавить фигуру\n";
    std::cout << "\t1.1. В начало списка\n";
    std::cout << "\t1.2. В конец списка\n";
    std::cout << "\t1.3. По индексу\n";

    std::cout << "2. Удалить фигуру\n";
    std::cout << "\t1.1. В начале списка\n";
    std::cout << "\t1.2. В конце списка\n";
    std::cout << "\t1.3. По индексу\n";

    std::cout << "3. Вывести фигуру\n";
    std::cout << "\t3.1. Первую в списке\n";
    std::cout << "\t3.2. Последнюю в списке\n";
    std::cout << "\t3.3. По индексу\n";

    std::cout << "4. Вывести все фигуры\n";
    std::cout << "5. Вывести кол-во фигур чья площадь больше чем ...\n";
    std::cout << "6. Выйти\n";
}

int main()
{
    help();

    list<Polygon<double>> MyList;
    Polygon<double> polygon;

    int n, m, deletedType, index;
    double Area;

    while (true)
    {
        try
        {
            std::cin >> n;
            switch (n)
            {
            case 1:
                std::cin >> m;
                switch (m)
                {
                case 1:
                    std::cin >> polygon;
                    MyList.push_front(polygon);
                    break;
                case 2:
                    std::cin >> polygon;
                    MyList.push_back(polygon);
                    break;
                case 3:
                    std::cin >> index;
                    std::cin >> polygon;
                    MyList.insert_by_number(index, polygon);
                    break;
                }
                std::cout << nameByType[polygon.n] << " succesfully added\n";
                break;
            case 2:
                std::cin >> m;
                switch (m)
                {
                case 1:
                    deletedType = MyList.front().n;
                    MyList.pop_front();
                    break;
                case 2:
                    deletedType = MyList.back().n;
                    MyList.pop_back();
                    break;
                case 3:
                    std::cin >> index;
                    deletedType = MyList[index].n;
                    MyList.delete_by_number(index);
                    break;
                }
                std::cout << nameByType[deletedType] << " succesfully removed\n";
                break;
            case 3:
                std::cin >> m;
                switch (m)
                {
                case 1:
                    std::cout << MyList.front() << '\n';
                    break;
                case 2:
                    std::cout << MyList.back() << '\n';
                    break;
                case 3:
                    std::cin >> index;
                    std::cout << MyList[index] << '\n';
                    break;
                }
                break;
            case 4:
                if (MyList.length() == 0) 
                    std::cout << "print error: list is empty\n";
                std::for_each(MyList.begin(), MyList.end(),
                              [](const Polygon<double> &X) {
                                  std::cout << X << '\n';
                              });
                break;
            case 5:
                std::cin >> Area;
                std::cout << std::count_if(MyList.begin(), MyList.end(),
                                           [Area](const Polygon<double> &X) {
                                               return Area > X.area;
                                           })
                          << '\n';
                break;
            case 6:
                return 0;
                break;
            }
        }
        catch (const char *ex)
        {
            std::cout << ex << '\n';
        }
    }

    return 0;
}