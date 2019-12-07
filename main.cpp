#include <iostream>
#include <fstream>
#include "src/Stopwatch.cpp"
#include "utils/DataOperator.cpp"
#include "utils/Validator.cpp"

const string verificationDataPath = "./verification_data/";

int main(){

    string caseName = "case";

    

    for(int i = 1; i <= 10; ++i){
        // string test = caseName + to_string(i) + "/in";
        cout << verificationDataPath + caseName + to_string(i) + "/in" << endl;

    }


    // DataReader <string> obj("./test","in");
    // vector <string> dataV = obj.readDataFromFile();
    
    // DataReader <string> objM("./test","in2");
    // vector <string> dataM = objM.readDataFromFile();

    // Validator <string> validatorObj;
    // validatorObj.validateResult(dataM, dataV);
    // vector <string> result = validatorObj.getValidatedResultVector();

    // DataWriter <string> obj2("./test", "out");
    // obj2.writeDataToFile(result);

    // Stopwatch watchObj;

    // watchObj.run(1,0,0);
    // watchObj.run(0,0,0);
    // watchObj.run(0,0,0);
    // watchObj.run(0,0,0);
    // cout << watchObj.getHSecond() << endl;
    // cout << watchObj.getSecond() << endl;
    // cout << watchObj.getMinute() << endl;
    return 0;
}