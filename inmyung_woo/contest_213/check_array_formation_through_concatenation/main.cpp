#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> pos(105, -1);
        for(int i = 0; i < arr.size(); i++)
            pos[arr[i]] = i;

        for(auto &piece : pieces) {
            if(pos[piece[0]] == -1)
                return false;
            for(int i = 1; i < piece.size(); i++) {
                if((pos[piece[i]]-pos[piece[i-1]]) != 1)
                    return false;
            }
        }
        return true;
    }
};

int main(int, char**) {
    vector<int> arr = {91,4,64,78};
    vector<vector<int> > pieces = {{78},{4,64},{91}};
    Solution s;
    cout << s.canFormArray(arr, pieces) << endl;
    return 0;
}
