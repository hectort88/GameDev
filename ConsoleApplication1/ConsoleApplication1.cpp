#include <iostream>
#include <string>
#include "Shape.hpp"

struct student {
    int birthyear;
    float height;
    std::string name;
};

int main()
{
    int ages[] = {16, 14, 24, 35, 19, 28, 27};
    int n = 42;
    int* p = nullptr;
    p = ages;
    int* n_location = &n;

    struct student students[] = { 
        {1988, 1.65, "Jeffrey Arroyo"},
        {1996, 1.65, "Madelyn Garza"},
        {1997, 1.60, "Colette Griffith"},
        {1995, 1.56, "Lilia Crawford"},
    };

    for  (auto &s : students)
    {
        std::cout << "Name: " << s.name << ", YOB: " << s.birthyear << ", Height: " << s.height << std::endl;
    }

    Shape square(8, 8);
    Shape rectangle(12, 20);
    square.print();
    rectangle.print();

    for (auto age : ages) {
        std::cout << age << std::endl;
    }
    std::cout << "n with value: " << *n_location << ", is located at " << n_location << std::endl;
    
    std::cout << *p << std::endl;    
    p++;
    std::cout << *p << std::endl;

    return 0;
}
