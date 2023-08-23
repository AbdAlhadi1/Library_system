#ifndef GET_H_INCLUDED
#define GET_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int get_number_of_student_in_course(const string courseId);

int get_number_of_student_solved_this_assignment(const string assignmentId);

string get_userName_from_ID(const string userId);

string get_assignment_from_assignmentId(const string assignmentId);

int get_assignment_fullMark(const string assignmentId);

string get_coures_creator_from_course_id(const string courseId);

string get_course_name_form_course_id(const string courseId);

string get_coures_id_from_course_name(const string courseName);

vector<pair<string,string>> get_all_assignments_for_this_course(const string courseId);

string get_this_assignment_grade(const string assignmentId, const string studentId);

string get_assignment_solution_from_assignmentId(const string assignmentId,const string studentId);

void get_all_teacher_assistant();

string get_message_from_messageId(const string messageId);

string get_message_sender_id_from_message_id(const string messageId);

string get_user_type(const string userId);

string get_post_from_post_id(const string postId);

#endif // GET_H_INCLUDED
