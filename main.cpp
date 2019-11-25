#include <iostream>
#include <fstream>
#include "./utils/DataOperator.cpp"

int main(){

    DataReader <string> obj("./test","in");
    obj.readDataFromFile();
    obj.showDataVector();
    return 0;

}