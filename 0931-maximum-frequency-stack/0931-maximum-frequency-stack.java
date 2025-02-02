class FreqStack {
    class Node 
    {
        int val;
        Node next;
        Node(int val) {
            this.val = val;
            this.next = null;
        }
    }

    Map<Integer, Node> store;
    Map<Integer, Integer> count;
    Integer mxCount;
    public FreqStack() {
        store = new HashMap<>();
        count = new HashMap<>();
        mxCount = 0;
    }

    public void push(int val)
    {
        int cnt = count.getOrDefault(val, 0);
        Node head = store.getOrDefault(cnt+1, null);
        
        if(head == null) {
            store.put(cnt+1, new Node(val));
        }
        else {
            Node newNode = new Node(val);
            newNode.next = head;
            head = newNode;

            store.put(cnt+1, head);
        }
        count.put(val, cnt+1);
        mxCount = Math.max(mxCount, cnt+1);
    }

    public int pop() {
        Node head = store.get(mxCount);
        int topElement = head.val;
        
        Node curr = head;
        while(curr != null) {
            curr = curr.next;
        } 

        if(head.next != null) {
            Node nxt = head.next;
            head.next = null;

            head = nxt;
            store.put(mxCount, head);
        }
        else {
            store.remove(mxCount);
            mxCount--;
        }

        int cnt = count.get(topElement);
        if(cnt == 1) {
            count.remove(topElement);
        }
        else count.put(topElement, cnt - 1);
        return topElement;
    }
}

/*



*/