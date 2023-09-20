import java.util.Comparator;
import java.util.Scanner;
import java.util.*;

public class p3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        //String tem = sc.nextLine();
        String[] maJong = new String[n];
        for (int i = 0; i < n; i++) {
            String temp = sc.nextLine();
            System.out.println(temp);
            maJong = temp.split(" ");
            Arrays.sort(maJong, new maJongComparator());
            System.out.println(maJong[i]);
        }
        sc.close();
    }
    public static int match(char o) {
        if (o == 'Z') {
            return 1;
        }
        if (o == 'F') {
            return 2;
        }
        if (o == 'B') {
            return 3;
        }
        if (o == 'N') {
            return 4;
        }
        if (o == 'W') {
            return 5;
        }
        if (o == 'S') {
            return 6;
        }
        if (o == 'E') {
            return 7;
        }
        if (o == 'Y') {
            return 8;
        }
        if (o == 'T') {
            return 9;
        }
        if (o == 'W') {
            return 10;
        }
        return 0;
    }
}

//Wx>Tx>Yx>E>S>W>N>B>F>Z

class maJongComparator implements Comparator<String> {
    @Override
    public int compare(String o1, String o2) {
        if (p3.match(o1.charAt(0)) > p3.match(o2.charAt(0))) {
            return 1;
        }
        else if (o1.charAt(0) == o2.charAt(0)) {
            return o1.charAt(1) - o2.charAt(1);
        }
        return o1.charAt(0) - o2.charAt(0);
    }
}

