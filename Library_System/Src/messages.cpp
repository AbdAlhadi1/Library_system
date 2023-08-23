#include "../Headers/messages.h"
#include "../Headers/get.h"
#include "../Headers/id.h"
#include "../Headers/chacking.h"
void see_all_my_messages(const string userId){

    ifstream in ("messages.txt");
    string senderId,reciverId,messageId,message;
    vector<vector<string>>messageS;
    while(in >> senderId >> reciverId >> messageId){
        getline(in,message,'\n');
        if(message.size()>1)message= message.substr(1);
        if( senderId == userId){
            messageS.push_back({message,messageId,get_userName_from_ID(reciverId)});
        }
    }

    for(int i=0; i<(int)messageS.size(); i++){
        cout<<"message number #"<<i+1<<": "<<messageS[i][0]<<" to :"<<messageS[i][2]<<"\n";
    }

}

void see_my_messages_replay(const string userId){

    ifstream in ("messages_reply.txt");
    string response,messageId,responderId,senderId;
    while(in >> messageId >> responderId >> senderId){
        getline(in,response,'\n');
        if(response.size()>1)response=response.substr(1);
        if(senderId == userId){
            cout<<"the response to the message :"<<get_message_from_messageId(messageId)<<"is :"<<response<<" from :"<<get_userName_from_ID(responderId)<<"\n";
        }
    }
}

void send_message(const string userId){
    cout<<"enter the user id you want to sent to him a message\n";
    string reciverId;
    while(true){
        cin>>reciverId;
        if(reciverId == "-1")return ;
        if(check_user_exist(reciverId))break;
        else cout<<"this user is not existed, enter again or enter -1 to go back\n";
    }
    string messageId=set_course_id();
    string message;
    cout<<"enter your message\n";
    cin.ignore();
    getline(cin,message,'\n');
    ofstream out("messages.txt",ios::app);
    out.clear();
    out<<userId <<" "<<reciverId<<" "<<messageId<<" "<<message<<"\n";
    out.close();
}

void reply_message(const string userId){
    cout<<"enter message id\n";
    string messageId;
    while(true){
        cin>> messageId;
        if(check_exist_message(messageId)){

            if(check_if_this_message_to_this_user(userId,messageId))break;
            else {cout<<"this message dont belong to your messages\n"; return;}

        }else cout<<"invalid input, ther is no message with this id, enter again or enter -1 to go back\n";
    }
    if(check_if_already_responsed_to_this_message(messageId)){
        cout<<"you already responsed to this message, enter 0 to cansel or 1 to update your answer\n";
        string choice;
        cin >> choice;
        if(choice == "0")return;
        else {
            string new_response;
            cout<<"enter your new response\n";
            cin.ignore();
            getline(cin,new_response,'\n');

            ifstream in1 ("messages_reply.txt");
            string messageID,responderId,senderId,response;
            vector<vector<string>> responses;
            while(in1 >> messageID >> responderId >> senderId){
                getline(in1,response,'\n');
                if(response.size()>1)response = response.substr(1);
                responses.push_back({messageID,responderId,senderId,response});
            }

            ofstream out("messages_reply.txt");
            out.clear();
            for(int i=0; i<(int)responses.size(); i++){
                if(responses[i][0] == messageId && responderId == userId){
                    out<<responses[i][0]<<" "<<responses[i][1]<<" "<<responses[i][2]<<" "<<new_response<<"\n";
                }
                else out<<responses[i][0]<<" "<<responses[i][1]<<" "<<responses[i][2]<<" "<<responses[i][3]<<"\n";
            }
        }
    } else {
        string response;
        cout<<"enter your new response\n";
        cin.ignore();
        getline(cin,response,'\n');

        ofstream out ("messages_reply.txt");
        out.clear();
        out<<messageId<<" "<<userId<<" "<<get_message_sender_id_from_message_id(messageId)<<" "<<response<<"\n";
        out.close();
    }

}

void see_all_message_to_me(const string userId){

    ifstream in("messages.txt");
    vector<vector<string>>messageS;
    string senderId,reciverId,messageId,message;
    while(in >> senderId >> reciverId >> messageId){
        getline (in, message, '\n');
        if(message.size()>1)message = message.substr(1);
        if(reciverId == userId ){
            messageS.push_back({get_userName_from_ID(senderId),messageId,message});
        }
    }

    for(int i=0; i<(int)messageS.size(); i++){
        cout<<"message :"<<messageS[i][2]<<" from :"<<messageS[i][0]<<" with id :"<<messageS[i][1]<<"\n";
    }
}
