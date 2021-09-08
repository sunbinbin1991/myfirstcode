  static bool SortByProfit(ProjInfo a, ProjInfo b){
        return a.profit > b.profit || a.profit == b.profit && a.cost < b.cost;
    }

    static bool SortByCost(ProjInfo a, ProjInfo b){
        return a.cost < b.cost || (a.cost == b.cost && a.profit > b.profit);
    }

    static void printPj(vector<ProjInfo>& vProj){
        if(vProj.empty()) return;
        for (int i = 0; i < vProj.size(); ++i) {
            printf("id:%d pro:%d, cost: %d\n",
                    vProj[i].index, vProj[i].profit, vProj[i].cost);
        }
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<ProjInfo> vProj;
        for (int i = 0; i < n; ++i) {
            ProjInfo temp{i, profits[i], capital[i]};
            vProj.push_back(temp);
        }
        sort(vProj.begin(),vProj.end(), SortByCost);
        // printPj(vProj);
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int j = 0; j < k; ++j) {
            while (curr < n && vProj[curr].cost <= w){
                pq.push(vProj[curr].profit);
                curr++;
            }
            // cout <<" === a " << (curr < n) << endl;
            // cout <<" === b " << vProj[curr].cost << endl;
            // cout <<" === c " << w << endl;
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }
        return w;
    }
