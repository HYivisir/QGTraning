package controller;

import model.PhotoList;
import net.sf.json.JSONObject;
import org.codehaus.jackson.map.ObjectMapper;
import view.Database;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Map;

@WebServlet("/conteoller/GetAllPhotos")
public class GetAllPhotos extends HttpServlet {
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
//          获取图片
            String email = params.get("email").toString();
            ArrayList<PhotoList> photos = database.getAllPhotos(email);
            for(int i=0;i<photos.size();i++){
                msg.put("imgUrl",photos.get(i).getImg_url());
                pwt.print(msg+" ");
            }
            database.close();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}