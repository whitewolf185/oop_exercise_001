#ifndef OOP_EXERCISE_01_MAIN_H
#define OOP_EXERCISE_01_MAIN_H
#include <string>
#include <iostream>

struct Time {
    int m,
        h,
        s;
};


bool operator<(const Time &lhs, const Time &rhs){
    if(lhs.h != rhs.h){
        return lhs.h < rhs.h;
    }
    else if(lhs.m != rhs.m){
        return lhs.m < rhs.m;
    }
    return lhs.s < rhs.s;
}


Time operator-(const Time &lhs, const Time &rhs){
    Time result{};

    if(lhs.h - rhs.h >= 0) {
        result.h = lhs.h - rhs.h;
    }
    else {
        result.h = 24 + lhs.h - rhs.h;
    }


    if(lhs.m - rhs.m >= 0) {
        result.m = lhs.m - rhs.m;
    }
    else {
        if(result.h > 0) {
            result.h = result.h - 1;
        }
        else{
            result.h = 24 - 1;
        }

        result.m = 60 + lhs.m - rhs.m;
    }


    if(lhs.s - rhs.s >= 0) {
        result.s = lhs.s - rhs.s;
    }
    else {

        if(result.m > 0) {
            result.m = result.m - 1;
        }
        else{
            result.m = 60 - 1;

            if(result.h > 0) {
                result.h = result.h - 1;
            }
            else{
                result.h = 24 - 1;
            }
        }

        result.s = 60 + lhs.s - rhs.s;
    }

    return result;
}



/*
Time operator=(const Time &tmp_time){
    Time result{};

    result.h = tmp_time.h;
    result.m = tmp_time.m;
    result.s = tmp_time.s;

    return result;
}
*/



Time operator+(const Time &lhs, const Time &rhs){
    Time result{};

    result.h = (lhs.h + rhs.h) % 24;

    if(lhs.m + rhs.m >= 60){
        result.h = (result.h + 1) % 24;
        result.m = (lhs.m + rhs.m) % 60;
    }
    else {
        result.m = lhs.m + rhs.m;
    }


    if(lhs.s + rhs.s >= 60){
        if(result.m == 59){
            result.h = (result.h + 1) % 24;
            result.m = 0;
            result.s = (lhs.s + rhs.s) % 60;
        }
        else{
            result.m++;
            result.s = (lhs.s + rhs.s) % 60;
        }
    }

    else {
        result.s = lhs.s + rhs.s;
    }

    return result;
}



















//----------------------the beginning of class----------------------

class TimePoint {
    //---------private----------
private:
    Time time{0,0,0};



    Time convert_to_time(const std::string& a){
        time = {0,0,0};
        int x = 0;
        for (auto i : a) {
            if(i == ':') {
                x++;
                continue;
            }

            if(i >= '0' && i<= '9'){
                if(x == 0)
                    time.h = time.h*10 + (i - '0');

                if (x == 1)
                    time.m = time.m*10 + (i - '0');

                if (x == 2)
                    time.s = time.s*10 + (i - '0');
            }


            if(i < '0' || i> '9'){
                std::cout << "Wrong time format";
                exit (1);
            }
        }

        if(x >= 3 || time.h>23 || time.m >=60 || time.s >=60 || (time.h<0 && time.m<0 && time.s<0) || x == 0) {
            std::cout << "Wrong time format";
            exit (1);
        }

        return time;
    }



    int time_to_seconds(){
        return time.h*60*60 + time.m*60 + time.s;
    }

    int time_to_seconds(Time time_tmp){
        return time_tmp.h*60*60 + time_tmp.m*60 + time_tmp.s;
    }

    Time seconds_to_time(int tmp){
        Time result{};
        result.h = (tmp/3600) % 24;
        result.m = (tmp%3600)/60;
        result.s = tmp%60;

        return result;
    }





    Time minutes_to_time(int tmp){
        Time result{};
        result.h = (tmp / 60) % 24;
        result.m = tmp % 60;
        result.s = 0;

        return result;
    }

    int time_to_minutes() {
        int result;
        result = time.h * 60 + time.m * 60;
        if (time.s >= 30) {
            result++;
        }
        return result;
    }

    int time_to_minutes(Time time_tmp){
        int result;
        result = time_tmp.h*60 + time_tmp.m*60;
        if (time_tmp.s >=30){
            result++;
        }
        return result;
    }


    //---------public-----------
public:
    Time setTime_in_format(){
        std::string a;
        std::cin >> a;
        return convert_to_time(a);
    }

