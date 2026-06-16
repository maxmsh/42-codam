import java.util.Scanner;

public class ft_water_reminder {
    public static void main(String[] args)
    {
        System.out.print("Days since last watering: ");
        Scanner scan = new Scanner(System.in);
        int days_since_watering = scan.nextInt();
        if (days_since_watering > 2)
            System.out.println("Water the plants!");
        else
            System.out.println("Plants are fine.");
    }
}