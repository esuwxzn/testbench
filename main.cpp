#include <iostream>
#include <fstream>
#include "./utils/DataOperator.cpp"

int main(){

    DataReader <string> obj("./test","in");
    obj.readDataFromFile();
    obj.showDataVector();

    vector <string> outputVector = obj.getDataVector();

    DataWriter <string> obj2("./test", "out");
    obj2.writeDataToFile(outputVector);
    obj2.showDataVector();

    DataReader <string> obj3("./test","out");
    obj3.readDataFromFile();
    obj3.showDataVector();

    return 0;

}