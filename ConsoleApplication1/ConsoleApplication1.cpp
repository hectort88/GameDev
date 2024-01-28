#include <iostream>
#include <string>

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
        {1988, 1.65, "Hector Trujillo"},
        {1996, 1.65, "Leonardo Trujillo"},
        {1997, 1.60, "Petra Diaz"},
        {1995, 1.56, "Katherin Mar"},
    };

    for  (auto &s : students)
    {
        std::cout << "Name: " << s.name << ", YOB: " << s.birthyear << ", Height: " << s.height << std::endl;
    }

    for (auto age : ages) {
        std::cout << age << std::endl;
    }
    std::cout << "n with value: " << *n_location << ", is located at " << n_location << std::endl;
    
    std::cout << *p << std::endl;    
    p++;
    std::cout << *p << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
