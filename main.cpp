#include <iostream>
#include <fstream>
#include "utils/DataOperator.cpp"
#include "utils/Validator.cpp"

int main(){

    DataReader <string> obj("./test","in");
    vector <string> dataV = obj.readDataFromFile();
    
    DataReader <string> objM("./test","in2");
    vector <string> dataM = objM.readDataFromFile();

    Validator <string> validatorObj;
    validatorObj.validateResult(dataM, dataV);
    vector <string> result = validatorObj.getValidatedResultVector();

    DataWriter <string> obj2("./test", "out");
    obj2.writeDataToFile(result);

    // displayDataVector(result);

    return 0;

}