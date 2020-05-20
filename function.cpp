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
void login(int choice){                         //login
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
        else{
            Worker worker((workers + option1)->name, (workers + option1)->sex, (workers + option1)->age, (workers + option1)->type, (workers + option1)->wage, (workers + option1)->ID, (workers + option1)->pass);
            worker.menu();
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
            manager.menu();
        }
    }
}
int search(info_Worker worker[],int id){
    int position;
    for (position = 0; position < worker->count; position++){
        if (id == (worker + position)->ID){
            break;
        }
    }
    return position;
}
int search(info_Manager manager[], int id)
{
    int position;
    for (position = 0; position < manager->count; position++)
    {
        if (id == (manager + position)->ID)
        {
            break;
        }
    }
    return position;
}
bool sortBySex(int option,info_Worker worker[]){
    string sex=(option==1)?"female":"male";
    for(int i=0;i<worker->count;i++){
        if ((worker+i)->sex==sex){
            cout << (worker + i)->ID << endl;
            cout << (worker + i)->pass << endl;
            cout << (worker + i)->name << endl;
            cout << (worker + i)->sex << endl;
            cout << (worker + i)->age << endl;
            cout << (worker + i)->wage << endl;
        }
    }
}
/*bool sortBytemp(int option, info_Worker worker[]){
    string temp;
    switch (option)
    {
    case 1:
        break;
    
    default:
        break;
    }
}*/

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
void Worker::Editor(){
    string temp;
    int option;
    info_Worker *p = writeFromFile(option);
    int target=search(p,this->ID);
    cout<<"what do you want do edit?"<<endl;
    cout << "1.name" << endl;
    cout << "2.password" << endl;
    cout << "3.type" << endl;
    cout << "4.age" << endl;
    cin>>option;
    cout<<"input content:"<<endl;
    cin>>temp;
    switch (option)
    {
    case 1:
        (p + target)->name = temp;
        break;
    case 2:
        (p + target)->pass = temp;
        break;
    case 3:
        (p + target)->type = temp;
        break;
    case 4:
        (p + target)->age = atoi(temp.c_str());       //string => int
        break;
    default:
        cout<<"NOT 1~4"<<endl;
        break;
    }
    cout<<"edited"<<endl;
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
    cout<<"5.editor"<<endl;
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
    case 5:
        Editor();
        break;
    default:
        cout<<"error"<<endl;
        break;
    }
}
void Manager::Add(){
    string password,name,type;
    int ID,age;
    double wage;
    bool flag;
    cout << "ID" << endl;
    cin>>ID;
    cout << "password" << endl;
    cin>>password;
    cout << "name" << endl;
    cin>>name;
    cout << "age" << endl;
    cin>>age;
    cout << "wage" << endl;
    cin>>wage;
    cout << "type" << endl;
    cin>>type;
    info_Worker *p=writeFromFile(ID);
    for(int i=0;i<p->count;i++){
        if(ID==(p+i)->ID){
            cout<<"registed"<<endl;
            flag=false;
            break;
        }
    }
    if(!flag){
        Add();
    }
    else{
        (p + (p)->count + 1)->ID = ID;
        (p + (p)->count + 1)->pass = password;
        (p + (p)->count + 1)->name = name;
        (p + (p)->count + 1)->sex = sex;
        (p + (p)->count + 1)->age = age;
        (p + (p)->count + 1)->wage = wage;
        (p + (p)->count + 1)->type = type;
    }
}
void Manager::Delete(){
    string ch;
    int id;
    cout<<"id:"<<endl;
    cin>>id;
    info_Worker * worker=writeFromFile(id);
    int target=search(worker,id);
    cout << (worker + target)->ID << endl;
    cout << (worker + target)->name << endl;
    cout << (worker + target)->sex << endl;
    cout << (worker + target)->age << endl;
    cout<<"sure?(Y/N)"<<endl;
    cin>>ch;
    if(ch=="Y"||ch=="y"){
        for(;(worker)->count;target++){
            *(worker + target) = *(worker + target+1);
        }
        writeIntoFile(worker);
    }
}
void Manager::Editor(){
    int choice1;
    float choice2=0;
    cout<<"1.yourself"<<endl;
    cout<<"2.workers"<<endl;
    cin>>choice1;
    if(choice1==1){
        int option;
        string temp;
        cout << "1.name" << endl;
        cout << "2.age" << endl;
        cout << "3.password" << endl;
        cin>>option;
        cout<<"content"<<endl;
        cin>>temp;
        info_Manager * manager=writeFromFile(choice2);
        int target=search(manager,this->ID);
        switch (option)
        {
        case 1:
            (manager+target)->name=temp;
            break;
        case 2:
            (manager + target)->age = atoi(temp.c_str());
            break;
        case 3:
            (manager+target)->pass=temp;
            break;
        default:
            break;
        }
    }
    else if(choice1==2){
        int ID;
        cout<<"ID:"<<endl;
        cin>>ID;
        info_Worker *worker = writeFromFile(choice1);
        int target = search(worker, ID);
        int option;
        cout << "1.name" << endl;
        cout << "2.age" << endl;
        cout << "3.wage" << endl;
        cout << "4.password" << endl;
        cout << "5.type" << endl;
        cin>>option;
        string temp;
        cout<<"content"<<endl;
        cin>>temp;
        switch (option)
        {
        case 1:
            (worker+target)->name=temp;
            break;
        case 2:
            (worker + target)->age = atoi(temp.c_str());
            break;
        case 3:
            (worker + target)->wage = atoi(temp.c_str());
            break;
        case 4:
            (worker+target)->pass=temp;
            break;
        case 5:
            (worker + target)->type = temp;
            break;
        default:
            break;
        }
    }
    else
    {
        cerr<<"error"<<endl;
        exit(1);
    }
}
void Manager::Sort(){
    int option1;
    int option2;
    cout << "1.by ID" << endl;
    cout << "2.by sex" << endl;
    cout << "3.by age" << endl;
    cout << "4.by wage" << endl;
    cin>>option1;
    info_Worker *worker=writeFromFile(option1);
    switch (option1)
    {
    case 1:
        /* code */
        break;
    case 2:
        cout << "1.female" << endl;
        cout << "2.male" << endl;
        cin>>option2;
        sortBySex(option2,worker);
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    default:
        break;
    }
} 
void Manager::display() const
{
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