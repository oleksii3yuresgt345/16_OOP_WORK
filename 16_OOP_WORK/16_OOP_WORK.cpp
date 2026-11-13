#include <iostream>
using namespace std;

/*
Завдання N 1
Створити базовий клас Employer (служ-
бовець) з чисто віртуальною функцією Print (). Створіть
три похідних класи: President, Manager, Worker. Переви-
значите функцію Print() для виведення інформації, що
відповідає кожному типу службовця.
Завдання N 2
Створити базовий клас «Транспортний
засіб» і похідні класи «Автомобіль», «Велосипед», «Віз».
Підрахувати час і вартість перевезення пасажирів і
вантажів кожним транспортним засобом.*/

class Employer
{
protected:
    string name;
    int wage;
    int experience;
public:
    Employer() :name("no name"), wage(0), experience(0){}
    Employer(string n, int w, int e) :name(n), wage(w), experience(e){}
    virtual void Print() = 0;
};

class President : public Employer
{
    int guards;
public:
    President() :guards(0), Employer(){}
    President(string n, int w, int e, int g) :guards(g), Employer(n, w, e){}
    void Print()
    {
        cout << "President's name : " << name << endl;
        cout << "President's wage : " << wage << endl;
        cout << "President's experience : " << experience << endl;
        cout << "President's guards : " << guards << endl << endl;
    }
};

class Manager : public Employer
{
    int workers;
public:
    Manager():workers(0), Employer(){}
    Manager(string n, int w, int e, int ws):workers(ws), Employer(n, w, e){}
    void Print()
    {
        cout << "Manager's name : " << name << endl;
        cout << "Manager's wage : " << wage << endl;
        cout << "Manager's experience : " << experience << endl;
        cout << "Manager's guards : " << workers << endl << endl;
    }
};

class Worker : public Employer
{
    string workName;
public:
    Worker() :workName("no work name"), Employer() {}
    Worker(string n, int w, int e, string wn):workName(wn), Employer(n, w, e){}
    void Print()
    {
        cout << "Worker's name : " << name << endl;
        cout << "Worker's wage : " << wage << endl;
        cout << "Worker's experience : " << experience << endl;
        cout << "Worker's work name : " << workName << endl << endl;
    }
};

class Transport
{
protected:
    string name;
    int speed;
    int passangers;
    int distance;
public:
    Transport() :name("no name"), speed(0), passangers(0), distance(0) {}
    Transport(string n, int s, int p, int d) :name(n), speed(s), passangers(p), distance(d) {}
    virtual void Print() = 0;
};

class Car : public Transport
{
    int fuelCost;
public:
    Car() : fuelCost(0), Transport() {}
    Car(string n, int s, int p, int d, int f) : fuelCost(f), Transport(n, s, p, d) {}
    void Print()
    {
        cout << "Car's name : " << name << endl;
        cout << "Car's speed : " << speed << endl;
        cout << "Car's passangers : " << passangers << endl;
        cout << "Car's fuel cost : " << fuelCost << endl;
        cout << "The passanger has to pay " << (distance / speed) * fuelCost << "hrn for " << distance << "m" << endl << endl;
    }
};

class Bicycle : public Transport
{
    int energy;
public:
    Bicycle() : energy(0), Transport() {}
    Bicycle(string n, int s, int p, int d, int e) : energy(e), Transport(n, s, p, d) {}
    void Print()
    {
        cout << "Bicycle's name : " << name << endl;
        cout << "Bicycle's speed : " << speed << endl;
        cout << "Bicycle's passangers : " << passangers << endl;
        cout << "Driver's energy : " << energy << endl;
        cout << "The passanger has to pay " << (distance / speed) * energy << "hrn for " << distance << "m" << endl << endl;
    }
};

class Viz : public Transport
{
    int wheatCost;
public:
    Viz() : wheatCost(0), Transport() {}
    Viz(string n, int s, int p, int d, int w) : wheatCost(w), Transport(n, s, p, d) {}
    void Print()
    {
        cout << "Viz's name : " << name << endl;
        cout << "Viz's speed : " << speed << endl;
        cout << "Viz's passangers : " << passangers << endl;
        cout << "Horse wheat cost : " << wheatCost << endl;
        cout << "The passanger has to pay " << (distance / speed) * wheatCost << "hrn for " << distance << "m" << endl << endl;
    }
};
int main()
{
    President president("Tom", 2000, 5, 5);
    Manager manager("Tom2", 10000, 3, 4);
    Worker worker("Tom3", 1000, 2, "Cool Job");

    president.Print();
    manager.Print();
    worker.Print();

    cout << "=============================================" << endl;

    Car car("Car", 160, 4, 1000, 95);
    Bicycle bicycle("Bicycle", 120, 2, 2000, 200);
    Viz viz("Viz", 60, 4, 4000, 120);

    car.Print();
    bicycle.Print();
    viz.Print();
}
