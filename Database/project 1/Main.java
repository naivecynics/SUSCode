import java.util.Scanner;

public class Main {

    //time calculation for comparison
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        timeCauculater time = new timeCauculater();

        //initialize database from csv file
        database tomato = new database("filmData.csv");

        time.printTime(1);
        
        //增删改查
        String operation = scanner.next();
        System.out.printf("%s",operation);
        
        tomato.search("a");
        //todo:
    }
}
