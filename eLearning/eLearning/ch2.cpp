#include <iostream>
#include <string>
#include <iomanip>

int mainch2()
{
    std::string lastName = "";
    int price;
    double seller = 0.06;
    double commission = 0.015;

    std::cout << "Enter the homeowner's last name: " << std::endl;
    std::getline(std::cin, lastName);
    std::cout << "Enter the sales price for the house: (no commas or decimal points) " << std::endl;
    std::cin >> price;

    std::cout << "\tHome Owner" << std::setw(15) << "\tPrice of Home" << "\tSeller's Cost" << "\tAgent's Commission" << std::endl;

    return 0;
}