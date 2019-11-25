#include <iostream>
#include <fstream>
#include "./utils/DataOperator.cpp"

int main(){

    DataReader <string> obj("./test","in");
    obj.readDataFromFile();

    return 0;

}