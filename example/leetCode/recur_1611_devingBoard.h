 #pragma once
#include<set>
//bool divingDFS(int shorter, int longer, int k,
//    int &sum, vector<int> &res) {
//    if (k == 0) {
//        res.insert(sum);
//        return;
//    }
    //if (shorter == longer) return[k * shorter];
    //const res = [];
    //for (let i = 0; i <= k; i++) {
    //    res.push(i * longer + (k - i) * shorter); // ��Ŀ����Ӷ̵������У��Ǿʹ�0��longer��ʼ��
    //}

//}
//
//vector<int> divingBoard(int shorter, int longer, int k)
//{
//}
void test_divingBoard() {
    int shorter = 1;
    int longer = 2;
    int k = 3;
    set<int> setOut;
    for (int i = 0; i <= k; i++) {
        setOut.insert(shorter*i + longer*(k - i));
    }
    vector<int> res;
    for (auto itr : setOut) {
        res.push_back(itr);
        cout << itr << endl;
    }
}