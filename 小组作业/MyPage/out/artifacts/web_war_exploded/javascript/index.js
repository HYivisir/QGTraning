function isLegal(type,obj,ico,otip,flag){
    if(type == 0){
        var legal = /^\w+@[a-z0-9]+\.[a-z]+$/i;
    }else{
        var legal = /\w{8,}/g;
    }
    var arr = new Array();
    arr = obj.value.split(" ");
    
    if(legal.test(obj.value) && arr.length == 1){
        flag = 1;
        ico[0].style.visibility = 'visible';
        ico[1].style.visibility = 'hidden';
        otip.style.visibility = 'hidden';

    }else{
        ico[0].style.visibility = 'hidden';
        ico[1].style.visibility = 'visible';
        otip.style.visibility = 'visible';

    }
    return flag;
}



window.onload = function (){
    var sflag = new Array();
    var lflag = new Array();
    sflag = [0,0,0];
    lflag = [0,0];
    // 导航栏
    var oLogin = document.getElementById('login');
    var oSignup = document.getElementById('sign');
    // 表单
    var oForm1 = document.getElementsByClassName('login');
    var oForm2 = document.getElementsByClassName('register');
    // 输入框
    var oUser = document.getElementsByClassName('user');
    var oPw = document.getElementsByClassName('pw');
    var oTip = document.getElementsByClassName('tip');

    // 图标
    var ico1 = document.getElementsByClassName('ico1');
    var ico2 = document.getElementsByClassName('ico2');
    var ico3 = document.getElementsByClassName('ico3');
    var ico4 = document.getElementsByClassName('ico4');
    var ico5 = document.getElementsByClassName('ico5');
    // 按钮
    var oBtn = document.getElementsByClassName("btn");
    // 提示框
    var Msg = document.getElementById("msg");
    var msg_btn = document.getElementById("msg_btn");
    var msg_a = document.getElementById("msg_a");
    
    // 表单切换
    oLogin.onclick = function(){
        oLogin.style.color = "#03e9f4";
        oSignup.style.color = "#fff";
        oForm1[0].style.visibility = "visible";
        oForm1[0].style.opacity = 100;
        oForm2[0].style.opacity = 0;
        oForm2[0].style.visibility = "hidden";
    }
    
    oSignup.onclick = function(){
        oSignup.style.color = "#03e9f4";
        oLogin.style.color = "#fff";
        oForm2[0].style.visibility = "visible";
        oForm2[0].style.opacity = 100;
        oForm1[0].style.opacity = 0;
        oForm1[0].style.visibility = "hidden";
    }

    oUser[0].onfocus = function(){
        oTip[0].style.visibility = 'visible'
        this.onblur = function(){
            lflag[0] = isLegal(0,this,ico1,oTip[0],lflag[0]);
        }
    }
    oPw[0].onfocus = function(){
        oTip[1].style.visibility = 'visible';
        this.onblur = function(){
            lflag[1] = isLegal(1,this,ico2,oTip[1],lflag[1]);
        }
    }
    oUser[1].onfocus = function(){
        oTip[2].style.visibility = 'visible'
        this.onblur = function(){
            sflag[0] = isLegal(0,this,ico3,oTip[2],sflag[0]);
            
        }
    }
    oPw[1].onfocus = function(){
        oTip[3].style.visibility = 'visible';
        this.onblur = function(){
            sflag[1] = isLegal(1,this,ico4,oTip[3],sflag[1]);
        }
    }
    oPw[2].onfocus = function(){
        oTip[4].style.visibility = 'visible';
        this.onblur = function(){
            if(this.value == oPw[1].value){
                ico5[0].style.visibility = 'visible';
                ico5[1].style.visibility = 'hidden';
                oTip[4].style.visibility = 'hidden';
                oTip[4].innerHTML = "请再次输入密码";
                sflag[2] = 1;
            }else{
                ico5[0].style.visibility = 'hidden';
                ico5[1].style.visibility = 'visible';
                oTip[4].style.visibility = 'visible'
                oTip[4].innerHTML = "两次密码不一致"
            }
        }
    }

    //提示框
    function MSGBOX(Msg,msg_a,msg_btn){

    }
    //ajax
    //登录
    oBtn[0].onclick = function (){

        if(lflag[0] && lflag[1]){
            let url = "http://localhost:8080/web_war_exploded/LoginServlet";
            let data = {
                email : oUser[0].value,
                psw : oPw[0].value,
            }
            Pajax(url,data,function(res){
                res = JSON.parse(res);
                Msg.style.display = "block";
                msg_a.innerHTML = res.msgs;
                msg_btn.addEventListener("click", function () {
                Msg.style.display = "none";
                })
                if(res.code == 1) {
                    alert("hahaha");
                }
            });
        }else{
            Msg.style.display = "block";
            msg_a.innerHTML =  "请输入格式正确的用户名或密码";
            msg_btn.addEventListener("click",function (){
                Msg.style.display = "none";
            })
        }
    }

    //注册
    oBtn[1].onclick = function (){
        if(sflag[0] && sflag[1] && sflag[2]){
            let url = "http://localhost:8080/web_war_exploded/RegisterServlet";
            let data = {
                email : oUser[1].value,
                psw : oPw[1].value,
            }
            Pajax(url,data,function(res){
            Msg.style.display = "block";
            msg_a.innerHTML = res;
            msg_btn.addEventListener("click",function (){
                Msg.style.display = "none";
            })
            });
        }else{
            Msg.style.display = "block";
            msg_a.innerHTML = "请输入格式正确的用户名或密码";
            msg_btn.addEventListener("click",function (){
                Msg.style.display = "none";
            }) 
            return false;
        }
    }

    
    
}



