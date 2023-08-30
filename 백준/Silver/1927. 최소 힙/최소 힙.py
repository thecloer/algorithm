import sys
input = sys.stdin.readline

class Heap:
    def __init__(self, maxSize):
        self.buckets = [0] * (maxSize + 1)
        self.HEAD = 1
        self.size = 0
    
    def parent(self, pos):
        return pos // 2
    def leftChild(self, pos):
        return pos * 2
    def isFirstSmaller(self, first, second):
        return self.buckets[first] < self.buckets[second]
    def swap(self, pos1, pos2):
        self.buckets[pos1], self.buckets[pos2] = self.buckets[pos2], self.buckets[pos1]
        
    def heapify(self, node):
        left = self.leftChild(node)
        if left > self.size: # node는 leaf
            return
        right = left + 1
        
        smallerChild = left
        if right <= self.size and self.isFirstSmaller(right, left):
            smallerChild = right
        
        if self.isFirstSmaller(smallerChild, node):
            self.swap(smallerChild, node)
            self.heapify(smallerChild)
    
    def add(self, element):
        self.size += 1
        self.buckets[self.size] = element
        
        current = self.size
        parent = self.parent(current)
        while self.isFirstSmaller(current, parent):
            self.swap(current, parent)
            current = parent
            parent = self.parent(current)
    
    def pop(self):
        popped = self.buckets[self.HEAD]
        self.buckets[self.HEAD] = self.buckets[self.size]
        self.size -= 1
        self.heapify(self.HEAD)
        return popped

def main():
    N = int(input())
    heap = Heap(N)
    for _ in range(N):
        n = int(input())
        if n:
            heap.add(n)
        elif heap.size == 0:
            print(0)
        else:
            print(heap.pop())
    
if __name__ == "__main__":
    main()