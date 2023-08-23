#include "../Headers/doctor.h"


void doctor_main_menu(const string doctorId){

    while(true){
        cout<<"\n";
        cout<<"main menu: \n";
        cout<<"    1) List courses\n";
        cout<<"    2) list my courses registrations requests\n";
        cout<<"    3) create course\n";
        cout<<"    4) view course\n";
        cout<<"    5) Delete course\n";
        cout<<"    6) request teacher assistant\n";
        cout<<"    7) view teacher assistant requset response\n";
        cout<<"    8) messages\n";
        cout<<"    9) posts\n";
        cout<<"    10) log out\n";
        string choice;
        cin>>choice;
        if(choice == "1"){

            List_course(doctorId);

        } else if(choice == "2"){

            list_my_courses_registration_request(doctorId);

        } else if(choice == "3" ){

            creat_course(doctorId);

        } else if(choice == "4"){

            view_course(doctorId);

        } else if (choice == "5"){

            delete_course(doctorId);

        } else if(choice == "6"){

            request_teacher_assistant(doctorId);

        } else if(choice == "7"){

            view_teacher_assistant_responses(doctorId);

        } else if(choice == "8"){

            message_main_menu(doctorId);

        } else if(choice == "9"){

            post_main_menu(doctorId);

        } else if(choice == "10") {
            return;
        } else {
            cout<<"invalid input, please enter again\n";
        }
    }
}
