import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    private static Scanner myScanner=new Scanner(System.in);
    static BigInteger factorial(int n)
    {
        BigInteger fact=new BigInteger("1");
        for(int i=2;i<=n;i++)
        {
            fact=fact.multiply(BigInteger.valueOf(i));
        }
        return fact;
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        int n=myScanner.nextInt();
        while(n!=0)
        {
            int t=myScanner.nextInt();
            System.out.println(factorial(t));
            n--;
        }

    }
}