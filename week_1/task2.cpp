#include <iostream>

enum Flavours
{
    dummy = 0,
    Chocolate,
    Vanilla,
    Cream,
    Strawberry
};

struct IceCream
{
    double price;
    int grams;
    Flavours flavour;

    void create()
    {
        int choice;
        std::cout << "Enter ice cream:" << std::endl;
        std::cout << "Enter flavour (1 - chocolate, 2 - vanilla, 3 - cream, 4 - strawberry)" << std::endl;
        std::cin >> choice;
        flavour = getFlavour(choice);
        std::cout << "Enter price: " << std::endl;
        std::cin >> price;
        std::cout << "Enter grams: " << std::endl;
        std::cin >> grams;
    }

    Flavours getFlavour(int choice)
    {
        switch (choice)
        {
            case 1:
                return Chocolate;
            case 2:
                return Vanilla;
            case 3:
                return Cream;
            case 4:
                return Strawberry;
            default:
                return dummy;
        }
    }

    void print()
    {
        std::cout << std::endl;
        switch (flavour)
        {
            case 1:
            {
                std::cout << "Chocolate" << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "Vanilla" << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "Cream" << std::endl;
                break;
            }
            case 4:
            {
                std::cout << "Strawberry" << std::endl;
                break;
            }
            
        }
        std::cout << price << std::endl;
        std::cout << grams << std::endl;
    }
};

struct IceCreamFactory
{
    IceCream iceCream[3];

    void getMostExpensive()
    {

        IceCream mostExps = iceCream[0];
        for (int i = 0; i < 3; i++)
        {

            if (iceCream[i].price > mostExps.price)
            {

                mostExps = iceCream[i];
            }
        }
        std::cout << "Most expensive:" << std::endl;
        mostExps.print();
    }
};

int main()
{
    IceCream ic;
    ic.create();
    ic.print();
}