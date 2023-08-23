#include "../Headers/assignment.h"
#include "../Headers/id.h"
#include "../Headers/get.h"
#include "../Headers/chacking.h"

void create_Assignnmt(const string courseId, const string doctorId){

    cout<<"\n";
    cout<<"Enter the assignmern\n";
    string assignment,assignmentId,creatorName=get_userName_from_ID(doctorId);
    cin.ignore();
    getline(cin,assignment,'\n');
    cout<<"\nplease enter full mark (between 20 and 60 )\n";
    string fullMark ;
    while(true){
        cin>>fullMark;
        if ( all_of( fullMark.begin() , fullMark.end() , ::isdigit ) ){

            if( stoi(fullMark) >= 20 && stoi(fullMark) <= 60)break;

            else {cout<<"\ninvalid input, enter again\n";}


        } else { cout<<"invalid input, please enter again\n"; }
    }

    assignmentId=set_course_id();

    ofstream out ("assignment.txt", ios::app);
    out.clear();

    out<<assignmentId<<" "<<courseId<<" "<<creatorName<<" "<<fullMark<<" "<<assignment<<"\n";

    out.close();

    return;

}
void List_assignment(const string courseId){

    vector<pair<string,string>> Assignment;
    ifstream in("assignment.txt");
    string courseID,creatorName,assigmnentId,fullMark,assignment;

    while(in>>assigmnentId>>courseID>>creatorName>>fullMark){
        getline(in,assignment,'\n');
        assignment=assignment.substr(1);
        if(courseID == courseId){
            Assignment.push_back({assigmnentId,assignment});
        }
    }
    for(auto X:Assignment)cout<<X.second<<" "<<X.first<<"\n";

}

void gread_report(const string assignmentId, const string courseId){

    int numberOfStudentInThisCourse=get_number_of_student_in_course(courseId);
    int numberOfStudentSolvedThisAssignment=get_number_of_student_solved_this_assignment(assignmentId);

    cout<<"number of student in this course is : "<<numberOfStudentInThisCourse<<"\n";
    cout<<"\n";
    cout<<"number of student solved this assignment : "<<numberOfStudentSolvedThisAssignment<<"\n";
    cout<<"\n";
    if(numberOfStudentInThisCourse==0){
        cout<<"the prsenteag of student whom had solved this assignment is : "<<0<<" %"<<"\n\n";
    } else {
        cout<<"the prsenteag of student whom had solved this assignment is : "<<(double)numberOfStudentSolvedThisAssignment/numberOfStudentInThisCourse<<" %"<<"\n\n";}


}




void List_solutions(const string assignmentId){
    ifstream in ("assignments_sol.txt");

    vector<pair<string ,string >> solutions;
    string userName,solutionId,assignmentID,solution;

    while(in>>solutionId>>userName>>assignmentID){
        getline(in,solution,'\n');
        solution=solution.substr(1);
        if(assignmentID==assignmentId){
            solutions.push_back({userName,solution});
        }
    }

    for(auto X : solutions )cout<<"solution is : "<<X.second<<" from student : "<<X.second<<"\n";

    cout<<"\n";

}

void show_assignment_information(const string assignment_id){

    ifstream in("assignment.txt");
    string courseId,assignmentID,creatorName,fullMark,assignment;

    while(in>>assignmentID>>courseId>>creatorName>>fullMark){
        getline(in,assignment,'\n');
        assignment=assignment.substr(1);
        if(assignment_id==assignmentID){
            cout<<"the assignmet : "<<assignment<<" from : "<<creatorName<<" with code : "<<assignmentID<<"\n";
            return;
        }
    }
}


void show_solution_information(const string solutionId){

    ifstream in ("assignment_sol.txt");
    in.clear();

    string solutionID,solution,studentName,assignmentID;
    while(in>>solutionID>>studentName>>assignmentID){
        getline(in,solution,'\n');
        solution=solution.substr(1);
        if(solutionID == solutionId){
            cout<<"the solution : "<<solution<<" to assignment : "<<get_assignment_from_assignmentId(assignmentID)<<" from student : "<<studentName<<" with code : "<<solutionID<<"\n";
            return;
        }
    }
}

void set_grade(const string solutionId,const int this_assignment_full_mark){

    ofstream out("grades.txt",ios::app);
    cout<<"enter the greade out of "<<this_assignment_full_mark<<"\n";
    string grade;
    while(true){
        cin>>grade;
        if(all_of( grade.begin() , grade.end() , ::isdigit ) ){

            if(stoi(grade)<=this_assignment_full_mark)break;
            else cout<<"invalid input, please enter again\n";

        }else cout<<"invalid input, please enter again\n";
    }
    out.clear();
    out<<solutionId<<" "<<grade<<"\n";
    out.close();
}


void set_comment(const string solutionId){

    ofstream out ("solutions_comment.txt",ios::app);
    string comment;
    cout<<"please enter your comment\n";
    cin>>comment;
    out.clear();
    out<<solutionId<<" "<<comment<<"\n";
    out.close();
}

void view_solution(const string solutionId,const int assignmentFullMark){

    while(true){
        cout<<"\nmenu:\n";
        cout<<"    1) show solution information\n";
        cout<<"    2) set grade\n";
        cout<<"    3) set comment\n";
        cout<<"    4) back\n";
        string choice ;
        cin>> choice ;
        if( choice == "1" ){

            show_solution_information(solutionId);

        } else if( choice == "2"){

            set_grade(solutionId,assignmentFullMark);

        } else if( choice == "3"){

            set_comment(solutionId);

        } else if( choice == "4"){

            return ;

        } else {cout<<"ivalid input, enter again\n";}
    }

}



void view_assignment(const string courseId){

    cout<<"\nenert assignment id\n";
    string assignmentId;
    while(true){
        cin>>assignmentId;
        if(assignmentId == "-1"){
            return;
            }
        if(check_validate_courseID_and_assignmentID( assignmentId , courseId))break;
        else {cout<< "invalid id, please enter again or enter -1 to cansel\n";}
        }

    while(true){
        cout<<"\n";
        cout<<"menu :\n";
        cout<<"    1) Show assignment information\n";
        cout<<"    2) gread reporte\n";
        cout<<"    3) list solutions\n";
        cout<<"    4) view solution\n";
        cout<<"    5) back\n";
        string choice;
        cin>>choice;
        if (choice == "1"){

            show_assignment_information(assignmentId);

        } else if (choice == "2"){

            gread_report(assignmentId,courseId);

        } else if (choice == "3"){

            List_solutions(assignmentId);

        } else if (choice == "4"){

            cout<<"enter solution id\n";
            string solutionId;
            while(true){
                cin>>solutionId;
                if(solutionId == "-1")break;
                if(check_validate_solutionId_and_assignmentId(solutionId,assignmentId))break;
                else {cout << "invalid id,please enter again or enter -1 to cansel\n";}
            }
            int fullMark=get_assignment_fullMark(assignmentId);
            view_solution(solutionId,fullMark);

        } else if (choice == "5"){

            break;

        } else {cout<<"invalid input, please enter again\n";}
    }

    return;
}
