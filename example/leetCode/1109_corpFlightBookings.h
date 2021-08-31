    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int bookingsNums = bookings.size(); // 预定记录数
        vector<int> answer(n);  
        vector<int> bookingDev(n + 1);

        for (int i = 0; i < bookings.size(); ++i) {
            int firsti = bookings[i][0] - 1;
            int lasti = bookings[i][1] - 1;
            int seatsi = bookings[i][2];
            bookingDev[firsti] += seatsi;
            bookingDev[lasti + 1] -= seatsi;
        }

        answer[0] = bookingDev[0];
        for(int j = 1; j < n; j++){
            answer[j] = answer[j - 1] + bookingDev[j];
        }

        return answer;
    }
