#include "../Headers/student_function.h"
#include "../Headers/get.h"
#include "../Headers/chacking.h"
#include "../Headers/messages.h"
#include "../Headers/posts.h"

void view_courses_not_registerd_in(const string studentId){

     map<string,int> courses_rigesterd_in;

    ifstream in("courses_registration.txt");

    string studentName,courseId;
    while(in>> studentName >> courseId){
        if(studentName == get_userName_from_ID(studentId))courses_rigesterd_in[courseId]++;
    }

    vector<pair<string,pair<string,string >>> courses;
    ifstream in1("courses.txt");
    string courseId1,creatorId,courseName1,coursePassword;
    while(in1>> courseId1 >> creatorId >> coursePassword){
        getline(in1,courseName1,'\n');
        courseName1=courseName1.substr(1);
        if(courses_rigesterd_in.count(courseId1)>0)continue;
        else {
            courses.push_back({courseId1,{courseName1,get_userName_from_ID(creatorId)}});
        }
    }
    for(auto x:courses)cout<<"course name :"<<x.second.first<<" "<<"with code : "<<x.first<<" for doctor : "<<x.second.second<<"\n";

}

void list_my_courses(const string studentId){

    map<string,int> courses_rigesterd_in;

    ifstream in("courses_registration.txt");
    string goalStudent = get_userName_from_ID(studentId);

    string studentName,courseId;
    while(in>> studentName >> courseId){
        if(studentName == goalStudent)courses_rigesterd_in[courseId]++;
    }

    vector<pair<string,pair<string,string >>> courses;
    ifstream in1("courses.txt");
    string courseId1,creatorId,courseName1,coursePassword;
    while(in1>> courseId1 >> creatorId >> coursePassword){
        getline(in1,courseName1,'\n');
        courseName1=courseName1.substr(1);
        if(courses_rigesterd_in.count(courseId1) == 0)continue;
        else {
            courses.push_back({courseId,{courseName1,get_userName_from_ID(creatorId)}});
        }
    }
    for(auto x:courses)cout<<"course name : "<<x.second.first<<" "<<"with code : "<<x.first<<" for doctor : "<<x.second.second<<"\n";
}

void register_in_course(const string studentId){
            cout<<"enter course id\n";
            string courseId;
            while (true){
                cin>> courseId;
                if(courseId == "-1"){return;}
                if(check_existing_course(courseId))break;
                else cout<<"invalid course id, enter again or enter -1 to cansel\n";
            }

    if(check_if_student_registred_in_this_course(courseId,studentId)){
        cout<<"you already registerted in this course\n";
        return;
    }

    if(!check_prrvios_knowlege_for_course( courseId ,studentId)){
        cout<<" you cant register in this course now, ther is courses you must pass it first\n";
        return;
    }
    ofstream out ("courses_registrations_requests.txt",ios::app);
    out.clear();
    out<<get_coures_creator_from_course_id(courseId)<<" "<<get_userName_from_ID(studentId)<<" "<<get_course_name_form_course_id(courseId)<<"\n";
    out.close();
    cout<<"your request is done, wait for doctor resposnse\n";
}

void see_courses_requests_respons(const string studentId){

    ifstream in ("courses_registrations_response.txt");

    string studentName = get_userName_from_ID(studentId);
    string studentsName, response, courseName;
    vector<vector<string>> responses;
    while(in>> studentsName >> response){
        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        responses.push_back({studentsName, response, courseName});
    }
    bool non=true;
    for(int i=0; i<(int)responses.size(); i++){
        if(responses[i][0] == studentName){
            non=false;
            if(responses[i][1] == "1"){

                cout<<"your request to course: "<<responses[i][2]<<" has been approved\n";

            } else {

                cout<<"your request to course: "<<responses[i][2]<<" has been rejected\n";

            }
        }
    }
    if(non){
        cout<<"ther is no responses yet\n";
        return;
    }
    ofstream out ("courses_registrations_response.txt");
    out.clear();
    for(int i=0; i<(int)responses.size(); i++){
        if(responses[i][0] != studentName){
            out<<responses[i][0]<<" "<<responses[i][1]<<" "<<responses[i][2]<<"\n";
        }
    }
}

void student_grade_report(const string studentId){

    ifstream in ("courses_registration.txt");
    map<string ,int> courses_registred_in;
    string studentName,courseId;
    string goal_studnet=get_userName_from_ID(studentId);
    while(in >> studentName >> courseId){
        if(studentName == goal_studnet){ courses_registred_in[courseId]++;}
    }
    vector<string> coursesId;
    ifstream in1("courses.txt");
    string courseID,creatorId,coursePassword,courseName;

    while(in1 >> courseID >> creatorId >> coursePassword){
        getline(in,courseName,'\n');
        if(courseName.size()>1)courseName=courseName.substr(1);
        if(courses_registred_in.count(courseID)>0)coursesId.push_back(courseID);
    }
    for(int i=0; i<(int)coursesId.size(); i++){

        cout<<"course # "<<i+1<<": "<<get_course_name_form_course_id(coursesId[i])<<"\n";

        vector<pair<string,string>> assignments;
        assignments = get_all_assignments_for_this_course(coursesId[i]);

        for(int j=0; j<(int)assignments.size(); j++){
            string grade =get_this_assignment_grade(assignments[j].second,studentId);
            string solution = get_assignment_solution_from_assignmentId(assignments[i].second,studentId);
            if(solution == ""){
                cout<<"    "<<assignments[j].first<<" "<<"not solved yet \n";
            } else {
                if(grade == ""){
                    cout<<"    "<<assignments[j].first<<" "<<"the doctor didn't correct your solutin yet\n";
                } else{
                    cout<<"    "<<assignments[j].first<<" "<<grade<<"\n";
                }
            }
        }
    }
}

