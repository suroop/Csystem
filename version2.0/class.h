#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
typedef struct info_Worker
{
    string name;
    string sex;
    int age;
    string type;
    double wage;
    int ID;
    string pass;
    int count;
} info_Worker;
typedef struct info_Manager
{
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

class infoWorker{
    private:
        infoWorker *next = NULL;
        static int count;
    public:
        info_Worker information ;
        infoWorker();
        static int getLength();
        bool insertAfter(infoWorker *);
        infoWorker* nextinfo(infoWorker *);
        infoWorker *getNext();
        ~infoWorker();
};
class infoManager{
    private:
        infoManager *next = NULL;
        static int count;
    public:
        info_Manager information;
        infoManager();
        static int getLength();
        bool insertAfter(infoManager *);
        bool insertAfter(infoManager &);
        infoManager nextinfo(infoManager *);
        infoManager *getNext();
        ~infoManager();
};
class Person{
    protected:
        int ID;
        string pass;
    public:
        Person(int,string);
        void Prev();
        void login(int);
        void regist(int);
        virtual void display() const;
        virtual void Editor();
        virtual void menu();
        ~Person();
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
info_Worker *writeFromFile(int choice);
info_Manager *writeFromFile(float choice);
bool writeIntoFile(info_Worker workers[]);
bool writeIntoFile(info_Manager managers[]);
bool printAll(info_Worker worker[]);
int search(info_Worker worker[], int id);
int search(info_Manager manager[], int id);
bool sortBySex(int option, info_Worker worker[]);
info_Worker *sortBysection(string section, info_Worker worker[]);
bool sortByID(info_Worker worker[]);
bool sortByAge(info_Worker worker[]);
bool sortByWage(info_Worker worker[]);