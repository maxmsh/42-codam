import java.util.Scanner;

public class ft_garden_summary {
    public static void main(String[] args) {
        System.out.print("Enter garden name: ");
        Scanner scan = new Scanner(System.in);
        String gardenName = scan.nextLine();
        System.out.print("Enter number of plants: ");
        Scanner scan2 = new Scanner(System.in);
        int plant_num = scan2.nextInt();
        System.out.println(gardenName + " has " + plant_num + " plants growing well!");
    }
}