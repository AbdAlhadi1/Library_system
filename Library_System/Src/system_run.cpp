#include "../Headers/system.h"
#include "../Headers/log_in.h"
#include "../Headers/sign_up.h"


void System_run(){
    while(true){
        cout<<"Menu :\n";
        cout<<"    1) log_in\n";
        cout<<"    2) sign_up\n";
        cout<<"    3) close system\n";

        string choice;
        cin>>choice;
        if(choice == "1"){Log_in();}
        else if(choice == "2"){Sign_up();}
        else if(choice == "3")return;
        else {cout<< "invalid input, enter again" << "\n";}
    }
}
