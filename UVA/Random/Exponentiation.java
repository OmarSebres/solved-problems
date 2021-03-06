import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        BigDecimal R = null;
        String result;

        while (cin.hasNext()) {
            R = cin.nextBigDecimal();
            result = R.pow(cin.nextInt()).stripTrailingZeros().toPlainString();

            if (result.charAt(0) == '0') {
                System.out.println(result.substring(1));
            } else {
                System.out.println(result);
            }
        }
    }
}