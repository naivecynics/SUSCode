import java.io.*;
import java.util.*;

public class FileManipulation implements DataManipulation {

    public ArrayList<film> films;

    public FileManipulation(String csvFile) {

        this.films = new ArrayList<film>();
        String line;

        //只有当分隔符是逗号且不在引号内时才分割
        String csvSplitBy = ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)";

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                String[] data = line.split(csvSplitBy);
                if (data[0].equals("No")) {
                    continue;
                }
                film newFilm = new film(data);
                this.films.add(newFilm);     
                //System.out.println(newFilm.getTitle());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }

    public film getFilm(int index) {
        return films.get(index);
    }

    public ArrayList<film> search (String keyword){
        ArrayList<film> result = new ArrayList<film>();
        for (int i = 0; i < this.films.size(); i++) {
            film currentFilm = this.films.get(i);
            if (currentFilm.getTitle().contains(keyword) || currentFilm.getDescription().contains(keyword) || currentFilm.getDirector().contains(keyword) || currentFilm.getGenre().contains(keyword) || currentFilm.getLanguage().contains(keyword) || currentFilm.getCast().contains(keyword)) {
                result.add(currentFilm);
            }
        }
       return result;
    }

    public void printFilms (ArrayList<film> films) {
        System.out.printf ("No\tTitle\tDirector\tGenre\tLanguage\tYear\n");
        for (int i = 0; i < films.size(); i++) {
            film currentFilm = films.get(i);
            System.out.printf ("%d\t%s\t%s\t%s\t%s\t%d\n", currentFilm.getNo(), currentFilm.getTitle(), currentFilm.getDirector(), currentFilm.getGenre(), currentFilm.getLanguage(), currentFilm.getYear());
            //print in tab
        }
        System.out.printf ("Total: %d\n", films.size());
    }
}
