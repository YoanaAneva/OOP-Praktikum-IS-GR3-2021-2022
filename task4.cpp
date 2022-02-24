#include <iostream>

struct Doctor
{
    char name[20];
    int yearsOfWork;
    char hospitalName[30];
    char gender[7];

    void createDoctor()
    {
        std::cout << "Enter doctor: " << std::endl;
        std::cout << "Enter name: " << std::endl;
        std::cin.getline(name, 20);
        std::cout << "Enter years of work: " << std::endl;
        std::cin >> yearsOfWork;
        std::cout << "Enter hospital name: " << std::endl;
        std::cin.ignore();
        std::cin.getline(hospitalName, 30);
        std::cout << "Enter gender: " << std::endl;
        std::cin.getline(gender, 7);
    }

    void printDoctor()
    {
        std::cout << std::endl << name << std::endl;
        std::cout << yearsOfWork << std::endl;
        std::cout << hospitalName << std::endl;
        std::cout << gender << std::endl;
    }

    void changeName()
    {
        char *newName = new char[20];
        std::cout << "Enter new name: ";
        std::cin.getline(newName, 30);

        for(int i = 0; i < 30; i++)
            name[i] = newName[i];

        delete[] newName;
    }

    void changeHospital()
    {
        char *newName = new char[20];
        std::cout << "Enter new name: ";
        std::cin.getline(newName, 30);

        for (int i = 0; i < 30; i++)
            hospitalName[i] = newName[i];

        delete[] newName;
    }
};

int main()
{
    Doctor doctors[10];

    for(int i = 0; i < 10; i++)
        doctors[i].createDoctor();

    for(int i = 0; i < 10; i++)
    {
        for(int j = i; j < 10; j++)
        {
            if(doctors[i].yearsOfWork < doctors[j].yearsOfWork)
            {
                Doctor temp = doctors[i];
                doctors[i] = doctors[j];
                doctors[j] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++)
        doctors[i].printDoctor();

}