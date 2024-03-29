class Solution {
    PriorityQueue<ListNode> list = new PriorityQueue<>((a,b) -> a.val - b.val);
    public ListNode mergeKLists(ListNode[] lists) {
        // Will not activate null/empty lists, <3 Java
        for(ListNode ls: lists) {
            while(ls != null) {
                list.offer(ls);
                ls = ls.next;
            }
        }
        var head = list.poll();
        var temp = head;
        while(list.peek() != null) {
            temp.next = list.poll();
            temp = temp.next;
        }
        if (head != null)
            temp.next = null;
        return head;
    }
}