function isLegal(type,obj,ico,otip,flag){
    if(type == 0){
        var legal = /^\w+@[a-z0-9]+\.[a-z]+$/i;
    }else{
        var legal = /\w{8}/;
    }
    
    if(legal.test(obj.value)){
        flag++;
        ico[0].style.visibility = 'visible';
        ico[1].style.visibility = 'hidden';
        otip.style.visibility = 'hidden';
    }else{
        ico[0].style.visibility = 'hidden';
        ico[1].style.visibility = 'visible';
        otip.style.visibility = 'visible'
    }
    return flag;
}



window.onload = function (){
    var sflag = 0;
    var lflag = 0;
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
    oLogin.onclick = function(){
        oLogin.style.background = "#00d2ff";
        oSignup.style.background = "#928DAB";
        oForm1[0].style.visibility = "visible";
        oForm1[0].style.opacity = 100;
        oForm2[0].style.opacity = 0;
        oForm2[0].style.visibility = "hidden";
    }
    
    oSignup.onclick = function(){
        oSignup.style.background = "#00d2ff";
        oLogin.style.background = "#928DAB";
        oForm2[0].style.visibility = "visible";
        oForm2[0].style.opacity = 100;
        oForm1[0].style.opacity = 0;
        oForm1[0].style.visibility = "hidden";
    }

    oUser[0].onfocus = function(){
        oTip[0].style.visibility = 'visible'
        this.onblur = function(){
            lflag = isLegal(0,this,ico1,oTip[0],lflag);
            
        }
    }
    oPw[0].onfocus = function(){
        oTip[1].style.visibility = 'visible';
        this.onblur = function(){
            lflag = isLegal(1,this,ico2,oTip[1],lflag);
        }
    }
    oUser[1].onfocus = function(){
        oTip[2].style.visibility = 'visible'
        this.onblur = function(){
            sflag = isLegal(0,this,ico3,oTip[2],sflag);
            
        }
    }
    oPw[1].onfocus = function(){
        oTip[3].style.visibility = 'visible';
        this.onblur = function(){
            sflag = isLegal(1,this,ico4,oTip[3],sflag);
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
                sflag++;
            }else{
                ico5[0].style.visibility = 'hidden';
                ico5[1].style.visibility = 'visible';
                oTip[4].style.visibility = 'visible'
                oTip[4].innerHTML = "两次密码不一致"
            }
        }
    }

    oBtn[0].onclick = function (){
        if(lflag >= 1){
            alert("登陆成功！");
            
        }else{
            alert("请输入正确的用户名和密码！");
            return false;
        }
    }
    oBtn[1].onclick = function (){
        if(sflag >2){
            alert(sflag);
            alert("注册成功！");
        }else{
            alert("请输入正确的用户名和密码！");
            return false;
        }
    }
    
}

