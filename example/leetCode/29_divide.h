#pragma once
#include <stdio.h>
#include <limits.h>
int div(long a, long b)
{  // �ƺ�������ѵ�����������⼸��
    if (a<b) return 0;
    long count = 1;
    long tb = b; // �ں���Ĵ����в�����b
    while ((tb + tb) <= a) {
        count = count + count; // ��С�ⷭ��
        tb = tb + tb; // ��ǰ���Ե�ֵҲ����
    }
    return count + div(a - tb, b);
}

int divide(int dividend, int divisor)
{
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if (dividend > INT_MIN) return -dividend;// ֻҪ������С���Ǹ�����������ֱ�ӷ����෴���ͺ���
        return INT_MAX;// ����С���Ǹ����Ǿͷ�������������
    }
    long a = dividend;
    long b = divisor;
    int sign = 1;
    if ((a > 0 && b < 0) || (a < 0 && b>0)) {
        sign = -1;
    }
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    long res = div(a, b);
    if (sign > 0)return res > INT_MAX ? INT_MAX : res;
    return -res;
}
