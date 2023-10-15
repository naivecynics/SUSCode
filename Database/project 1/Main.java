import java.util.Scanner;


public class Main {
    
    public static void main (String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        //time calculation for comparison
        timeCalculator time = new timeCalculator();
        
        System.out.println("Please enter the data source:");
        System.out.println("(file / database)");
        String arg = scanner.next();
        scanner.nextLine();
        time.resetTime();
        switch (arg) {

            case "file":
                //initialize database from csv file
                FileManipulation tomato = new FileManipulation("filmData.csv");
                time.printTime();
                
                System.out.println("Please enter the operation:");
                System.out.println("(search / insert / delete / update / ttoo / binary)");

                String operation = scanner.next();
                scanner.nextLine();
                while (!operation.equals("exit")) {
                    switch (operation) {
                        case "search":
                            System.out.println("Please enter the searching type:");
                            String type = scanner.next();
                            scanner.nextLine();
                            System.out.println("Please enter the keyword:");
                            String keyword = scanner.nextLine();
                            time.resetTime();
                            System.out.println(tomato.searchFilmByKeyword(type, keyword));
                            break;
                        case "insert":
                            System.out.println("Please enter the film data:");
                            String str = scanner.nextLine();
                            time.resetTime();
                            tomato.insertFilm(str);
                            System.out.println("Film added.");
                            break;
                        case "delete":
                            System.out.println("Please enter the film No you want to delete:");
                            int index = scanner.nextInt();
                            time.resetTime();
                            tomato.deleteFilm(index);
                            break;
                        case "update":
                            System.out.println("Please enter the film No you want to update:");
                            int index2 = scanner.nextInt();
                            scanner.nextLine();
                            System.out.println("Please enter the type you want to update:");
                            String type2 = scanner.next();
                            scanner.nextLine();
                            System.out.println("Please enter the new value:");
                            String value = scanner.nextLine();
                            time.resetTime();
                            tomato.updateFilmByNo(index2, type2, value);
                            break;
                        case "ttoo":
                            System.out.println("Please input two letters");
                            String to = scanner.next();
                            scanner.nextLine();
                            time.resetTime();
                            tomato.toTOttoo(to);
                            break;
                        case "binary":
                            System.out.println("Please input the film No");
                            int no = scanner.nextInt();
                            scanner.nextLine();
                            time.resetTime();
                            System.out.println(tomato.searchFilmByNo(no));
                    }
                    time.printTime();
                    System.out.println("Please enter the operation:");
                    System.out.println("(search / insert / delete / update)");
                    operation = scanner.next();
                    scanner.nextLine();
                }    
                break;

            case "database":
                //time.printTime();
                DatabaseManipulation database = new DatabaseManipulation ();
                database.getConnection();
                time.printTime();
                System.out.println("Please enter the operation:");
                System.out.println("(search / insert / delete / update)");
                operation = scanner.next();
                scanner.nextLine();
                while (!operation.equals("exit")) {
                    switch (operation) {
                        case "search":
                            System.out.println("Please enter the searching type:");
                            String type = scanner.next();
                            scanner.nextLine();
                            System.out.println("Please enter the keyword:");
                            String keyword = scanner.nextLine();
                            time.resetTime();
                            System.out.println(database.searchFilmByKeyword(type, keyword));
                            break;
                        case "insert":
                            System.out.println("Please enter the film data:");
                            String str = scanner.nextLine();
                            time.resetTime();
                            database.insertFilm(str);
                            break;
                        case "delete":
                            System.out.println("Please enter the film No you want to delete:");
                            int index = scanner.nextInt();
                            scanner.nextLine();
                            time.resetTime();
                            database.deleteFilmByNo(index);
                            break;
                        case "update":
                            System.out.println("Please enter the film No you want to update:");
                            int index2 = scanner.nextInt();
                            scanner.nextLine();
                            System.out.println("Please enter the type you want to update:");
                            String type2 = scanner.next();
                            scanner.nextLine();
                            System.out.println("Please enter the new value:");
                            String value = scanner.nextLine();
                            time.resetTime();
                            database.updateFilmByNo(index2, type2, value);
                            break;
                        case "ttoo":
                            System.out.println("Please input two letters");
                            String to = scanner.next();
                            scanner.nextLine();
                            time.resetTime();
                            database.toTOttoo(to);
                        case "binary":
                            System.out.println("Please input the film No");
                            int no = scanner.nextInt();
                            scanner.nextLine();
                            time.resetTime();
                            System.out.println(database.searchFilmByNo(no));
                    }
                    time.printTime();
                    System.out.println("Please enter the operation:");
                    System.out.println("(search / insert / delete / update)");
                    operation = scanner.next();
                    scanner.nextLine();
                }    
                database.closeConnection();
                break;
            default:
                scanner.close();
                throw new IllegalArgumentException("Illegal Argument:" + arg);
        }
        scanner.close();
    }
}
