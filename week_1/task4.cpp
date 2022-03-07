#include <iostream>
#include <cstring>

enum Gender{Female, Male};

struct Doctor
{
    char name[20];
    int yearsOfWork;
    char hospitalName[20];
    Gender gender;

    void createDoctor()
    {
        std::cout << "Enter doctor: " << std::endl;
        std::cout << "Enter name: " << std::endl;
        std::cin.getline(name, 20);
        std::cout << "Enter years of work: " << std::endl;
        std::cin >> yearsOfWork;
        std::cout << "Enter hospital name: " << std::endl;
        std::cin.ignore();
        std::cin.getline(hospitalName, 20);
        char choice;
        std::cout << "Enter gender(f/m): " << std::endl;
        std::cin >> choice;
        gender = getGender(choice);
        std::cin.ignore();
    }

    Gender getGender(int choice)
    {
        switch (choice)
        {
            case 'f':
                return Female;
            case 'm':
                return Male;
        }
    }

    void printDoctor()
    {
        std::cout << std::endl << name << std::endl;
        std::cout << yearsOfWork << std::endl;
        std::cout << hospitalName << std::endl;
        switch (gender)
        {
            case 0:
            {
                std::cout << "Female" << std::endl;
                break;
            }
            case 1:
            {
                std::cout << "Male" << std::endl;
                break;
            }
        }
    }

    void changeHospital()
    {
        char *newName = new char[20];
        std::cout << "Enter new hospital name: ";
        std::cin.getline(hospitalName, 20);
    }

     void changeDoctorName()
    {
        std::cout << "Enter new name: ";
        std::cin.getline(name, 20);
    }
};

int main()
{
    Doctor doctors[3];

    for(int i = 0; i < 3; i++)
        doctors[i].createDoctor();

    for(int i = 0; i < 3; i++)
    {
        for(int j = i; j < 3; j++)
        {
            if(doctors[i].yearsOfWork < doctors[j].yearsOfWork)
            {
                Doctor temp = doctors[i];
                doctors[i] = doctors[j];
                doctors[j] = temp;
            }
        }
    }

    for(int i = 0; i < 3; i++)
        doctors[i].printDoctor();

    doctors[2].changeDoctorName();
    doctors[1].changeHospital();

    for(int i = 0; i < 3; i++)
        doctors[i].printDoctor(); 

}