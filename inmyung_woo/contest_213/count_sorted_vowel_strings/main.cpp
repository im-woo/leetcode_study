#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int _count_vowel_strings_cache[5][55] = {0,};
    int _count_vowel_strings(int start_ch, int n) {
        int &cache = _count_vowel_strings_cache[start_ch][n];
        if(cache != 0)
            return cache;

        if(n == 1)
            return cache = 1;

        int sum = 0;
        for(int ch = start_ch; ch < 5; ch++) {
            sum += _count_vowel_strings(ch, n-1);
        }

        return cache = sum;
    }

    int countVowelStrings(int n) {
        return _count_vowel_strings(0, n+1);
    }
};

int main(int, char**) {
    Solution s;
    cout << s.countVowelStrings(33) << endl;
}
