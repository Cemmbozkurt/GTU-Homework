import java.util.Arrays;
import java.util.Iterator;


public class MyArraylist<E> implements MyList<E>
{
    private int capacity = 0;
    private E [] data;
    private int size = 0;
    private static final int initial_capacity = 10;

    public MyArraylist()
    {
        capacity = initial_capacity;
        data = (E[]) new Object[capacity];
    }

    private void reallocate()
    {
        capacity = capacity + 10;
        data = Arrays.copyOf(data, capacity);
    }
    @Override
    public boolean add(E e)
    {
        if(size == capacity)
        {
            reallocate();
        }
        data[size] = e;
        size++;
        return true;
    }

    public Iterator iterator()
    {
        return new MyIterator();
    }

    @Override
    public void clear()
    {
        size = 0;
        capacity = 0;
        data = null;
    }

    @Override
    public boolean contains(E e)
    {
        Iterator<E> iter = this.iterator();

        while(iter.hasNext())
        {
            if (iter.next().equals(e))
            {
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean isEmpty()
    {
        if(size == 0)
            return true;
        else
            return  false;
    }

    @Override
    public int size()
    {
        return size;
    }

    @Override
    public boolean remove(E e)
    {
        if(!this.contains(e) || size == 0)
            return false;
        int i,indexs=0;


        for(i=0; i < size; ++i)
        {
            if(data[i].equals(e))
            {
                indexs = i;
            }
        }

        for(i = indexs; i < size; ++i)
        {
            data[i] = data[i+1];
        }
        size--;
        return true;
    }

    @Override
    public boolean addAll(MyCollection<E> c)
    {
        if (c.isEmpty())
            return false;

        Iterator<E> iter = c.iterator();
        while (iter.hasNext())
        {
            this.add(iter.next());
        }
        return true;
    }

    @Override
    public boolean containsAll(MyCollection<E> c)
    {
        if(this.size() < c.size())
        {
            return  false;
        }

        Iterator<E> iter = c.iterator();
        while(iter.hasNext())
        {
            if(!this.contains(iter.next()))
            {
                return  false;
            }
        }
        return  true;
    }

    @Override
    public boolean removeAll(MyCollection<E> c)
    {
        if(c.isEmpty() || this.isEmpty())
            return false;


        Iterator<E> iter = c.iterator();
        while (iter.hasNext()){
            E e = iter.next();
            if(this.contains(e)){
                this.remove(e);
            }

        }

        return true;
    }

    @Override
    public boolean retainAll(MyCollection<E> c)
    {
        if (c.isEmpty())
            return false;

        Iterator<E> iter = this.iterator();

        while (iter.hasNext())
        {
            if (!c.contains(iter.next()))
            {
                iter.remove();
            }
        }
    return true;
    }



   @Override
   public String toString() {
       return Arrays.toString(data);
   }


    private class MyIterator<E> implements Iterator<E>
    {
        int position = 0;
        int lastPosition= -1;

        @Override
        public boolean hasNext() {

            if(position < size)
                return true;
            else
                return false;
        }

        @Override
        public E next() {
            lastPosition = position;
            position++;
            return (E) data[lastPosition];
        }

        @Override
        public void remove()
        {
            if(lastPosition < 0)
            {
                throw new UnsupportedOperationException("!Something went wrong!");
            }
            MyArraylist.this.remove(data[lastPosition]);
            position = lastPosition;
            lastPosition = -1;
            
        }

    }


}
