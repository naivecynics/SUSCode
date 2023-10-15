import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.ArrayList;

public class FileManipulation {
    public ArrayList<Film> films;

    public FileManipulation(String csvFile) {

        this.films = new ArrayList<Film>();
        String line;

        //只有当分隔符是逗号且不在引号内时才分割
        String csvSplitBy = ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)";

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                String[] data = line.split(csvSplitBy);
                if (data[0].equals("No")) {
                    continue;
                }
                Film newFilm = new Film(data);
                this.films.add(newFilm);     
                //System.out.println(newFilm.getTitle());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }

    public Film getFilm(int index) {
        return films.get(index);
    }

    public String searchFilmByKeyword (String type, String keyword){
        type = type.toLowerCase();
        StringBuilder sb = new StringBuilder();
        StringBuilder list = new StringBuilder();
        int tot = 0;
        for (int i = 0; i < this.films.size(); i++) {
            Film currentFilm = this.films.get(i);
            switch (type) {
                case "no" :
                case "year" :
                    try {
                        Field field = currentFilm.getClass().getDeclaredField(type);
                        field.setAccessible(true);
                        if (field.get(currentFilm).toString().equals(keyword)) {
                            sb.setLength(0);
                            sb.append(currentFilm.getNo() + "\t");
                            sb.append(currentFilm.getTitle() + "\t");
                            sb.append(currentFilm.getDirector() + "\t");
                            sb.append(currentFilm.getYear() + "\t");
                            sb.append(System.lineSeparator());
                            list.append(sb.toString());
                            tot++;
                        }
                    } catch (NoSuchFieldException e) {
                        e.printStackTrace();
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    }
                    break;
                case "title" :
                case "description" :
                case "language" :
                    try {
                        Field field = currentFilm.getClass().getDeclaredField(type);
                        field.setAccessible(true);
                        if (field.get(currentFilm).toString().toLowerCase().contains(keyword.toLowerCase())) {
                            sb.setLength(0);
                            sb.append(currentFilm.getNo() + "\t");
                            sb.append(currentFilm.getTitle() + "\t");
                            sb.append(currentFilm.getDirector() + "\t");
                            sb.append(currentFilm.getYear() + "\t");
                            sb.append(System.lineSeparator());
                            list.append(sb.toString());
                            tot++;
                        }
                    } catch (NoSuchFieldException e) {
                        e.printStackTrace();
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    }
                    break;
                case "director" :
                case "genre" :
                case "cast" :
                    try {
                        Field field = currentFilm.getClass().getDeclaredField(type);
                        field.setAccessible(true);
                        ArrayList<String> list1 = (ArrayList<String>) field.get(currentFilm);
                        for (int j = 0; j < list1.size(); j++) {
                            if (list1.get(j).toLowerCase().contains(keyword.toLowerCase())) {
                                sb.setLength(0);
                                sb.append(currentFilm.getNo() + "\t");
                                sb.append(currentFilm.getTitle() + "\t");
                                sb.append(currentFilm.getDirector() + "\t");
                                sb.append(currentFilm.getYear() + "\t");
                                sb.append(System.lineSeparator());
                                list.append(sb.toString());
                                tot++;
                                break;
                            }
                        }
                    } catch (NoSuchFieldException e) {
                        e.printStackTrace();
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    }
                    break;
            }
        }
        System.out.println("Satisfied Films : " + tot);
        return list.toString();
    }

    public void insertFilm (String str) {
        String[] data = str.split(";");
        Film film = new Film(data);
        this.films.add(film);
    }

    public void deleteFilm (int No) {
        for (int i = 0; i < this.films.size(); i++) {
            Film currentFilm = this.films.get(i);
            if (currentFilm.getNo() == No) {
                this.films.remove(i);
                break;
            }
        }
    }

    public void updateFilmByNo (int No, String type, String value) {
        for (int i = 0; i < this.films.size(); i++) {
            Film currentFilm = this.films.get(i);
            if (currentFilm.getNo() == No) {
                switch (type) {
                    case "title" :
                        currentFilm.setTitle(value);
                        break;
                    case "description" :
                        currentFilm.setDescription(value);
                        break;
                    case "director" :
                        currentFilm.setDirector(value.split(","));
                        break;
                    case "genre" :
                        currentFilm.setGenre(value.split(","));
                        break;
                    case "language" :
                        currentFilm.setLanguage(value);
                        break;
                    case "year" :
                        currentFilm.setYear(Integer.parseInt(value));
                        break;
                    case "cast" :
                        currentFilm.setCast(value.split(","));
                        break;
                }
                break;
            }
        }
    }

    public void toTOttoo (String to) {
        StringBuilder oo = new StringBuilder();
        oo.append(to.charAt(0)); oo.append(to.charAt(0));
        oo.append(to.charAt(1)); oo.append(to.charAt(1));
        String ttoo = oo.toString();
        for (int i = 0; i < this.films.size(); i++) {
            Film currentFilm = this.films.get(i);
            for (int j = 0; j < currentFilm.getDirector().size(); j++) {
                currentFilm.getDirector().set(j, currentFilm.getDirector().get(j).replace(to, ttoo));
            }
        }
    }

    public void printFilms (ArrayList<Film> films) {
        System.out.printf ("No\tTitle\tDirector\tGenre\tLanguage\tYear\n");
        for (int i = 0; i < films.size(); i++) {
            Film currentFilm = films.get(i);
            System.out.printf ("%d\t%s\t%s\t%s\t%s\t%d\n", currentFilm.getNo(), currentFilm.getTitle(), currentFilm.getDirector(), currentFilm.getGenre(), currentFilm.getLanguage(), currentFilm.getYear());
            //print in tab
        }
        System.out.printf ("Total: %d\n", films.size());
    }

    public int binaryOptimizeNo (int id) {
        int left = 0, right = this.films.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (this.films.get(mid).getNo() == id) {
                return mid;
            } else if (this.films.get(mid).getNo() < id) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; //not found
    }

    public String searchFilmByNo (int no){
        StringBuilder list = new StringBuilder();
        StringBuilder sb = new StringBuilder();
        int tot = 0;
        for (int i = no; i < this.films.size(); i+=10) {
            int index = binaryOptimizeNo(i);
            if (index == -1)  return "Not found";
            Film currentFilm = this.films.get(index);
            sb.setLength(0);
            sb.append(currentFilm.getNo() + "\t");
            sb.append(currentFilm.getTitle() + "\t");
            sb.append(currentFilm.getDirector() + "\t");
            sb.append(currentFilm.getYear() + "\t");
            sb.append(System.lineSeparator());
            list.append(sb.toString());
            tot++;
        }
        System.out.println("Satisfied Films : " + tot);
        return list.toString();
    }
}
