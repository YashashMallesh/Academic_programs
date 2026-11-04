import java.util.*;
class Main {
static void div(int[] d, int[] g) {
for (int i = 0; i <= d.length - g.length; i++)
if (d[i] == 1) for (int j = 0; j < g.length; j++) d[i + j] ^= g[j];
}
static int[] bits(String s) { return s.chars().map(c -> c - '0').toArray(); }
public static void main(String[] a) {
Scanner sc = new Scanner(System.in);
System.out.print("Enter data stream: "); String ds = sc.nextLine();
System.out.print("Enter generator: "); String g = sc.nextLine();
int[] data = Arrays.copyOf(bits(ds), ds.length() + g.length() - 1), gen = bits(g);
div(data.clone(), gen);
System.out.print("The CRC code is: " + ds);
div(data, gen);
Arrays.stream(data, ds.length(), data.length).forEach(System.out::print);
System.out.println();
System.out.print("Enter CRC code: "); ds = sc.nextLine();
System.out.print("Enter generator: "); g = sc.nextLine();
data = bits(ds); gen = bits(g);
div(data, gen);
System.out.println(Arrays.stream(data).allMatch(x -> x == 0) ? "Data stream is valid" : "Data stream is invalid. CRC error occurred.");
}
}
