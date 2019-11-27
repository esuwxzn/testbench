#include "DataOperator.h"

//Data reader implementation
template <class T>
DataReader <T>::DataReader(const string& filepath, const string& filename){
    this->fileOperator.setFilePath(filepath);
    this->fileOperator.setFileName(filename);
    cout << "Data reader constructor is called!" << endl;
}

template <class T>
FileOperator <ifstream>& DataReader <T> :: getFileOperator(){
    return this->fileOperator;
}

template <class T>
int DataReader <T>::readDataFromFile(){

    string fileFullPath = this->getFileOperator().getFullFielPath();

    ifstream& file = this->getFileOperator().getFile();
    
    file.open(fileFullPath, ios::in);

    string line;
    this->dataVector.clear();

    if(file.fail()){
        return -1;
    }
    else{
        while(file >> line){
            this->dataVector.push_back(line);
        }
    }

    file.close();
    return 0;
}

template <class T>
void DataReader <T>::showDataVector(){
    showData(this->dataVector);
}


template <class T>
const vector <T>& DataReader <T>::getDataVector(){
    return this->dataVector;
}


//Data writer implementation
template <class T>
DataWriter <T>::DataWriter(const string& filepath, const string& filename){
    this->fileOperator.setFilePath(filepath);
    this->fileOperator.setFileName(filename);
    cout << "Data writer constructor is called!" << endl;
}

template <class T>
FileOperator <ofstream>& DataWriter <T> :: getFileOperator(){
    return this->fileOperator;
}


template <class T>
int DataWriter <T>::writeDataToFile (vector <T> & outputDataVector){

    if(outputDataVector.size() == 0){
        cout << "The data vector is empty!" << endl;
        return -1;
    }

    string fileFullPath = this->getFileOperator().getFullFielPath();

    ofstream& file = this->getFileOperator().getFile();
    
    file.open(fileFullPath, ios::out | ios::trunc);

    if(file.fail()){
        cout << "Could not open file:" << fileFullPath << endl;
    }

    for(auto data = outputDataVector.cbegin(); data != outputDataVector.cend(); ++data){
        file << *data + "\n";
        this->dataVector.push_back(*data);
    }

    file.close();
    return 0;
}

template <class T>
void DataWriter <T>::showDataVector(){
    showData(this->dataVector);
}
