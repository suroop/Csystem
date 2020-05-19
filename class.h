#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
class Person{
protected:
    int ID;
    string pass;
public:
    Person(int,string);
    ~Person();
    virtual void display() const =0;
    virtual void Editor() = 0;
    virtual void menu() = 0;
};
class Worker:protected Person{
    protected:
        string name;
        string sex;
        int age;
        string type;
        double wage;
    public:
        Worker(string, string,int, string,double ,int,string );
        ~Worker();
        void Editor();
        void display() const;
        void menu();
};
class Manager:protected Worker{
    private:
        string section;
    public:
        Manager(string, string, string, int, string, double,  int,string);
        void Editor();
        void Add();
        void Delete();
        void Sort();
        void display() const;
        void menu();
        ~Manager();
};
typedef struct info_Worker{
    string name;
    string sex;
    int age;
    string type;
    double wage;
    int ID;
    string pass;
    int count;
} info_Worker;
typedef struct info_Manager{
    string section;
    string name;
    string sex;
    int age;
    string type;
    double wage;
    int ID;
    string pass;
    int count;
} info_Manager;
void login(int);
void regist(int);
