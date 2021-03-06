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
}info;
class Info{
    private:
        Info *next = NULL;      
        info information;      
    public:
        static int count;
        Info();
        static int getLength();
        bool insertAfter(Info *,Info *);   
        bool deleteAfter();  
        info returnInfo(info);     
        void setterInfo(string, double, string, int, string, int,string,string );   
        Info* nextinfo(Info *); 
        Info *getNext();    
        friend Info *infoList(Info *);  
        friend int search(Info *, int );   
        friend bool wirteIntoFile(Info *);  
        friend bool printAll(Info *ptr);   
        friend bool sortBygender(Info *ptr, int choice);    
        friend bool sortByother(Info *);
        ~Info();
};
class Person{
    protected:
        int ID;
        string pass;
    public:
        Person(int,string);
        void Prev();
        void login();
        void regist();
        virtual void display() const;
        virtual void Editor();
        virtual void menu();
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
        Worker(string, string,int, string,double ,int,string );
        ~Worker();
        void Editor();
        void display() const;
        void menu();
};
class Manager:public Worker{
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

Info::Info(){   //ok
    count++;
}
int Info::count=0;
int Info::getLength(){      //ok
    return count;
}
bool Info::insertAfter(Info *temp, Info *ptr){
    temp->nextinfo(ptr->getNext());
    ptr->nextinfo(temp);
    this->next=ptr;
}
bool Info::deleteAfter(){
    Info *temp=new Info();
    temp=this->getNext();
    this->nextinfo(temp->getNext());
    delete temp;
    return true;
}
info Info::returnInfo(info message){        //ok
    message.ID=this->information.ID;
    message.pass = this->information.pass;
    message.name = this->information.name;
    message.age = this->information.age;
    message.sex = this->information.sex;
    message.type=this->information.type;
    message.wage = this->information.wage;
    message.section= this->information.section;
    return message;
}
void Info::setterInfo(string type, double wage, string name, int age, string sex, int ID, string pass, string section = "NULL"){
    this->information.ID =ID;
    this->information.pass =pass;
    this->information.name =name;
    this->information.age =age;
    this->information.sex =sex;
    this->information.type =type;
    this->information.wage =wage;
    this->information.section = section;
}
Info *Info::nextinfo(Info *ptr){
    this->next = ptr;
}
Info *Info::getNext(){      //ok
    return this->next;
};
Info::~Info(){
    cout << 123 << endl;
    count--;
}

Person::Person(int ID, string pass){ // Person's Constructor
    if(ID==123&&pass=="root"){
        this->ID = ID;
        this->pass=pass;
    }
    else{
        exit(1);
    }
    
}
void Person::Prev(){        //ok
    int option;
    cout << "-------------------------------" << endl;
    cout << "|          1.login            |" << endl;
    cout << "|          2.regist           |" << endl;
    cout << "-------------------------------" << endl;
    cin >> option;
    if (option == 1){
        system("cls");
        login();
    }
    else if (option == 2){
        system("cls");
        regist();
    }
    else{
        cerr << "Exiting program..." << endl;
        exit(0);
    }
}
void Person::display() const{       //ok
    cout<<"display"<<endl;
};
void Person::menu(){            //ok
    cout << "menu" << endl;
}
void Person::Editor(){      //ok
    cout << "Editor" << endl;
};
void Person::regist(){
    bool flag = true;
    int ID;
    cout << "-------------------------------" << endl;
    cout << "input the ID you want to create" << endl;
    cout << "-------------------------------" << endl;
    cin >> ID;
    Info *ptr = new Info();
    Info *newptr = infoList(ptr);
    try{
        if (search(newptr, ID)){
            throw ID;
        }
    }
    catch(const exception& e){
        cout << "-------------------------------" << endl;
        cout << "        ID was registedd       " << endl;
        cout << "-------------------------------" << endl;
    }
    Info *temptr=new Info();
    string pass,checkpass,name,sex,type,section="NULL";
    int age;
    double wage;
    cout << "-------------------------------" << endl;
    cout << "       input your password     " << endl;
    cout << "-------------------------------" << endl;
    cin>>pass;
    do{
        cout << "-------------------------------" << endl;
        cout << "   input your password again   " << endl;
        cout << "-------------------------------" << endl;
        cin >> checkpass;
        if (checkpass != pass){
            cout << "-------------------------------" << endl;
            cout << "    password is not the same   " << endl;
            cout << "-------------------------------" << endl;
        }
    } while (checkpass!=pass);
    cout << "-------------------------------" << endl;
    cout << "         input your name       " << endl;
    cout << "-------------------------------" << endl;
    cin>>name;
    cout << "-------------------------------" << endl;
    cout << "         input your age       " << endl;
    cout << "-------------------------------" << endl;
    cin >> age;
    cout << "-------------------------------" << endl;
    cout << "         input your sex       " << endl;
    cout << "-------------------------------" << endl;
    cin >> sex;
    cout << "-------------------------------" << endl;
    cout << "         input your wage       " << endl;
    cout << "-------------------------------" << endl;
    cin >> wage;
    cout << "-------------------------------" << endl;
    cout << "         input your type       " << endl;
    cout << "-------------------------------" << endl;
    cin >> type;
    if(1==1){
        cout << "-------------------------------" << endl;
        cout << "      input your section       " << endl;
        cout << "-------------------------------" << endl;
        cin >> section;
    }
    temptr->setterInfo(type, wage, name, age, sex, ID, pass,section);
    newptr->insertAfter(temptr,newptr);
    cout << "-------------------------------" << endl;
    cout << "     successfully registed     " << endl;
    cout << "-------------------------------" << endl;
    system("cls");
    wirteIntoFile(newptr);
    delete temptr,ptr,newptr;
    login();
}
void Person::login(){ //login
    bool flag = true;
    int ID;
    string pass;
    cout << "-------------------------------" << endl;
    cout << "    please input your ID      :" << endl;
    cout << "-------------------------------" << endl;
    cin >> ID;
    cout << "-------------------------------" << endl;
    cout << "  please input your password  :" << endl;
    cout << "-------------------------------" << endl;
    cin >> pass;
    Info *ptr = new Info();
    Info *nowptr = infoList(ptr);
    try{
        if (search(nowptr, ID))
        {
            throw ID;
        }
    }
    catch (const exception &e){
        cout << "-------------------------------" << endl;
        cout << "    ID or password is wrong    " << endl;
        cout << "-------------------------------" << endl;
    }
    Person*person0;
    info message;
    message=nowptr->returnInfo(message);
    if(message.section=="NULL"){
        person0=new Worker(message.type,message.name, message.age,message.sex, message.wage,message.ID,message.pass);
        person0->menu();
    }
    else{
        person0= new Manager(message.section,message.type, message.name,message.age,message.sex,message.wage,message.ID,message.pass);
        person0->menu();
    }
    delete person0;
}
Person::~Person(){
    cout<<"Person"<<endl;
}

Worker::Worker(string name, string sex, int age, string type, double wage, int ID, string pass) : Person(ID, pass){
    this->ID = ID;
    this->pass = pass;
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->wage=wage;
    this->type=type;
}
void Worker::menu(){        //ok
    int choice;
    cout << "--------------------------------" << endl;
    cout << "|        input a number        |"<<endl;
    cout << "--------------------------------" << endl;
    cout << "|           1.display          |"<<endl;
    cout << "|           2.edit             |"<<endl;
    cout << "--------------------------------" << endl;
    cin>>choice;
    if(choice==1){
        display();
    }
    else if(choice==2){
        Editor();
    }
    else{
        menu();
    }
}
void Worker::display() const{       //ok
    cout << "-----------information---------" << endl;
    cout << "|ID:" << this->ID << endl;
    cout << "-------------------------------" << endl;
    cout << "|name:" << this->name << endl;
    cout << "-------------------------------" << endl;
    cout << "|sex:" << this->sex << endl;
    cout << "-------------------------------" << endl;
    cout << "|age:" << this->age << endl;
    cout << "-------------------------------" << endl;
    cout << "|type:" << this->type << endl;
    cout << "-------------------------------" << endl;
    cout << "|wage" << this->wage << endl;
    cout << "-------------------------------" << endl;
}
void Worker::Editor(){
    int option;
    string temp;
    Info *ptr=new Info();
    Info *nowptr = infoList(ptr);
    try{
        if (search(nowptr, ID))
        {
            throw ID;
        }
    }
    catch (const exception &e){
        cout << "-------------------------------" << endl;
        cout << "        ID was registedd       " << endl;
        cout << "-------------------------------" << endl;
    }
    cout << "-------------------------------" << endl;
    cout << "|  what do you want do edit?  |" << endl;
    cout << "-------------------------------" << endl;
    cout << "|            1.name           |" << endl;
    cout << "|            2.password       |" << endl;
    cout << "|            3.type           |" << endl;
    cout << "|            4.age            |" << endl;
    cout << "-------------------------------" << endl;
    cin >> option;
    cout << "-------------------------------" << endl;
    cout << "|        input content:       |" << endl;
    cout << "-------------------------------" << endl;
    cin >> temp;
    /*switch (option)
    {
    case 1:
        nowptr->information.name = temp;
        break;
    case 2:
        nowptr->information.pass = temp;
        break;
    case 3:
        nowptr->information.type = temp;
        break;
    case 4:
        nowptr->information.age = atoi(temp.c_str()); //string => int
        break;
    default:
        cout << "NOT 1~4" << endl;
        system("cls");
        Editor();
        break;
    }*/
    wirteIntoFile(nowptr);
    system("cls");
    menu();
}
Worker::~Worker(){
    cout<<"Worker"<<endl;
}

Manager::Manager(string section, string name, string sex, int age, string type, double wage, int ID, string pass) : Worker(name, sex, age,type, wage, ID,pass){
    this->ID = ID;
    this->pass = pass;
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->wage = wage;
    this->type = type;
    this->section=section;
}
void Manager::menu(){       //ok
    int choice;
    cout << "-------------------------------" << endl;
    cout << "|        input a number       |" << endl;
    cout << "-------------------------------" << endl;
    cout << "|            1.add            |"<<endl;
    cout << "|            2.sort           |"<<endl;
    cout << "|            3.delete         |"<<endl;
    cout << "|            4.display        |"<<endl;
    cout << "|            5.editor         |"<<endl;
    cout << "-------------------------------" << endl;
    cin>>choice;
    switch (choice){
    case 1:
        Add();
        break;
    case 2:
        Sort();
        break;
    case 3:
        Delete();
        break;
    case 4:
        display();
        break;
    case 5:
        Editor();
        break;
    default:
        cout<<"exiting programing"<<endl;
        exit(0);
        break;
    }
}
void Manager::Add(){
    int ID, age;
    double wage;
    bool flag=true;
    string password,name,type;
    cout << "-------------------------------" << endl;
    cout << "|        input the ID         |" << endl;
    cout << "-------------------------------" << endl;
    cin >> ID;
    Info *ptr = new Info();
    Info *newptr = infoList(ptr);
    try{
        if (search(newptr, ID)){
            throw ID;
        }
    }
    catch (const exception &e){
        cout << "-------------------------------" << endl;
        cout << "|         ID was wrong        |" << endl;
        cout << "-------------------------------" << endl;
    }
    cout << "-------------------------------" << endl;
    cout << "|      input the password     |" << endl;
    cin>>password;
    cout << "-------------------------------" << endl;
    cout << "|        input the name       |" << endl;
    cin>>name;
    cout << "-------------------------------" << endl;
    cout << "|        input the age        |" << endl;
    cin>>age;
    cout << "|------------------------------" << endl;
    cout << "|        input the wage       |" << endl;
    cin>>wage;
    cout << "|------------------------------" << endl;
    cout << "|        input the type       |" << endl;
    cin>>type;
    Info *temp=new Info();
    temp->setterInfo(type,wage,name,age,sex,ID,pass,section);
    newptr->insertAfter(temp,newptr);
    wirteIntoFile(newptr);
    system("cls");
    menu();
}
void Manager::Delete(){
    string ch;
    bool flag=true;
    int id;
    cout << "-------------------------------" << endl;
    cout << "|  The ID you want to delete:  " << endl;
    cout << "-------------------------------" << endl;
    cin>>id;
    Info *ptr = new Info();
    Info *nowptr = infoList(ptr);
    try
    {
        if (search(nowptr, id))
        {
            throw id;
        }
    }
    catch (const exception &e)
    {
        cout << "-------------------------------" << endl;
        cout << "|      can't find the ID      |" << endl;
        cout << "-------------------------------" << endl;
    }
    info message;
    message = nowptr->returnInfo(message);
    cout << "----------information----------" << endl;
    cout << "|ID:" << message.ID << endl;
    cout << "-------------------------------" << endl;
    cout << "|name:" << message.name << endl;
    cout << "-------------------------------" << endl;
    cout << "|sex:" << message.sex << endl;
    cout << "-------------------------------" << endl;
    cout << "|age:" << message.age << endl;
    cout << "-------------------------------" << endl;
    cout << "|type:" << message.type << endl;
    cout << "-------------------------------" << endl;
    cout << "|wage" << message.wage << endl;
    cout << "-------------------------------" << endl;
    cout<<"sure?(Y/N)"<<endl;
    cin>>ch;
    if(ch=="Y"||ch=="y"){
        nowptr->deleteAfter();
    }
    else{
        system("cls");
        menu();
    }
    wirteIntoFile(nowptr);
    cout << "-------------------------------" << endl;
    cout << "|           finshed           |"<<endl;
    cout << "-------------------------------" << endl;
    system("cls");
    menu();
}
void Manager::Editor(){
    int choice;
    cout << "-------------------------------" << endl;
    cout << "|      input your choice      |" << endl;
    cout << "-------------------------------" << endl;
    cout << "|          1.yourself         |" << endl;
    cout << "|          2.workers          |" << endl;
    cout << "-------------------------------" << endl;
    cin>>choice;
    if(choice==1){
        Info *ptr = new Info();
        Info *nowptr = infoList(ptr);
        search(nowptr,this->ID);
        int option;
        string temp;
        cout << "-------------------------------" << endl;
        cout << "|  what do you want do edit?  |" << endl;
        cout << "-------------------------------" << endl;
        cout << "|            1.name           |" << endl;
        cout << "|            2.password       |" << endl;
        cout << "|            3.type           |" << endl;
        cout << "|            4.age            |" << endl;
        cout << "-------------------------------" << endl;
        cin >> option;
        cout << "-------------------------------" << endl;
        cout << "|        input content:       |" << endl;
        cout << "-------------------------------" << endl;
        cin >> temp;
        /*switch (option){
        case 1:
            nowptr->information.name = temp;
            break;
        case 2:
            nowptr->information.pass = temp;
            break;
        case 3:
            nowptr->information.type = temp;
            break;
        case 4:
            nowptr->information.age = atoi(temp.c_str()); //string => int
            break;
        default:
            cout << "NOT 1~4" << endl;
            system("cls");
            Editor();
            break;
        }*/
        wirteIntoFile(nowptr);
    }
    else if(choice==2){
        Info *ptr = new Info();
        Info *nowptr = infoList(ptr);
        search(nowptr, this->ID);
        int option,ID;
        string temp;
        cout << "-------------------------------" << endl;
        cout << "|      input worker's ID      |" << endl;
        cout << "-------------------------------" << endl;
        cin>>ID;
        cout << "-------------------------------" << endl;
        cout << "|  what do you want do edit?  |" << endl;
        cout << "-------------------------------" << endl;
        cout << "|            1.name           |" << endl;
        cout << "|            2.password       |" << endl;
        cout << "|            3.type           |" << endl;
        cout << "|            4.age            |" << endl;
        cout << "|            5.wage           |" << endl;
        cout << "-------------------------------" << endl;
        cin >> option;
        cout << "-------------------------------" << endl;
        cout << "|        input content:       |" << endl;
        cout << "-------------------------------" << endl;
        cin >> temp;
        /*switch (option){
            case 1:
                nowptr->information.name = temp;
                break;
            case 2:
                nowptr->information.pass = temp;
                break;
            case 3:
                nowptr->information.type = temp;
                break;
            case 4:
                nowptr->information.age = atoi(temp.c_str()); //string => int
                break;
            case 5:
                nowptr->information.wage = atoi(temp.c_str());
                break;
            default:
                cout << "NOT 1~5" << endl;
                system("cls");
                Editor();
                break;
        }*/
        wirteIntoFile(nowptr);
    }
    else{
        cout << "-------------------------------" << endl;
        cerr << "|  input the correct number!  |" << endl;
        cout << "-------------------------------" << endl;
        system("cls");
        Editor();
    }
    system("cls");
    menu();
}
void Manager::Sort(){
    int option;
    cout << "-------------------------------" << endl;
    cout << "|          1.by ID            |" << endl;
    cout << "|          2.by sex           |" << endl;
    cout << "|          3.by age           |" << endl;
    cout << "|          4.by wage          |" << endl;
    cout << "-------------------------------" << endl;
    cin>>option;
    Info *p=new Info();
    switch (option){
    case 1:
        printAll(p);
        break;
    case 2:
        cout << "1.female" << endl;
        cout << "2.male" << endl;
        cin>>option;
        sortBygender(p,option);
        break;
    case 3:
        //sortByAge(newworker);
        printAll(p);
        break;
    case 4:
        //sortByWage(newworker);
        printAll(p);
        break;
    default:
        break;
    }
} 
void Manager::display() const{      //ok
    cout << "----------information----------" << endl;
    cout << "|ID:" << this->ID << endl;
    cout << "-------------------------------" << endl;
    cout << "|name:" << this->name << endl;
    cout << "-------------------------------" << endl;
    cout << "|sex:" << this->sex << endl;
    cout << "-------------------------------" << endl;
    cout << "|age:" << this->age << endl;
    cout << "-------------------------------" << endl;
    cout << "|type:" << this->type << endl;
    cout << "-------------------------------" << endl;
    cout << "|wage" << this->wage << endl;
    cout << "-------------------------------" << endl;
    cout << "|section:" << this->section << endl;
    cout << "-------------------------------" << endl;
}
Manager::~Manager(){    
    cout<<"Manager"<<endl;
}

Info *infoList(Info *information1){ 
    ifstream infile;
    Info *pptr = information1;
    infile.open("information.txt", ios::in);
    if (!infile){
        cerr << "can't find the information.txt" << endl;
        exit(1);
    }
    while (infile >> pptr->information.ID){
        infile >> pptr->information.pass;
        infile >> pptr->information.name;
        infile >> pptr->information.age;
        infile >> pptr->information.sex;
        infile >> pptr->information.type;
        infile >> pptr->information.wage;
        infile >> pptr->information.section;
        Info *ptr = new Info();
        pptr->nextinfo(ptr);
        pptr = ptr;
    }
    return information1;
}
int search(Info *ptr, int ID){
    bool flag=false;
    Info *temp = ptr;
    int count = ptr->getLength();
    for (int i = 0; i < count-1; i++){
        if (ptr->information.ID == ID){
            flag=true;
            break;
        }
        temp = temp->getNext();
    }
    ptr=temp;
    delete temp;
    return flag;
}
bool wirteIntoFile(Info *information1){
    ofstream outfile;
    Info *pptr = information1;
    outfile.open("information.txt", ios::out);
    if (!outfile){
        cerr << "can't find the information.txt" << endl;
        exit(1);
    }
    int count=information1->getLength();
    for(int i=0;i<count;i++){
        outfile << information1->information.ID;
        outfile << information1->information.pass;
        outfile << information1->information.name;
        outfile << information1->information.age;
        outfile << information1->information.sex;
        outfile << information1->information.wage;
        outfile << information1->information.type;
        outfile << information1->information.section << endl;
        pptr=pptr->getNext();
    }
    return true;
};
bool printAll(Info *ptr){
    Info *temp=ptr;
    int count=ptr->getLength();
    for(int i=0;i<count-1;i++){
        cout << "ID:";
        cout << " password:";
        cout << " name:";
        cout << " age:";
        cout << " sex:";
        cout << " wage:";
        cout << " type:" << endl;
        temp=temp->getNext();
    }
    delete temp;
    return true;
}
bool sortBygender(Info *ptr,int choice){
    string gender=choice==1?"male":"female";
    Info *temp = ptr;
    int count = ptr->getLength();
    for (int i = 0; i < count-1; i++){
        if(temp->information.sex==gender){
            cout << "ID:";
            cout << " password:";
            cout << " name:";
            cout << " age:";
            cout << " sex:";
            cout << " wage:";
            cout << " type:" << endl;
        }
        temp = temp->getNext();
    }
    delete temp;
    return true;
};
bool sortByother(Info *ptr){
    Info *temp=new Info();
    int count=ptr->getLength();
    for(int i=0;i<count;i++){
        
    }
}

int main(void){
    Person *admin = new Person(123, "root");
    admin->Prev();
    delete admin;
    return 0;
}
