// Jeremiah Richard
// ID: 1001475742
/* This code checks to see if Dallas and
* Fort-Worth area codes are correct */

public class phonecall {
   public static boolean phoneNum (String number,String city)
   {
       String dallas_area_codes [] = {"214","972","469"};
       String fortworth_area_codes [] = {"817","682"};

       boolean number_check = false;
       String area_code = number.substring(0,number.indexOf("-"));
       area_code.trim();
       System.out.println("Area Code: "+area_code);

       if(city.toLowerCase().equals("dallas"))
       {
           for(int i = 0;i < dallas_area_codes.length;i++)
           {
               if(dallas_area_codes[i].equals(area_code))
               {
                   number_check = true;
                   break;
               }
           }
       }
       else if(city.toLowerCase().equals("fort worth"))
       {
           for(int i = 0;i < fortworth_area_codes.length;i++)
           {
               if(fortworth_area_codes[i].equals(area_code))
               {
                   number_check = true;
                   break;
               }
           }
       }

       return number_check;
   }

    public static void main(String [] args)
    {
       /* Dallas Area Codes
       * 214, 972, 469
       * Fort-Worth Area Codes
       *  817, 682*/

        System.out.println(phoneNum("817-999-9999","Dallas"));
    }
}
