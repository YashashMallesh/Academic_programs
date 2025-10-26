// Program to calculate Area of different 2D objects using method overloading

class AreaCalculator {

    // Area of Circle
    double area(double radius) {
        return Math.PI * radius * radius;
    }

    // Area of Rectangle
    double area(double length, double breadth) {
        return length * breadth;
    }

    // Area of Triangle
    double area(double base, double height, boolean isTriangle) {
        if (isTriangle)
            return 0.5 * base * height;
        else
            return base * height; // fallback, not a triangle
    }

    // Area of Square (overloaded with integer type)
    int area(int side) {
        return side * side;
    }
}

public class AreaOverloadDemo {
    public static void main(String[] args) {
        AreaCalculator calc = new AreaCalculator();

        System.out.println("Area of Circle (r=5): " + calc.area(5.0));
        System.out.println("Area of Rectangle (l=4, b=6): " + calc.area(4.0, 6.0));
        System.out.println("Area of Triangle (b=4, h=5): " + calc.area(4.0, 5.0, true));
        System.out.println("Area of Square (side=5): " + calc.area(5));
    }
}