void list_assignments(const string courseId, const string studentId){

    vector<pair<string,string>> assignments;
    assignments = get_all_assignments_for_this_course(courseId);
    for(int j=0; j<(int)assignments.size(); j++){
        string grade =get_this_assignment_grade(assignments[j].second,studentId);
        string solution = get_assignment_solution_from_assignmentId(assignments[j].second,studentId);
        if(solution == ""){
            cout<<"    "<<assignments[j].first<<" "<<"not solved yet \n";
        } else {
                if(grade == ""){
                    cout<<"    "<<assignments[j].first<<" "<<"the doctor didn't correct your solutin yet\n";
                } else{
                    cout<<"    "<<assignments[j].first<<" "<<grade<<"\n";
                }
        }
    }

}

void submit_solution(const string courseId,const string studentId){
    cout<<"enter assignment id\n";
    string assignmentID;
    while(true){
        cin>>assignmentID;
        if(assignmentID == "-1")return;
        if(!check_existing_assignment(assignmentID)){
            cout<<"invalid input, please enter again or enter -1 to go back\n";
        } else {
            if(check_validate_courseID_and_assignmentID(assignmentID,courseId))break;
            else cout<<"this assignment not belong to this course, enter again or enter -1 to go back\n";
        }
    }
    if(check_have_solution_for_this_assignment(assignmentID,studentId)){
        cout<<"you have solution on this assignment, enter 1 to update it or 0 to leave it\n";
        string choise ;
        while(true){
            cin>> choise;
            if(choise == "1"){
                cout<<"enter  your soltuion please\n";
                string solution;
                cin.ignore();
                getline(cin,solution,'\n');
                ifstream in("assignmetns_sol.txt");
                vector<vector<string>> assignment_sols;
                string solutionId,studentName,assignmentId,solution1;
                while(in >> solutionId >> studentName >> assignmentID){
                    getline(in, solution1, '\n');
                    if(solution1.size() >1)solution1 = solution1.substr(1);
                    assignment_sols.push_back({solutionId,studentName,assignmentId,solution1});
                }
                ofstream out("assignments_sol.txt");
                out.clear();
                for(int i=0; i<(int)assignment_sols.size(); i++){
                    if(assignment_sols[i][1] == get_userName_from_ID(studentId) && assignment_sols[i][2] == assignmentID ){

                        out<<assignment_sols[i][0]<<" "<<assignment_sols[i][1]<<" "<<assignment_sols[i][2]<<" "<<solution<<"\n";

                    }else out<<assignment_sols[i][0]<<" "<<assignment_sols[i][1]<<" "<<assignment_sols[i][2]<<" "<<assignment_sols[i][3]<<"\n";
                }
                out.close();
                return ;
            } else if(choise == "0"){

                return ;

            } else cout<<"invalid intput, please enter again\n";
        }
    } else {

    }
}

void unregister_from_course(const string courseId,const string studentId){
    vector<pair<string,string>> courses_registrarions;
    string studentName,courseID;
    ifstream in("course_registration.txt");

    while(in >> studentName >> courseID){
        courses_registrarions.push_back({studentName,courseID});
    }
    ofstream out("courses_registration.txt");
    out.clear();
    for(int i=0; i<(int)courses_registrarions.size(); i++){
        if(courses_registrarions[i].first == get_userName_from_ID(studentId) && courses_registrarions[i].second == courseId)continue;
        else {
            out<<courses_registrarions[i].first<<" "<<courses_registrarions[i].second<<"\n";
        }
    }
    out.close();
}

void student_view_course(const string studentId){
    cout<<"enter course id\n";
    string courseId;
    while(true){
        cin>> courseId;
        if(courseId == "-1")return;
        if(check_coures_exist(courseId)){
            if(check_if_student_registred_in_this_course(courseId,studentId))break;
            else {cout<<"you are not registerd in this course\n";return;}
        }else cout<<"invalid input, please etner again or enter -1 to  go back\n";

    }
    cout<<"the course name : "<<get_course_name_form_course_id(courseId)<<" with code : "<<courseId<<"\n";
    while(true){
        cout<<"menu :\n";
        cout<<"    1) list assignments\n";
        cout<<"    2) submit solution\n";
        cout<<"    3) unregistered from course\n";
        cout<<"    4) back\n";
        string choice;
        cin>>choice;
        if(choice == "1"){

            list_assignments(courseId,studentId);

        } else if(choice == "2"){

            submit_solution(courseId,studentId);

        } else if(choice == "3"){

            unregister_from_course(courseId,studentId);

        } else if(choice == "4"){
            return;

        } else cout<<"invalid inpute, please enter again\n";
    }
}

void message_main_menu1(const string studentId){

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

            send_message(studentId);

        } else if(choice == "2"){

            reply_message(studentId);

        } else if(choice == "3"){

            see_all_my_messages(studentId);

        } else if(choice == "4"){

            see_all_message_to_me(studentId);

        } else if(choice == "5"){

            see_my_messages_replay(studentId);

        } else if(choice == "6"){

            return;

        } else cout<<"invalid input, enter again\n";



    }

}

void post_main_menu1(const string studentId){

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

            creat_post(studentId);

        } else if(choice == "2"){

            get_all_my_posts(studentId);

        } else if(choice == "3"){

            add_coment_to_post(studentId);

        } else if(choice == "4"){

            get_all_comment_on_this_post();

        } else if(choice == "5"){
            return;

        } else cout<<"invalid input,enter again\n";

    }

}


