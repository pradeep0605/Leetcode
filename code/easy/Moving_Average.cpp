// int circ_buff[100000] = {0};

class MovingAverage {
public:
    int index;

    int sum;
    int size;
    int curr_size;
    int *circ_buff;
    
    /** Initialize your data structure here. */
    MovingAverage(int sz) {
        // cout << sz << endl;
        index = -1;
        sum = curr_size = 0;
        
        circ_buff = new int[sz + 1]();    
        size = sz;
    }
    
    double next(int val) {
        index = (index + 1) % size;
        if (curr_size < size) curr_size ++;
        
        sum += val - circ_buff[index];
        // cout << sum << endl;
        circ_buff[index] = val;
        
        return double(sum) / curr_size;
    }
};  

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */