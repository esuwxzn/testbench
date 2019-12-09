#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "src/Stopwatch.cpp"
#include "utils/DataOperator.cpp"
#include "utils/Validator.cpp"

using namespace std;

template <typename classT, typename T>

void run(classT& obj,
         const vector <T>& vectorStartStop, const vector <T>& vectorLap, const vector <T>& vectorReset,
         vector <T>& vectorHSecond, vector <T>& vectorSecond, vector <T>& vectorMinute){

    for(auto START_STOP = vectorStartStop.cbegin(),
        LAP = vectorLap.cbegin(),
        RESET = vectorReset.cbegin();
        START_STOP != vectorStartStop.cend();
        ++START_STOP, ++LAP, ++RESET){
            obj.run(stoi(*START_STOP), stoi(*LAP), stoi(*RESET));
            vectorHSecond.push_back(obj.getHSecond());
            vectorSecond.push_back(obj.getSecond());
            vectorMinute.push_back(obj.getMinute());
    }
}

void printVerdictSummary(const int caseNumber,
                         const bool& verdictResultHSecond,
                         const bool& verdictResultSecond,
                         const bool& verdictResultMinute){

    cout << "###########################################"  << endl;
    cout << "The result summary for case: " << caseNumber << endl;
    cout << left << setw(10) <<"H_Second: " << (verdictResultHSecond ? "PASS" : "FAIL") << endl;
    cout << left << setw(10) << "Second: " << (verdictResultSecond ? "PASS" : "FAIL") << endl;
    cout << left << setw(10) << "Minute: " << (verdictResultMinute ? "PASS" : "FAIL") << endl;
    cout << "###########################################"  << endl << endl;

}

template <typename T>

void runVerfication(DataReader <T>& dataReaderObj,
                    const string readFileName,
                    DataWriter <T>& dataWriterObj,
                    const string outputFileName,
                    Validator <T>& validatorObj,
                    const vector <T>& vectorOutputC,
                    bool& verdictResult){
        
        //initialize the verdict flag
        verdictResult = false;

        //Read MATLAB output data
        dataReaderObj.setFileName(readFileName);
        vector <T> vectorOutputM = dataReaderObj.readDataFromFile();
        
        //Validate the result.
        validatorObj.validateResult(vectorOutputM, vectorOutputC);
        
        vector <T> vectorValidateResult = validatorObj.getValidatedResultVector();
        
        //Write verdict result to file.
        dataWriterObj.setFileName(outputFileName);
        dataWriterObj.writeDataToFile(vectorValidateResult);

        verdictResult = validatorObj.verdictResult();
}


const string verificationDataPath = "./verification_data/";

int main(){

    DataReader <string> dataReaderObj;
    DataWriter <string> dataWriterObj;
    Validator <string> validatorObj;
    Stopwatch stopwatchObj;

    cout << endl << "Starting run the testbench..." << endl << endl;

    for(int caseNumber = 1; caseNumber <= 10; ++caseNumber){

        //Set the path of the input data.
        string caseInputDataFullPath = verificationDataPath + "case" + to_string(caseNumber) + "/in";
        string caseOutputDataFullPath = verificationDataPath + "case" + to_string(caseNumber) + "/out";
    
        //Read the input data from the file
        dataReaderObj.setFilePath(caseInputDataFullPath);
        dataReaderObj.setFileName("START_STOP");
        vector <string> vectorStartStop = dataReaderObj.readDataFromFile();

        dataReaderObj.setFileName("LAP");
        vector <string> vectorLap = dataReaderObj.readDataFromFile();

        dataReaderObj.setFileName("RESET");
        vector <string> vectorReset = dataReaderObj.readDataFromFile();
        
        if(!(vectorStartStop.size() == vectorReset.size() and vectorStartStop.size() == vectorLap.size())){
            cout << "The size of input date for case " << caseNumber << " is inconsistent" << endl;
            continue;
        }

        vector <string> vectorHSecond, vectorSecond, vectorMinute;

        //Reset the stop
        stopwatchObj.run(0, 0, 1);

        run(stopwatchObj, vectorStartStop, vectorLap, vectorReset, vectorHSecond, vectorSecond, vectorMinute);

        //Write C code output data into files
        dataWriterObj.setFilePath(caseOutputDataFullPath);
        dataWriterObj.setFileName("H_Second_C");
        dataWriterObj.writeDataToFile(vectorHSecond);

        dataWriterObj.setFileName("Second_C");
        dataWriterObj.writeDataToFile(vectorSecond);

        dataWriterObj.setFileName("Minute_C");
        dataWriterObj.writeDataToFile(vectorMinute);

        //Validate the result
        dataReaderObj.setFilePath(caseOutputDataFullPath);

        bool verdictResultHSecond, verdictResultSecond, verdictResultMinute;

        runVerfication(dataReaderObj, "H_Second" , dataWriterObj, "Result_H_Second", validatorObj, vectorHSecond, verdictResultHSecond);
        runVerfication(dataReaderObj, "Second" ,   dataWriterObj, "Result_Second",   validatorObj, vectorSecond,  verdictResultSecond);
        runVerfication(dataReaderObj, "Minute" ,   dataWriterObj, "Result_Minute",   validatorObj, vectorMinute,  verdictResultMinute);

        printVerdictSummary(caseNumber, verdictResultHSecond, verdictResultSecond, verdictResultMinute);
    }    

    return 0;
}
