class MyCircularDeque {
    private Deque<Integer> dq;
    int maxSize;
    
    public MyCircularDeque(int k) {
        dq = new ArrayDeque<>();
        maxSize = k;
    }

    public boolean insertFront(int value) {
        if(!isFull()) {
            dq.addFirst(value);
            return true;
        }
        return false;
    }

    public boolean insertLast(int value) {
        if(!isFull()) {
            dq.addLast(value);
            return true;
        }
        return false;
    }

    public boolean deleteFront() {
        if(!isEmpty()) {
            dq.removeFirst();
            return true;
        }
        return false;
    }

    public boolean deleteLast() {
        if(!isEmpty()) {
            dq.removeLast();
            return true;
        }
        return false;
    }

    public int getFront() {
        if(!isEmpty()) return dq.getFirst();
        return -1;
    }

    public int getRear() {
        if(!isEmpty()) return dq.getLast();
        return -1;
    }

    public boolean isEmpty() {
        return dq.isEmpty();
    }

    public boolean isFull() {
        return dq.size() == maxSize;
    }
}