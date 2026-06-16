import java.util.Scanner;

public class ft_plant_age {
    public static void main(String[] args) {
        System.out.print("Enter plant age in days: ");
        Scanner scan = new Scanner(System.in);
        int plant_age = scan.nextInt();
        if (plant_age > 60)
            System.out.println("Plant is ready to harvest!");
        else
            System.out.println("Plant needs more time to grow.");
    }
}