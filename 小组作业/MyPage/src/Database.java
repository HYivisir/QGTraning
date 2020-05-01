import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Database {
    Connection connection = null;
    public Database(String User,String Password) throws ClassNotFoundException, SQLException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        this.connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/myuser?serverTimezone=UTC",User,Password);
    }

    public void insert(String email,String psw,String imagePath) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("INSERT INTO users VALUES(null,?,?,null)");
        prep.setString(1,email);
        prep.setString(2,psw);
        prep.execute();
    }
//    public void delete(int id) throws SQLException {
//        PreparedStatement prep = connection.prepareStatement("DELETE FROM users where id=?");
//        prep.setInt(1,id);
//        prep.execute();
//    }
    public Userdata getUser(String email) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("SELECT * FROM users where email=?");
        prep.setString(1,email);
        prep.execute();
        ResultSet res = prep.getResultSet();
        if(res.next()){
            int id = res.getInt("id");
            String psw = res.getString("psw");
            String path = res.getString("image");
            return new Userdata(id,email,psw,path);
        }else{
            return null;
        }


    }
    public ArrayList<Userdata> getAllUser() throws SQLException {
        ArrayList<Userdata> UserList = new ArrayList<Userdata>();
        PreparedStatement prep = connection.prepareStatement("SELECT * FROM users");
        prep.execute();
        ResultSet res = prep.getResultSet();
        while(res.next()){
            int id = res.getInt("id");
            String email = res.getString("email");
            String psw = res.getString("psw");
            String path = res.getString("image");
            UserList.add(new Userdata(id,email,psw,path));
        }
        UserList.size();
        return UserList;

    }
    public void close() throws SQLException {
        connection.close();
    }
    public Userdata check(String email,String psw) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("SELECT email,psw from users where email=?");
        prep.setString(1,email);
        prep.execute();
        ResultSet res = prep.getResultSet();
        if(res.next()){
            String Dpsw  = res.getString("psw");
            if(Dpsw.equals(psw)){
                return getUser(email);
            }else{
                return null;
            }
        }else{
            return null;
        }
    }
    public Userdata isExist(String email) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("SELECT email from users where email=?");
        prep.setString(1,email);
        prep.execute();
        ResultSet res = prep.getResultSet();
        if(res.next()){
            return getUser(email);
        }else{
            return null;
        }
    }
}
