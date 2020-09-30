/*Волков Матвей Андреевич
 *
 * Создать класс TimePoint для работы с моментами времени в формате "час:минута:секунда".
 * Обязательными операциями являются: вычисление разницы между двумя моментами времени,
 * сумма моментов времени, сложение момента времени и заданного количества секунд,
 * вычитание из момента времени заданного количества секунд, вычисление во сколько раз один момент времени
 * больше (меньше) другого, сравнение моментов времени, перевод в секунды и обратно, перевод в
 * минуты (с округлением до минуты) и обратно.
*/
#include "main.h"


int main(){
    TimePoint time1, time2;
    int sec;
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


    std::cin >> sec;

    time1.show_seconds_in_time(time1.sum_time_seconds(sec));




    std::cout << std::endl << "Enter time for sub in sec. The First one is time. \n"
                              "The second one is seconds" << std::endl;

    time1.setTime_in_format();
    std::cin >> sec;

    time1.sub_time_seconds(sec);




    std::cout << std::endl << "Enter time for how times bigger (smaller)" << std::endl;

    time1.setTime_in_format();
    time2.setTime_in_format();

    time1.how_times(time2.get_time_in_format());




    std::cout << std::endl << "Enter time for show subtraction" << std::endl;

    time1.setTime_in_format();
    time2.setTime_in_format();

    time1.sub_time_in_format(time2.get_time_in_format());




    std::cout << std::endl << "Enter time for convert in seconds and minutes" << std::endl;

    time1.setTime_in_format();
    time2.setTime_in_format();

    time1.show_time_in_minutes();
    time2.show_time_in_seconds();





    std::cout << std::endl << "Enter sec and minutes for convert in time" << std::endl;

    int min;

    std::cin >> sec >> min;

    time1.show_seconds_in_time(sec);
    time2.show_minutes_in_time(min);

    return 0;
}