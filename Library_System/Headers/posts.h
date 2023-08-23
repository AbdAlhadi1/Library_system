#ifndef POSTS_H_INCLUDED
#define POSTS_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void creat_post(const string userId);

void get_all_my_posts(const string userId);

void add_coment_to_post(const string userId);

void get_all_comment_on_this_post();


#endif // POSTS_H_INCLUDED
