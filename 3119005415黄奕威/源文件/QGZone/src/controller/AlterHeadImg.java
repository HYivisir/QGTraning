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

@WebServlet("/controller/AlterHeadImg")
public class AlterHeadImg extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        response.setHeader("content-type", "text/html;charset=utf-8");

        BufferedReader reader = null;
        StringBuilder sb = new StringBuilder("");
        ObjectMapper om = new ObjectMapper();
        PrintWriter pwt = response.getWriter();
        try {
            reader = request.getReader();
            String str;
            while ((str = reader.readLine()) != null) {
                sb.append(str);
            }
            reader.close();
            String data = sb.toString();
            Map<String, String> params = om.readValue(data, Map.class);
            JSONObject msg = new JSONObject();
            Database database = new Database("root", "843702140");
            String email = params.get("email").toString();
            String url = params.get("headImg").toString();

            database.alterImg(email,url);
            System.out.println("头像修改成功！");
            msg.put("code",1);
            msg.put("msgs","修改成功！");
            msg.put("headimg",url);
            pwt.print(msg);
            database.close();

        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
