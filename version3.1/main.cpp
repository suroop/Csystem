#include "function.cpp"
int main(void){
    Person *admin = new Person(123, "root");
    admin->Prev();
    delete admin;
    return 0;
}