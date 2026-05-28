import java.util.Scanner;

public class Example_1_25 {

    public static boolean checkifAdd (String input, String word_check)
    {
                boolean ret=true;
                String [] temp = input.split(" ");
                for(int i = 0; i < temp.length&&ret;i++)
                {
                    if(temp[i].equals(word_check))
                    {
                        ret = false;
                    }
                }

                return ret;
    }

    public static String getUserinput(String message)
    {
        Scanner in = new Scanner(System.in);
        System.out.println(message);
        String answer = in.nextLine();

        while(answer.split(" ").length < 2)
        {
            System.out.println("Entries must have at least two words. Enter again: ");
            answer = in.nextLine();
        }

        return answer;
    }

    public static void main(String [] arg)
    {
        String [] agenda=new String[3];
        int index = 0;
        int counter = 0;

        while(index<agenda.length)
        {
            String userinput = getUserinput("Enter agenda entry: ");
            if(checkifAdd(userinput, "tomato"))
            {
                System.out.println("Adding...\n");
                agenda[index] = userinput;
                index++;
            }
            else
            {
                System.out.println("Not adding.\n");
                counter++;
            }

        }
        System.out.println("Exiting. Total attempts not added: "+counter);

    }
}
