class Solutionoffer69 {
public:
int peakIndexInMountainArray(vector<int>& arr) {
    if (arr.empty()) return 0;
    int left = 0;
    int right = arr.size();
    while(left < right) {
        int mid  = (left + right) / 2;
        if (mid > 0 && arr[mid] > arr[mid-1]) {
            left = mid;
        }
        if (mid < arr.size() - 1 && arr[mid] > arr[mid+1]) {
            right = mid;
        }
    }
    return left;
}
};
