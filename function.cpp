#include "class.h"

info_Worker* writeFromFile(int choice){     //Export workers' data
    ifstream infile;
    int i=0;
    info_Worker workers[100];
    infile.open("worker.txt",ios::in);
    if(!infile){
        cerr<<"error"<<endl;
        exit(1);
    }
    while (infile >> workers[i].ID >> workers[i].pass >> workers[i].name >> workers[i].sex >> workers[i].age >> workers[i].type >> workers[i].wage ){
        i++;    
    }
    workers[0].count=i;
    infile.close();
    return workers;
}
info_Manager *writeFromFile(float choice){  //Export managers' data
    ifstream infile;
    int i = 0;
    info_Manager managers[100];
    infile.open("manager.txt", ios::in);
    if (!infile)
    {
        cerr << "error" << endl;
        exit(1);
    }
    while (infile >> managers[i].ID >> managers[i].pass >> managers[i].name >> managers[i].sex >> managers[i].age >> managers[i].type >> managers[i].wage >> managers[i].section)
    {
        i++;
    }
    managers[0].count = i;
    infile.close();
    return managers;
}
bool writeIntoFile(info_Worker workers[]){        //import workers' data
    ofstream outfile;
    outfile.open("worker.txt",ios::out);
    if(!outfile){
        cerr << "error" << endl;
        exit(1);
    }
    int i=0;
    for(;i<workers[0].count;i++){
        outfile << workers[i].ID << " " << workers[i].pass << " " << workers[i].name << " " << workers[i].sex << " " ;
        outfile<< workers[i].age << " " << workers[i].type << " "<< workers[i].wage<<endl;
    }
    return true;
}
bool writeIntoFile(info_Manager managers[]){       //import managers' data
    ofstream outfile;
    outfile.open("manager.txt", ios::out);
    if (!outfile)
    {
        cerr << "error" << endl;
        exit(1);
    }
    int i = 0;
    for (; i < managers[0].count; i++)
    {
        outfile << managers[i].ID << " " << managers[i].pass << " " << managers[i].name << " " << managers[i].sex << " ";
        outfile << managers[i].age << " " << managers[i].type << " "<< " " << managers[i].wage << " " <<managers[i].section<<endl;
    }
    return true;
}
void regist(int choice){                        //regist
    int option1 = 0;
    float option2 = 0;
    string filename = (choice == 1 ? "manager.txt" : "worker.txt");
    //char filename[10];
    //strcpy(filename[10],file);
    bool flag = true;
    int id;
    string pass, checkedpass;
    string name;
    string sex;
    int age;
    string type;
    double wage;
    string section;
    info_Worker *workers = NULL;
    info_Manager *managers = NULL;
    cin >> id;
    if (choice == 2)
    {
        info_Worker *workers = writeFromFile(option1);
        for (option1 = 0; option1 < workers->count; option1++)
        {
            if (id == (workers + option1)->ID)
            {
                cout << "registed" << endl;
                flag = false;
                break;
            }
        }
        option2 = 1;
    }
    else
    {
        managers = writeFromFile(option2);
        for (option1 = 0; option1 < managers->count; option1++)
        {
            if (id == (managers + option1)->ID)
            {
                cout << "registed" << endl;
                flag = false;
                break;
            }
        }
    }
    if (!flag)
    {
        regist(choice);
    }
    else{
        cin >> pass;
        cin >> checkedpass;
        do
        {
            cin >> checkedpass;
            if (checkedpass != pass)
            {
                cout << "error" << endl;
            }
        } while (checkedpass != pass);
    }
    cin >> name;
    cin >> sex;
    cin >> age;
    cin >> type;
    cin >> wage;
    if (option2)
    {
        writeIntoFile(workers);
    }
    else
    {
        cin >> section;
        writeIntoFile(managers);
    }
}
void login(int choice)
{
    int option1 = 0;
    float option2 = 0;
    bool flag=true;
    info_Worker *workers = NULL;
    info_Manager *managers = NULL;
    int ID;
    string pass;
    cout<<"please input your ID:"<<endl;
    cin >> ID;
    cout<<"please input your password"<<endl;
    cin >> pass;
    if (choice == 2)
    {
        info_Worker *workers = writeFromFile(option1);
        for (option1 = 0; option1 < workers->count; option1++)
        {
            if (ID == (workers + option1)->ID && pass == (workers + option1)->pass)
            {
                cout << "logining" << endl;
                flag=false;
                break;
            }
        }
        if(!flag){
            cout<<"NO FUND"<<endl;
            exit(1);
        }
    }
    else
    {
        managers = writeFromFile(option2);
        for (option1 = 0; option1 < managers->count; option1++)
        {
            if (ID == (managers + option1)->ID && pass == (managers + option1)->pass)
            {
                cout << "logining" << endl;
                flag=false;
                break;
            }
        }
        if(!flag){
            cout<<"NO FUND"<<endl;
            exit(1);
        }
        else{
            Manager manager((managers + option1)->section, (managers + option1)->name, (managers + option1)->sex, (managers + option1)->age,(managers + option1)->type, (managers + option1)->wage, (managers + option1)->ID, (managers + option1)->pass);
        }
    }
}
Person::Person(int ID,string pass){         // Person's Constructor 
    this->ID = ID;
    this->pass=pass;
}
Person::~Person(){
    cout<<"Person"<<endl;
}
void Person::menu(){
    cout<<"menu"<<endl;
}
Worker::Worker(string name, string sex, int age, string type, double wage, int ID, string pass) : Person(ID, pass)
{
    this->ID = ID;
    this->pass = pass;
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->wage=wage;
    this->type=type;
}
void Worker::menu(){
    int choice;
    cout<<"input a number"<<endl;
    cout<<"1.display"<<endl;
    cout<<"2.edit"<<endl;
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
void Worker::display() const{
    cout << "ID:" << this->ID << endl;
    cout << "name:" << this->name << endl;
    cout << "sex:" << this->sex << endl;
    cout << "age:" << this->age << endl;
    cout << "type:" << this->type << endl;
    cout << "wage" << this->wage << endl;
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
void Manager::menu(){
    int choice;
    cout<<"input a number"<<endl;
    cout<<"1.add"<<endl;
    cout<<"2.sort"<<endl;
    cout<<"3.delete"<<endl;
    cout<<"4.display"<<endl;
    cin>>choice;
    switch (choice)
    {
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
    default:
        cout<<"error"<<endl;
        break;
    }
}
void Manager::display() const{
    cout << "ID:" << this->ID << endl;
    cout << "name:" << this->name << endl;
    cout << "sex:" << this->sex << endl;
    cout << "age:" << this->age << endl;
    cout << "type:" << this->type << endl;
    cout << "wage" << this->wage << endl;
    cout << "section:" << this->section << endl;
}
Manager::~Manager(){
    cout<<"Manager"<<endl;
}