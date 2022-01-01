import java.util.*;

public class Main {

 public static void main(String[] args) {
  /*ARRAY LIST FOR INTEGER*/
  MyArraylist<Integer> arrlist1 = new MyArraylist<Integer>();
  MyArraylist<Integer> arrlist2 = new MyArraylist<Integer>();
  MyArraylist<Integer> arrlist3 = new MyArraylist<Integer>();
  MyArraylist<Integer> arrlist4 = new MyArraylist<Integer>();

  arrlist1.add(20);
  arrlist1.add(30);
  arrlist1.add(40);
  arrlist1.add(50);
  arrlist1.add(60);
  arrlist1.add(20);
  arrlist1.add(30);
  arrlist1.add(40);
  arrlist1.add(50);
  arrlist1.add(60);
  arrlist1.add(20);
  arrlist1.add(30);
  arrlist1.add(40);
  arrlist1.add(50);
  arrlist1.add(60);
  arrlist1.add(60);
  arrlist1.add(20);
  arrlist1.add(30);
  arrlist1.add(40);

  System.out.println("\nAfter addAll() function:\n");
  arrlist2.addAll(arrlist1);

  if(arrlist1.containsAll(arrlist2))
    System.out.println("Arraylist2 contains all elements of Arraylis1");
  else
   System.out.println("Arraylist2 does NOT contains all elements of Arraylis1!");

  System.out.println("1.ARRAYLIST: " + arrlist1);
  System.out.printf("1.ARRAYLIST SIZE: %d\n",arrlist1.size());
  System.out.println("2.ARRAYLIST: " + arrlist2);
  System.out.printf("2.ARRAYLIST SIZE: %d\n",arrlist1.size());

  System.out.println("\n================================================\n");

  arrlist3.add(10);
  arrlist3.add(20);
  arrlist3.add(30);
  arrlist3.add(40);
  arrlist3.add(50);

  arrlist4.add(79);
  arrlist4.add(89);
  arrlist4.add(99);
  arrlist4.add(10);
  arrlist4.add(20);

  System.out.println("3.ARRAYLIST: " + arrlist3);
  System.out.printf("3.ARRAYLIST SIZE: %d\n",arrlist3.size());
  System.out.println("4.ARRAYLIST: " + arrlist4);
  System.out.printf("4.ARRAYLIST SIZE: %d\n",arrlist4.size());

  System.out.println("\nAfter removeAll() function:\n");
  arrlist4.removeAll(arrlist3);
  System.out.println("3.ARRAYLIST: " + arrlist3);
  System.out.printf("3.ARRAYLIST SIZE: %d\n",arrlist3.size());
  System.out.println("4.ARRAYLIST: " + arrlist4);
  System.out.printf("4.ARRAYLIST SIZE: %d\n",arrlist4.size());

  System.out.println("\n================================================\n");

  arrlist4.add(30);
  arrlist4.add(40);
  arrlist4.add(50);

  System.out.println("3.ARRAYLIST: " + arrlist3);
  System.out.printf("3.ARRAYLIST SIZE: %d\n",arrlist3.size());
  System.out.println("4.ARRAYLIST: " + arrlist4);
  System.out.printf("4.ARRAYLIST SIZE: %d\n",arrlist4.size());

  arrlist3.retainAll(arrlist4);
  System.out.println("After retainAll()funtion: \n");
  System.out.println("3.ARRAYLIST: " + arrlist3);
  System.out.printf("3.ARRAYLIST SIZE: %d\n",arrlist3.size());
  System.out.println("4.ARRAYLIST: " + arrlist4);
  System.out.printf("4.ARRAYLIST SIZE: %d\n",arrlist4.size());

  arrlist3.clear();
  System.out.println("3.ARRAYLIST: " + arrlist3);
  System.out.printf("3.ARRAYLIST SIZE: %d\n",arrlist3.size());

  System.out.println("\n================================================\n");
  /*ARRAY LIST FOR STRING*/
  System.out.println("\n=====For Strings======\n");
  MyArraylist<String> arrlist5 = new MyArraylist<String>();
  MyArraylist<String> arrlist6 = new MyArraylist<String>();

  arrlist5.add("Atiba");
  arrlist5.add("Aboubakar");
  arrlist5.add("Larin");
  arrlist5.add("Mensah");
  arrlist5.add("Ljajic");
  arrlist5.add("Ridvan");
  arrlist5.add("Josef");

  arrlist6.addAll(arrlist5);
  System.out.println("After addAll()funtion: \n");
  System.out.println("5.ARRAYLIST: " + arrlist5);
  System.out.printf("5.ARRAYLIST SIZE: %d\n",arrlist5.size());
  System.out.println("6.ARRAYLIST: " + arrlist6);
  System.out.printf("6.ARRAYLIST SIZE: %d\n",arrlist6.size());

  if(arrlist5.containsAll(arrlist6))
   System.out.println("Arraylist5 contains all elements of Arraylis6");
  else
   System.out.println("Arraylist5 does NOT contains all elements of Arraylis6!");

  arrlist6.add("Vida");
  arrlist6.add("Rosier");

  arrlist6.removeAll(arrlist5);
  System.out.println("After removeAll()funtion: \n");
  System.out.println("5.ARRAYLIST: " + arrlist5);
  System.out.printf("5.ARRAYLIST SIZE: %d\n",arrlist5.size());
  System.out.println("6.ARRAYLIST: " + arrlist6);
  System.out.printf("6.ARRAYLIST SIZE: %d\n",arrlist6.size());

  arrlist6.add("Josef");
  arrlist6.add("Atiba");
  arrlist6.add("Cem");

  System.out.println("\nAfter retainAll() function:\n");
  arrlist6.retainAll(arrlist5);
  System.out.println("5.ARRAYLIST: " + arrlist5);
  System.out.printf("5.ARRAYLIST SIZE: %d\n",arrlist5.size());
  System.out.println("6.ARRAYLIST: " + arrlist6);
  System.out.printf("6.ARRAYLIST SIZE: %d\n",arrlist6.size());
  System.out.println("\n=====================================================\n");

  /*HASHSET FOR INTEGER*/
  System.out.println("\nHash Set:");
  MyHashset<Integer> hashset1 = new  MyHashset<Integer>();
  MyHashset<Integer> hashset2 = new  MyHashset<Integer>();

  hashset1.add(20);
  hashset1.add(30);
  hashset1.add(30);
  hashset1.add(30);
  hashset1.add(40);
  hashset1.add(50);
  hashset1.add(60);

  System.out.println("\nAfter addAll() function:\n");
  hashset2.addAll(hashset1);


  if(hashset1.containsAll(hashset2))
   System.out.println("hashset2 contains all elements of hashset1");
  else
   System.out.println("hashset2 does NOT contains all elements of hashset1!");

  System.out.println("1.hashset1: " + hashset1);
  System.out.printf("1.hashset1 SIZE: %d\n",hashset1.size());
  System.out.println("2.hashset2: " +  hashset2);
  System.out.printf("2.hashset2 SIZE: %d\n",hashset2.size());

  hashset2.add(80);
  hashset2.add(90);

  hashset2.removeAll(hashset1);
  System.out.println("\nAfter removeAll()funtion: ");
  System.out.println("1.hashset1: " + hashset1);
  System.out.printf("1.hashset1 SIZE: %d\n",hashset1.size());
  System.out.println("2.hashset2: " + hashset2);
  System.out.printf("2.hashset2 SIZE: %d\n",hashset2.size());

   hashset2.add(30);
   hashset2.add(40);


  hashset2.retainAll(hashset1);
  System.out.println("\nAfter retainAll()funtion: ");
  System.out.println("1.hashset1: " + hashset1);
  System.out.printf("1.hashset1 SIZE: %d\n",hashset1.size());
  System.out.println("2.hashset2: " + hashset2);
  System.out.printf("2.hashset2 SIZE: %d\n",hashset2.size());




  System.out.println("\n=====================================================\n");

  /*HASHSET FOR STRING*/
  System.out.println("\n=====For Strings======\n");
  MyHashset<String> hashset3 = new MyHashset<String>();
  MyHashset<String> hashset4 = new MyHashset<String>();

  hashset3.add("Atiba");
  hashset3.add("Aboubakar");
  hashset3.add("Larin");
  hashset3.add("Mensah");
  hashset3.add("Ljajic");
  hashset3.add("Ridvan");
  hashset3.add("Josef");
  hashset3.add("Josef");

  hashset4.addAll(hashset3);
  System.out.println("After addAll()funtion: \n");
  System.out.println("3.hashset3: " + hashset3);
  System.out.printf("3.hashset3 SIZE: %d\n",hashset3.size());
  System.out.println("4.hashset4: " + hashset4);
  System.out.printf("4.hashset4 SIZE: %d\n",hashset4.size());

  if(hashset3.containsAll(hashset4))
   System.out.println("hashset3 contains all elements of hashset4");
  else
   System.out.println("hashset3 does NOT contains all elements of hashset4!");

  hashset4.add("Vida");
  hashset4.add("Rosier");

  hashset4.removeAll(hashset3);
  System.out.println("\nAfter removeAll()funtion: ");
  System.out.println("3.hashset3: " + hashset3);
  System.out.printf("3.hashset3 SIZE: %d\n",hashset3.size());
  System.out.println("4.hashset4: " + hashset4);
  System.out.printf("4.hashset4 SIZE: %d\n",hashset4.size());

  hashset4.add("Josef");
  hashset4.add("Atiba");
  hashset4.add("Cem");

  System.out.println("\nAfter retainAll() function:\n");
  hashset4.retainAll(hashset3);
  System.out.println("3.hashset3: " + hashset3);
  System.out.printf("3.hashset3 SIZE: %d\n",hashset3.size());
  System.out.println("4.hashset4: " + hashset4);
  System.out.printf("4.hashset4 SIZE: %d\n",hashset4.size());
  System.out.println("\n=====================================================\n");

  /*LINKEDLIST FOR INTEGER*/
  MyLinkedlist<Integer> linkedList1 = new MyLinkedlist<Integer>();
  MyLinkedlist<Integer> linkedList2 = new MyLinkedlist<Integer>();

  linkedList1.add(20);
  linkedList1.add(30);
  linkedList1.add(30);
  linkedList1.add(30);
  linkedList1.add(40);
  linkedList1.add(50);
  linkedList1.add(60);

  System.out.println("\nAfter addAll() function:");
  linkedList2.addAll(linkedList1);


  if(linkedList1.containsAll(linkedList2))
   System.out.println("linkedList2 contains all elements of linkedList1");
  else
   System.out.println("linkedList2 does NOT contains all elements of linkedList1!");

  System.out.println("1.linkedList1: " + linkedList1);
  System.out.printf("1.linkedList1 SIZE: %d\n",linkedList1.size());
  System.out.println("2.linkedList2: " +  linkedList2);
  System.out.printf("2.linkedList2 SIZE: %d\n",linkedList2.size());

  linkedList2.add(80);
  linkedList2.add(90);

  linkedList2.removeAll(linkedList1);
  System.out.println("\nAfter removeAll()funtion: ");
  System.out.println("1.linkedList1: " + linkedList1);
  System.out.printf("1.linkedList1 SIZE: %d\n",linkedList1.size());
  System.out.println("2.linkedList2: " + linkedList2);
  System.out.printf("2.linkedList2 SIZE: %d\n",linkedList2.size());

  linkedList2.add(30);
  linkedList2.add(40);


  linkedList2.retainAll(linkedList1);
  System.out.println("\nAfter retainAll()funtion: ");
  System.out.println("1.linkedList1: " + linkedList1);
  System.out.printf("1.linkedList1 SIZE: %d\n",linkedList1.size());
  System.out.println("2.linkedList2: " + linkedList2);
  System.out.printf("2.linkedList2 SIZE: %d\n",linkedList2.size());

  System.out.println("Root element of linkedList1: "+linkedList1.element());
  linkedList1.offer(40);
  System.out.println("1.linkedList1 after use of offer function: " + linkedList1);

  linkedList1.clear();
  try{
     linkedList1.poll();
  }
  catch (Exception excpt)
  {
    System.out.println("Something went wrong: "+excpt.getMessage());
  }
  System.out.println("2.linkedList2: " + linkedList2);
  linkedList2.poll();
  System.out.println("poll() function:");
  System.out.println("2.linkedList2: " + linkedList2);
  System.out.println("\n=====================================================\n");
  /*LINKEDLIST FOR STRING*/
  MyLinkedlist<String> linkedList3 = new MyLinkedlist<String>();
  MyLinkedlist<String> linkedList4 = new MyLinkedlist<String>();

  linkedList3.add("Atiba");
  linkedList3.add("Aboubakar");
  linkedList3.add("Larin");
  linkedList3.add("Mensah");
  linkedList3.add("Ljajic");
  linkedList3.add("Ridvan");
  linkedList3.add("Josef");


  linkedList4.addAll(linkedList3);
  System.out.println("After addAll()funtion: \n");
  System.out.println("3.linkedList3: " + linkedList3);
  System.out.printf("3.linkedList3 SIZE: %d\n",linkedList3.size());
  System.out.println("4.linkedList4: " + linkedList4);
  System.out.printf("4.linkedList4 SIZE: %d\n",linkedList4.size());

  if(linkedList3.containsAll(linkedList4))
   System.out.println("linkedList3 contains all elements of linkedList4");
  else
   System.out.println("linkedList3 does NOT contains all elements of linkedList4!");

  linkedList4.add("Vida");
  linkedList4.add("Rosier");

  linkedList4.removeAll(linkedList3);
  System.out.println("\nAfter removeAll()funtion: ");
  System.out.println("3.linkedList3: " + linkedList3);
  System.out.printf("3.linkedList3 SIZE: %d\n",linkedList3.size());
  System.out.println("4.linkedList4: " + linkedList4);
  System.out.printf("4.linkedList4 SIZE: %d\n",linkedList4.size());

  linkedList4.add("Josef");
  linkedList4.add("Atiba");
  linkedList4.add("Cem");

  System.out.println("\nAfter retainAll() function:\n");
  linkedList4.retainAll(linkedList3);
  System.out.println("3.linkedList3: " + linkedList3);
  System.out.printf("3.linkedList3 SIZE: %d\n",linkedList3.size());
  System.out.println("4.linkedList4: " + linkedList4);
  System.out.printf("4.linkedList4 SIZE: %d\n",linkedList4.size());

  System.out.println("Root element of linkedList1: "+linkedList3.element());
  linkedList3.offer("Montero");
  System.out.println("3.linkedList3 after use of offer function: " + linkedList3);

  linkedList3.clear();
  try{
   linkedList3.poll();
  }
  catch (Exception excpt)
  {
   System.out.println("Something went wrong: "+excpt.getMessage());
  }
  System.out.println("4.linkedList4: " + linkedList4);
  linkedList4.poll();
  System.out.println("poll() function:");
  System.out.println("4.linkedList4: " + linkedList4);
  System.out.println("=====================================================\n");

 }

}
