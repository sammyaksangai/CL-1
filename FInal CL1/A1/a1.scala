object BinarySearch{
    def binsearch(nos:Array[Int], srno: Int,l:Int,r:Int) :Int ={
        var mid=(l+r)/2
        if(l>r) {return -1;}
        else if(nos(mid)==srno)
            {return mid}
        else if(nos(mid)>srno)
            {binsearch(nos,srno,l,mid-1)}
        else
            {binsearch(nos,srno,mid+1,r)}
    }

def main(args:Array[String]){
    println("Enter no of elements in array: ")
    var n:Int=Console.readInt
    var nos= new Array[Int](n)
    println("Now enter array elements: ")
    for(i <- 0 to n-1) {
        nos(i)=Console.readInt
    }
    nos=nos.sorted
    println("Enter number to be searched for: ")
    var srno=Console.readInt
    var posn:Int=binsearch(nos,srno,0,n-1)
    if(posn == -1)
        {println("Not found")}
    else
    {println("Found at position "+(posn+1)+" in sorted array")}
}
}

/* Output
sammyak@sammyak-Inspiron-3542:~$ scala a1.scala
warning: there were three deprecation warnings; re-run with -deprecation for details
one warning found
Enter no of elements in array: 
6
Now enter array elements: 
4
5
3
2
7
5
Enter number to be searched for: 
3
Found at position 2 in sorted array
sammyak@sammyak-Inspiron-3542:~$ scala a1.scala
warning: there were three deprecation warnings; re-run with -deprecation for details
one warning found
Enter no of elements in array: 
6
Now enter array elements: 
3
5
6
1
2
3
Enter number to be searched for: 
45
Not found
sammyak@sammyak-Inspiron-3542:~$*/
