#include "../Headers/doctor_function.h"
#include "../Headers/id.h"
#include "../Headers/assignment.h"
#include "../Headers/chacking.h"
#include "../Headers/get.h"
#include "../Headers/messages.h"
#include "../Headers/posts.h"

void previous_courses_required(const string courseId){
    ofstream out("previous_courses_required.txt");

    cout<<"enter the number fo courses\n";

    int courseNumber;
    cin>>courseNumber;

    cout<<"enter courses name\n";
    string courseName;
    out.clear();
    out<<courseId<<"\n";

    while(courseNumber--){
    cin.ignore();
    getline(cin,courseName,'\n');
    out<<courseName<<"\n";

    }
    out.close();

}

void creat_course( const string creator_id ){
    string courseName,creatorId,coursePassword,courseId;

    courseId=set_course_id();
    creatorId=creator_id;

    cout<<"enter coures name\n";
    cin.ignore();
    getline(cin,courseName,'\n');

    cout<<"enter coures password\n";
    cin>>coursePassword;

    cout<<"this coures required previous knwoledge?\nif yes enter 1 or enter 0\n";
    string choise;
    cin>>choise;
    if(choise == "1"){
        previous_courses_required(courseId);
    }

    ofstream out("courses.txt",ios::app);
    out.clear();
    out<<courseId<<" "<<creatorId<<" "<<coursePassword<<" "<<courseName<<"\n";
    out.close();

    return;
}

void delete_course(const string doctorId){

    cout<<"enter course id\n";
    string courseId;
    while(true){
        cin>>courseId;
        if(courseId == "-1")return;
        if(check_existing_course(courseId)){
            if(check_validate_courseID_and_doctorId(doctorId,courseId))break;
            else {cout<<"this course not belong to your courses\n";return;}

        } else cout<<"this course not exist, enter again or enter -1 to go back\n";
    }

    ifstream in ("courses.txt");
    vector<vector<string>> courses;

    string courseID,creatorId,coursePassword,courseName;
    while(in>> courseID >> creatorId >> coursePassword){
        getline(in,courseName,'\n');
        if(courseName.size()>1)courseName=courseName.substr(1);
        courses.push_back({courseID,creatorId,coursePassword,courseName});
    }

    ofstream out ("courses.txt");
    out.clear();
    for(int i=0; i<(int)courses.size(); i++){
        if( courses[i][0] == courseId)continue;
        else {
            out<< courses[i][0] <<" "<<courses[i][1]<<" "<<courses[i][2]<<" "<<courses[i][3]<<"\n";
        }
    }
    out.close();
    courseID = "";

    ifstream in1 ("assignment.txt");
    vector<vector<string>> assignments;
    map<string,int> non_wanted_assignments;
    string assignmentId,creatorName,fullMark,assignment;

    while(in1>> assignmentId >> courseID >> creatorName >> fullMark){
        getline(in1,assignment,'\n');
        if(assignment.size()>1)assignment=assignment.substr(1);
        assignments.push_back({assignmentId,courseID,creatorName,fullMark,assignment});
        if(courseID == courseId) non_wanted_assignments[assignmentId]++;
    }

    ofstream out1 ("assignment.txt");
    out1.clear();
    for(int i=0; i<(int)assignments.size(); i++){
        if(assignments[i][1] == courseId)continue;
        else {
            out1<<assignments[i][0]<<" "<<assignments[i][1]<<" "<<assignments[i][2]<<" "<<assignments[i][3]<<" "<<assignments[i][4]<<"\n";
        }
    }
    out1.close();
    assignmentId = "";

    ifstream in2 ("assignments_sol.txt");
    string solutionId,studentName,solution;
    vector<vector<string>> solutions;
    map<string,int> non_wanted_solutions;
    while(in2>> solutionId >> studentName >> assignmentId){
        getline(in2,solution,'\n');
        if(solution.size()>1)solution=solution.substr(1);
        solutions.push_back({solutionId,studentName,assignmentId,solution});
        if(non_wanted_assignments.count(assignmentId) >0){non_wanted_solutions[solutionId]++;}
    }

    ofstream out2 ("assignments_sol.txt");
    out2.clear();
    for(int i=0; i<(int)solutions.size(); i++){
        if(non_wanted_assignments.count(solutions[i][2])>0)continue;
        else {
            out2<<solutions[i][0]<<" "<<solutions[i][1]<<" "<<solutions[i][2]<<" "<<solutions[i][3]<<"\n";
        }
    }
    out2.close();
    solutionId = "";

    ifstream in3 ("solutions_comment.txt");
    string comment;
    vector<pair<string,string>> comments;
    while(in3>> solutionId){
        getline(in3,comment,'\n');
        if(comment.size()>1)comment=comment.substr(1);
        comments.push_back({solution,comment});
    }

    ofstream out3 ("solutions_comment.txt");
    out3.clear();
    for(int i=0; i<(int)solutions.size(); i++){
        if(non_wanted_solutions.count(comments[i].first)>0)continue;
        else {
            out3<< comments[i].first<<" "<<comments[i].second<<"\n";
        }
    }
    out3.close();

    ifstream in4 ("courses_registration.txt");
    string studentName1,courseIDD;
    vector<pair<string,string>>courses_registration;
    while(in4 >> studentName1 >> courseIDD){
        courses_registration.push_back({studentName1,courseIDD});
    }
    ofstream out4 ("courses_registration.txt");
    out4.clear();
    for(int i=0; i<(int)courses_registration.size(); i++){
        if(courses_registration[i].second == courseId)continue;
        else {
            out4<<courses_registration[i].first<<" "<<courses_registration[i].second<<"\n";
        }
    }
}



