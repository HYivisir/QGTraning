package model;

public class PhotoList {
    private String email;
    private String img_url;

    public PhotoList(String email,String img_url){
        this.email = email;
        this.img_url = img_url;
    }

    public String getEmail() {
        return email;
    };

    public String getImg_url() {
        return img_url;
    };
}
