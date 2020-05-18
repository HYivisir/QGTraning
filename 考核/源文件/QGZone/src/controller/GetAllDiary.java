package controller;

import model.DiaryList;
import net.sf.json.JSONObject;
import org.codehaus.jackson.JsonParseException;
import org.codehaus.jackson.map.JsonMappingException;
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
import java.util.ArrayList;
import java.util.Map;
@WebServlet("/controller/GetAllDiary")
public class GetAllDiary extends HttpServlet{
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
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
//          获取日志
            String email = params.get("email").toString();
            ArrayList<DiaryList> diarys = database.getAllDiary(email);
            for(int i=0;i<diarys.size();i++){
                msg.put("d_name",diarys.get(i).getD_name());
                msg.put("d_date",diarys.get(i).getD_date());
                msg.put("d_tag",diarys.get(i).getD_tag());
                msg.put("d_text",diarys.get(i).getD_text());
                pwt.print(msg+" ");
            }
            database.close();
        } catch (JsonParseException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}