import java.util.ArrayList;

public class film {
    //No,Title,Description,Director,Genre,Language,Year,Cast
    private int no;
    private String title;
    private String description;
    private String director;
    private ArrayList<String> genre;
    private String language;
    private int year;
    private ArrayList<String> cast;

    public film (String[] data) {
        this.genre = new ArrayList<String>();
        this.cast = new ArrayList<String>();

        this.no = Integer.parseInt(data[0]);
        this.title = data[1];
        this.description = data[2];
        this.director = data[3];
        String[] genreList = data[4].split(", ");
        for (int i = 0; i < genreList.length; i++) {
            if (i == 0){
                this.genre.add(genreList[i].substring(1));
            } else if (i == genreList.length - 1) {
                this.genre.add(genreList[i].substring(0, genreList[i].length() - 1));
            } else if (i != 0 && i != genreList.length - 1) {
                this.genre.add(genreList[i]);
            }
        }
        this.language = data[5];
        this.year = Integer.parseInt(data[6]);
        String[] castList = data[7].split(", ");
        for (int i = 0; i < castList.length; i++) {
            if (i == 0) {
                this.cast.add(castList[i].substring(1));
            } else if (i == castList.length - 1) {
                this.cast.add(castList[i].substring(0, castList[i].length() - 1));
            } else if (i != 0 && i != castList.length - 1) {
                this.cast.add(castList[i]);
            }
        }
    }

    //getters
    public int getNo() {
        return this.no;
    }
    public String getTitle() {
        return this.title;
    }
    public String getDescription() {
        return this.description;
    }
    public String getDirector() {
        return this.director;
    }
    public ArrayList<String> getGenre() {
        return this.genre;
    }
    public String getLanguage() {
        return this.language;
    }
    public int getYear() {
        return this.year;
    }
    public ArrayList<String> getCast() {
        return this.cast;
    }
    
    //setters
    public void setNo(int no) {
        this.no = no;
    }
    public void setTitle(String title) {
        this.title = title;
    }
    public void setDescription(String description) {
        this.description = description;
    }
    public void setDirector(String director) {
        this.director = director;
    }
    public void setGenre(ArrayList<String> genre) {
        this.genre = genre;
    }
    public void setLanguage(String language) {
        this.language = language;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public void setCast(ArrayList<String> cast) {
        this.cast = cast;
    }
}
