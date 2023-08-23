#ifndef STUDENT_FUNCTION_H_INCLUDED
#define STUDENT_FUNCTION_H_INCLUDED
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

void view_courses_not_registerd_in(const string studentId);

void list_my_courses(const string studentId);

void register_in_course(const string studentId);

void see_courses_requests_respons(const string studentId);

void student_grade_report(const string studentId);

void student_view_course(const string studentId);

void list_assignments(const string courseId, const string studentId);

void submit_solution(const string courseId,const string studentId);

void unregister_from_course(const string courseId,const string studentId);

void message_main_menu1(const string studentId);

void post_main_menu1(const string studentId);


#endif // STUDENT_FUNCTION_H_INCLUDED
