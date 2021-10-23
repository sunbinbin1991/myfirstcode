// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution278 {
public:
    int firstBadVersion(int n) {
        long left = 1;
        long right = n;
        while (left < right) {
            long mid = (left + right) / 2;
            if(isBadVersion(mid) && mid > 0 && isBadVersion(mid - 1) == false){
                return mid;
            }
            if(isBadVersion(mid) == false && mid < n && isBadVersion(mid + 1)){
                return mid+1;
            }
            if (isBadVersion(mid)){
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
