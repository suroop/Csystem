#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
typedef struct info{
    string section;
    string name;
    string sex;
    int age;
    string type;
    double wage;
    int ID;
    string pass;
} info;
class Info{
    private:
        Info *next = NULL;      
        info information;      
        static int count;       
    public:
        Info();  
        static int getLength();     
        bool insertAfter(Info *);   
        bool deleteAfter();  
        info returnInfo();      
        void setterInfo(string, double, string, int, string, int,string,string );   
        void editInfo(int,string);
        Info* nextinfo(Info *); 
        Info *getNext();    
        friend Info *infoList(Info *);  
        friend int search(Info *, int );    
        friend Info* search(Info *, int, string);
        friend bool wirteIntoFile(Info *);  
        friend bool printAll(Info *ptr);    
        friend bool sortBygender(Info *ptr, int choice);    
        friend void editInfo(int,string,Info *) ;
        friend void sortByAge(Info *);
        friend void sortByWage(Info *ptr);
        friend void sortByID(Info *ptr);
        ~Info();
};
class Person{
    protected:
        int ID;
        string pass;
    public:
        Person(){
            this->ID=000;
            this->pass="123";
        }
        Person(int,string);
        void Prev();
        void login(Info *);
        void regist(Info *);
        virtual void display(Info *, Info *);
        virtual void Editor(Info *,Info *);
        virtual void menu(Info *,Info *);
        ~Person();
};
class Worker:public Person{
    protected:
        string name;
        string sex;
        int age;
        string type;
        double wage;
    public:
        Worker(){
            this->ID = 000;
            this->pass = "123";
            this->name = "user";
            this->age = 0;
            this->sex = "male";
            this->type = "NULL";
            this->wage = 0;
        }
        Worker(string name, string sex, int age, string type, double wage, int id, string passwd);
        void Editor(Info *,Info *);
        void display(Info *,Info *);
        void menu(Info *,Info *);
        ~Worker();
};
class Manager:public Worker{
    private:
        string section;
    public:
        Manager(){
            this->ID = 000;
            this->pass = "123";
            this->name = "user";
            this->age = 0;
            this->sex = "male";
            this->type = "NULL";
            this->wage = 0;
            this->section="NULL";
        }
        Manager(string, string, string, int, string, double,  int,string);
        void Editor(Info *,Info *);
        void Add(Info *,Info *);
        void Delete(Info *,Info *);
        void Sort(Info *, Info *);
        void display(Info *, Info *);
        void menu(Info *,Info *);
        ~Manager();
};
