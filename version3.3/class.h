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
        Info *next = NULL;      //下一个对象的地址 
        info information;       //存储信息
        static int count;       //计数用
    public:
        Info();  
        static int getLength();     //返回计数
        bool insertAfter(Info *);   //插入链表
        bool deleteAfter();  //删除链表
        info returnInfo();      //返回该对象的信息
        void setterInfo(string, double, string, int, string, int,string,string );   //对该对象进行赋值
        void editInfo(int,string);
        Info* nextinfo(Info *); 
        Info *getNext();    //返回下一个对象的地址
        friend Info *infoList(Info *);  //获得文件的数据,并生成链表
        friend int search(Info *, int );    //查询目标对象
        friend Info* search(Info *, int, string);
        friend bool wirteIntoFile(Info *);  //将数据写入文件
        friend bool printAll(Info *ptr);    //打印所有数据
        friend bool sortBygender(Info *ptr, int choice);    //按性别分类
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
