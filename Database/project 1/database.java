import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class database {
    public ArrayList<film> films;

    public database(String csvFile) {

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

    public film[] search (String keyword){
`       
    }

    //public film[] search ()
}
