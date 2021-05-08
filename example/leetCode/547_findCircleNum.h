#pragma once
#include <vector>
using namespace std;

//�������������˼·�Ǻ�ֱ�۵ġ��������г��У�����ÿ�����У�����ó�����δ�����ʹ���
//��Ӹó��п�ʼ�������������ͨ������ \textit{ isConnected }isConnected 
//�õ���ó���ֱ�������ĳ�������Щ����Щ���к͸ó�������ͬһ����ͨ������Ȼ�����Щ
//���м����������������ֱ��ͬһ����ͨ���������г��ж������ʵ������ɵõ�һ��ʡ�ݡ�
//������ȫ�������Ժ󣬼��ɵõ���ͨ��������������ʡ�ݵ�������

void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int privince, int i) {
    for (int j = 0; j < privince; j++) {
        if (!visited[j] && isConnected[i][j]) {
            visited[j] = true;
            dfs(isConnected, visited, privince, j); // ���Ϊʲôд������ �����?
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected)
{
    if (isConnected.empty()) return 0;

    int privinces = isConnected.size();
    vector<bool> visited(privinces);
    int circleNum = 0;
    for (size_t i = 0; i < privinces; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, privinces, i);
            circleNum++;
        }
    }
}