#include "DataOperator.h"

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
    if(!file){
        return -1;
    }
    else{
        while(file >> line){
            cout << line << endl;
        }
    }

    file.close();
    return 1;
}


template <class T>
DataWriter <T>::DataWriter(const string& filepath, const string& filename){
    this->file.setFilePath(filepath);
    this->file.setFileName(filename);
    cout << "Data writer constructor is called!" << endl;
}

template <class T>
FileOperator <ofstream>& DataWriter <T> :: getFileOperator(){
    return this->fileOperator;
}