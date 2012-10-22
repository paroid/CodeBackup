import java.io.*;
import java.util.*;

public class jt{
    public static void main (String [] args)
    {
        try{
            Scanner sc=new Scanner(new File("in"));
            PrintStream ps=new PrintStream("out");  
            System.setOut(ps);  
            Tree<Double> tt=new Tree();
            for(int i=0;i<8;++i){
                tt.insert(sc.nextDouble());
                if(tt.root==null)
                    System.out.println("Root Null!");
            }
            for(int i=0;i<0;++i){
                tt.search(sc.nextDouble());
            }
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
    }
} 


class Tree<T>{
    public Node<T> root;
    public void search(T key){
        search(root,key);
    }
    public void search(Node<T> path,T key){
        if(path.data==key){
            System.out.println(key);
        }
        else if(path.left!=null && (((Comparable)key).compareTo(path.data)<0)){
            System.out.print(path.data+" ->l ");
            search(path.left,key);
        }
        else if(path.right!=null && (((Comparable)key).compareTo(path.data)>0)){
            System.out.print(path.data+" ->r ");
            search(path.right,key);
        }
        else
            System.out.println("Oops!");
    }
    public void insert(T key){
        if(root==null){
            root=new Node<T>(key);
            System.out.println(key);
        }
        else
            insert(root,key);
    }
    public void insert(Node<T> path,T key){
        if(((Comparable)key).compareTo(path.data)<0){
            if(path.left==null){
                path.left=new Node<T>(key);
                    System.out.println(path.data+" ->l "+key);
            }
            else{
                System.out.print(path.data+" ->l ");
                insert(path.left,key);
            }
        }
        else if(((Comparable)key).compareTo(path.data)>0){
            if(path.right==null){
                path.right=new Node<T>(key);
                    System.out.println(path.data+" ->r "+key);
            }
            else{
                System.out.print(path.data+" ->r ");
                insert(path.right,key);
            }
        }
    }
}

class Node<T>{
    public Node(T val){
        data=val;
    } 
    public Node<T> left,right;
    public T data;
}

/* Simplified version*/
/*
import java.io.*;
import java.util.*;

public class jt{
    public static void main (String [] args)
    {
        try{
            Scanner sc=new Scanner(new File("in"));
            PrintStream ps=new PrintStream("out");  
            System.setOut(ps);  
            Tree<Integer> tt=new Tree();
            for(int i=0;i<8;++i){
                tt.insert(sc.nextInt());
                if(tt.root==null)
                    System.out.println("Root Null!");
            }
            for(int i=0;i<0;++i){
                tt.search(sc.nextInt());
            }
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
    }
} 


class Tree<T>{
    public Node<T> root;
    public void search(T key){
        search(root,key);
    }
    public void search(Node<T> path,T key){
        if(path.data==key){
            System.out.println("Find "+key);
        }
        else if(path.left!=null && (((Comparable)key).compareTo(path.data)<0))
            search(path.left,key);
        else if(path.right!=null && (((Comparable)key).compareTo(path.data)>0))
            search(path.right,key);
        else
            System.out.println("Oops!");
    }
    public void insert(T key){
        if(root==null)
            root=new Node<T>(key);
        else
            insert(root,key);
    }
    public void insert(Node<T> path,T key){
        if(((Comparable)key).compareTo(path.data)<0){
            if(path.left==null)
                path.left=new Node<T>(key);
            else
                insert(path.left,key);
        }
        else if(((Comparable)key).compareTo(path.data)>0){
            if(path.right==null)
                path.right=new Node<T>(key);
            else
                insert(path.right,key);
        }
    }
}

class Node<T>{
    public Node(T val){
        data=val;
    } 
    public Node<T> left,right;
    public T data;
}
*/
