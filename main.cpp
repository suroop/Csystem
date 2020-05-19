#include "function.cpp"
int main(void){
    int role,option;
    cout << "1.manager" << endl;
    cout << "2.worker" << endl;
    cin>>role;
    cout << "1.login" << endl;
    cout << "2.regist" << endl;
    cin>>option;
    if(option==1){
        login(role);
    }
    else if (option==2)
    {
        regist(role);
    }
    else{
        cerr<<"error"<<endl;
        exit(0);
    }
    
    return 0;
}