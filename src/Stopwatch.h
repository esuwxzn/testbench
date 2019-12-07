#include <iostream>
#include <string>

using namespace std;

class Stopwatch{
    
    private:
        int H_SECOND;
        int SECOND;
        int MINUTE;

    public:
        Stopwatch();
        const string getHSecond();
        const string getSecond();
        const string getMinute();
        
        int run(const int&, const int&, const int&);
};