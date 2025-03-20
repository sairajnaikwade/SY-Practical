public class ConditionalStatement {
    public static void main(String[] args) {
        
        // Printing numbers between 1 and 100 that are divisible by 7
        System.out.print("Numbers divisible by 7: ");
        for (int i = 1; i <= 100; i++) {
            if (i % 7 == 0) {  // Check if the number is divisible by 7
                System.out.print(i + " ");
            }
        }
        System.out.println(); // Move to the next line
        
        // Finding the sum of numbers between 100 and 200 that are divisible by 7
        int sum = 0;
        for (int i = 100; i <= 200; i++) {
            if (i % 7 == 0) {  // Check if the number is divisible by 7
                sum += i;      // Add the number to sum
            }
        }
        System.out.println("Sum of numbers divisible by 7 (100-200): " + sum);
    }
}
