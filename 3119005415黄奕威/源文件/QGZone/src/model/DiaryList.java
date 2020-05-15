package model;

public class DiaryList {
    private String email;
    private String d_name;
    private String d_date;
    private String d_text;
    private String d_tag;

    public DiaryList(String email,String d_name,String d_date,String d_text,String d_tag){
        this.email = email;
        this.d_date = d_date;
        this.d_name = d_name;
        this.d_text = d_text;
        this.d_tag = d_tag;
    }

    public String getD_date() {
        return d_date;
    }

    public String getD_name() {
        return d_name;
    }

    public String getD_tag() {
        return d_tag;
    }

    public String getD_text() {
        return d_text;
    }

    public String getEmail() {
        return email;
    }
}
