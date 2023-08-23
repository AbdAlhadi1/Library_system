#include "../Headers/get.h"

int get_number_of_student_in_course(const string courseId){
    ifstream in ("courses_registration.txt");

    int numberOfStudentsInThisCourse=0;
    string courseID,studentId;

    in.clear();
    while(in>>studentId>>courseID){
        if(courseID==courseId)numberOfStudentsInThisCourse++;
    }
    in.close();

    return numberOfStudentsInThisCourse;
}


int get_number_of_student_solved_this_assignment(const string assignmentId){

    ifstream in("assignments_sol.txt");
    string assignmentID,sol;
    int numberOfStudentsSolvedThisAssignment=0;
    while(in>>assignmentID){
        getline(in,sol,'\n');
        sol=sol.substr(1);
        if(assignmentID==assignmentId)numberOfStudentsSolvedThisAssignment++;
    }

    return numberOfStudentsSolvedThisAssignment;

}

string get_userName_from_ID(const string userId){

    ifstream in("users.txt");

    in.clear();
    string type,id,userName,password,fullName;
    while(in>>type>>id>>userName>>password){
        getline(in,fullName,'\n');
        fullName=fullName.substr(1);
        if(id==userId)return userName;
    }
}

string get_assignment_from_assignmentId(const string assignmentId){

    ifstream in ("assignment.txt");

    string assignmentID,assignment,creatorName,fullMark,courseId;
    while(in>>assignmentID>>courseId>>creatorName>>fullMark){
        getline(in,assignment,'\n');
        assignment=assignment.substr(1);
        if(assignmentID==assignmentId)return assignment;
    }
}

int get_assignment_fullMark(const string assignmentId){

    ifstream in ("assignment.txt");

    string assignmentID,creatorName,assignment,courseId;
    int fullMark;

    while(in>>assignmentID>>courseId>>creatorName>>fullMark){
        getline(in,assignment,'\n');
        assignment=assignment.substr(1);
        if(assignmentID == assignmentId)return fullMark;
    }
}

string get_coures_creator_from_course_id(const string courseId){

    ifstream in ("courses.txt");
    string courseID,creatorId,coursePassword,courseName;
    while(in>>courseID >> creatorId >> coursePassword){
        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        if(courseID == courseId) return get_userName_from_ID(creatorId);
    }
}


string get_course_name_form_course_id(const string courseId){

    ifstream in ("courses.txt");

    string courseID,creatorId,coursePassword,courseName;
    while(in>>courseID>>creatorId>>coursePassword){
        getline(in,courseName,'\n');
        courseName=courseName.substr(1);
        if(courseID == courseId) return courseName;
    }
}

string get_coures_id_from_course_name(const string courseName){
    ifstream in ("courses.txt");
    string courseID,creatorId,coursePassword,courseNAme;
    while(in >> courseID >> creatorId >> coursePassword){
        getline(in,courseNAme,'\n');
        courseNAme = courseNAme.substr(1);
        if(courseNAme == courseName) return courseID;
    }
}

vector<pair<string ,string >> get_all_assignments_for_this_course(const string courseId){

    vector<pair<string,string>> assignments;
    ifstream in ("assignment.txt");
    string assignmentId,courseID,creatorName,fullMark,assignment;
    while(in>> assignmentId >> courseID >> creatorName >> fullMark ){
        getline(in,assignment,'\n');
        assignment = assignment.substr(1);
        if(courseID == courseId)assignments.push_back({assignment,assignmentId});
    }

    return assignments;
}

string get_this_assignment_grade(const string assignmentId, const string studentId){

    ifstream in ("assignmets_sol.txt");
    string solutionId, userName, assignmentID,solution;
    string solutionID;
    while(in >>solutionId >> userName >> assignmentID ){
        getline(in,solution,'\n');
        solution = solution.substr(1);
        if(userName == get_userName_from_ID(studentId) && assignmentID == assignmentId){
            solutionID = solutionId;
            break;
        }
    }
    ifstream in1 ("grades.txt");
    string solutionID1,grade;
    while(in1 >> solutionID1 >> grade){
        if(solutionID1 == solutionID)return grade;
    }

    return "";
}

string get_assignment_solution_from_assignmentId(const string assignmentId,const string studentId){
    ifstream in("assignments_sol.txt");

    string solutionId,studentName,assignmentID,solution;
    while(in>> solutionId >> studentName >> assignmentID){
        getline(in,solution,'\n');
        solution = solution.substr(1);
        if(assignmentID == assignmentId && studentName == get_userName_from_ID(studentId)) return solution;
    }

    return "";
}

void get_all_teacher_assistant(){
    ifstream in ("users.txt");
    vector<pair<string,string>>all_teacher_assistants;
    string type,id,userName,password,email,fullName;
    while(in >> type >> id >> userName >> password >> email){
        getline(in,fullName,'\n');
        if(fullName.size()>1)fullName = fullName.substr(1);
        if(type == "2")all_teacher_assistants.push_back({userName,id});
    }

    for(auto x:all_teacher_assistants){
        cout<<"teacher assistant name :"<<x.first<<" with id :"<<x.second<<"\n";
    }
}


string get_message_from_messageId(const string messageId){
    ifstream in ("messages.txt");
    string senderId,reciverId,messageID,message;
    while(in >> senderId >> reciverId >> messageID){
        getline(in , message , '\n');
        if(message.size()>1)message=message.substr(1);
        if(messageID == messageId)return message;
    }
}

string get_message_sender_id_from_message_id(const string messageId){
    ifstream in ("messages.txt");
    string senderId,reciverId,messageID,message;
    while(in >> senderId >> reciverId >> messageID){
        getline(in , message, '\n');
        if(messageID == messageId)return senderId;
    }
}

string get_user_type(const string userId){
    ifstream in ("users.txt");
    string type,id,userName,password,email,fullName;
    while(in >> type >> id >> userName >> password >> email){
        getline(in, fullName, '\n');
        if(id == userId)return type;
    }
}

string get_post_from_post_id(const string postId){
    ifstream in ("posts.txt");
    string userId,courseId,postID,post;
    while(in >> userId >> courseId >> postID){
        getline(in,post,'\n');
        if(post.size()>1)post = post.substr(1);
        if(postID == postId)return post;
    }
}
