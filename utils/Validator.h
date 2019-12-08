#ifndef __VALIDATOR_H__
#define __VALIDATOR_H__
#include <vector>
#include <algorithm>

enum VALIDATOR_RESULT{PASS, FAIL, UNKNOWN};

template <class T>
class Validator{

    private:
        vector <T>          ValidatedResultVector;
        VALIDATOR_RESULT    ValidatedResult;

    public:
        Validator();
        bool validateResult(const vector <T>& resultVectorM, const vector <T>& resultVectorC);
        const vector <T>& getValidatedResultVector();
        bool verdictResult();
};
#endif