package controller;

import net.sf.json.JSONObject;
import org.codehaus.jackson.map.ObjectMapper;
import view.Database;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.sql.SQLException;
import java.util.Map;
@WebServlet("/controller/DiaryServlet")
public class DiaryServlet extends HttpServlet {
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
            JSONObject msg = new JSONObject();
            Database database = new Database("root","843702140");
//          获取日志
            String email = params.get("email").toString();
            String d_name = params.get("d_name").toString();
            String d_date = params.get("d_date").toString();
            String d_text = params.get("d_text").toString();
            String d_tag = params.get("d_tag").toString();
//          插入日志
            database.insertDiary(email,d_name,d_date,d_text,d_tag);
            System.out.println("插入日志成功");
            msg.put("code",1);
            msg.put("msgs","插入日志成功!");
            pwt.print(msg);
            database.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }


}
