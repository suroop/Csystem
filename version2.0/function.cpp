#include "class.h"

infoWorker *infoList(infoWorker *information1){ //读取文件数据
    ifstream infile;
    infoWorker *pptr = information1;
    infile.open("worker.txt", ios::in);
    if (!infile){
        cerr << "can't find the woker.txt" << endl;
        exit(1);
    }
    while (infile >> pptr->information.ID){
        infile >> pptr->information.pass;
        infile >> pptr->information.name;
        infile >> pptr->information.age;
        infile >> pptr->information.sex;
        infile >> pptr->information.type;
        infile >> pptr->information.wage;
        infoWorker *ptr = new infoWorker();
        pptr->nextinfo(ptr);
        pptr = ptr;
    }
    return information1;
}
infoManager *infoList(infoManager *information1){//重载读取文件
    ifstream infile;
    infoManager *pptr = information1;
    infile.open("manager.txt", ios::in);
    if (!infile){
        cerr << "can't find the manager.txt" << endl;
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
        infoManager *ptr = new infoManager();
        pptr->nextinfo(ptr);
        pptr = ptr;
    }
    return information1;
}
infoWorker *searchperson(infoWorker *ptr,int ID){
    infoWorker *temp=ptr;
    int count = ptr->getLength();
    for (int i = 0; i <count;i++){
        if(ptr->information.ID==ID){
            break;
        }
        temp=temp->getNext();
    }
    return temp;
}
infoManager *searchperson(infoManager *ptr, int ID){
    infoManager *temp = ptr;
    int count = ptr->getLength();
    for (int i = 0; i < count; i++)
    {
        if (ptr->information.ID == ID)
        {
            break;
        }
        temp = temp->getNext();
    }
    return temp;
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
bool printAll(info_Worker worker[]){
    for (int i = 0; i < worker->count; i++){
        cout << (worker + i)->ID << " ";
        cout << (worker + i)->pass << " ";
        cout << (worker + i)->name << " ";
        cout << (worker + i)->sex << " ";
        cout << (worker + i)->age << " ";
        cout << (worker + i)->wage << endl;
    }
    return true;
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
int search(info_Manager manager[], int id){
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
        if ((worker + i)->sex == sex ){
            cout << (worker + i)->ID << " ";
            cout << (worker + i)->pass << " ";
            cout << (worker + i)->name << " ";
            cout << (worker + i)->sex << " ";
            cout << (worker + i)->age << " ";
            cout << (worker + i)->wage <<" ";
            cout << (worker + i)->type << endl;
        }
    }
}
info_Worker* sortBysection(string section,info_Worker worker[]){   
    static info_Worker nw[100];
    int n=0;
    for (int i = 0; i < worker->count; i++){
        if ((worker + i)->type == section){
            nw[n]= worker[i];
            n++;
        }
    }
    nw[0].count=n;
    return nw;
}
bool sortByID(info_Worker worker[]){
    int begin = 0;
    int end = worker->count - 1;
    while (begin < end){
        int min = begin, max = begin;
        for (int i = begin; i <= end; ++i){
            if (worker[min].ID > worker[i].ID){
                min = i;
            }
            if (worker[max].ID < worker[i].ID){
                max = i;
            }
        }
        worker[min].count = worker[begin].count;
        swap(worker[min], worker[begin]);
        if (max == begin){
            max = min;
        }
        swap(worker[max], worker[end]);
        begin++;
        end--;
    }
}
bool sortByAge(info_Worker worker[]){
    int begin = 0;
    int end = worker->count - 1;
    while (begin < end){
        int min = begin, max = begin;
        for (int i = begin; i <= end; ++i){
            if (worker[min].age > worker[i].age){
                min = i;
            }
            if (worker[max].age < worker[i].age){
                max = i;
            }
        }
        worker[min].count = worker[begin].count;
        swap(worker[min], worker[begin]);
        if (max == begin)
        {
            max = min;
        }
        swap(worker[max], worker[end]);
        begin++;
        end--;
    }
}
bool sortByWage(info_Worker worker[]){
    int begin = 0;
    int end = worker->count - 1;
    while (begin < end)
    {
        int min = begin, max = begin;
        for (int i = begin; i <= end; ++i)
        {
            if (worker[min].wage > worker[i].wage)
            {
                min = i;
            }
            if (worker[max].wage < worker[i].wage)
            {
                max = i;
            }
        }
        worker[min].count = worker[begin].count;
        swap(worker[min], worker[begin]);
        if (max == begin)
        {
            max = min;
        }
        swap(worker[max], worker[end]);
        begin++;
        end--;
    }
}

infoWorker::infoWorker(){
    count++;
}
int infoWorker::getLength(){
    return count;
}
bool infoWorker::insertAfter(infoWorker *ptr){
    this->next=ptr;
}
infoWorker *infoWorker::nextinfo(infoWorker *ptr){
    this->next = ptr;
}
infoWorker *infoWorker::getNext(){
    return this->next;
};
infoWorker::~infoWorker(){
    cout << 123 << endl;
}

infoManager::infoManager(){
    count++;
}
int infoManager::getLength(){
    return count;
}
bool infoManager::insertAfter(infoManager *ptr){
    this->next = ptr;
}
infoManager infoManager::nextinfo(infoManager *ptr){
    this->next = ptr;
}
infoManager *infoManager::getNext(){
    return this->next;
};
infoManager::~infoManager(){
    cout<<123<<endl;
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
void Person::Prev(){
    int role, option;
    cout << "-------------------------------" << endl;
    cout << "|          1.manager          |" << endl;
    cout << "|          2.worker           |" << endl;
    cout << "-------------------------------" << endl;
    cin >> role;
    cout << "-------------------------------" << endl;
    cout << "|          1.login            |" << endl;
    cout << "|          2.regist           |" << endl;
    cout << "-------------------------------" << endl;
    cin >> option;
    if (option == 1){
        login(role);
        system("cls");
    }
    else if (option == 2){
        regist(role);
        system("cls");
    }
    else{
        cerr << "Exiting program..." << endl;
        exit(0);
    }
}
void Person::display() const{
    cout<<"display"<<endl;
};
void Person::menu(){
    cout << "menu" << endl;
}
void Person::Editor(){
    cout << "Editor" << endl;
};
void Person::regist(int choice){
    bool flag = true;
    int ID;
    cout << "-------------------------------" << endl;
    cout << "input the ID you want to create" << endl;
    cout << "-------------------------------" << endl;
    cin >> ID;
    if(choice==2){
        infoWorker *ptr = new infoWorker();
        infoWorker *newptr = infoList(ptr);
        infoWorker *nowptr=newptr;
        int count = newptr->getLength();
        int count=newptr->getLength();
        for(int i=0;i<count;i++){
            if(ID==nowptr->information.ID){
                flag=false;
                break;
            }
            nowptr=nowptr->getNext();
        }
        if(false){
            cout << "-------------------------------" << endl;
            cout << "        ID was registedd       " << endl;
            cout << "-------------------------------" << endl;
            exit(0);
        }
        else{
            infoWorker *temptr=new infoWorker();
            string pass,checkpass,name,sex,type;
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
            temptr->information.ID = ID;
            temptr->information.pass = pass;
            temptr->information.name = name;
            temptr->information.age = age;
            temptr->information.sex = sex;
            temptr->information.wage = wage;
            temptr->information.type = type;
            nowptr->insertAfter(temptr);
            cout << "-------------------------------" << endl;
            cout << "     successfully registed     " << endl;
            cout << "-------------------------------" << endl;
            system("cls");
            login(choice);
            
        }
    }
    else{
        infoManager *ptr = new infoManager();
        infoManager *newptr = infoList(ptr);
        infoManager *nowptr=newptr;
        int count = newptr->getLength();
        for (int i = 0; i < count; i++){
            if (ID == newptr->information.ID){
                flag = false;
                break;
            }
            nowptr=nowptr->getNext();
        }
        if (false){
            cout << "-------------------------------" << endl;
            cout << "        ID was registedd       " << endl;
            cout << "-------------------------------" << endl;
        }
        else{
            infoManager *temptr = new infoManager();
            string pass, checkpass, name, sex, type,section;
            int age;
            double wage;
            cout << "-------------------------------" << endl;
            cout << "       input your password     " << endl;
            cout << "-------------------------------" << endl;
            cin >> pass;
            do
            {
                cout << "-------------------------------" << endl;
                cout << "   input your password again   " << endl;
                cout << "-------------------------------" << endl;
                cin >> checkpass;
                if (checkpass != pass)
                {
                    cout << "-------------------------------" << endl;
                    cout << "    password is not the same   " << endl;
                    cout << "-------------------------------" << endl;
                }
            } while (checkpass != pass);
            cout << "-------------------------------" << endl;
            cout << "         input your name       " << endl;
            cout << "-------------------------------" << endl;
            cin >> name;
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
            cin >> wage;
            cout << "-------------------------------" << endl;
            cout << "      input your section       " << endl;
            cout << "-------------------------------" << endl;
            cin >> section;
            temptr->information.ID = ID;
            temptr->information.pass = pass;
            temptr->information.name = name;
            temptr->information.age = age;
            temptr->information.sex = sex;
            temptr->information.wage = wage;
            temptr->information.type = type;
            temptr->information.section = section;
            nowptr->insertAfter(temptr);
            cout << "-------------------------------" << endl;
            cout << "     successfully registed     " << endl;
            cout << "-------------------------------" << endl;
            system("cls");
            login(choice);
        }
    }
}
void Person::login(int choice){ //login
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
    if (choice == 2){
        infoWorker *ptr=new infoWorker();
        infoWorker *newptr=infoList(ptr);
        infoWorker *nowptr=newptr;
        int count=newptr->getLength();
        for(int i=0;i<count;i++){
            if(ID==nowptr->information.ID&&pass==nowptr->information.pass){
                flag=false;
                break;
            }
            nowptr=nowptr->getNext();
        }
        if(false){
            cout << "-------------------------------" << endl;
            cout << "       someting is wrong       " << endl;
            cout << "-------------------------------" << endl;
        }
        else{
            Worker *WORKER = new Worker(nowptr->information.type, nowptr->information.name, nowptr->information.age, nowptr->information.sex, nowptr->information.wage, nowptr->information.ID, nowptr->information.pass);
            WORKER->menu();
            delete WORKER;
        }
    }
    else{
        infoManager *ptr=new infoManager();
        infoManager *newptr=infoList(ptr);
        infoManager *nowptr = newptr;
        int count=newptr->getLength();
        for(int i=0;i<count;i++){
            if(ID==newptr->information.ID&&pass==newptr->information.pass){
                flag=false;
                break;
            }
            nowptr = nowptr->getNext();
        }
        if(false){
            cout << "-------------------------------" << endl;
            cout << "       someting is wrong       " << endl;
            cout << "-------------------------------" << endl;
        }
        else{
            Manager *MANAGER = new Manager(nowptr->information.section,nowptr->information.type, nowptr->information.name, nowptr->information.age, nowptr->information.sex, nowptr->information.wage, nowptr->information.ID, nowptr->information.pass);
            MANAGER->menu();
            delete MANAGER;
        }
    }
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
void Worker::menu(){
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
void Worker::display() const{
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
    infoWorker *ptr=new infoWorker();
    infoWorker *newptr=infoList(ptr);
    infoWorker *nowptr = new infoWorker();
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
    switch (option)
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
    }
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
void Manager::menu(){
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
    //检查ID是否重复
    info_Worker *p=NULL;
    p = writeFromFile(ID);
    for (int i = 0; i < p->count; i++){
        if (ID == (p + i)->ID){
            cout << "registed" << endl;
            flag = false;
            break;
        }
    }
    if (!flag){
        exit(1);
    }
    cout << "-------------------------------" << endl;
    cout << "|         input the password  |" << endl;
    cin>>password;
    cout << "-------------------------------" << endl;
    cout << "|         input the name      |" << endl;
    cin>>name;
    cout << "-------------------------------" << endl;
    cout << "|         input the age       |" << endl;
    cin>>age;
    cout << "|------------------------------" << endl;
    cout << "|         input the wage      |" << endl;
    cin>>wage;
    cout << "|------------------------------" << endl;
    cout << "|         input the type      |" << endl;
    cin>>type;
    system("cls");
    menu();
}
void Manager::Delete(){
    string ch;
    int id=0;
    cout<<"id:"<<endl;
    cin>>id;
    info_Worker * worker=writeFromFile(id);
    int target=search(worker,id);
    cout<<target<<endl;
    cout << (worker + target)->ID << endl;
    cout << (worker + target)->name << endl;
    cout << (worker + target)->sex << endl;
    cout << (worker + target)->age << endl;
    cout<<"sure?(Y/N)"<<endl;
    cin>>ch;
    if(ch=="Y"||ch=="y"){
        cout<<"doing"<<endl;
        for(;target<(worker)->count;target++){
            cout << "step:"<<target << endl;
            worker[target]=worker[target+1];
        }
        worker[0].count--;
        writeIntoFile(worker);
        printAll(worker);
    }
    cout<<"finshed"<<endl;
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
        infoManager *ptr = new infoManager();
        infoManager *newptr = infoList(ptr);
        infoManager *nowptr=searchperson(newptr,this->ID);
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
        default:
            cout << "NOT 1~4" << endl;
            system("cls");
            Editor();
            break;
        }
    }
    else if(choice==2){
        infoWorker *ptr = new infoWorker();
        infoWorker *newptr = infoList(ptr);
        infoWorker *nowptr = searchperson(newptr, this->ID);
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
                cout << "NOT 1~5" << endl;
                system("cls");
                Editor();
                break;
        }
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
    int option1;
    int option2;
    cout << "1.by ID" << endl;
    cout << "2.by sex" << endl;
    cout << "3.by age" << endl;
    cout << "4.by wage" << endl;
    cin>>option1;
    info_Worker *worker=writeFromFile(option1);
    info_Worker *newworker=sortBysection(this->section,worker);
    switch (option1){
    case 1:
        sortByID(newworker);
        printAll(newworker);
        break;
    case 2:
        cout << "1.female" << endl;
        cout << "2.male" << endl;
        cin>>option2;
        sortBySex(option2,newworker);
        break;
    case 3:
        sortByAge(newworker);
        printAll(newworker);
        break;
    case 4:
        sortByWage(newworker);
        printAll(newworker);
        break;
    default:
        break;
    }
} 
void Manager::display() const
{
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
