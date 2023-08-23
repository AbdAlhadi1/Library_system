#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void create_Assignnmt(const string courseId, const string doctorId);

void List_assignment(const string courseId);

void view_assignment(const string courseId);

void show_assignment_information(const string assignmentId);

void gread_report(const string assignmentId,const string courseId);

void List_solutions(const string assignmentId);

void view_solution(const string solutionId, const int assignmentFllMark);

void set_grade(const string solutionId,const int assignmentFullMark);

void set_comment(const string solutionId);
#endif // ASSIGNMENT_H_INCLUDED
