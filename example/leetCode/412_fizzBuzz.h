class Solution412 {
public:
    vector<string> fizzBuzz(int n) {
        if(n < 1) return {};
        vector<string> res;
        int index = 1;
        while(index <= n){
            if(index % 3 == 0 && index % 5 == 0){
                res.push_back("FizzBuzz");
                index++;
                continue;
            }
            if(index % 3 == 0){
                res.push_back("Fizz");
            } else if (index % 5 == 0){
                res.push_back("Buzz");
            }else{
                res.push_back(std::to_string(index));
            }
            index++;
        }
        return res;
    }
};
