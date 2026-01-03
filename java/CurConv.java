import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CurrencyConverter {

    // Map to store exchange rates relative to a base currency (USD)
    private static final Map<String, Double> exchangeRates = new HashMap<>();

    // Static block to initialize hardcoded rates
    // In a real-world app, these would be fetched from an API
    static {
        // Base Currency: USD (1.0)
        exchangeRates.put("USD", 1.0);
        exchangeRates.put("EUR", 0.92);   // Euro
        exchangeRates.put("GBP", 0.79);   // British Pound
        exchangeRates.put("INR", 83.15);  // Indian Rupee
        exchangeRates.put("AUD", 1.52);   // Australian Dollar
        exchangeRates.put("CAD", 1.36);   // Canadian Dollar
        exchangeRates.put("JPY", 151.60); // Japanese Yen
        exchangeRates.put("CNY", 7.23);   // Chinese Yuan
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("===============================================");
        System.out.println("      WELCOME TO THE JAVA CURRENCY CONVERTER   ");
        System.out.println("===============================================");
        System.out.println("Available Currencies: " + exchangeRates.keySet());
        
        boolean continueRunning = true;

        while (continueRunning) {
            try {
                // 1. Get Source Currency
                System.out.print("\nEnter Source Currency (e.g., USD): ");
                String fromCurrency = scanner.next().toUpperCase();

                if (!exchangeRates.containsKey(fromCurrency)) {
                    System.out.println("Error: Currency not supported.");
                    continue;
                }

                // 2. Get Target Currency
                System.out.print("Enter Target Currency (e.g., EUR): ");
                String toCurrency = scanner.next().toUpperCase();

                if (!exchangeRates.containsKey(toCurrency)) {
                    System.out.println("Error: Currency not supported.");
                    continue;
                }

                // 3. Get Amount
                System.out.print("Enter Amount to Convert: ");
                double amount = scanner.nextDouble();

                if (amount < 0) {
                    System.out.println("Error: Amount cannot be negative.");
                    continue;
                }

                // 4. Perform Conversion
                double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency);

                // 5. Display Result
                System.out.printf("Success: %.2f %s = %.2f %s%n", 
                        amount, fromCurrency, convertedAmount, toCurrency);

            } catch (Exception e) {
                System.out.println("Invalid input. Please enter numbers for amounts.");
                scanner.nextLine(); // Clear the buffer
            }

            // Ask to continue
            System.out.print("\nDo you want to perform another conversion? (yes/no): ");
            String choice = scanner.next();
            if (!choice.equalsIgnoreCase("yes") && !choice.equalsIgnoreCase("y")) {
                continueRunning = false;
            }
        }

        System.out.println("Thank you for using the converter. Goodbye!");
        scanner.close();
    }

    /**
     * Converts an amount from one currency to another using USD as the bridge.
     * Formula: (Amount / FromRate) * ToRate
     */
    private static double convertCurrency(double amount, String fromCurrency, String toCurrency) {
        double fromRate = exchangeRates.get(fromCurrency);
        double toRate = exchangeRates.get(toCurrency);
        
        // Convert 'from' currency to USD, then USD to 'to' currency
        return (amount / fromRate) * toRate;
    }
}
