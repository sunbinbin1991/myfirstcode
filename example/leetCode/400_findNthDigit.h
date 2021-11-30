int findNthDigit(int n) {
    int carry = 1;
    long base = 0;
    long currNum = 0;
    while (currNum < n) {
        base = pow(10,  carry - 1);
        currNum += 9 * (carry) * base;
        carry++;
    }
    long remain = n - currNum + 9 * (carry - 1) * base;
    int perNum = carry - 1;
    if(perNum == 1) {
        return base + remain - 1;
    }
    if(remain % perNum == 0){
         int index = remain / perNum;
         int findNum = base + index - 1;
         return findNum % 10;
    }else{
          int index = remain / perNum;
          int findNum = base + index;
          int pos = (remain - index * perNum) % perNum;
          if(pos != perNum){
              return findNum / ((int)pow(10, perNum - pos)) % 10;
          }else{
              return findNum / ((int)pow(10, pos)) % 10;
          }
    }
}
