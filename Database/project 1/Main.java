import java.util.Scanner;

public class Main {

    //time calculation for comparison
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        timeCalculator time = new timeCalculator();

        
        String arg = scanner.next();
        switch (arg) {

            case "file":
                //initialize database from csv file
                file tomato = new file("filmData.csv");
                time.printTime(1);
                
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

                break;

            case "database":
                break;

            default:
                throw new IllegalArgumentException("Illegal Argument:" + arg);
        }
        
        
        
    }
}
