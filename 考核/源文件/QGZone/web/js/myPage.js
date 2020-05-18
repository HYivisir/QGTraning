let unlogin = document.getElementById("unlogin"),
showPage = document.getElementById("showPage"),
alterPage = document.getElementById("alterPage"),
infos = document.getElementsByClassName("infos"),
input_infos = document.getElementsByClassName("input-infos"),
headImg = document.getElementById("head-img");

// 判断是否登录
if(email == null){
    unlogin.style.display = "block";
    showPage.style.display = "none";
    headImg.style.display = "none";
}else{
    infos[1].innerHTML = username;
    infos[2].innerHTML = sex;
    infos[3].innerHTML = age;
    infos[4].innerHTML = phone;
    infos[5].innerHTML = email;
    if(headimg != "undefined"){
        headImg.style.backgroundImage = "url(" + headimg + ")";
    }
};


let head = document.getElementById("head-img");
if(email == null){
    head.onclick = function (){
        window.location.href = "../index.html";
    }
}else{
    let imgurl = headimg.split("blob:");
    head.style.backgroundImage = "url("  + imgurl[1] + ")";
}
// 修改头像
// 获取头像绝对路径
function getObjectURL(file) { 
    var url = null; 
    if (window.createObjcectURL != undefined) { 
        url = window.createOjcectURL(file); 
    } else if (window.URL != undefined) { 
        url = window.URL.createObjectURL(file);
    } else if (window.webkitURL != undefined) { 
        url = window.webkitURL.createObjectURL(file); 
    } 
    return url; 
}
// let head = document.getElementById("head-img");
let headBtn = document.getElementById("head-up");
if(email == null){
    headBtn.style.display = "none";
    head.onclick = function (){
        window.location.href = "../index.html";
    }
}else{
    headBtn.style.display = "block";
    headBtn.onchange = function (){
        let imgUrl = getObjectURL(this.files[0]);
        let url2 = "http://localhost:8080/web_war_exploded/controller/AlterHeadImg";
        let data2 = {
            email : email,
            headImg : imgUrl,
        }
        Pajax(url2,data2,function (res){
            res = JSON.parse(res);
            if(res.code == 1){
                window.localStorage.setItem("headimg",imgUrl);
                alert(res.msgs);
                // let temp = res.headimg.split("blob:");
                head.style.backgroundImage = "url("  + imgUrl + ")";
            }
        })
        

    }
}

// 修改信息
let alterBtn = document.getElementsByClassName("alter-infos");
let Msg = document.getElementById("msg"),
msg_btn = document.getElementById("msg_btn"),
msg_a = document.getElementById("msg_a");


alterBtn[0].onclick = function (){
    showPage.style.display = "none";
    alterPage.style.display = "block";
    input_infos[0].value = username;
    document.getElementById("sex-select").value = sex;
    input_infos[1].value = age;
    input_infos[2].value = phone;
    infos[6].innerHTML = email;
}

alterBtn[1].onclick = function (){
    // 提交信息至服务器
    let data = {
        email : infos[6].innerHTML,
        username : input_infos[0].value,
        age : input_infos[1].value,
        phone : input_infos[2].value,
        sex : document.getElementById("sex-select").value,    
    };
    let url = "http://localhost:8080/web_war_exploded/controller/AlterInfosServlet"
    Pajax(url,data,function (res){
        res = JSON.parse(res);
        if(res.code == 1){
            window.localStorage.setItem("email",data.email);
            window.localStorage.setItem("username",data.username);
            window.localStorage.setItem("age",data.age);
            window.localStorage.setItem("phone",data.phone);
            window.localStorage.setItem("sex",data.sex);
            showPage.style.display = "block";
            alterPage.style.display = "none";
            Msg.style.display = "block";
            msg_a.innerHTML = res.msgs;
            msg_btn.addEventListener("click", function () {
                Msg.style.display = "none";
                location.reload();
            });
        }else{
            Msg.style.display = "block";
            msg_a.innerHTML = res.msgs;
            msg_btn.addEventListener("click", function () {
                Msg.style.display = "none";
            });
        }
    })
    
}