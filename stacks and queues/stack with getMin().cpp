#include <bits/stdc++.h>

class SpecialStack {
    // Define the data members.
	vector <int> v;
    int minn, size;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    SpecialStack() {
        minn = INT_MAX;
        size = 0;
    }
     
    void push(int data) {
        // Implement the push() function.
        if (data < minn) minn = data;
        size++;
        v.push_back(data);
    }

    int pop() {
        // Implement the pop() function.
        if (size <= 0) return -1;
        size--;
        int rv = v[size];
        v.pop_back();
        if (rv == minn) {
            minn = INT_MAX;
            for (int i: v) 
                if (minn > i) minn = i;
        }
        return rv;
    }

    int top() {
        // Implement the top() function.
        return v[size-1];
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return size == 0;
    }

    int getMin() {
        // Implement the getMin() function.
        return minn==INT_MAX ? -1 : minn;
    }  
};
