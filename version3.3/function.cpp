#include "class.h"

Info *infoList(Info *information1){ //ok读取文件数据
    ifstream infile;
    Info *pptr = information1;
    infile.open("information.txt", ios::in);
    if (!infile){
        cerr << "can't find the information.txt" << endl;
        exit(1);
    }
    while (infile >> pptr->information.ID){
        infile >>pptr->information.pass;
        infile >> pptr->information.name;
        infile >> pptr->information.age;
        infile >> pptr->information.sex;
        infile >> pptr->information.wage;
        infile >> pptr->information.type;
        infile >> pptr->information.section;
        //cout << "infoList():"<<pptr->information.name<< endl;
        //cout << "infoList():" << pptr->information.type << endl;
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
    for (int i = 0; i < count; i++){
        if (temp->information.ID == ID){
            flag = true;
            break;
        }
        temp=temp->getNext();
    }
    delete temp;
    return flag;
}
Info* search(Info *ptr, int ID,string pass){
    Info *pptr=ptr;
    int i;
    int count = ptr->getLength();
    //cout<<"ID"<<ID<<"passwd"<<pass<<endl;
    for (i = 0; i < count; i++){
        //cout << "search():" << pptr->information.name << endl;
        if (pptr->information.ID == ID && pptr->information.pass==pass){
            //cout << "bingo():" << pptr->information.name << endl;
            break;
        }
        pptr = pptr->getNext();
    }
    if(i==count){
        return 0;
    }
    return pptr;
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
    for(int i=0;i<count-1;i++){
        outfile << pptr->information.ID<<" ";
        outfile << pptr->information.pass << " ";
        outfile << pptr->information.name << " ";
        //cout << "writeInfoFile:" << pptr->information.name<<endl; 
        outfile << pptr->information.age << " ";
        outfile << pptr->information.sex << " ";
        outfile << pptr->information.wage << " ";
        outfile << pptr->information.type << " ";
        outfile << pptr->information.section << endl;
        //cout << "writeInfoFile(next):" << 
        cout <<pptr->next->information.name<< endl;
        pptr = pptr->getNext();
    }
    return true;
};
bool printAll(Info *ptr){
    Info *temp=ptr;
    int count=ptr->getLength();
    for(int i=0;i<count-1;i++){
        cout << "ID:"<<temp->information.ID;
        cout << " password:" << temp->information.pass;
        cout << " name:" << temp->information.name;
        cout << " age:" << temp->information.age;
        cout << " sex:" << temp->information.sex;
        cout << " wage:" << temp->information.wage;
        cout << " type:" << temp->information.type;
        cout << " section:" << temp->information.section << endl;
        temp=temp->getNext();
    }
    return true;
}
void editInfo(int option, string temp,Info *nowptr){
    switch (option){
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
        cout << "NOT 1~4" << endl;
        //system("cls");
        exit(0);
        break;
    }
    //cout << "editInfo()" << nowptr->information.age << endl;
}
bool sortBygender(Info *ptr,int choice){
    string gender=choice==1?"female":"male";
    Info *temp = ptr;
    int count = ptr->getLength();
    for (int i = 0; i < count; i++){
        if(temp->information.sex==gender){
            cout << "ID:" << temp->information.ID;
            cout << " password:" << temp->information.pass;
            cout << " name:"<< temp->information.name;
            cout << " age:" << temp->information.age;
            cout << " sex:" << temp->information.sex;
            cout << " wage:" << temp->information.wage;
            cout << " type:" << temp->information.type<<endl;
        }
        temp = temp->getNext();
    }
    return true;
};
void sortByAge(Info *ptr){
    int count = ptr->getLength();
    int j;
    info message;
    Info *prevNode = ptr;
    Info *nextNode = ptr->getNext();
    for (int i = 1; i <= count - 2; i++){ 
        for (j = 1; j <= count - i - 1; j++){
            if ((prevNode->information.age) > (nextNode->information.age)){
                message = prevNode->returnInfo();
                prevNode->information = nextNode->information;
                nextNode->information = message;
            }
            nextNode = nextNode->getNext();
        }
        if ((prevNode->information.age) > (nextNode->information.age)){
            message = prevNode->information;
            prevNode->information = nextNode->information;
            nextNode->information = message;
        }
        prevNode = prevNode->getNext();
        nextNode = prevNode->getNext();
    }
    if ((prevNode->information.age) > (nextNode->information.age)){
        message = prevNode->information;
        prevNode->information = nextNode->information;
        nextNode->information = message;
    }
    printAll(ptr);
}
void sortByWage(Info *ptr){
    int count = ptr->getLength();
    int j;
    info message;
    Info *prevNode = ptr;
    Info *nextNode = ptr->getNext();
    for (int i = 1; i <= count - 2; i++){
        for (j = 1; j <= count - i - 1; j++){
            if ((prevNode->information.wage) > (nextNode->information.wage)){
                message = prevNode->returnInfo();
                prevNode->information = nextNode->information;
                nextNode->information = message;
            }
            nextNode = nextNode->getNext();
        }
        if ((prevNode->information.wage) > (nextNode->information.wage)){
            message = prevNode->information;
            prevNode->information = nextNode->information;
            nextNode->information = message;
        }
        prevNode = prevNode->getNext();
        nextNode = prevNode->getNext();
    }
    if ((prevNode->information.wage) > (nextNode->information.wage)){
        message = prevNode->information;
        prevNode->information = nextNode->information;
        nextNode->information = message;
    }
    printAll(ptr);
}
void sortByID(Info *ptr){
    int count = ptr->getLength();
    int j;
    info message;
    Info *prevNode = ptr;
    Info *nextNode = ptr->getNext();
    for (int i = 1; i <= count - 2; i++){
        for (j = 1; j <= count - i - 1; j++){
            if ((prevNode->information.ID) > (nextNode->information.ID)){
                message = prevNode->returnInfo();
                prevNode->information = nextNode->information;
                nextNode->information = message;
            }
            nextNode = nextNode->getNext();
        }
        if ((prevNode->information.ID) > (nextNode->information.ID)){
            message = prevNode->information;
            prevNode->information = nextNode->information;
            nextNode->information = message;
        }
        prevNode = prevNode->getNext();
        nextNode = prevNode->getNext();
    }
    if ((prevNode->information.ID) > (nextNode->information.ID)){
        message = prevNode->information;
        prevNode->information = nextNode->information;
        nextNode->information = message;
    }
    printAll(ptr);
}

int Info::count = 0;
Info::Info(){
    count++;
}
int Info::getLength(){     
    return count;
}
bool Info::insertAfter(Info *temp){
    temp->nextinfo(this->getNext());
    this->nextinfo(temp);
}
bool Info::deleteAfter(){
    Info *temp = this->getNext();
    info message=temp->returnInfo();
    this->setterInfo(message.type, message.wage, message.name, message.age, message.sex, message.ID, message.pass, message.section);
    this->nextinfo(temp->getNext());
    delete temp;
    return true;
}
info Info::returnInfo(){
    info message;
    //cout <<"returnInfo "<<this->information.name << endl;
    message.ID=this->information.ID;
    message.pass = this->information.pass;
    message.name = this->information.name;
    message.age = this->information.age;
    message.sex = this->information.sex;
    message.type = this->information.type;
    message.wage = this->information.wage;
    message.section = this->information.section;
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
Info *Info::getNext(){
    return this->next;
};
Info::~Info(){
    count--;
}

Person::Person(int ID,string pass){ // Person's Constructor
        this->ID = ID;
        this->pass=pass;
}
void Person::Prev(){        //ok
    int option;
    cout << "-------------------------------" << endl;
    cout << "|          1.login            |" << endl;
    cout << "|          2.regist           |" << endl;
    cout << "-------------------------------" << endl;
    cin >> option;
    Info *ptr = new Info();
    Info *newptr = infoList(ptr);
    if (option == 1){
        system("cls");
        login(newptr);
    }
    else if (option == 2){
        system("cls");
        regist(newptr);
    }
    else{
        cerr << "Exiting program..." << endl;
        exit(0);
    }
}
void Person::display(Info *,Info *){       //ok
    cout<<"display"<<endl;
};
void Person::menu(Info *ptr,Info *pptr){            //ok
    cout << "menu" << endl;
}
void Person::Editor(Info * ptr,Info *pptr){ //ok
    cout << "Editor" << endl;
};
void Person::regist(Info *newptr){
    bool flag = true;
    int ID;
    cout << "-------------------------------" << endl;
    cout << "input the ID you want to create" << endl;
    cout << "-------------------------------" << endl;
    cin >> ID;
    try{
        if (search(newptr, ID)){
            throw ID;
        }
    }
    catch(int ID){
        cout << "-------------------------------" << endl;
        cout << "  "<<ID<<" was registedd       " << endl;
        cout << "-------------------------------" << endl;
        system("cls");
        regist(newptr);
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
    cout << "-------------------------------" << endl;
    cout << "      input your section       " << endl;
    cout << "-------------------------------" << endl;
    cin >> section;
    temptr->setterInfo(type, wage, name, age, sex, ID, pass,section);
    newptr->insertAfter(temptr);
    cout << "-------------------------------" << endl;
    cout << "     successfully registed     " << endl;
    cout << "-------------------------------" << endl;
    system("cls");
    wirteIntoFile(newptr);
    login(newptr);
}
void Person::login(Info *nowptr){ //login
    bool flag = true;
    int ID;
    string pass;
    Info *pptr=NULL;
    cout << "-------------------------------" << endl;
    cout << "    please input your ID      :" << endl;
    cout << "-------------------------------" << endl;
    cin >> ID;
    cout << "-------------------------------" << endl;
    cout << "  please input your password  :" << endl;
    cout << "-------------------------------" << endl;
    cin >> pass;
    pptr=search(nowptr,ID,pass);
    try{
        if (!ID){
            throw ID;
        }
    }
    catch (int ID){
        cout << "-------------------------------" << endl;
        cout << "   ID or password is wrong    " << endl;
        cout << "-------------------------------" << endl;
    }
    Person *guy=NULL;
    info message = pptr->returnInfo();
    if(message.section=="NULL"){
        guy = new Worker(message.name, message.sex, message.age, message.type, message.wage, message.ID, message.pass);
        guy->menu(nowptr,pptr);
    }
    else{
        guy = new Manager(message.section, message.name, message.sex, message.age, message.type, message.wage, message.ID, message.pass);
        guy->menu(nowptr,pptr);
    }
    delete guy;
}
Person::~Person(){
    cout<<"Person"<<endl;
}

Worker::Worker(string name, string sex, int age, string type, double wage, int ID, string pass):Person(ID, pass){
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->wage = wage;
    this->type = type;
    this->ID = ID;
    this->pass = pass;
}
void Worker::menu(Info *ptr,Info *pptr){       
    int choice;
    cout << "--------------------------------" << endl;
    cout << "|        input a number        |"<<endl;
    cout << "--------------------------------" << endl;
    cout << "|           1.display          |"<<endl;
    cout << "|           2.edit             |"<<endl;
    cout << "|           3.exit             |" << endl;
    cout << "--------------------------------" << endl;
    cin>>choice;
    if(choice==1){
        display(ptr, pptr);
    }
    else if(choice==2){
        Editor(ptr,pptr);
    }
    else if(choice==3){
        exit(0);
    }
    else{
        menu(ptr,pptr);
    }
}
void Worker::display(Info *ptr, Info *pptr){ 
    int num;
    cout << "-----------information---------" << endl;
    cout << "|ID: " << this->ID << endl;
    cout << "-------------------------------" << endl;
    cout << "|name: " << this->name << endl;
    cout << "-------------------------------" << endl;
    cout << "|sex: " << this->sex << endl;
    cout << "-------------------------------" << endl;
    cout << "|age: " << this->age << endl;
    cout << "-------------------------------" << endl;
    cout << "|type: " << this->type << endl;
    cout << "-------------------------------" << endl;
    cout << "|wage " << this->wage << endl;
    cout << "-------------------------------" << endl;
    cout << "| type number one to the menu |";
    cout << "-------------------------------" << endl;
    if(num==1){
        menu(ptr,pptr);  
    }
    else{
        exit(0);
    }
}
void Worker::Editor(Info *ptr,Info *pptr){
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
    if(option>4||option<1){
        cout << "-------------------------------" << endl;
        cout << "|        OPTION NO FUND        |"<<endl;
        cout << "-------------------------------" << endl;
        Editor(ptr,pptr);
    }
    cout << "-------------------------------" << endl;
    cout << "|        input content:       |" << endl;
    cout << "-------------------------------" << endl;
    cin >> temp;
    editInfo(option,temp,pptr);
    printAll(ptr);
    wirteIntoFile(ptr);
    system("cls");
    menu(ptr,pptr);
}
Worker::~Worker(){
    cout<<"~Worker()"<<endl;
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
void Manager::menu(Info *ptr,Info *pptr){       //ok
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
            Add(ptr,pptr);
            break;
        case 2:
            Sort(ptr,pptr);
            break;
        case 3:
            Delete(ptr,pptr);
            break;
        case 4:
            display(ptr,pptr);
            break;
        case 5:
            Editor(ptr,pptr);
            break;
        default:
            cout<<"exiting programing"<<endl;
            exit(0);
            break;
    }
}
void Manager::Add(Info *ptr, Info *pptr){
    int ID, age;
    double wage;
    bool flag=true;
    string password,name,type;
    cout << "-------------------------------" << endl;
    cout << "|        input the ID         |" << endl;
    cout << "-------------------------------" << endl;
    cin >> ID;
    try{
        if (search(ptr, ID)){
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
    ptr->insertAfter(temp);
    wirteIntoFile(ptr);
    system("cls");
    menu(ptr,pptr);
}
void Manager::Delete(Info * ptr,Info *pptr){
    string ch,pass;
    bool flag=true;
    int id;
    cout << "-------------------------------" << endl;
    cout << "|  The ID you want to delete:  " << endl;
    cout << "-------------------------------" << endl;
    cin>>id;
    cout << "-------------------------------" << endl;
    cout << "|          The pass           |" << endl;
    cout << "-------------------------------" << endl;
    cin >> pass;
    Info *nowptr = search(ptr, id, pass);
    try{
        if (!id){
            throw id;
        }
    }
    catch (const exception &e){
        cout << "-------------------------------" << endl;
        cout << "|      can't find the ID      |" << endl;
        cout << "-------------------------------" << endl;
    }
    info message = nowptr->returnInfo();
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
        menu(ptr,pptr);
    }
    wirteIntoFile(ptr);
    cout << "-------------------------------" << endl;
    cout << "|           finshed           |"<<endl;
    cout << "-------------------------------" << endl;
    system("cls");
    menu(ptr,pptr);
}
void Manager::Editor(Info * ptr,Info *pptr){
    int choice;
    cout << "-------------------------------" << endl;
    cout << "|      input your choice      |" << endl;
    cout << "-------------------------------" << endl;
    cout << "|          1.yourself         |" << endl;
    cout << "|          2.workers          |" << endl;
    cout << "-------------------------------" << endl;
    cin>>choice;
    if(choice==1){
        Info *nowptr =search(ptr,this->ID,this->pass);
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
        if (option > 4 || option < 1){
            cout << "-------------------------------" << endl;
            cout << "|        OPTION NO FUND        |" << endl;
            cout << "-------------------------------" << endl;
            Editor(ptr,pptr);
        }
        cout << "-------------------------------" << endl;
        cout << "|        input content:       |" << endl;
        cout << "-------------------------------" << endl;
        cin >> temp;
        editInfo(option,temp,nowptr);
        wirteIntoFile(ptr);
    }
    else if(choice==2){
        int option,ID;
        string temp,pass;
        cout << "-------------------------------" << endl;
        cout << "|      input worker's ID      |" << endl;
        cout << "-------------------------------" << endl;
        cin>>ID;
        cout << "-------------------------------" << endl;
        cout << "|     input worker's pass     |" << endl;
        cout << "-------------------------------" << endl;
        cin >> pass;
        Info *nowptr =search(ptr, ID,pass);
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
        editInfo(option,temp,nowptr);
        wirteIntoFile(ptr);
    }
    else{
        cout << "-------------------------------" << endl;
        cerr << "|  input the correct number!  |" << endl;
        cout << "-------------------------------" << endl;
        system("cls");
        Editor(ptr,pptr);
    }
    system("cls");
    menu(ptr,pptr);
}
void Manager::Sort(Info *ptr,Info *pptr){
    int option;
    cout << "-------------------------------" << endl;
    cout << "|          1.by ID            |" << endl;
    cout << "|          2.by sex           |" << endl;
    cout << "|          3.by age           |" << endl;
    cout << "|          4.by wage          |" << endl;
    cout << "-------------------------------" << endl;
    cin>>option;
    switch (option){
    case 1:
        sortByID(ptr);
        break;
    case 2:
        cout << "1.female" << endl;
        cout << "2.male" << endl;
        cin>>option;
        sortBygender(ptr,option);
        break;
    case 3:
        sortByAge(ptr);
        break;
    case 4:
        sortByWage(ptr);
        break;
    default:
        break;
    }
    menu(ptr,pptr);
}
void Manager::display(Info *ptr, Info * pptr){
    int option;
    cout << "----------information----------" << endl;
    cout << "|ID: " << this->ID << endl;
    cout << "-------------------------------" << endl;
    cout << "|name: " << this->name << endl;
    cout << "-------------------------------" << endl;
    cout << "|sex: " << this->sex << endl;
    cout << "-------------------------------" << endl;
    cout << "|age: " << this->age << endl;
    cout << "-------------------------------" << endl;
    cout << "|type: " << this->type << endl;
    cout << "-------------------------------" << endl;
    cout << "|wage: " << this->wage << endl;
    cout << "-------------------------------" << endl;
    cout << "|section: " << this->section << endl;
    cout << "-------------------------------" << endl;
    cout << "|      type 1 to the menu     |"<<endl;
    cout << "-------------------------------" << endl;
    cin>>option;
    if(option==1){
        menu(ptr,pptr);
    }
    else{
        exit(0);
    }
}
Manager::~Manager(){    
    cout<<"~Manager()"<<endl;
}
