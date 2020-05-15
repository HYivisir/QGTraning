// 表单切换
loginTag.onclick = function (){
    oForm1.style.visibility = "visible";
    oForm1.style.opacity = 100;
    oForm2.style.opacity = 0;
    oForm2.style.visibility = "hidden";
    loginTag.style.color = "#03e9f4";
    registerTag.style.color = "#fff";
}

registerTag.onclick = function (){
    oForm2.style.visibility = "visible";
    oForm2.style.opacity = 100;
    oForm1.style.opacity = 0;
    oForm1.style.visibility = "hidden";
    registerTag.style.color = "#03e9f4";
    loginTag.style.color = "#fff";
}

// 输入判断
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

var sflag = new Array();
var lflag = new Array();
sflag = [0,0,0];
lflag = [0,0];

oEmail[0].onfocus = function(){
    oTip[0].style.visibility = 'visible'
    this.onblur = function(){
        lflag[0] = isLegal(0,this,ico1,oTip[0],lflag[0]);
    }
}

oPwd[0].onfocus = function(){
    oTip[1].style.visibility = 'visible';
    this.onblur = function(){
        lflag[1] = isLegal(1,this,ico2,oTip[1],lflag[1]);
    }
}
oEmail[1].onfocus = function(){
    oTip[2].style.visibility = 'visible'
    this.onblur = function(){
        sflag[0] = isLegal(0,this,ico3,oTip[2],sflag[0]);

    }
}
oPwd[1].onfocus = function(){
    oTip[3].style.visibility = 'visible';
    this.onblur = function(){
        sflag[1] = isLegal(1,this,ico4,oTip[3],sflag[1]);
    }
}
oPwd[2].onfocus = function(){
    this.onblur = function(){
        if(this.value == oPwd[1].value){
            ico5[0].style.visibility = 'visible';
            ico5[1].style.visibility = 'hidden';
            sflag[2] = 1;
        }else{
            ico5[0].style.visibility = 'hidden';
            ico5[1].style.visibility = 'visible';
        }
    }
}

// 绑定
oBtn[0].onclick = function (){

    if(lflag[0] && lflag[1]){
        let url = "http://localhost:8080/web_war_exploded/controller/LoginServlet";
        let data = {
            email : oEmail[0].value,
            psw : oPwd[0].value,
        }
        Pajax(url,data,function(res){
            res = JSON.parse(res);
            Msg.style.display = "block";
            msg_a.innerHTML = res.msgs;
            msg_btn.addEventListener("click", function () {
                Msg.style.display = "none";
            })
            if(res.code == 1) {
                window.localStorage.setItem("email",res.email);
                window.localStorage.setItem("username",res.username);
                window.localStorage.setItem("phone",res.phone);
                window.localStorage.setItem("age",res.age);
                window.localStorage.setItem("sex",res.sex);
                window.localStorage.setItem("headimg",res.imgPath);
                window.location.href = "./template/homePage.html"
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
        let url = "http://localhost:8080/web_war_exploded/controller/RegisterServlet";
        let data = {
            email : oEmail[1].value,
            psw : oPwd[1].value,
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



