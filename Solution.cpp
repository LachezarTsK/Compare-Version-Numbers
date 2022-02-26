
#include <sstream>
#include <vector>
using namespace std;

class Solution {
    
    inline const static int less = -1;
    inline const static int greater = 1;
    inline const static char equal = 0;
    inline const static char delimeter = '.';

public:

    int compareVersion(string version1, string version2) {

        vector<string> v1;
        vector<string> v2;
        splitStringIntoVector(v1, version1, delimeter);
        splitStringIntoVector(v2, version2, delimeter);

        const size_t sizeShorter = min(v1.size(), v2.size());

        for (int i = 0; i < sizeShorter; i++) {
            int first = stoi(v1[i]);
            int second = stoi(v2[i]);
            if (first != second) {
                return (first < second) ? less : greater;
            }
        }

        if (v1.size() != v2.size()) {
            return (v1.size() < v2.size()) ? checkRemainder(v1, v2, less) : checkRemainder(v2, v1, greater);
        }
        return equal;
    }

    int checkRemainder(const vector<string>& first, const vector<string>& second, const int returnValueIfNonzeroElementIsFound) {
        for (int i = first.size(); i < second.size(); i++) {
            if (stoi(second[i]) > 0) {
                return returnValueIfNonzeroElementIsFound;
            }
        }
        return equal;
    }

    void splitStringIntoVector(vector<string>& numToString, string& version, const char delimiter) {
        string num;
        stringstream sstream(version);
        while (getline(sstream, num, '.')) {
            numToString.push_back(num);
        }
    }
};
