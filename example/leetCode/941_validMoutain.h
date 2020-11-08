#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A)
    {
        int N = A.size();
        int i = 0;

        // ����ɨ��
        while (i + 1 < N && A[i] < A[i + 1]) {
            i++;
        }

        // ��ߵ㲻��������ĵ�һ��λ�û����һ��λ��
        if (i == 0 || i == N - 1) {
            return false;
        }

        // �ݼ�ɨ��
        while (i + 1 < N && A[i] > A[i + 1]) {
            i++;
        }

        return i == N - 1;
    }
};
