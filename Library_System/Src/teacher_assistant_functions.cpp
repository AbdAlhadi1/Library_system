#include "../Headers/teacher_assistant_functions.h"
#include "../Headers/get.h"
#include "../Headers/messages.h"
#include "../Headers/posts.h"
void check_my_request(const string teacherAssistantId){
    ifstream in ("teacher_assistant_requests.txt");
    string doctorName,courseId,teacherAssistantID;
    set<vector<string>>teacherAssistantRequests;
    while(in >> doctorName >> courseId >> teacherAssistantID){
        if(teacherAssistantID == teacherAssistantId){
            teacherAssistantRequests.insert({doctorName,courseId,teacherAssistantID});
        }
    }
    ofstream out ("teacher_assistant_requests.txt");
    out.clear();
    ofstream out1 ("teacher_assistant_responses.txt",ios::app);
    out1.clear();
    ofstream out2 ("teacher_assistant.txt", ios::app);
    out2.clear();
    for(auto x :teacherAssistantRequests){

        if(x[2] != teacherAssistantId){
            out<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
        } else {
            cout<<"request form :"<<x[0]<<", for course"<<get_course_name_form_course_id(x[1])<<"\n";
            cout<<"enter 1 to accept or 0 to reject\n";
            string choise ;
            while(true){
                cin>> choise ;
                if(choise == "1"){

                    out1<<x[0]<<" "<<get_course_name_form_course_id(x[1])<<" "<<1<<" "<<x[2]<<"\n";
                    out2<<x[2]<<" "<<x[1]<<"\n";
                    break;

                } else if(choise == "0"){

                    out1<<x[0]<<" "<<get_course_name_form_course_id(x[1])<<" "<<0<<" "<<x[2]<<"\n";
                    break;

                } else cout<<"invalid input, enter again \n";
            }
        }
    }
}

void list_teacher_assistant_courses(const string teacherAssistantId){
    ifstream in ("teacher_assistant.txt");
    bool non =false;
    string teacherAssistantID,courseId;
    while(in >> teacherAssistantID >> courseId){
        if(teacherAssistantID == teacherAssistantId ){
            non = true;
            cout<<"the course :"<<get_course_name_form_course_id(courseId)<<" with code :"<<courseId<<"\n";
        }
    }
    if(non)cout<<"you are not in any course yet\n";
}

void message_main_menu2(const string teacherAssistantId){

    while(true){
        cout<<"main menu :\n";
        cout<<"    1) send message\n";
        cout<<"    2) reply to message\n";
        cout<<"    3) see all message from me\n";
        cout<<"    4) see all my message\n";
        cout<<"    5) see all my message reply\n";
        cout<<"    6) back\n";
        string choice;
        cin>> choice;
        if(choice == "1"){

            send_message(teacherAssistantId);

        } else if(choice == "2"){

            reply_message(teacherAssistantId);

        } else if(choice == "3"){

            see_all_my_messages(teacherAssistantId);

        } else if(choice == "4"){

            see_all_message_to_me(teacherAssistantId);

        } else if(choice == "5"){

            see_my_messages_replay(teacherAssistantId);

        } else if(choice == "6"){

            return;

        } else cout<<"invalid input, enter again\n";



    }

}

void post_main_menu2(const string teacherAssistantId){

    while(true){
        cout<<"main menu\n";
        cout<<"    1) creat post\n";
        cout<<"    2) see all my posts\n";
        cout<<"    3) comment on post\n";
        cout<<"    4) see all comment on post\n";
        cout<<"    5) back\n";
        string choice ;
        cin>> choice ;
        if(choice == "1"){

            creat_post(teacherAssistantId);

        } else if(choice == "2"){

            get_all_my_posts(teacherAssistantId);

        } else if(choice == "3"){

            add_coment_to_post(teacherAssistantId);

        } else if(choice == "4"){

            get_all_comment_on_this_post();

        } else if(choice == "5"){
            return;

        } else cout<<"invalid input,enter again\n";

    }


}
