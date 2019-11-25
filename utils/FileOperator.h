#ifndef __FILE_OPERATOR_H__

#define __FILE_OPERATOR_H__

#include <string>

using namespace std;

template <class T>
class FileOperator{
    private:
        T file;
        string filePath;
        string fileName;
    
    public:
        FileOperator();
        FileOperator(const string&, const string&);
        T& getFile();
        void setFilePath(const string&);
        void setFileName(const string&);
        void showFilePath();
        void showFileName();
        string getFullFielPath();
};
#endif