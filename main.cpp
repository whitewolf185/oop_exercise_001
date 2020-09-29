#include "main.h"
#include <vector>

int main(){

    std::cout<< "Enter your time for show difference" << std::endl;
    TimePoint time1, time2;
    time1.setTime_in_format();
    time2.setTime_in_format();

    time1.show_difference(time2.get_time_in_format());

    return 0;
}