#pragma once
vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    if (words.empty()) return{};
    vector<string> ans;
    vector<vector<string>> whole;
    vector<string> parts;
    int spaceNum = 0;
    int strNum = 0;
    printf("0 \n");
    for (int i = 0; i < words.size(); ++i) {
        // µ±Ç°ÊÇ·ñÎª¿Õ
        if (parts.empty()) {
            parts.push_back(words[i]);
            spaceNum += 1;
            strNum += words[i].size();
        } else {
            if (!parts.empty() && (strNum + spaceNum + words[i].size() <= maxWidth)) {
                parts.push_back(words[i]);
                spaceNum += 1;
                strNum += words[i].size();
            } else {
                whole.push_back(parts);
                parts = {};
                parts.push_back(words[i]);
                spaceNum = 1;
                strNum = words[i].size();
            }
        }
    }
    if (!parts.empty()) {
        whole.push_back(parts);
    }
    printf("1 \n");

    for (int j = 0; j < whole.size(); ++j) {
        if (j < whole.size() - 1) {
            string single = "";
            int strNum = 0;
            for (int i = 0; i < whole[j].size(); ++i) {
                strNum += whole[j][i].size();
            }
            int avgZero, remainZero, temp;
            if (whole[j].size() != 1) {
                avgZero = (maxWidth - strNum) / (whole[j].size() - 1);
                if ((maxWidth - strNum) % (whole[j].size() - 1) == 0) {
                    remainZero = 0;
                } else {
                    avgZero += 1;
                    remainZero = maxWidth - strNum - avgZero * (whole[j].size() - 2);
                }
            } else {
                avgZero = 0;
                remainZero = maxWidth - strNum;
            };

            printf("2 remainZero %d avgZero \n", remainZero, avgZero);
            for (int k = 0; k < whole[j].size() - 1; ++k) {
                if ((k == whole[j].size() - 2 && (maxWidth - strNum) % (whole[j].size() - 1) != 0)) {
                    single += whole[j][k];
                    if (avgZero == 1) {
                        single += " ";
                    }
                    continue;
                }
                temp = avgZero;
                single += whole[j][k];
                while (temp-- > 0) {
                    single += " ";
                }
            }
            printf("3 \n");
            if (!single.empty()) {
                while (remainZero-- > 0) {
                    single += " ";
                }
                single += whole[j].back();
            } else {
                single += whole[j].back();
                while (remainZero-- > 0) {
                    single += " ";
                }
            }
            ans.push_back(single);
        } else {
            printf("4 \n");
            string single = "";
            int strNum = 0;
            for (int k = 0; k < whole[j].size(); ++k) {
                if (k < whole[j].size() - 1) {
                    single += whole[j][k];
                    single += " ";
                } else {
                    single += whole[j][k];
                }
                strNum += whole[j][k].size();
            }
            printf("5 \n");
            int remainZero = maxWidth - single.size();
            while (remainZero--) {
                single += " ";
            }
            ans.push_back(single);
        }
    }
    return ans;
}


vector<int> avgNum(int sum, int splits){
    vector<int> ans;
    if(splits == 0){
        ans.push_back(sum);
        return ans;
    }
    if(sum % splits == 0) {
        for (int i = 0; i < splits; ++i) {
            ans.push_back(sum / splits);
            cout << (sum/splits) << endl;
        }
    } else {
        int base = sum / splits;
        for (int i = 0; i < splits; ++i) {
            ans.push_back(base);
        }
        int start = 0;
        int rm0 = sum - base * splits;
        while (rm0-- > 0 && start < splits){
            ans[start++] += 1;
        }
    }
    return ans;
}

vector<string> fullJustify2(vector<string>& words, int maxWidth) {
    if (words.empty()) return {};
    vector<string> ans;
    vector<vector<string>> whole;
    vector<string> parts;
    int spaceNum = 0;
    int strNum = 0;
    for (int i = 0; i < words.size(); ++i) {
        // 当前是否为空
        if (parts.empty()) {
            parts.push_back(words[i]);
            spaceNum += 1;
            strNum += words[i].size();
        } else {
            if (!parts.empty() && (strNum + spaceNum + words[i].size() <= maxWidth)) {
                parts.push_back(words[i]);
                spaceNum += 1;
                strNum += words[i].size();
            } else {
                whole.push_back(parts);
                parts = {};
                parts.push_back(words[i]);
                spaceNum = 1;
                strNum = words[i].size();
            }
        }
    }
    if(!parts.empty()){
        whole.push_back(parts);
    }

    for (int j = 0; j < whole.size(); ++j) {
        if (j < whole.size() - 1) {
            string single = "";
            int strNum = 0;
            for (int i = 0; i < whole[j].size(); ++i) {
                strNum += whole[j][i].size();
            }
            int temp;
            auto zeros = avgNum(maxWidth - strNum, (whole[j].size() - 1));
            for (int k = 0; k < whole[j].size(); ++k) {
                if(k == whole[j].size() - 1){
                    single += whole[j][k];
                    continue;
                }
                temp = zeros[k];
                single += whole[j][k];
                while (temp-- > 0) {
                    single += " ";
                }
            }
            ans.push_back(single);
        } else {
            printf("4 \n");
            string single = "";
            int strNum = 0;
            for (int k = 0; k < whole[j].size(); ++k) {
                if(k < whole[j].size() - 1){
                    single += whole[j][k];
                    single += " ";
                } else {
                    single += whole[j][k];
                }
                strNum +=  whole[j][k].size();
            }
            printf("5 \n");
            int remainZero = maxWidth - single.size();
            while (remainZero--) {
                single += " ";
            }
            ans.push_back(single);
        }
    }
    return ans;
}

