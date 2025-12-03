class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        // slope intecepts

        unordered_map<float, vector<float>> slopeIntercepts;
        unordered_map<int, vector<float>> midpointmap;
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dy = y2 - y1;
                int dx = x2 - x1;
                float slope, intercept;
                if (x2 == x1) {
                    // dx =0 means our dy is infinite
                    slope = 1e9 + 7;
                    intercept = x1;

                } else {
                    slope = (float)(y2 - y1) / (x2 - x1);
                    intercept = (float)(y1 * dx - x1 * dy) / dx;
                }
                int midpointkey = (x1 + x2) * 10000 + (y1 + y2);
                slopeIntercepts[slope].push_back(intercept);
                midpointmap[midpointkey].push_back(slope);
            }
        }
        for (auto& it : slopeIntercepts) {
            if (it.second.size() <= 1)
                continue;
            map<float, int> mp; // intercepts count
            for (float intercept : it.second) {
                mp[intercept]++;
            }
            int prevHorizontallines = 0;
            for (auto& it : mp) {
                int count = it.second;
                result +=
                    count * prevHorizontallines; // counting duplicates also
                prevHorizontallines += count;
            }
        }
        for (auto& it : midpointmap) {
            if (it.second.size() <= 1)
                continue;
            map<float, int> mp;

            for (float slope : it.second) {
                mp[slope]++;
            }
            int prevHorizontallines = 0;
            for (auto& it : mp) {
                int count = it.second;
                result -= count * prevHorizontallines; // removing duplicates
                prevHorizontallines += count;
            }
        }
        return result;
    }
};
