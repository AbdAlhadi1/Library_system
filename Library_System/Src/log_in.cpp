#include "../Headers/log_in.h"
#include "../Headers/chacking.h"
#include "../Headers/distribute.h"

void Log_in(){

    string userName,password;
    string type,id;
    bool canselLogIn=false;
    while(true){
        cout<<"Enter username"<<"\n";
        cin>>userName;
        if(userName=="-1"){
            canselLogIn=true;
            break;
        }
        cout<<"Enter password"<<"\n";
        cin>>password;
        id=Log_in_validate(userName,password).first;
        type=Log_in_validate(userName,password).second;
        if(id!="0")break;
        else {
            cout<<"user not found, please enter again or enter -1 to sign_up\n";
        }
    }
    if(canselLogIn)return;
    distribute_users(type,id);
}
