#ifndef CHACKING_H_INCLUDED
#define CHACKING_H_INCLUDED
#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <map>
#include <vector>


using namespace std;

pair<string,string> Log_in_validate(const string userName,const string password);

bool email_checker(string email);

bool check_userName(const string userName);

bool check_validate_courseID_and_doctorId(const string doctorId, const string couresId);

bool check_coures_exist(const string couresId);

bool check_teacher_assistent_exist(const string teacherAssistentId);

bool check_validate_courseID_and_assignmentID(const string assignmentId,const string courseId);

bool check_validate_solutionId_and_assignmentId(const string solutionId, const string assignmentId);

bool check_existing_course(const string courseId);

bool check_prrvios_knowlege_for_course(const string courseId,const string studentId);

bool check_if_student_registred_in_this_course(const string courseId, const string studentId);

bool check_have_solution_for_this_assignment(const string assignmentId, const string studentId);

bool check_existing_assignment(const string assignmentId);

bool check_if_this_teacher_assistant_in_this_course_already(const string teacherAssistantId,string courseId);

bool check_if_this_user_is_teacher_assistant(const string id);

bool check_user_exist(const string userId);

bool check_exist_message(const string messageId);

bool check_if_this_message_to_this_user(const string userId,const string messageId);

bool check_if_already_responsed_to_this_message(const string messageId);

bool check_if_post_exist(const string postId);
#endif // CHACKING_H_INCLUDED