void List_course(const string doctorId){

    set<pair<string, string>> courses;

    ifstream in("courses.txt");
    in.clear();
    string courseId,creatorId,coursePassword,courseName;

    while(in>>courseId>>creatorId>>coursePassword){
        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        if(creatorId==doctorId){
            courses.insert({courseName,courseId});
        }
    }
    in.close();
    cout<<"\n";
    for(auto X:courses){
        cout<<X.first<<" "<<X.second<<"\n";
    }

    return;
}

void view_course(const string doctorId){
     string courseId;
    if(check_if_this_user_is_teacher_assistant(doctorId)){
        cout<<"please enter course id\n";
        while(true){
            cin>>courseId;
            if(courseId == "-1"){return;}
            if(check_if_this_teacher_assistant_in_this_course_already(doctorId,courseId))break;
            else {cout<<"invalid id, this course is not belong to your courses,enter again\nor enter -1 to cansel\n";}
            }
    } else {
        cout<<"please enter course id\n";
        while(true){
            cin>>courseId;
            if(courseId == "-1"){return;}
            if(check_validate_courseID_and_doctorId(doctorId,courseId))break;
            else {cout<<"invalid id, this course is not belong to your courses,enter again\nor enter -1 to cansel\n";}
            }
        }
    while(true){
        cout<<"\n";
        cout<<"menu: \n";
        cout<<"    1) List Assaignmts\n";
        cout<<"    2) Creat Assignmt\n";
        cout<<"    3) view Assignmt\n";
        cout<<"    4) Back\n";

        string choice ;
        cin>> choice ;
        if(choice == "1"){
            List_assignment(courseId);

        } else if(choice == "2"){
            create_Assignnmt(courseId,doctorId);

        } else if(choice == "3"){

            view_assignment(courseId);

        } else if(choice == "4"){
            break;

        } else {

            cout<<"invalid inpute, enter again\n";
        }
    }
    return;

}

void list_my_courses_registration_request(const string doctorId){

    ifstream in ("courses_registrations_requests.txt");
    set<vector<string>> requests;
    string doctorName = get_userName_from_ID(doctorId);

    string doctorsName, studentName, courseName;
    while(in >> doctorsName >> studentName ){
        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        requests.insert({doctorsName, studentName, courseName});
    }
    ofstream out ("courses_registrations_response.txt",ios::app);
    out.clear();
    ofstream out1 ("courses_registration.txt",ios::app);
    out1.clear();
    for(auto x:requests){
        if(x[0] == doctorName){
            cout<<"request from : "<<x[1]<<" for course : "<<x[2]<<"\n";
            cout<<"enter 1 to approve, 0 to reject\n";
            string choice;
            while(true){
                cin>> choice;
                if(choice == "1"){

                    out<<x[1]<<" "<<1<<" "<<x[2]<<"\n";
                    out1<<x[1]<<" "<<get_coures_id_from_course_name(x[2])<<"\n";
                    break;

                } else if(choice == "0"){

                    out<<x[1]<<" "<<0<<" "<<x[2]<<"\n";
                    break;

                } else cout<<"invalid input, enter again\n";
            }
        } else continue;
    }
    out.close();
    out1.close();
    ofstream out3("courses_registrations_requests.txt");
    out3.clear();
    for(auto x:requests){
        if(x[0] != doctorName){
            out3<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
        } else continue;
    }
}

