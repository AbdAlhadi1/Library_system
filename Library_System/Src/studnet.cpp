#include "../Headers/student.h"
#include "../Headers/student_function.h"
#include "../Headers/chacking.h"
#include "../Headers/messages.h"
#include "../Headers/posts.h"

void student_main_menu(const string studentId){

    while(true){
        cout<<"\n";
        cout<<"main_menu :\n";
        cout<<"    1) register in course\n";
        cout<<"    2) see registration requests responses\n";
        cout<<"    3) view courses not registerd in\n";
        cout<<"    4) list my courses\n";
        cout<<"    5) view course\n";
        cout<<"    6) grade report\n";
        cout<<"    7) messages\n";
        cout<<"    8) posts\n";
        cout<<"    9) log_out\n";
        string choice;
        cin>> choice;
        if (choice == "1"){
            register_in_course(studentId);

        } else if(choice == "2"){

            see_courses_requests_respons(studentId);

        } else if( choice == "3"){

            view_courses_not_registerd_in(studentId);

        } else if( choice == "4"){

            list_my_courses(studentId);

        } else if( choice == "5"){

            student_view_course(studentId);

        } else if( choice == "6"){

            student_grade_report(studentId);

        } else if(choice == "7"){

            message_main_menu1(studentId);

        } else if(choice == "8"){

            post_main_menu1(studentId);

        } else if( choice == "9"){
            return;
        } else cout<<"invalid input, enter again\n";
    }
}
