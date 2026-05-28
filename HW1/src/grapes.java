// Jeremiah Richard
// ID: 1001475742
import java.util.Scanner;

public class grapes {
    public static String[] enterInput(int grapeFarms)
    {
        Scanner in=new Scanner(System.in);
        String [] grapeInfo = new String[grapeFarms];
        for(int i = 0; i < grapeFarms; i++)
        {
            System.out.println("Enter the number of grapes and the number of grape leaves, separated by a space: ");
            grapeInfo[i] = in.nextLine();
        }

        return grapeInfo;
    }

    public static int getTotal (String item, String [] grapeInfo)
    {
        int total = 0;
        if(item.toLowerCase().contains("grape"))
        {
            if(item.toLowerCase().contains("leaves"))
            {
                String leaves [] = new String[grapeInfo.length];
                for(int i = 0; i < grapeInfo.length; i++)
                {
                    leaves = grapeInfo[i].split(" ");
                    total = total + Integer.parseInt(leaves[1]);
                }
            }
            else
            {
                String grapes [] = new String[grapeInfo.length];
                for(int i = 0; i < grapeInfo.length; i++)
                {
                    grapes = grapeInfo[i].split(" ");
                    total = total + Integer.parseInt(grapes[0]);
                }
            }
        }

        return total;
    }

    public static void main(String [] args)
    {
        String	[]	grapeInfo=enterInput(3);
        System.out.println("\nTotal	grapes:	"+getTotal("grape",	grapeInfo)+"\n");
        System.out.println("Total   grape	leaves:	"+getTotal("grape	leaves",	grapeInfo)+"\n");
    }
}
