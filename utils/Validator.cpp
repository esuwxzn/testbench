#include "Validator.h"

template <class T>
struct compareResult{

    string operator() (const T& inDataA, const T& inDataB){
        if(!inDataA.compare(inDataB)){
            return "PASS";
        }
        else{
            return "FAIL";
        }   
    }
};

template <class T>
Validator <T> :: Validator(){

    ValidatedResult = UNKNOWN;
    ValidatedResultVector.clear();
    cout << "Validator constructor is called!" << endl;
}

template <class T>
bool Validator <T> :: validateResult(const vector <T>& resultVectorM, const vector <T>& resultVectorC){
    
    if(resultVectorM.size() != resultVectorC.size()){
        ValidatedResult = UNKNOWN;
        cout << "The sizes of input result is not equal." << endl;
        return false;
    }
    
    if(ValidatedResultVector.size() != 0)
        ValidatedResultVector.clear();

    ValidatedResultVector.resize(resultVectorM.size());

    transform(resultVectorM.cbegin(),
              resultVectorM.cend(),
              resultVectorC.cbegin(),
              ValidatedResultVector.begin(),
              compareResult <T> ());
}

template <class T>
const vector <T>& Validator <T> :: getValidatedResultVector(){
    return ValidatedResultVector;
}