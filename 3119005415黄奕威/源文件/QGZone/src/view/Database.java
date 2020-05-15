package view;

import java.sql.*;
import java.util.ArrayList;
import model.*;
public class Database {
    Connection connection = null;
    public Database(String User,String Password) throws ClassNotFoundException, SQLException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        this.connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/myuser?serverTimezone=UTC",User,Password);
    }
//    插入用户
    public void insert(String email,String psw,String imagePath) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("INSERT INTO users VALUES(null,?,?,?,null,null,null,null)");
        prep.setString(1,email);
        prep.setString(2,psw);
        prep.setString(3,imagePath);
        prep.execute();
    }
//    修改信息
    public void alterInfos(String useremail,String userage,String usersex,String userphone,String username) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("UPDATE users SET age=?, sex=? , phone=?,`name`=? WHERE email=?");
        prep.setString(1,userage);
        prep.setString(2,usersex);
        prep.setString(3,userphone);
        prep.setString(4,username);
        prep.setString(5,useremail);
        prep.execute();
    }
//    注销用户
//    public void delete(int id) throws SQLException {
//        PreparedStatement prep = connection.prepareStatement("DELETE FROM users where id=?");
//        prep.setInt(1,id);
//        prep.execute();
//    }

//    获取用户
    public Userdata getUser(String email) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("SELECT * FROM users where email=?");
        prep.setString(1,email);
        prep.execute();
        ResultSet res = prep.getResultSet();
        if(res.next()){
            int id = res.getInt("id");
            String psw = res.getString("psw");
            String path = res.getString("image");
            String sex = res.getString("sex");
            String age = res.getString("age");
            String username = res.getString("name");
            String phone = res.getString("phone");
            return new Userdata(id,email,psw,path,sex,age,username,phone);
        }else{
            return null;
        }
    }

//    获取所有用户信息
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
            String sex = res.getString("sex");
            String age = res.getString("age");
            String username = res.getString("name");
            String phone = res.getString("phone");
            UserList.add(new Userdata(id,email,psw,path,sex,age,username,phone));
        }
        UserList.size();
        return UserList;

    }

//    检测用户密码
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

//    检测用户是否已存在
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

//    插入日志
    public void insertDiary(String email,String d_name,String d_date,String d_text,String d_tag) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("INSERT INTO diary_list VALUES(?,?,?,?,?)");
        prep.setString(1,email);
        prep.setString(2,d_name);
        prep.setString(3,d_date);
        prep.setString(4,d_text);
        prep.setString(5,d_tag);
        prep.execute();
    }
//获取所有日志
    public ArrayList<DiaryList> getAllDiary(String email) throws SQLException {
        ArrayList<DiaryList> Diarylist = new ArrayList<DiaryList>();
        PreparedStatement prep = connection.prepareStatement("SELECT * FROM diary_list WHERE email = ?");
        prep.setString(1,email);
        prep.execute();
        ResultSet res = prep.getResultSet();
        while(res.next()){
            String d_name = res.getString("d_name");
            String d_date = res.getString("d_date");
            String d_text = res.getString("d_text");
            String d_tag = res.getString("d_tag");
            Diarylist.add(new DiaryList(email,d_name,d_date,d_text,d_tag));
        }
        Diarylist.size();
        return Diarylist;

    }

//修改头像
    public void alterImg(String email,String imgUrl) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("UPDATE users SET image=? where email=?");
        prep.setString(1,imgUrl);
        prep.setString(2,email);
        prep.execute();
    }
//上传图片
    public void uploadImg(String email,String img_url) throws SQLException {
        PreparedStatement prep = connection.prepareStatement("INSERT INTO img_list VALUES(?,?)");
        prep.setString(1,email);
        prep.setString(2,img_url);
        prep.execute();
    }

//    获取所有图
    public ArrayList<PhotoList> getAllPhotos(String email) throws SQLException {
        ArrayList<PhotoList> photos = new ArrayList<PhotoList>();
        PreparedStatement prep = connection.prepareStatement("SELECT * FROM img_list WHERE email=?");
        prep.setString(1,email);
        prep.execute();
        ResultSet res = prep.getResultSet();
        while(res.next()){
            String imgUrl = res.getString("img_url");
            photos.add(new PhotoList(email,imgUrl));
        }
        photos.size();
        return photos;
    }
    //    关闭数据库链接
    public void close() throws SQLException {
        connection.close();
    }

}




