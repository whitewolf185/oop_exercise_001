#include "main.h"
#include <vector>

int main(){
    TimePoint time1, time2;
    std::cout<< "Enter your time for show difference" << std::endl;

    time1.setTime_in_format();
    time2.setTime_in_format();

    time1.show_difference(time2.get_time_in_format());



    std::cout << std::endl << "Enter time for sum" << std::endl;

    time1.setTime_in_format();
    time2.setTime_in_format();

    time1.sum_time_in_format(time2.get_time_in_format());



    std::cout << std::endl << "Enter time for sum in sec. The First one is time. \n"
                              "The second one is seconds" << std::endl;

    time1.setTime_in_format();

    int sec;
    std::cin >> sec;

    time1.show_seconds_in_time(time1.sum_time_seconds(sec));



    std::cout << std::endl << "Enter time for how times bigger (smaller)" << std::endl;

    time1.setTime_in_format();
    time2.setTime_in_format();

    time1.how_times(time2.get_time_in_format());

    return 0;
}