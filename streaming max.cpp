#include <bits/stdc++.h>
using namespace std;

class StreamingMax {
private:
    deque<int> dq;
    int k;

public:
    StreamingMax(int window) { k = window; }

    vector<int> process(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements out of window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
