#ifndef __DATA_OPERATOR_H__
#define __DATA_OPERATOR_H__

#include <string>
#include <fstream>
#include <vector>
using namespace std;

template <typename T>
struct File{
    string  FilePath;
    string  FileName;
    T       FileStream;
};

template <class T>
class DataReader{

    private:
        File <ifstream> DataFile;
        vector <T>      DataVector;

    public:
        DataReader();
        DataReader(const string&, const string&);
        const vector <T>& readDataFromFile();
        void setFilePath(const string&);
        void setFileName(const string&);
        void showData();
};

template <class T>
class DataWriter{

    private:
        File <ofstream> DataFile;

    public:
        DataWriter();
        DataWriter(const string&, const string&);
        bool writeDataToFile(const vector <T>&);
        void setFilePath(const string&);
        void setFileName(const string&);
};
#endif