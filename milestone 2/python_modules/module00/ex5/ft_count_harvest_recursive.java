import java.util.Scanner;

public class ft_count_harvest_recursive {
    public static void ft_count_harvest_recursive(int day, int i)
    {
        if (i != day)
        {
            System.out.println("Day " + day);
            day++;
        }
        else
            System.out.println("Harvest time!");
    }

    public static void main(String[] args)
    {
        System.out.print("Days until harvest: ");
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        int i = 1;
        while (i <= num)
        {
            ft_count_harvest_recursive(i, num);
            i++;
        }
    }
}