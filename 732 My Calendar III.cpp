/*
https://leetcode.com/problems/my-calendar-iii
732. My Calendar III

A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

You are given some events [start, end), after each given event, return an integer k representing the maximum k-booking between all the previous events.

Implement the MyCalendarThree class:

MyCalendarThree() Initializes the object.
int book(int start, int end) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.
 
*/

class MyCalendarThree {
public:
    
    map<int,int> m;
    int maxSum=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum = 0;
        for(auto i : m){
            sum+=i.second;
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
