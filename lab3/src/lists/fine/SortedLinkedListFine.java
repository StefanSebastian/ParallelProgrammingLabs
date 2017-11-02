package lists.fine;

import lists.IIterator;
import lists.SortedLinkedList;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by Sebi on 02-Nov-17.
 */
public class SortedLinkedListFine implements SortedLinkedList {
    private Node dummyStart;
    private Node start;

    public SortedLinkedListFine(){
        dummyStart = new Node();
    }

    @Override
    public void insert(double a) {
        dummyStart.getLock().lock();

        // empty list
        if (start == null){
            start = new Node(a);
            dummyStart.setNext(start);
            dummyStart.getLock().unlock();
            return;
        }

        // before first
        if (a <= start.getValue()){
            Node element = new Node(a);
            dummyStart.setNext(element);
            element.setNext(start);
            start.setPrev(element);
            start = element;
            dummyStart.getLock().unlock();
            return;
        }

        Node prev = dummyStart;
        Node curr = start;

        curr.getLock().lock();
        while (curr != null && a > curr.getValue()){
            prev.getLock().unlock();
            prev = curr;
            curr = curr.getNext();
            if (curr != null) {
                curr.getLock().lock();
            }
        }

        Node element = new Node(a);

        // last element
        if (curr == null){
            prev.setNext(element);
            element.setPrev(prev);
            prev.getLock().unlock();
            return;
        }

        // intermediary
        prev.setNext(element);
        element.setPrev(prev);
        element.setNext(curr);
        curr.setPrev(element);

        prev.getLock().unlock();
        curr.getLock().unlock();
    }

    @Override
    public void delete(double a) {

    }

    @Override
    public IIterator getIterator() {
        return new Iterator(start);
    }

    public class Node {
        private double value;
        private Node next;
        private Node prev;
        private Lock lock;

        public Node(){
            lock = new ReentrantLock();
        }

        public Node(double value, Node next, Node prev, Lock lock) {
            this.value = value;
            this.next = next;
            this.prev = prev;
            this.lock = lock;
        }

        public Node(double value) {
            this.value = value;
            this.next = null;
            this.prev = null;
            this.lock = new ReentrantLock();
        }

        public double getValue() {
            return value;
        }

        public void setValue(double value) {
            this.value = value;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node next) {
            this.next = next;
        }

        public Node getPrev() {
            return prev;
        }

        public void setPrev(Node prev) {
            this.prev = prev;
        }

        public Lock getLock() {
            return lock;
        }

        public void setLock(Lock lock) {
            this.lock = lock;
        }
    }

    public class Iterator implements IIterator {
        private Node node;

        public Iterator(Node node){
            this.node = node;
        }

        @Override
        public void getNext() {
            node = node.getNext();
        }

        @Override
        public double getElement() {
            return node.getValue();
        }

        @Override
        public boolean isValid() {
            return node != null;
        }
    }
}
