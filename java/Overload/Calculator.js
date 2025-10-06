// Program: Simple Calculator using Method Overloading

class Calculator {

    // Addition of two integers
    int calculate(int a, int b) {
        return a + b;
    }

    // Subtraction of two doubles
    double calculate(double a, double b) {
        return a - b;
    }

    // Multiplication of three integers
    int calculate(int a, int b, int c) {
        return a * b * c;
    }

    // Division of two doubles
    double calculate(double a, double b, boolean isDivision) {
        if (isDivision) {
            if (b == 0) {
                System.out.println("Error: Division by zero!");
                return 0;
            }
            return a / b;
        } else {
            return 0; // fallback
        }
    }
}

public class SimpleCalculatorOverload {
    public static void main(String[] args) {
        Calculator calc = new Calculator();

        System.out.println("Addition (int): 10 + 20 = " + calc.calculate(10, 20));
        System.out.println("Subtraction (double): 50.5 - 30.2 = " + calc.calculate(50.5, 30.2));
        System.out.println("Multiplication (int): 2 * 3 * 4 = " + calc.calculate(2, 3, 4));
        System.out.println("Division (double): 100 / 5 = " + calc.calculate(100.0, 5.0, true));
    }
}
