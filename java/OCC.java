import java.util.Scanner;

public class SimpleConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        System.out.println("--- Simple Currency Converter ---");
        System.out.println("1. USD to INR");
        System.out.println("2. INR to USD");
        System.out.println("3. EUR to USD");
        System.out.println("4. USD to EUR");
        System.out.print("\nSelect an option (1-4): ");
        
        int choice = scanner.nextInt();
        System.out.println("Enter The Amount to be converted");
        double amount = scanner.nextDouble();

        double result = 0;
        if (choice == 1) {
            result = amount * 83.50; // 1 USD = 83.50 INR
            System.out.printf("%.2f USD = %.2f INR\n", amount, result);
        } else if (choice == 2) {
            result = amount / 83.50;
            System.out.printf("%.2f INR = %.2f USD\n", amount, result);
        } else if (choice == 3) {
            result = amount * 1.08; // 1 EUR = 1.08 USD
            System.out.printf("%.2f EUR = %.2f USD\n", amount, result);
        } else if (choice == 4) {
            result = amount / 1.08;
            System.out.printf("%.2f USD = %.2f EUR\n", amount, result);
        } else {
            System.out.println("Invalid selection!");
        }

        scanner.close();
    }
}
