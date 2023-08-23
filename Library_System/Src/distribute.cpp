#include "../Headers/distribute.h"
#include "../Headers/doctor.h"
#include "../Headers/student.h"
#include "../Headers/teacher_assistant.h"
void distribute_users(const string type , const string id){

    if(type == "1"){

        doctor_main_menu(id);

    } else if(type == "2"){

        teacher_assistant_main_menu(id);

    } else {

        student_main_menu(id);

    }
    return;
}
