public class Userdata {
    private int id;
    private String email;
    private String psw;
    private String imagePath;
    public Userdata(int id,String email,String psw,String imagePath){
        this.id = id;
        this.email = email;
        this.psw = psw;
        this.imagePath = imagePath;
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

}
