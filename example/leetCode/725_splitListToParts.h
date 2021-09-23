/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // 这一题的关键是是怎么让两部分的长度差距不超过1，且前面的长度大于等于后面的长度
 // 1:先使用一个数组把每个位置的的值先计算出来
 // 2:还有个坑，就算是空指针，k不小于零那也是要加那么多空指针在后面


class Solution725 {
    
public:
    void getAvgVec(int len, int k, vector<int>& nums) {
        nums.resize(k);
        int count = 0 ;
        while(len > 0 && k > 0){
            if (len % k == 0) {
                nums[count++] = len / k;
                len -= (len / k);
            } else{
                nums[count++] = len / k + 1;
                len -= (len / k + 1);
            }
            k--;
        }
        for(int i = 0; i < nums.size();i++){
            // printf("%d\n", nums[i]);
        }
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (k <= 0) return {};
        int len = 0;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* tmp = dummy->next;
        while (tmp) {
            tmp = tmp->next;
            len ++;
        }
        vector<ListNode*> res;
        printf("%d\n", len);
        vector<int> nums;
        getAvgVec(len, k, nums);

        tmp = dummy->next;
        int count = 0;
        res.push_back(tmp);
        int cnt = 0;
        while (tmp) {
            count++;
            ListNode* tmp2 = nullptr;
            if (count == nums[cnt]) {
                tmp2 = tmp->next;
                tmp->next = nullptr;
                if (tmp2) {
                    res.push_back(tmp2);
                }
                count = 0;
                cnt++;
            }
            if (tmp2) {
                tmp = tmp2;
            } else {
                tmp = tmp->next;
            }
        }
        
        while(res.size() < k) {
            res.push_back(nullptr);
        }
        return res;
    }
};
