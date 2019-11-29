#include "DataOperator.h"

template <typename T>
void displayDataVector(const T& dataVector){

    for(auto data = dataVector.cbegin(); data != dataVector.cend(); ++data){
        cout << *data << endl;
    }
}

//Data reader 
template <class T>
DataReader <T> :: DataReader(const string& filepath, const string& filename){
    
    DataFile.FilePath = filepath;
    DataFile.FileName = filename;
    cout << "Data reader constructor is called!" << endl;
}

template <class T>
void DataReader <T> :: setFilePath(const string& filepath){
    DataFile.FilePath = filepath;
}

template <class T>
void DataReader <T> :: setFileName(const string& filename){
    DataFile.FileName = filename;
}

template <class T>
void DataReader <T> :: showData(){
    displayDataVector(DataVector);
}

template <class T>
const vector <T>& DataReader <T> :: readDataFromFile(){

    string fileFullPath = this->DataFile.FilePath + "/" + this->DataFile.FileName;
    DataVector.clear();

    DataFile.FileStream.open(fileFullPath, ios::in);
    if(DataFile.FileStream.fail()){
        cout << "Cannot open file:" << fileFullPath << endl;
        return DataVector;
    }

    T data;
    while(DataFile.FileStream >> data ){
        DataVector.push_back(data);
    }

    return DataVector;
}


//Data writer
template <class T>
DataWriter <T> :: DataWriter(const string& filepath, const string& filename){
    DataFile.FilePath = filepath;
    DataFile.FileName = filename;
    cout << "Data writer constructor is called!" << endl;

}

template <class T>
void DataWriter <T> :: setFilePath(const string& filepath){
    DataFile.FilePath = filepath;
}

template <class T>
void DataWriter <T> :: setFileName(const string& filename){
    DataFile.FileName = filename;
}

template <class T>
bool DataWriter <T> :: writeDataToFile(const vector <T>& inputDataVector){

    if(inputDataVector.size() == 0){
        cout << "The input data vector is empty, no file will not be created." << endl;
        return false;
    }

    string fileFullPath = DataFile.FilePath + "/" + DataFile.FileName; 
    
    DataFile.FileStream.open(fileFullPath, ios::out | ios::trunc);

    if(DataFile.FileStream.fail()){
        cout << "Cannot create the file:" << fileFullPath << endl;
        return false;
    }

    for(auto data = inputDataVector.cbegin(); data != inputDataVector.cend(); ++data){
        DataFile.FileStream << *data + "\n";
    }

    DataFile.FileStream.close();
    return true;
}
