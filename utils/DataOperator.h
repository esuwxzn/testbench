#include <fstream>
#include <vector>
#include "FileOperator.cpp"
template <typename T>
void showData(const T& dataVector){
    for(auto data = dataVector.cbegin(); data != dataVector.cend(); ++data){
        cout << *data << endl;
    }
}

template <class T>
class DataReader{
    private:
        FileOperator <ifstream> fileOperator;
        vector <T> dataVector;
    
    public:
        DataReader(const string&, const string&);
        int readDataFromFile(void);
        void showDataVector();
        FileOperator <ifstream>& getFileOperator();
};

template <class T>
class DataWriter{
    private:
        FileOperator <ofstream> fileOperator;
        vector <T> dataVector;
    
    public:
        DataWriter(const string&, const string&);
        int writeDataToFile(void);
        void showDataVector();
        FileOperator <ofstream>& getFileOperator();
};
