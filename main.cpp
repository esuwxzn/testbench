#include <iostream>
#include <fstream>
#include "utils/DataOperator.cpp"

int main(){

    DataReader <string> obj("./test","in");
    vector <string> dataV = obj.readDataFromFile();
    obj.showData();

    DataWriter <string> obj2("./test", "out");
    obj2.writeDataToFile(dataV);

    DataReader <string> obj3("./test","out");
    obj3.readDataFromFile();
    obj3.showData();

    return 0;

}