/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
    // (1) stack of minimum pairs  space:O(N)
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val,val});
        } else {
            int min_val = min(val,st.top().second);
            st.push({val,min_val});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
    
    // (2) two stacks
// public:
//     stack<int> st;
//     stack<int> min_st;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         st.push(val);
//         if (min_st.empty() || min_st.top() >= val ) {
//             min_st.push(val);
//         }
//     }
    
//     void pop() {
//         if (st.top() == min_st.top()) {
//             min_st.pop();
//         }
//         st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return min_st.top();
//     }   
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

