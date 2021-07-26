#include <iostream>
#include <unistd.h>
#include <vector>
#include "ramen_app.h"

class A 
{
    public:
       int x;
    protected:
       int y;
    private:
       int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

void operator_ofstream_demo()
{
    Complex c(10,5);
	    
	std::cout<<c;

}

void operator_demo()
{
    Complex c1(5,3),c2(10,5),c3;

    c3 = c1 + c2;

    c3.display();
}

void vector_demo()
{
    std::vector<int> g1;
    
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
  
    std::cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        std::cout << *i << " ";
  
    std::cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        std::cout << *i << " ";
  
    std::cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        std::cout << *ir << " ";
  
    std::cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        std::cout << *ir << " ";
  
}

void range_based_demo()
{
    auto texts = {"one", "two", "three"};

    for(auto text:texts)
    {
        std::cout<<text<<std::endl;
    }

    std::vector <int> numbers;
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);
    numbers.push_back(10);

    for(int number:numbers)
    {
        std::cout<<number<<std::endl;
    }

    std::string myString = "Hello";

    for(auto c: myString)
    {
        std::cout<<c;
    }
}

void cpp_style_enum()
{
    enTest id = monday;
    std::cout<<id<<std::endl;
    id++;
    std::cout<<id<<std::endl;
}

int main(int argc, char *argv[])
{

    int opt = 0;
    while((opt = getopt(argc, argv,"abcdefghijklmnopq")) != -1)
    {
        switch(opt)
        {
            case'a':
                cpp_style_enum();
            break;

            case 'b':
                range_based_demo();
            break;

            case 'c':
                operator_demo();
            break;

            case 'd':
                operator_ofstream_demo();
            break;

            case 'e':
                vector_demo();
            break;

            default :
                printf("unable to parse cli\n");
            break;
        }
    }
    return 0;
}