void request_teacher_assistant(const string doctorId){
    cout<<"if you want to list all teacher assistant available enter 1\n";
    string first_choise;
    cin>>first_choise;
    if(first_choise == "1")get_all_teacher_assistant();
    cout<<"\nenter course id\n";
    string courseId;
    while(true){
        cin>>courseId;
        if(courseId == "-1")return;
        if(check_existing_course(courseId)){
            if(check_validate_courseID_and_doctorId(doctorId,courseId))break;
            else {cout<<"this course not belong to your courses\n";return;}

        } else cout<<"this course not exist, enter again or enter -1 to go back\n";
    }
    cout<<"enter teacher assistant  id\n";
    string teacherAssistantId;
    while(true){
        cin>>teacherAssistantId;
        if(teacherAssistantId == "-1")return;
        if(check_teacher_assistent_exist(teacherAssistantId)){
            if(check_if_this_teacher_assistant_in_this_course_already(teacherAssistantId,courseId))break;
            else {cout<<"already in this course \n";return;}

        } else cout<<"invlaid input, enter again or enter -1 to go back\n";
    }
    ofstream out ("teacher_assistant_requests.txt",ios::app);
    out.clear();
    out<<get_userName_from_ID(doctorId)<<" "<<courseId<<" "<<teacherAssistantId<<"\n";
    out.close();
    cout<<"your request is done, wait for response\n";

}

void view_teacher_assistant_responses(const string doctorId){
    ifstream in ("teacher_assistant_responses.txt");
    string goal_doctorName = get_userName_from_ID(doctorId);
    string doctorName,courseName,requestAnswer,teacherAssistantId;
    vector<vector<string>> teacherAssistantResponses;
    while(in >> doctorName >> courseName >> requestAnswer >> teacherAssistantId){
        teacherAssistantResponses.push_back({doctorName,courseName,requestAnswer,get_userName_from_ID(teacherAssistantId)});
    }

    ofstream out ("teacher_assistant_responses.txt");
    out.clear();
    for(int i=0; i<(int)teacherAssistantResponses.size(); i++){
        if(teacherAssistantResponses[i][0] == goal_doctorName){

            if(teacherAssistantResponses[i][2] == "1"){
                cout<<"your request to :"<<teacherAssistantResponses[i][3]<<" for course :"<<teacherAssistantResponses[i][1]<<" has been approved\n";
            } else {
                cout<<"your request to :"<<teacherAssistantResponses[i][3]<<" for course :"<<teacherAssistantResponses[i][1]<<" has been rejected\n";
            }


        } else {
            out<<teacherAssistantResponses[i][0]<<" "<<teacherAssistantResponses[i][1]<<" "<<teacherAssistantResponses[i][2]<<" "<<teacherAssistantResponses[i][3]<<"\n";
        }
    }
    out.close();
}

void message_main_menu(const string doctorId){

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

            send_message(doctorId);

        } else if(choice == "2"){

            reply_message(doctorId);

        } else if(choice == "3"){

            see_all_my_messages(doctorId);

        } else if(choice == "4"){

            see_all_message_to_me(doctorId);

        } else if(choice == "5"){

            see_my_messages_replay(doctorId);

        } else if(choice == "6"){

            return;

        } else cout<<"invalid input, enter again\n";



    }

}


void post_main_menu(const string doctorId){

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

            creat_post(doctorId);

        } else if(choice == "2"){

            get_all_my_posts(doctorId);

        } else if(choice == "3"){

            add_coment_to_post(doctorId);

        } else if(choice == "4"){

            get_all_comment_on_this_post();

        } else if(choice == "5"){
            return;

        } else cout<<"invalid input,enter again\n";

    }
}
