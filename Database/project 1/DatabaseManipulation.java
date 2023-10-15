import java.sql.*;

public class DatabaseManipulation {
    timeCalculator time = new timeCalculator();
    private Connection con = null;
    private ResultSet resultSet;
    //private int BATCH_SIZE = 500;
    private String host = "localhost";
    private String dbname = "cslab1";
    private String user = "postgres";
    private String pwd = "xwpc.769394";
    private String port = "5432";


    public void getConnection() {
        try {
            Class.forName("org.postgresql.Driver");

        } catch (Exception e) {
            System.err.println("Cannot find the PostgreSQL driver. Check CLASSPATH.");
            System.exit(1);
        }

        try {
            String url = "jdbc:postgresql://" + host + ":" + port + "/" + dbname;
            con = DriverManager.getConnection(url, user, pwd);
            System.out.println("Database connection established");
            //con.setAutoCommit(false);

        } catch (SQLException e) {
            System.err.println("Database connection failed");
            System.err.println(e.getMessage());
            System.exit(1);
        }
    }


    public void closeConnection() {
        if (con != null) {
            try {
                con.close();
                con = null;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public String searchFilmByKeyword (String type, String keyword) {
        //getConnection();
        StringBuilder sb = new StringBuilder();       
        StringBuilder list = new StringBuilder();
        String sql;
        int tot = 0;
        if (type.equals("year") || type.equals("no")) {
            sql = "select no, title, director, year from films " +
                    " where " + type + " = '" + keyword + "';";
        }
        else if (type.equals("cast")){
            sql = "select no, title, director, year from films " +
                    " where \"" + type + "\"  like '%" + keyword + "%';";
        
        }
        else {
            sql = "select no, title, director, year from films " +
                    " where " + type + " like '%" + keyword + "%';";
        }
        try {
            //time.resetTime();
            PreparedStatement preparedStatement = con.prepareStatement(sql);
            resultSet = preparedStatement.executeQuery();
            //time.printTime();
            while (resultSet.next()) {
                sb.setLength(0);
                sb.append(resultSet.getString("no") + "\t");
                sb.append(resultSet.getString("title") + "\t");
                sb.append(resultSet.getString("director") + "\t");
                sb.append(resultSet.getString("year") + "\t");
                sb.append(System.lineSeparator());
                list.append(sb.toString());
                tot++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //closeConnection();
        }
        System.out.println("Satisfied Films : " + tot);
        return list.toString();
    }

    public int insertFilm (String str) {
        //getConnection();
        int result = 0;
        String sql = "insert into films (no, title, description, director, genre, language, year, \"cast\") " +
                        "values (?,?,?,?,?,?,?,?)";
        String movieInfo[] = str.split(";");
        try {
            PreparedStatement preparedStatement = con.prepareStatement(sql);
            preparedStatement.setInt(1, Integer.parseInt(movieInfo[0]));
            preparedStatement.setString(2, movieInfo[1]);
            preparedStatement.setString(3, movieInfo[2]);
            preparedStatement.setString(4, movieInfo[3]);
            preparedStatement.setString(5, movieInfo[4]);
            preparedStatement.setString(6, movieInfo[5]);
            preparedStatement.setInt(7, Integer.parseInt(movieInfo[6]));           
            preparedStatement.setString(8, movieInfo[7]);

            System.out.println(preparedStatement.toString());

            result = preparedStatement.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //closeConnection();
            System.out.println("Insert successfully");
        }
        return result;
    }

    public int deleteFilmByNo (int index) {
        //getConnection();
        int result = 0;
        String sql = "delete from films where no = ?";
        try {
            PreparedStatement preparedStatement = con.prepareStatement(sql);
            preparedStatement = con.prepareStatement(sql);
            preparedStatement.setInt(1, index);
            result = preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //closeConnection();
            System.out.println("Delete successfully");
        }
        return result;
    }

    public int updateFilmByNo (int index, String type, String data) {
        //getConnection();
        int result = 0;
        String sql;
        if (type.equals("no") || type.equals("year")) 
            sql = "update films set " + type + " = " + data + " where no = ?";
        else if (type.equals("cast"))
            sql = "update films set \"" + type + "\" = " + data + " where no = ?";
        else 
            sql = "update films set " + type + " = '" + data + "' where no = ?";
        try {
            PreparedStatement preparedStatement = con.prepareStatement(sql);
            //preparedStatement.setString(1, type);
            preparedStatement.setInt(1, index);
            result = preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //closeConnection();
            System.out.println("Update successfully");
        }
        return result;
    }

    public void toTOttoo (String to) {
        StringBuilder oo = new StringBuilder();
        oo.append(to.charAt(0)); oo.append(to.charAt(0));
        oo.append(to.charAt(1)); oo.append(to.charAt(1));
        String ttoo = oo.toString();
        String sql = "update films set director = replace(director, '" + to + "', '" + ttoo + "')";
        try {
            PreparedStatement preparedStatement = con.prepareStatement(sql);
            //preparedStatement.setString(1, to);
            //preparedStatement.setString(2, ttoo);
            preparedStatement.executeUpdate();
            //con.commit();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //closeConnection();
            System.out.println(to + " to " + ttoo + " successfully");
        }
    }

    public String searchFilmByNo (int no) {
        //getConnection();
        StringBuilder sb = new StringBuilder();       
        StringBuilder list = new StringBuilder();
        String sql;
        int tot = 0;
        sql = "select no, title, director, year from films " +
                " where no = ?; ";
        try {
            PreparedStatement preparedStatement = con.prepareStatement(sql);
            for (int i = 1; no+10*i<=10020; i++){
                preparedStatement.setInt(1, no+10*i);
                //preparedStatement.addBatch();
                resultSet = preparedStatement.executeQuery();
                while (resultSet.next()) {
                    sb.setLength(0);
                    sb.append(resultSet.getString("no") + "\t");
                    sb.append(resultSet.getString("title") + "\t");
                    sb.append(resultSet.getString("director") + "\t");
                    sb.append(resultSet.getString("year") + "\t");
                    sb.append(System.lineSeparator());
                    list.append(sb.toString());
                }
                tot++;
            }            
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //closeConnection();
        }
        System.out.println("Satisfied Films : " + tot);
        return list.toString();
    }

}
