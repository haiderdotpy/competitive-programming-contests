# Write Up 

## Approach

**Toggle**: 
1. Convert seat number to indices. 
2. Check if seat is already assigned, if it's true free the seat. 
3. Otherwise, if it's a middle seat, simply 1 second is consumed. 
4. If it's a window seat, we check if adjacent middle seat is occupied. If true, 3 seconds are consumed, 1 otherwise. 
5. Total time is tracked while the seats are being toggled. 
6. Minimum time is found by iterating over all occupied seast, counting windows and middle seats and adding them up. 

## Contest Solution

```cpp 
class BusBooking {
public:
    vector<vector<int>> v;
    int time = 0; 
    BusBooking(int n) : v(n, vector<int>(4, 0)) {
        
    }
    
    void toggle(string seat) {
        int seatno = seat[0] - 'A'; // seat = 0, 1, 2, 3
        int row = stoi(seat.substr(1)); // row = 1, 20, etc. 

        if (v[row-1][seatno]) {
            time -= v[row-1][seatno]; 
            v[row-1][seatno] = 0; 
        } 
        
        else if (seatno == 1 || seatno == 2) {
            v[row-1][seatno] = 1; 
            time++; 
        }
        
        else {
            v[row-1][seatno] = 1; 
            time++; 
            if (seatno == 0 && v[row-1][1]) { time += 2; v[row-1][seatno] += 2; }
            if (seatno == 3 && v[row-1][2]) { time += 2; v[row-1][seatno] += 2; } 
        }
    }
    
    int getTotalTime() {
        return time; 
    }
    
    int getMinTime() {
        int window = 0, middle = 0; 
        
        for (int i=0; i<v.size(); i++) {
            if (v[i][0]) window++; 
            if (v[i][1]) middle++; 
            if (v[i][2]) middle++; 
            if (v[i][3]) window++; 
        }

        return window + middle; 
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
```

Verdict: TLE 

## Upsolved Solution

Added a variable to track minimum time. The minimum time is simply the number of occupied seats (achieved by seating all window seats first, and then middle seats). This was done using a full vector scan per query in the contest solution, resulting in TLE. 

```cpp 
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
```
