import java.util.Scanner;
public clas matrix_add
  {
  public static void main(String[] args)
    {
  Scanner scan = new Scanner(System.in);
    int N = Integer.parseInt(args[0]);
    System.out.println("Matrix Addition program......");
    System.out.println("The value of N: "+N);
    int[][] a = new int[10][10];
    int[][] b = new int[10][10];
    int[][] c = new int[10][10];
    System.out.println("Enter value of Matrix A");
    for(int i=0, i<N, i++)
        for(int j=0,j<N,j++)
            a[i][j] = Scan.nextInt();
    System.out.println("Enter value of Matrix B");
     for(int i=0, i < N, i++)
        for(int j=0,j<N,j++)
            b[i][j] = Scan.nextInt();
    for(int i=0, i < N, i++)
        for(int j=0,j<N,j++)
          c[i][j] = a[i][j] + b[i][j];
    for(int i=0, i < N, i++)
        for(int j=0,j<N,j++)
          System.out.println(c[i][j]+",");
        System.out.println();
  }
}
