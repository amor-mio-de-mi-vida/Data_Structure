#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    int heapSize;
    int realSize;

public:
    MaxHeap(int size):heapSize(size),realSize(0),heap(size+1){heap[0]=0;};
    int peek() {
        return heap[1];
    }
    int size() {
        return realSize;
    }
    void add(int elem) {
        realSize++;
        if (realSize > heapSize) {
            cout << "elems exceeded" << endl;
            realSize--;
            return;
        }
        heap[realSize]=elem;
        int elemID=realSize;
        int parentID=elemID/2;
        while(heap[elemID]>heap[parentID] && elemID > 1) {
            int temp = heap[elemID];
            heap[elemID]=heap[parentID];
            heap[parentID]=temp;
            elemID=parentID;
            parentID=elemID/2;
        }
    }

    int pop() {
        if (realSize < 1) {
            cout << "elems emptied" << endl;
            return INT32_MIN;
        } else {
            int heapTop=heap[1];
            heap[1]=heap[realSize];
            realSize--;
            int elemID=1;
            while (elemID < realSize && elemID<=realSize/2) {
                int left = elemID * 2;
                int right = (elemID * 2) + 1;
                if (heap[elemID] < heap[left] || heap[elemID] < heap[right]) {
                    if (heap[left] > heap[right]) {
                        int temp = heap[left];
                        heap[left] = heap[elemID];
                        heap[elemID] = temp;
                        elemID = left;
                    } else {
                        int temp = heap[right];
                        heap[right] = heap[elemID];
                        heap[elemID] = temp;
                        elemID = right;
                    }
                } else { break; }
            } 
            return heapTop;
        } 
    }

    string toStr(){
        string fin;
        stringstream tempss;
        copy(heap.begin()+1,heap.end(),ostream_iterator<int>(tempss,""));
        fin=tempss.str();
        return fin;
    }
};   