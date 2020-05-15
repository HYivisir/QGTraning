package controller;

import net.sf.json.JSONObject;
import org.codehaus.jackson.map.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.Map;
import model.*;
import view.Database;

@WebServlet("/controller/LoginServlet")
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        response.setHeader("content-type","text/html;charset=utf-8");

        BufferedReader reader = null;
        StringBuilder sb = new StringBuilder("");
        ObjectMapper om = new ObjectMapper();
        PrintWriter pwt = response.getWriter();
        try{
            reader = request.getReader();
            String str;
            while((str = reader.readLine()) != null){
                sb.append(str);
            }
            reader.close();
            String data = sb.toString();
            Map<String,String> params = om.readValue(data, Map.class);
            String email = params.get("email").toString();
            String psw = params.get("psw").toString();
            JSONObject msg = new JSONObject();
            Database database = new Database("root","843702140");
            Userdata userdata = database.check(email,psw);
            if(userdata == null){
                System.out.println("email:" + email + "\npassword:" + psw);
                System.out.println("账户不存在或者密码错误");
                msg.put("code",0);
                msg.put("msgs","账户不存在或者密码错误");
                pwt.print(msg);
            }else{
                msg.put("code",1);
                msg.put("msgs","登录成功！");
                msg.put("email",email);
                msg.put("sex",userdata.getSex());
                msg.put("age",userdata.getAge());
                msg.put("username",userdata.getUsername());
                msg.put("phone",userdata.getPhone());
                msg.put("imgPath",userdata.getImagePath());
                pwt.print(msg);
                database.close();
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
