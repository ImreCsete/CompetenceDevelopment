// eLearning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

double getArea();
double calcPrice(double sqr, double price);

int main()
{   
    std::string rainbow[] = { "Yellow", "Orange", "Red", "Purple", "Blue", "Teal", "Green" };
    
    for (auto&& i : rainbow)
    {
        std::cout << i << ", " << std::endl;
    }
    
}

double getArea() {
    double x = 0;
    double y = 0;

    std::cout << "Please enter the length of the room: " << std::endl;
    std::cin >> x;
    std::cout << "Please enter the width of the room: " << std::endl;
    std::cin >> y;

    return x * y;
}

double calcPrice(double sqr, double price) {
    
    const int minimalArea = 120;
    const double defaultPrice = 99;

    if (sqr <= minimalArea) {
        return defaultPrice;
    }
    else {
        return (sqr - minimalArea) * price + defaultPrice;
    }
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
