import java.util.Iterator;

public interface MyCollection<E>
{
    public Iterator<E> iterator();
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

}
