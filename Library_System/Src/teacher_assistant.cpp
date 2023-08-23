#include "../Headers/teacher_assistant.h"
#include "../Headers/teacher_assistant_functions.h"
#include "../Headers/doctor_function.h"
#include "../Headers/posts.h"

void teacher_assistant_main_menu(const string teacherAssistantId){

    while(true){
        cout<<"\nmenu: \n";
        cout<<"    1) check my requests\n";
        cout<<"    2) list my courses\n";
        cout<<"    3) view course\n";
        cout<<"    4) messages\n";
        cout<<"    5) posts\n";
        cout<<"    6) log out\n";
        string choice;
        cin>>choice;
        if(choice == "1"){

            check_my_request(teacherAssistantId);

        } else if(choice == "2"){

            list_teacher_assistant_courses(teacherAssistantId);

        } else if(choice == "3"){

            view_course(teacherAssistantId);

        } else if(choice == "4"){

            message_main_menu(teacherAssistantId);

        } else if(choice == "5"){

            post_main_menu2(teacherAssistantId);

        } else if(choice == "6"){

        return;

        } else cout<<"invalid input, enter again\n";
    }
}
