package model;

public class Userdata {
    private int id;
    private String email;
    private String psw;
    private String imagePath;
    private String age;
    private String sex;
    private String phone;
    private String username;

    public Userdata(int id,String email,String psw,String imagePath,String sex,String age,String username,String phone){
        this.id = id;
        this.email = email;
        this.psw = psw;
        this.imagePath = imagePath;
        this.age = age;
        this.phone = phone;
        this.sex = sex;
        this.username = username;

    }

    public int getId(){
        return id;
    }
    public String getEmail(){
        return email;
    }
    public String getPsw() {
        return psw;
    }
    public String getImagePath() {
        return imagePath;
    }
    public String getAge() { return age; }
    public String getPhone() { return phone; }
    public String getSex() { return sex; }
    public String getUsername() { return username; }
}
