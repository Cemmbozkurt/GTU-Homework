import java.util.NoSuchElementException;

public interface MyQueue<E> extends MyCollection<E>
{
    public boolean add(E e);
    public boolean addAll(MyCollection<E> e);
    public void clear();
    public boolean contains(E e);
    public boolean containsAll(MyCollection<E> e);
    public boolean isEmpty();
    public boolean remove(E e);
    public boolean removeAll(MyCollection<E> e);
    public boolean retainAll(MyCollection<E> e);
    public int size();

    public E element();
    public void offer(E e);
    public void poll()throws NoSuchElementException;


}
