#include "../Headers/sign_up.h"
#include "../Headers/chacking.h"
#include "../Headers/id.h"
#include "../Headers/distribute.h"

void Sign_up(){

    string fullName,userName,password,email,confirmPassword,type,id;
    cout<<"for doctor register enter 1\nfor teacher assistent register enter 2\nfor student register enter 3\n";
    while(true){
        cin>>type;
        if(type == "1" || type == "2"|| type == "3")break;
        else cout<<"invalid input, enter again\n";
    }
    while(true){

        cout<<"enter full name\n";
        cin.ignore();
        getline(cin,fullName,'\n');

        cout<<"enter username\n";
        while(true){
            cin>>userName;
            if(!check_userName(userName))break;
            else {
                cout<<"username already exist, enter again\n";
            }
        }

        cout<<"enter password\n";
        cin>>password;
        while(true){
            cout<<"confirm password\n";
            cin>>confirmPassword;
            if(confirmPassword==password)break;
            else cout<<"not matching, enter again\n";
        }
        cout<<"enter email\n";
        while(true){
            cin>>email;
            if(email_checker(email))break;
            else cout<<"invalid email, enter again\n";
        }
        break;
    }
    id=to_string(set_id());
    ofstream out("users.txt",ios::app);
    out.clear();
    out<<type<<" "<<id<<" "<<userName<<" "<<password<<" "<<email<<" "<<fullName<<"\n";
    out.close();


    distribute_users(type,id);
    return ;
}
