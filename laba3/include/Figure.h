#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Figure {
protected:
    std::vector<Point> vertices;

public:
    virtual ~Figure() = default;
    
    // Вычисление геометрического центра
    virtual Point center() const = 0;
    
    // Вычисление площади
    virtual double area() const = 0;
    
    // Вывод координат вершин
    virtual void print(std::ostream& os) const = 0;
    
    // Чтение фигуры
    virtual void read(std::istream& is) = 0;
    
    // Операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
    
    // Оператор приведения к double (площадь)
    virtual operator double() const;
};

// Объявления операторов
std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

#endif