let home_unlogin = document.getElementById("home_unlogin");
let home_logined = document.getElementById("home_logined");
// 检测登录状态
if(email == null){
    home_unlogin.style.display = "block";
    home_logined.style.display = "none";
}else{
    home_unlogin.style.display = "none";
    home_logined.style.display = "display";
    
}


let welPages = document.getElementsByClassName("welcome");
let up = document.getElementById("pre");
let down = document.getElementById("nex");
let distance = 0;
up.onclick = function (){
    if(distance != 0){
        distance+=100;
        for(let i=0;i<welPages.length;i++){
            welPages[i].style.transform = "translateY(" + distance + "%)";
        }
    }
}
down.onclick = function (){
    if(distance != -300){
        distance-=100;
        for(let i=0;i<welPages.length;i++){
            welPages[i].style.transform = "translateY(" + distance + "%)";
        }
    }
}