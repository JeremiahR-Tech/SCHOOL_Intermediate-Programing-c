import java.util.Scanner;

public class Practice1 {
    public static String [] getAllCheese(int n)
    {
        Scanner in=new Scanner(System.in);

        while(n < 3)
        {
            System.out.println("n is too small. Enter a new value: ");
            n=in.nextInt();
        }

        String [] cheese=new String[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("-Enter cheese "+(i+1)+":");
            cheese[i]=in.nextLine();
        }

        return cheese;
    }

    public static boolean checkCheese(String s,char letter)
    {
        if(s.charAt(0)==letter && s.length()<5)
        {
            return true;
        }
        return false;
    }

    public static void printOutCheese(String [] s)
    {
        System.out.println("\n--All Cheeses--");
        for(int i=0;i<s.length;i++)
        {
            if(s[i].toLowerCase().equals("brie"))
            {
                System.out.println("**I LOVE brie!**");
            }
            else
            {
                System.out.println(s[i]);
            }
        }
    }
    public static void main(String [] args)
    {
        System.out.println("How many types of cheeses?");
        Scanner input= new Scanner(System.in);
        int cheese_num = input.nextInt();

        String [] allCheese=getAllCheese(cheese_num);

        if(checkCheese(allCheese[0],'g'))
        {
            System.out.println(allCheese[0]+" start with g and is less than 5 letters long.");
        }
        else
        {
            printOutCheese(allCheese);
        }

    }
}