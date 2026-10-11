class BusBooking {
public:
    vector<vector<int>> v;
    int time = 0; 
    int mint = 0; 
    BusBooking(int n) : v(n, vector<int>(4, 0)) {
        
    }
    
    void toggle(string seat) {
        int seatno = seat[0] - 'A'; // seat = 0, 1, 2, 3
        int row = stoi(seat.substr(1)); // row = 1, 20, etc. 

        if (v[row-1][seatno]) {
            time -= v[row-1][seatno]; 
            v[row-1][seatno] = 0; 
            mint--; 
        } 
        
        else if (seatno == 1 || seatno == 2) {
            v[row-1][seatno] = 1; 
            time++; 
            mint++; 
        }
        
        else {
            v[row-1][seatno] = 1; 
            time++; 
            if (seatno == 0 && v[row-1][1]) { time += 2; v[row-1][seatno] += 2; }
            if (seatno == 3 && v[row-1][2]) { time += 2; v[row-1][seatno] += 2; } 
            mint++; 
        }
    }
    
    int getTotalTime() {
        return time; 
    }
    
    int getMinTime() {
        return mint; 
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
