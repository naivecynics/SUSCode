import java.util.Arrays;
import java.util.Scanner;

public class ttt {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入字符串数组的长度： ");
        int n = scanner.nextInt();
        scanner.nextLine(); // 消耗掉换行符

        String[] stringArray = new String[n];

        System.out.println("请输入字符串数组元素：");
        for (int i = 0; i < n; i++) {
            stringArray[i] = scanner.nextLine();
        }

        // 使用Arrays.sort()方法对字符串数组进行排序
        Arrays.sort(stringArray);

        System.out.println("排序后的字符串数组为：");
        for (String str : stringArray) {
            System.out.println(str);
        }

        scanner.close();
    }
}
