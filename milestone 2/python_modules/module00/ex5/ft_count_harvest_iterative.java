import java.util.Scanner;

public class ft_count_harvest_iterative {
    public static void main(String[] args) {
        int i = 0;
        System.out.print("Days until harvest: ");
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        while (i <= num)
        {
            System.out.println("Day " + i);
            i++;
        }
        System.out.println("Harvest time!");
    }
}