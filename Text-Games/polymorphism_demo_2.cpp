// YT Video Link: https://www.youtube.com/watch?v=wE0_F4LpGVc

#include <iostream>

class Shape
{
public:
    // abstract class is a class that have atleast one pure virtual function.
    float virtual Area() const = 0; // pure virtual member function
    // an abstract class also does not have any object instance.
};

class Square : public Shape{
    public:
        float m_Length;
        Square(float length = 1); 
        float Area() const;
};

Square::Square(float length):
    m_Length(length)
    {}


float Square::Area() const{
    return m_Length*m_Length;
}


class Triangle : public Shape{
    public:
        float m_Length, m_Height;
        Triangle(float length = 1.0f, float Height = 1.0f);
        float Area() const;
};

Triangle::Triangle(float length, float heigth):
    m_Length(length), m_Height(heigth)
    {}

float Triangle::Area() const{
    return 0.5*m_Length*m_Height;
}


int main(){
    Shape *shapes[] = {         // we can have pointers to the abstract class 'shape'.
        new Square(5),
        new Triangle(8, 10),
        new Square(7),
        new Triangle(3, 4),
    };

    for (int i = 0; i < 4; i++){
        std::cout << "Shape " << i << ": " << shapes[i]->Area() << std::endl; 
    }
}