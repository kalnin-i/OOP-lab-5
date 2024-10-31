#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

double pi = atan(1) * 4;

class GeometricBody
{
public:
    virtual double surfaceArea() const = 0;
    virtual double volume() const = 0;

    virtual ~GeometricBody() = default;
};

class Pyramid : public GeometricBody
{
private:
    double baseArea;
    double height;

public:
    Pyramid(double baseArea, double height) : baseArea(baseArea), height(height) {}

    double surfaceArea() const override
    {
        double sideSurfaceArea = sqrt((baseArea / 2) * (baseArea / 2) + height * height);
        return baseArea + sideSurfaceArea;
    }

    double volume() const override
    {
        return (baseArea * height) / 3.0;
    }
};

class Sphere : public GeometricBody
{
private:
    double radius;

public:
    Sphere(double radius) : radius(radius) {}

    double surfaceArea() const override
    {
        return 4 * pi * radius * radius;
    }

    double volume() const override
    {
        return (4.0 / 3.0) * pi * radius * radius * radius;
    }
};

double inputValue(const string& prompt)
{
    double value;
    do
    {
        cout << prompt;
        cin >> value;
        if (value < 0)
        {
            cout << "Значення повинно бути невід’ємним. Введіть ще раз.\n";
        }
    } 
    while (value < 0);
    return value;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть дані для піраміди:\n";
    double pyramidBaseArea = inputValue("Площа основи: ");
    double pyramidHeight = inputValue("Висота: ");

    GeometricBody* pyramid = new Pyramid(pyramidBaseArea, pyramidHeight);

    cout << "\nВведіть дані для кулі:\n";
    double sphereRadius = inputValue("Радіус: ");

    GeometricBody* sphere = new Sphere(sphereRadius);

    cout << "\nРезультати для піраміди:\n";
    cout << "Площа поверхні піраміди: " << pyramid->surfaceArea() << endl;
    cout << "Об'єм піраміди: " << pyramid->volume() << endl;

    cout << "\nРезультати для кулі:\n";
    cout << "Площа поверхні кулі: " << sphere->surfaceArea() << endl;
    cout << "Об'єм кулі: " << sphere->volume() << endl;

    delete pyramid;
    delete sphere;

    return 0;
}