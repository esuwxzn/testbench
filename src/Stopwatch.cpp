#include "Stopwatch.h"


Stopwatch :: Stopwatch(){

    H_SECOND = 0;
    SECOND = 0;
    MINUTE = 0;

    cout << "Stopwatch constructor is called and all the data is reset." << endl;
}

const string Stopwatch :: getHSecond(){
    return to_string(H_SECOND);
}

const string Stopwatch :: getSecond(){
    return to_string(SECOND);
}

const string Stopwatch :: getMinute(){
    return to_string(MINUTE);
}



int Stopwatch :: run(const int& start_stop,
                      const int& lap,
                      const int& reset){

    static bool freezeFlag = false;
    static bool runningFlag = false;
    static long currentTime = 0;
    static long freezedTime = 0;


    if(reset){

        H_SECOND = 0;
        SECOND = 0;
        MINUTE = 0;

        freezeFlag = false;
        runningFlag = false;
        currentTime = 0;
        freezedTime = 0;
    }
    else{
        if (runningFlag){
            
            ++currentTime;
            
            if (start_stop)
            {
                runningFlag = false;
            }
            else if (lap && !freezeFlag)
            {
                freezeFlag = currentTime;
                freezeFlag = true;
            }
            else if (lap && freezeFlag)
            {
                freezeFlag = false;
            }
        }
        else{
            
            if(start_stop){
                runningFlag = true;
            }
            else if (lap && freezeFlag)
            {
                currentTime = 0;
            }
            else if (lap && !freezeFlag)
            {
                freezeFlag = false;
            }
        }
    }

    if(freezeFlag){
        MINUTE = freezedTime / 60 / 100;
        SECOND = (freezedTime / 100) % 60;
        H_SECOND = freezedTime % 100;
    }
    else{
        MINUTE = currentTime / 60 / 100;
        SECOND = (currentTime / 100) % 60;
        H_SECOND = currentTime % 100;
    }

    return 0;
}
