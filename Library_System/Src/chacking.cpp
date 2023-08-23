#include "../Headers/chacking.h"
#include "../Headers/get.h"

pair<string , string> Log_in_validate(const string userName,const string Password){
    pair <string , string> result={"0","0"};
    string username,password,type,fullName,email,id;
    ifstream in("users.txt");
    while(in>>type>>id>>username>>password>>email){
        getline(in,fullName,'\n');
        fullName=fullName.substr(1);
        if(username==userName&&password==Password){
            result.first=id;
            result.second=type;
            break;
        }
    }
    return result;
}

bool email_checker(string email){
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}
bool check_userName(const string userName){
    string a,b,c,d,username;
    ifstream in("users.txt");
    bool exist=false;
    while(in>>a>>b>>username>>c){
        getline(in,c,'\n');
        c=c.substr(1);
        if(userName==username){
            exist=true;
            break;
        }
    }
    return exist;
}

bool check_validate_courseID_and_doctorId(const string doctorId, const string couresId){

    ifstream in("courses.txt");

    string creatorId,couresID,coursePassword,courseName;
    while(in>>couresID>>creatorId>>coursePassword){

        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        if(couresId==couresID){
            if(creatorId==doctorId)return true;
        }
    }

    return false;
}

bool check_coures_exist(const string courseId){

    ifstream in("courses.txt");
    string courseName,coursePassword,courseID,creatorId;
    while(in>>courseID>>creatorId>>coursePassword){
        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        if(courseId==courseID)return true;
    }
    return false;

}
bool check_teacher_assistent_exist(const string teacherAssistentId){
    ifstream in("users.txt");
    string fullName,userName,password,id,type,email;


    while(in>>type>>id>>userName>>password>>email){
        getline(in,fullName,'\n');
        fullName=fullName.substr(1);
        if(id==teacherAssistentId && type == "2") return true;
    }
    return false;
}

bool check_validate_courseID_and_assignmentID(const string assignmentId, const string courseId){

    ifstream in("assignment.txt");

    string creatorName,courseID,assignmentID,assignment,fullMark;
    while(in>>assignmentID>>courseID>>creatorName>>fullMark){

        getline(in,assignment,'\n');
        assignment=assignment.substr(1);
        if(courseID==courseId){
            if(assignmentID==assignmentId)return true;
        }
    }

    return false;
}

bool check_validate_solutionId_and_assignmentId(const string solutionId, const string assignmentId){

    ifstream in("assignmetn_sol.txt");

    in.clear();
    string solutionID,assignmentID,solution,studentName;
    while(in>>solutionID>>studentName>>assignmentID){
        getline(in,solution,'\n');
        solution=solution.substr(1);
        if( solutionID == solutionId && assignmentID == assignmentId )return true;
    }
    return false;
}

bool check_existing_course(const string courseId){

    ifstream in("courses.txt");
    string courseID,creatorId,coursePassword,courseName;
    while(in>> courseID >> creatorId >> coursePassword ){
        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        if(courseID == courseId)return true;
    }
    return false;
}

bool check_prrvios_knowlege_for_course(const string courseId,const string studentId){

    ifstream in("previous_courses_required.txt");
    string courseID;
    vector<string> requirments;
    bool done = false;
    while(in>>courseID){

        if(courseID == courseId){
            string requirment;

            while(in>>requirment){

                if(requirment[0] == '_'){
                    done = true;
                    break;

                } else {
                    requirments.push_back(requirment);
                }
            }
        if(done)break;
        }
    }

    ifstream in1 ("courses_registrations.txt");
    string studentID,courseName;
    map<string , int> courses_registred_in;
    while(in1 >> studentID ){
        getline(in1,courseName,'\n');
        courseName=courseName.substr(1);
        if(studentID == studentId){
            courses_registred_in[courseName]++;
        }
    }

    bool ok = true;

    for(int i=0; i<(int)requirments.size(); i++){
        if(courses_registred_in.count(requirments[i]) == 0){
            ok = false ;
            break;
        }
    }

    return ok;
}

bool check_if_student_registred_in_this_course(const string courseId, const string studentId){
    ifstream in("courses_registration.txt");

    string studentName,courseID;
    while(in >> studentName >> courseID){
        if(courseID == courseId && studentName == get_userName_from_ID(studentId))return true;
    }
    return false;
}


bool check_have_solution_for_this_assignment(const string assignmentId, const string studentId){
    ifstream in ("assignments_sol.txt");
    string solutionId,studentName,assignmentID,solution;
    while(in >> solutionId >> studentName >> assignmentID){
        getline(in, solution , '\n');
        solution = solution.substr(1);
        if(assignmentID == assignmentId && studentName == get_userName_from_ID(studentId))return true;
    }
    return false;
}

bool check_existing_assignment(const string assignmentId){
    ifstream in ("assignment.txt");
    string assignmentID,courseId,creatorName,assignment;
    while(in >> assignmentID >> courseId >> creatorName ){
        getline(in,assignment,'\n');
        if(assignment.size()>1) assignment = assignment.substr(1);
        if(assignmentID == assignmentId)return true;
    }
    return false;
}

bool check_if_this_teacher_assistant_in_this_course_already(const string teacherAssistantId,const string courseId){
    ifstream in("teacher_assistant.txt");
    string teacherAssistantID,courseName;
    while(in >> teacherAssistantID >> courseName){
        if(teacherAssistantID == teacherAssistantId && courseName == get_course_name_form_course_id(courseId))return true;
    }
    return false;
}

bool check_if_this_user_is_teacher_assistant(const string id){
    ifstream in ("users.txt");
    string type,iD,userName,password,email,fullName;
    while(in >> type >> iD >> userName >> password >> email){
        getline(in,fullName,'\n');
        if(fullName.size()>1)fullName = fullName.substr(1);

        if(iD == id){
            if(type == "2")return true;
            else return false;
        }
    }
}

bool check_user_exist(const string userId){
    ifstream in("users.txt");
    string type,id,userName,password,email,fullName;
    while(in >> type >> id >> userName >> password >> email){
        getline(in,fullName,'\n');
        if(fullName.size()>1)fullName = fullName.substr(1);
        if(id == userId)return true;
    }
    return false ;
}

bool check_exist_message(const string messageId){
    ifstream in ("messages.txt");
    string senderId,reciverId,messageID,message;
    while(in >> senderId >> reciverId >> messageID){
        getline(in,message,'\n');
        if(message.size() >1)message = message.substr(1);
        if(messageID == messageId)return true;
    }
    return false;
}


bool check_if_this_message_to_this_user(const string userId,const string messageId){

    ifstream in ("messages.txt");
    string senderId,reciverId,messageID,message;
    while(in >> senderId >> reciverId >> messageID){
        getline(in, message,'\n');
        if(message.size()>1)message = message.substr(1);
        if(messageID == messageId && reciverId == userId)return true;
    }

    return false;

}

bool check_if_already_responsed_to_this_message(const string messageId){
    ifstream in ("messages_reply.txt");
    string messageID,responderId,senderId,response;
    while(in >> messageID >> responderId >> senderId){
        getline(in,response,'\n');
        if(response.size()>1)response = response.substr(1);
        if(messageID == messageId)return true;
    }

    return false;

}

bool check_if_post_exist(const string postId){
    ifstream in ("posts.txt");
    string postID,courseId,userId,post;
    while(in >> userId >> courseId >> postID){
        getline(in,post,'\n');
        if(post.size()>1)post = post.substr(1);
        if(postID == postId)return true;
    }
    return false;
}
