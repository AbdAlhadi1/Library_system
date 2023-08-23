#ifndef DOCTOR_FUNCTION_H_INCLUDED
#define DOCTOR_FUNCTION_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <map>

using namespace std;


void creat_course(const string creator_id);

void previous_courses_required(const string courseId);

void List_course(const string doctorId);

void view_course(const string doctorId);

void create_Assignnmt(const string doctorId);

void delete_course(const string doctorId);

void list_my_courses_registration_request(const string doctorId);

void request_teacher_assistant(const string doctorId);

void view_teacher_assistant_responses(const string doctorId);

void message_main_menu(const string doctorId);

void post_main_menu(const string doctorId);

#endif // DOCTOR_FUNCTION_H_INCLUDED
