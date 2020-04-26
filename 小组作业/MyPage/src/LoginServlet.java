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

@WebServlet("/LoginServlet")
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

            System.out.println(email + psw);
            Database database = new Database("root","843702140");
            Userdata userdata = database.check(email,psw);
            if(userdata == null){
                System.out.println("email:" + email + "\npassword:" + psw);
                System.out.println("账户不存在或者密码错误");
                pwt.write("账户不存在或者密码错误");
            }else{
                pwt.write("登录成功！");
                database.close();
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
