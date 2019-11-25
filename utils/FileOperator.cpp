#include "FileOperator.h"

template <class T>
FileOperator <T>::FileOperator(){
    this->fileName = "";
    this->filePath = "";
    cout << "Default constructor in cpp file is called!" << endl;
}

template <class T>
FileOperator <T>::FileOperator(const string& filepath, const string& filename){

    this->filePath = filepath;
    this->fileName = filename;
    cout << "Constructor with initialized value is called!" << endl;
}

template <class T>
void FileOperator <T>::setFilePath(const string& filepath){
    this->filePath = filepath;
}


template <class T>
void FileOperator <T>::setFileName(const string& filename){
    this->fileName = filename;
}

template <class T>
void FileOperator <T>::showFilePath(){
    cout << this->filePath << endl;
}

template <class T>
void FileOperator <T>::showFileName(){
    cout << this->fileName << endl;
}


template <class T>
string FileOperator <T>::getFullFielPath(){
    
    string fullFilePath = this->filePath + "/" + this->fileName;
    return fullFilePath;
}

template <class T>

T& FileOperator <T> :: getFile(){

    return this->file;

}