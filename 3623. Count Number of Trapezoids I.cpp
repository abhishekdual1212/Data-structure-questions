class Solution {
public:
    int M = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp; // fpr storing y count
        for (auto& point : points) {
            int y = point[1];
            mp[y]++;
        }
        long long result = 0;
        long long previoushorizontallines = 0;
        for (auto& it : mp) {
            long long  count = it.second;
             long long horizontallines = count * (count - 1) / 2;
            result += horizontallines * previoushorizontallines;
            previoushorizontallines += horizontallines;
        }
        return result % M;
    }
};
