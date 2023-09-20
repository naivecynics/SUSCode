import java.util.Scanner;

public class p1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int num = sc.nextInt();
            boolean flag = false;
            for (int j = 0; j < n; j++) {
                if (A[j] == num) {
                    System.out.println("yes");
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                System.out.println("no");
            }
        }
        sc.close();
    }
}