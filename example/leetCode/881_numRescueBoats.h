//
// Created by s30001871 on 2021/8/26.
//
//重点关注： 这个船上最多两个人
#ifndef MYFIRSTCODE_881_NUMRESCUEBOATS_H
#define MYFIRSTCODE_881_NUMRESCUEBOATS_H

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    int ans = 0;
    while (left <= right){
        if(people[left] + people[right] <= limit){
            left++;
            right--;
            ans+=1;
        } else {
            right--;
            ans += 1;
        }
    }
    return ans;
}

void test_numRescueBoats() {
    vector<int> people = {1,2,2,3,4};
    int lim = 5;
    int ans = 0;
    ans = numRescueBoats(people, lim);
    cout << ans << endl;
}
#endif //MYFIRSTCODE_881_NUMRESCUEBOATS_H
