class Solution1011 {
public:
    bool isOk(vector<int>& weights, int we, int days){
        long sum = 0;
        int need = 0;
        for (int i = 0; i < weights.size(); ++i) {
            if(sum + weights[i] > we) {
                sum = weights[i];
                need++;
                if(need > days){
                    return false;
                }
            } else {
                sum += weights[i];
            }
        }
        if (sum != 0){
            need++;
        }
        return need <= days;
    }
    int shipWithinDays_work2(vector<int>& weights, int days) {
        int sum = 0;
        int maxVal = INT_MIN;
        for (int i = 0; i < weights.size(); ++i) {
            sum += weights[i];
            maxVal = max(weights[i], maxVal);
        }
        int left = maxVal;
        int right = sum;
        while(left < right) {
            int mid = left + (right - left) / 2;
            bool isEnough = isOk(weights, mid, days);
            if(isEnough){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
      int shipWithinDays_work1(vector<int>& weights, int days) {
        int sum = 0;
        int maxVal = INT_MIN;
        for (int i = 0; i < weights.size(); ++i) {
            sum += weights[i];
            maxVal = max(weights[i], maxVal);
        }
        int left = maxVal;
        int right = sum;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            bool isEnough = isOk(weights, mid, days);
            // printf("L:[%d],R:[%d] B:[%d]\n", left, right, isEnough);
            if(isEnough){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
