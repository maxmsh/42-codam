import java.util.Scanner;

public class ft_harvest_total {
    public static void main(String[] args)
    {
        System.out.print("Day 1 harvest: ");
        Scanner scan = new Scanner(System.in);
        int first = scan.nextInt();
        System.out.print("Day 2 harvest: ");
        Scanner scan2 = new Scanner(System.in);
        int second = scan2.nextInt();
        System.out.print("Day 3 harvest: ");
        Scanner scan3 = new Scanner(System.in);
        int third = scan3.nextInt();
        int total = (first + second + third);
        System.out.println("Total harvest: " + total);
    }
}