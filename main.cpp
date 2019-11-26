#include <iostream>
#include <fstream>
#include "./utils/DataOperator.cpp"

int main(){

    DataReader <string> obj("./test","in");
    obj.readDataFromFile();
    obj.showDataVector();

    vector <string> outputVector;

    for(int i = 0; i <= 10; ++i){
        outputVector.push_back("Test");
    }

    // showData(outputVector);
    

    DataWriter <string> obj2("./test", "out");
    obj2.writeDataToFile((string&) outputVector);
    // obj2.showDataVector();

    DataReader <string> obj3("./test","out");
    obj3.readDataFromFile();
    obj3.showDataVector();

    return 0;

}