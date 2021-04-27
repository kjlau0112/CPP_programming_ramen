#include <iostream>

class Complex
{
    private:
    int real;
    int img;
            
    public:
    Complex(int r=0,int i=0)
    {
        real=r;
        img=i;
    }
                
    void display()
    {
        std::cout<<real<<"+i"<<img<<std::endl;
    }
                
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real=real+c.real;
        temp.img=img+c.img;
        return temp;
    }
    
    friend std::ostream & operator<<(std::ostream &out,Complex &c);
};

std::ostream & operator<<(std::ostream &out,Complex &c)
{
    out<<c.real<<"+i"<<c.img<<std::endl;
    return out;
}

enum enTest
{
    monday,
    tuesday,
    wednesday
};

enTest operator++(enTest &id, int)
{
    int temp = static_cast<int>(id);
    temp++;
    id = static_cast<enTest>(temp);

    return (id);
}