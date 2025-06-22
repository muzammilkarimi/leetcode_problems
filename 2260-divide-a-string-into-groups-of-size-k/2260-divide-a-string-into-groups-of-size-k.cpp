#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int i = 0;
        while (i < s.length()) {
            string temp = "";
            for (int j = 0; j < k; ++j) {
                if (i < s.length()) {
                    temp += s[i++];
                } else {
                    temp += fill;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};