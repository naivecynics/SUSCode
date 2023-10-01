import java.util.Scanner;

public class Main {

    //time calculation for comparison
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        timeCauculater time = new timeCauculater();

        //initialize database from csv file
        database tomato = new database("filmData.csv");

        time.printTime(1);
        
        //todo:
        //增删改查
        
        String operation = scanner.next();
        while (!operation.equals("exit")) {
            switch (operation) {
                case "search":
                    String keyword = scanner.next();
                    tomato.printFilms(tomato.search(keyword));
                    time.printTime(2);
                    break;
                case "add":
                    String[] data = new String[8];
                    for (int i = 0; i < 8; i++) {
                        data[i] = scanner.next();
                    }
                    film newFilm = new film(data);
                    tomato.films.add(newFilm);
                    break;
                case "delete":
                    int index = scanner.nextInt();
                    tomato.films.remove(index);
                    break;
                case "update":
                    int index2 = scanner.nextInt();
                    String[] data2 = new String[8];
                    for (int i = 0; i < 8; i++) {
                        data2[i] = scanner.next();
                    }
                    film newFilm2 = new film(data2);
                    tomato.films.set(index2, newFilm2);
                    break;
            }
            operation = scanner.next();
        }    
    }
}
