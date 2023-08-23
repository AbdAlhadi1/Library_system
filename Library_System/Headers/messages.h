#ifndef MESSAGES_H_INCLUDED
#define MESSAGES_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void see_all_my_messages(const string id);

void see_all_message_to_me(const string userId);

void see_my_messages_replay(const string userId);

void send_message(const string userId);

void reply_message(const string userId);

#endif // MESSAGES_H_INCLUDED
