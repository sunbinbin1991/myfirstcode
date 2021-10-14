    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        vector<long> prefixChalk(chalk.size());
        prefixChalk[0] = chalk[0];
        for (int i = 1; i < chalk.size(); i++){
            prefixChalk[i] = prefixChalk[i-1] + chalk[i];
        }
        k = k % prefixChalk.back();
        while (k > 0) {
            k -= chalk[i % chalk.size()];
            if (k < 0) {
                return i % chalk.size();
            }
            i++;
        }
        return i % chalk.size();
    }
