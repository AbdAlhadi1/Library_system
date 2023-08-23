#include "../Headers/id.h"


int set_id(){
    ifstream in("ids.txt");

    in.clear();
    int id,oldId;
    in>>oldId;
    in.close();

    id=oldId+1;

    ofstream ou("ids.txt");

    ou.clear();
    ou<<id;
    ou.close();

    return  id;
}
string set_course_id(){
    ifstream in("course_id.txt");

    string first;
    int number;
    in.clear();
    in>>first>>number;
    number++;
    in.close();

    string id=first+to_string(number);

    ofstream out("course_id.txt");
    out.clear();
    out<<first<<" "<<number;
    out.close();

    return id;
}
