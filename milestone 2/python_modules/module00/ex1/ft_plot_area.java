import java.util.Scanner;

public class ft_plot_area {
    public static void main(String[] args) {
        System.out.print("Enter length: " );
        Scanner scan = new Scanner(System.in);
        int width = scan.nextInt();
        System.out.print("Enter width: ");
        Scanner scan2 = new Scanner(System.in);
        int height = scan2.nextInt();
        System.out.println("Plot area: " + (width * height));
    }
}