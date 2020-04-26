import org.codehaus.jackson.map.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.sql.SQLException;
import java.util.Map;

@WebServlet("/RegisterServlet")
public class RegisterServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        response.setHeader("content-type","text/html;charset=utf-8");
        BufferedReader reader = null;
        StringBuilder sb = new StringBuilder("");
        ObjectMapper om = new ObjectMapper();
        PrintWriter pwt = response.getWriter();
        try {
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
            Database database = new Database("root","843702140");
            Userdata userdata = database.isExist(email);
            if(userdata == null){
                System.out.println("email:" + email + "\npassword:" + psw);
                database.insert(email,psw,"default");
                pwt.write("注册成功 ！");
                database.close();
            }else{
                System.out.println("用户名已被占用，请更换用户名后尝试！");
                pwt.write("用户名已被占用，请更换用户名后尝试!");
                database.close();
            }
        } catch (SQLException | ClassNotFoundException throwables) {
            throwables.printStackTrace();
        }
    }

}
