package controller;

import net.sf.json.JSONObject;
import view.Database;
import model.Userdata;
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

@WebServlet("/controller/AlterInfosServlet")
public class AlterInfosServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setCharacterEncoding("utf-8");
        response.setHeader("content-type","text/html;charset=utf-8");
        BufferedReader reader = null;
        StringBuilder sb = new StringBuilder("");
        ObjectMapper om = new ObjectMapper();
        PrintWriter pwt = response.getWriter();

        try{
            String str;
            reader = request.getReader();
            while((str = reader.readLine()) != null){
                sb.append(str);
            }
            reader.close();
            String data = sb.toString();
            Map<String,String> params = om.readValue(data, Map.class);
            JSONObject msg = new JSONObject();
            String email = params.get("email").toString();
            String username = params.get("username").toString();
            String age = params.get("age").toString();
            String sex = params.get("sex").toString();
            String phone = params.get("phone").toString();
            Database database = new Database("root","843702140");
            Userdata userdata = database.isExist(email);
            if(userdata == null){
                msg.put("code",0);
                msg.put("msgs","信息出错，请检查后重试");
                System.out.println("修改失败");
                pwt.print(msg);
                database.close();
            }else{
                database.alterInfos(email,age,sex,phone,username);
                msg.put("code",1);
                msg.put("msgs","修改成功！");
                System.out.println("修改成功！");
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