    void show_time_in_format() const{
        if (time.h >= 10 && time.m >= 10 && time.s>=10) {
            std::cout << "time is  " << time.h << ':' << time.m << ':' << time.s << std::endl;
        }
        else {
            if (time.h < 10)
                std::cout << "time is  " << '0' << time.h << ':';
            else
                std::cout << "time is  " << time.h << ':';

            if (time.m < 10)
                std::cout << '0' << time.m << ':';
            else
                std::cout << time.m << ':';

            if (time.s < 10)
                std::cout <<'0' << time.s << std::endl;
            else
                std::cout << time.s << std::endl;
        }
    }

    

    void show_time_in_format(const Time &time_tmp) const {
        if (time_tmp.h >= 10 && time_tmp.m >= 10 && time_tmp.s >=10) {
            std::cout << "time is  " << time_tmp.h << ':' << time_tmp.m << ':' << time_tmp.s << std::endl;
        }
        else {
            if (time_tmp.h < 10)
                std::cout << "time is  " << '0' << time_tmp.h << ':';
            else
                std::cout << "time is  " << time_tmp.h << ':';

            if (time_tmp.m < 10)
                std::cout << '0' << time_tmp.m << ':';
            else
                std::cout << time_tmp.m << ':';

            if (time_tmp.s < 10)
                std::cout <<'0' << time_tmp.s << std::endl;
            else
                std::cout << time_tmp.s << std::endl;
        }
    }

    Time get_time_in_format(){
        return time;
    }

    void show_difference(Time lhs, Time rhs){
        if(lhs < rhs){
            Time tmp;
            tmp = lhs;
            lhs = rhs;
            rhs = tmp;
        }

        Time result = lhs - rhs;

        show_time_in_format(result);
    }

    void show_difference(Time rhs){
        Time lhs = time; //lhs здесь нужно,чтобы не менять значения в классе
        if(lhs < rhs){
            Time tmp{};
            tmp = lhs;
            lhs = rhs;
            rhs = tmp;
        }

        Time result = lhs - rhs;

        show_time_in_format(result);
    }


    void sum_time_in_format(const Time &lhs, const Time &rhs){
        Time result = lhs + rhs;

        show_time_in_format(result);
    }

    void sum_time_in_format(const Time &rhs){
        time = time + rhs;
        show_time_in_format();
    }

    int sum_time_seconds(Time lhs, int &sec){
        int result = time_to_seconds(lhs);
        result += sec;

        std::cout << "time in sec: " << result << std::endl;
        return result;
    }

    int sum_time_seconds(int &sec){
        int result = time_to_seconds(time);
        result += sec;

        std::cout << "time in sec: " << result << std::endl;

        time = time + seconds_to_time(sec);

        return result;
    }




    void sub_time_in_format(const Time &lhs, const Time &rhs){
        Time result{};
        result = lhs - rhs;
        show_time_in_format(result);
    }

    void sub_time_in_format(const Time &lhs){
        time = time - lhs;
        show_time_in_format();
    }




    void sub_time_seconds(Time lhs, int &sec){
        int result = time_to_seconds(lhs);
        if(result < sec){
            result += 60*60*24;
        }
        result -= sec;

        show_time_in_format(seconds_to_time(result));
    }

    void sub_time_seconds(const int &sec){
        time = time - seconds_to_time(sec);

        show_time_in_format();
    }




    void how_times(const Time &tmp_time){
        float time_in_sec = time_to_seconds();
        float tmptime_in_sec = time_to_seconds(tmp_time);

        if(tmptime_in_sec == 0){
            std::cout << "WARNING: division by zero\n"
                         "PROPOSAL: check your time entering" << std::endl;

            exit(1);
        }

        std::cout << "about " << time_in_sec/tmptime_in_sec << " times" << std::endl;
    }




    void show_time_in_minutes(){
        std::cout << "time in minutes " << time_to_minutes() << std::endl;
    }

    void show_time_in_minutes(const Time &tmp){
        std::cout << "time in minutes " << time_to_minutes(tmp) << std::endl;
    }


    void show_minutes_in_time(const int &min){
        Time result = minutes_to_time(min);

        show_time_in_format(result);
    }



    void show_seconds_in_time(const int &sec){
        show_time_in_format(seconds_to_time(sec));
    }

    void show_time_in_seconds(){
        std::cout << "time in seconds " << time_to_seconds() << std::endl;
    }

    void show_time_in_seconds(Time tmp_time){
        std::cout << "time in seconds " << time_to_seconds(tmp_time) << std::endl;
    }

};

//---------------------the end of class---------------------------
#endif //OOP_EXERCISE_01_MAIN_H
