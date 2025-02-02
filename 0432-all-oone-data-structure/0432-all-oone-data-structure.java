class AllOne {
    private static class Node {
        int freq;
        LinkedHashSet<String> keys;
        Node prev, next;

        Node(int freq) {
            this.freq = freq;
            this.keys = new LinkedHashSet<>();
        }
    }

    private final Map<String, Node> keyToNode;
    private final Map<Integer, Node> freqToNode;
    private final Node head, tail;

    public AllOne() {
        keyToNode = new HashMap<>();
        freqToNode = new HashMap<>();
        
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
    }

    private void insertAfter(Node prevNode, Node newNode) {
        newNode.prev = prevNode;
        newNode.next = prevNode.next;
        prevNode.next.prev = newNode;
        prevNode.next = newNode;
    }

    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        freqToNode.remove(node.freq);
    }

    public void inc(String key) {
        Node curNode = keyToNode.getOrDefault(key, head);
        int newFreq = curNode.freq + 1;
        
        Node newNode = freqToNode.get(newFreq);
        if (newNode == null) {
            newNode = new Node(newFreq);
            freqToNode.put(newFreq, newNode);
            insertAfter(curNode, newNode);
        }

        newNode.keys.add(key);
        keyToNode.put(key, newNode);

        if (curNode != head) {
            curNode.keys.remove(key);
            if (curNode.keys.isEmpty()) remove(curNode);
        }
    }

    public void dec(String key) {
        if (!keyToNode.containsKey(key)) return;

        Node curNode = keyToNode.get(key);
        int newFreq = curNode.freq - 1;

        keyToNode.remove(key);
        curNode.keys.remove(key);

        if (newFreq > 0) {
            Node newNode = freqToNode.get(newFreq);
            if (newNode == null) {
                newNode = new Node(newFreq);
                freqToNode.put(newFreq, newNode);
                insertAfter(curNode.prev, newNode);
            }
            newNode.keys.add(key);
            keyToNode.put(key, newNode);
        }
        
        if (curNode.keys.isEmpty()) remove(curNode);
    }

    public String getMaxKey() {
        return tail.prev == head ? "" : tail.prev.keys.iterator().next();
    }

    public String getMinKey() {
        return head.next == tail ? "" : head.next.keys.iterator().next();
    }
}


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */