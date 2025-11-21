class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (maxheap.empty()) {
            maxheap.push(num);
            return;
        }

        if (num >= maxheap.top()) {
            minheap.push(num);    
            if (minheap.size() > maxheap.size()) {
                int node = minheap.top();
                minheap.pop();
                maxheap.push(node);
            }
        } else {
            maxheap.push(num);
            if (maxheap.size() > minheap.size() + 1) {
                int node = maxheap.top();
                maxheap.pop();
                minheap.push(node);
            }
        }
    }
    
    double findMedian() {
        if (maxheap.size() == minheap.size())
            return (maxheap.top() + minheap.top())/2.0;
        else
            return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */