#ifndef OOP_EXERCISE_01_MAIN_H
#define OOP_EXERCISE_01_MAIN_H
#include <string>
#include <iostream>

struct Time {
    int m,
        h,
        s;
};


bool operator<(Time lhs, Time rhs){
    if(lhs.h != rhs.h){
        return lhs.h < rhs.h;
    }
    else if(lhs.m != rhs.m){
        return lhs.m < rhs.m;
    }
    return lhs.s < rhs.s;
}


Time operator-(Time lhs, Time rhs){
    Time result;

    result.h = lhs.h - rhs.h;
    result.m = lhs.m - rhs.m;
    result.s = lhs.s - rhs.s;

    return result;
}



class TimePoint {
private:
    Time time{0,0,0};



    Time convert_to_time(const std::string& a){
        int x = 0;
        for (auto i : a) {
            if(i == ':')
                x++;

            if(i >= '0' && i<= '9'){
                if(x == 0)
                    time.h = time.h*10 + (i - '0');

                if (x == 1)
                    time.m = time.m*10 + (i - '0');

                if(x == 2)
                    time.s = time.s*10 + (i - '0');
            }
        }

        if(x == 4 || time.h>23 || time.m >=60 || time.s >=60 || (time.h<0 && time.m<0 && time.s<0) ) {
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
        result.h = tmp/3600;
        result.m = (tmp%3600)/60;
        result.s = tmp%60;

        return result;
    }


public:
    Time setTime_in_format(){
        std::string a;
        std::cin >> a;
        return convert_to_time(a);
    }

    void get_time_in_format() const{
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

    

    void get_time_in_format(Time time_tmp){
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



    void show_difference(Time lhs, Time rhs){
        if(lhs < rhs){
            Time tmp;
            lhs = tmp;
            lhs = rhs;
            rhs = tmp;
        }

        Time result = lhs - rhs;

        get_time_in_format(result);
    }



};


#endif //OOP_EXERCISE_01_MAIN_H
