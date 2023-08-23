#include "../Headers/posts.h"
#include "../Headers/get.h"
#include "../Headers/id.h"
#include "../Headers/chacking.h"

void creat_post(const string userId){
    string userType = get_user_type(userId);
    if(userType == "1"){
        cout<<"enter course id\n";
        string courseId;
        while(true){
            cin >>courseId;
            if(courseId == "-1")return;
            if(check_existing_course(courseId)){
                if(check_validate_courseID_and_doctorId(userId,courseId))break;
                else {cout<<"this course not belonge to your courses\n";return;}
            } else {
            cout<<"this course not existed, enter again or etner -1 to cansel\n";
            }
        }
        string postId = set_course_id();
        cout<<"enter your post\n";
        string post;
        cin.ignore();
        getline(cin,post,'\n');
        ofstream out("posts.txt");
        out.clear();
        out<<userId<<" "<<courseId<<" "<<postId<<" "<<post<<"\n";
        out.close();

    } else if(userType == "2"){
        cout<<"enter course id\n";
        string courseId;
        while(true){
            cin >>courseId;
            if(courseId == "-1")return;
            if(check_existing_course(courseId)){
                if(check_if_this_teacher_assistant_in_this_course_already(userId,courseId))break;
                else {cout<<"this course not belonge to your courses\n";return;}
            } else {
            cout<<"this course not existed, enter again or etner -1 to cansel\n";
            }
        }
        string postId = set_course_id();
        cout<<"enter your post\n";
        string post;
        cin.ignore();
        getline(cin,post,'\n');
        ofstream out("posts.txt");
        out.clear();
        out<<userId<<" "<<courseId<<" "<<postId<<" "<<post<<"\n";
        out.close();

    } else {

        cout<<"enter course id\n";
        string courseId;
        while(true){
            cin >>courseId;
            if(courseId == "-1")return;
            if(check_existing_course(courseId)){
                if(check_if_student_registred_in_this_course(courseId,userId))break;
                else {cout<<"this course not belonge to your courses\n";return;}
            } else {
            cout<<"this course not existed, enter again or etner -1 to cansel\n";
            }
        }
        string postId = set_course_id();
        cout<<"enter your post\n";
        string post;
        cin.ignore();
        getline(cin,post,'\n');
        ofstream out("posts.txt");
        out.clear();
        out<<userId<<" "<<courseId<<" "<<postId<<" "<<post<<"\n";
        out.close();
    }
}

void get_all_my_posts(const string userId){

    vector<vector<string>> posts;
    ifstream in ("posts.txt");
    string id,courseId,postId,post;
    while(in >> id >> courseId >> postId){
        getline(in,post,'\n');
        if(post.size()>1)post = post.substr(1);
        if(id == userId){
            posts.push_back({courseId,post,postId});
        }
    }

    for(int i=0; i<(int)posts.size(); i++){
        cout<<"post number #"<<i+1<<" :"<<posts[i][1]<<"with code :"<<posts[i][2]<<" for coures :"<<get_course_name_form_course_id(posts[i][0])<<"\n";
    }

}

void add_coment_to_post(const string userId){

    cout<<"enter post id\n";
    string postId;
    while(true){
        cin>> postId;
        if(postId == "-1")return;
        if(check_if_post_exist(postId))break;
        else cout<<"this course not exist, enter again or enter -1 to cansel\n";
    }

    cout<<"enter your comment\n";
    string comment;
    cin.ignore();
    getline(cin,comment,'\n');
    ofstream out ("posts_comments.txt");
    out.clear();
    out<<userId<<" "<<postId<<" "<<comment<<"\n";
    out.close();
}

void get_all_comment_on_this_post(){
    cout<<"enter post id\n";
    string postId;
    while(true){
        cin>> postId;
        if(postId == "-1")return;
        if(check_if_post_exist(postId))break;
        else cout<<"this course not exist, enter again or enter -1 to cansel\n";
    }
    ifstream in ("posts_comments.txt");
    string userId,postID,comment;
    vector<pair<string ,string>> comments;
    while(in >> userId >> postID){
        getline(in,comment,'\n');
        if(comment.size()>1)comment=comment.substr(1);
        if(postID == postId){
            comments.push_back({comment,get_userName_from_ID(userId)});
        }
    }

    cout<<"the post is :"<<get_post_from_post_id(postId)<<"\n";
    for(int i=0; i<(int)comments.size(); i++){
        cout<<"comment number #"<<i+1<<comments[i].first<<" from user :"<<comments[i].second<<"\n";
    }


}
