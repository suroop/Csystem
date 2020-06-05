#include<iostream>
using namespace std;
class Person{
    protected:
        int num;
    public:
        Person(){
            this->num=0;
        };
        Person(int num){
            this->num=num;
        };
        virtual void qwe(){
            cout<<12<<endl;
        }; 
        virtual bool get();
};
class Worker:public Person{
    public:
        Worker(){
            this->num=0;
        }
        Worker(int num){
            this->num=num;
        };
        void qwe(){
            cout<<123<<endl;
        }
        bool get();
};
bool Person::get(){
    Person *p1 = NULL;
    cout<<num<<endl;
    if (1){
        p1 = new Worker(45);
        p1->get();
        p1->qwe();
    }
    return true;
}
bool Worker::get(){
    cout<<"num:"<<num<<endl;
    return true;
}
int main(void){
    Person *p2 = NULL;
    p2 = new Person(4);
    p2->get();
    cout << "----" << endl;
    return 0;
}
