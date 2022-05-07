#include "Bank.h"

int main(){
    Person ivan("Ivan Petrov", "41040000kb");
    Person gosho("Georgi Ivanov", "32997500pb");
    Person ivana("Ivana Georgieva", "21314507kl");
    Person pesho("Petar Petrov", "11830000tm");
    Person mitko("Dimitar Georgiev", "873400sa");
    Person geri("Gergana Dimitrova", "46289080pv");

    DraftInfo drfInfo[6] = {{250, "21/06/2021"}, {50, "03/07/2021"}, {100, "18/07/2021"}, {120, "29/07/2021"}, {250, "05/08/2021"}, {150, "12/08/2021"}};
    DraftInfo drfInfo1[3] = {{140, "09/12/2022"}, {50, "26/12/2022"}, {300, "29/12/2022"}};
    DraftInfo drfInfo2[2] = {{200, "31/09/2020"}, {500, "12/10/2020"}};

    CurrentAccount currAcc(ivan, 8000, 210388009, 5000, 2.20, drfInfo, 6);
    CurrentAccount currAcc1(gosho, 12000, 782495923, 3000, 1.99, drfInfo1, 3);
    CurrentAccount currAcc2(ivana, 15000, 83247332, 5000, 2.12, drfInfo2, 2);
    CurrentAccount currAcc3(mitko, 3500, 3480923, 580, 1.99, drfInfo, 6);

    SavingsAccount sAcc(pesho, 7800, 8347394, 0.03, 3.98);
    SavingsAccount sAcc1(ivana, 3200, 8394893, 0.04, 4.60);
    SavingsAccount sAcc2(mitko, 14000, 38487474, 0.05, 3.99);
    SavingsAccount sAcc3(geri, 9500, 39048903, 0.03, 5.12);

    Employee emp1(ivan, 1700, 2018, "supplier");
    Employee emp2(gosho, 950, 2022, "hygienist");
    Employee emp3(ivana, 3500, 2019, "manager");
    Employee emp4(pesho, 1500, 2017, "secretary");
    Employee emp5(mitko, 1250, 2022, "secreatry");
    Employee emp6(geri, 1300, 2019, "supplier");

    Bank bank;

    bank.addEmployee(emp1);
    bank.addEmployee(emp2);
    bank.addEmployee(emp3);
    bank.addEmployee(emp4);
    bank.addEmployee(emp5);
    bank.addEmployee(emp6);

    bank.addSavingsAcc(sAcc);
    bank.addSavingsAcc(sAcc1);
    bank.addSavingsAcc(sAcc2);
    bank.addSavingsAcc(sAcc3);

    bank.addCreditAcc(currAcc);
    bank.addCreditAcc(currAcc3);
    bank.addCreditAcc(currAcc2);
    bank.addCreditAcc(currAcc1);

    bank.printAllAccounts("21314507kl");
    bank.printAllEmployeesWithAcc();

    return 0;
}