// Jeremiah Richard
// ID: 100147
// This program check the validness of emails!

import java.util.Scanner;

public class emailaddy {
    public static String getUseremail() {
        System.out.println("Enter your email address: ");
        Scanner in = new Scanner(System.in);
        String email = in.nextLine();

        return email;
    }

    public static boolean checkEmailChars(String email){
        boolean valid_email = false;
        boolean valid_at = false;
        boolean valid_dot = false;
        int counter_at = 0;
        int counter_dot = 0;

        for(int j = 0; j < 2;j++)
        {
            for (int i = 0; i < email.length(); i++)
            {
                char chr = email.charAt(i);
                if(j == 0) // j = 0 for @, j = 1 for .
                {
                    if(chr == '@')
                    {
                        counter_at++;
                        if (counter_at > 1)
                        {
                           // System.out.println("Invalid Email!");
                            valid_at = false;
                            break;
                        }
                        valid_at = true;
                    }
                }
                else if (j == 1)
                {
                    if(chr == '.')
                    {
                        counter_dot++;
                        if (counter_dot > 1)
                        {
                            //System.out.println("Invalid Email!");
                            valid_dot = false;
                            break;
                        }
                        valid_dot = true;
                    }
                }

            }
        }
        return valid_email = valid_at && valid_dot;
    }

    // The order of the characters are checked with the assumption that they are known to exist in the email by one
    public static boolean checkCharsOrder(String email)
    {
        boolean valid = false;
        boolean check_at = true; // I will use this to check for the dot after the @
        for(int i = 0; i < email.length();i++)
        {
            char chr = email.charAt(i);
            if(chr == '@' && check_at)
            {
                check_at = false;
                continue;
            }
            else if(chr == '.' && !check_at)
            {
                valid = true;
            }
        }
        return valid;
    }

    public static void main(String[] arg)
    {
        // What is considered an invalid email?
        // 1. More than one at or dot
        // 2. less than one at or dot
        // 3. a dot before an at
        // 4. Proper email code...".com" or ".edu"
        boolean valid_email = false;

        String email = getUseremail();
        email.trim();
        email = email.toLowerCase();

        valid_email = checkCharsOrder(email) && checkEmailChars(email);

        if(valid_email)
        {
  // TESTING ---          System.out.println("Valid Email!");

            // Knowing the email chars is valid, it's time to get individual net-code parts
            String netname = email.substring(email.indexOf("@")+1,email.indexOf("."));
       // TESTING ---     System.out.println("Netname: "+netname);
            String netsource = email.substring(email.indexOf(".")+1,email.length());
       // TESTING ---     System.out.println("Netsource: "+netsource);

            if(netsource.equals("com") || netsource.equals("net"))
            {
                System.out.println("This is a general email from the company: "+netname);
            }
            else if(netsource.equals("edu"))
            {
                System.out.println("This is a school email from the school: "+netname);
            }
            else
            {
                System.out.println("Invalid Email, wrong email code!");
            }
        }
        else
        {
            System.out.println("This is not a valid email address.");
        }

    }
}
