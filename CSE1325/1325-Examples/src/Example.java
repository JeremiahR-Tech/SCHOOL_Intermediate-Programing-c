import java.util.Scanner;

public class Example {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        String mailpersonName="Bob";

        System.out.println("--Please enter the mail person's name: ");
        mailpersonName=in.nextLine();

        System.out.println("How many houses does "+mailpersonName+" have to go to?");
        String numberHouses=in.nextLine();
        int numHousesInt=Integer.parseInt(numberHouses);

        for(int i = 0;i < numHousesInt;i++)
        {
            System.out.printf("Delivering to house %d!\n", i+1);
        }

    }
}
