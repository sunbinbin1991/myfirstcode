class Solution875 {
public:
bool isOk(const vector<int>& piles, int num, int h)
{
    int sum = 0;
    for (int i = 0; i < piles.size(); ++i) {
        sum += (piles[i] + num - 1) / num;
        if(sum > h) {
            return false;
        }
    }
    return true;
}

int minEatingSpeed(vector<int> &splis, int h)
{
    // 二分法思想
    long sum = 0;
    int left = 0;
    int right = INT_MIN;
    for (int i = 0; i < splis.size(); i++) {
        sum += splis[i];
        right = max(right, splis[i]);
    }
    left = sum / h + 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isOk(splis, mid, h)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
};
