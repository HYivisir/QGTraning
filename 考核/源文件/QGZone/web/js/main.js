let email = window.localStorage.getItem("email"),
username = window.localStorage.getItem("username"),
sex = window.localStorage.getItem("sex"),
age = window.localStorage.getItem('age'),
phone = window.localStorage.getItem("phone"),
headimg = window.localStorage.getItem("headimg");


// 主题切换
let themeBtn = document.getElementById("themes");
let themeSelect = document.getElementById("theme-select");
let themes = document.getElementsByClassName("themes");
let themePart = document.getElementsByClassName("theme-part");
let themeBg = document.getElementsByClassName("theme-bg");
themeBtn.onmouseout = themeSelect.onmouseout = function (){
    var timer = setTimeout(() => {
        themeSelect.style.display = "none"
    }, 1500);
    themeBtn.onmouseover = themeSelect.onmouseover= function (){
        clearTimeout(timer);
        themeSelect.style.display = "block";
    }
}
themeBtn.onmouseover = themeSelect.onmouseover= function (){
    themeSelect.style.display = "block";
}

themes[0].onclick = function (){
    for(let i=0;i<themePart.length;i++){
        themePart[i].style.background = "#275cac";
        themeBg[0].style.background = "#000"
        canvas.style.width = "100%";
        canvas.style.height = "100%";
    }
}
themes[1].onclick = function (){
    for(let i=0;i<themePart.length;i++){
        themePart[i].style.background = "#16878d";
        themeBg[0].style.backgroundImage = "url('../img/green.jpg')";
        canvas.style.width = 0;
        canvas.style.height = 0;
    }
}
themes[2].onclick = function (){
    for(let i=0;i<themePart.length;i++){
        themePart[i].style.background = "#b04e4f";
        themeBg[0].style.background = "url('../img/red.jpg')";
        canvas.style.width = 0;
        canvas.style.height = 0;
    }
}
themes[3].onclick = function (){
    for(let i=0;i<themePart.length;i++){
        themePart[i].style.background = "#76528f";
        themeBg[0].style.background = "url('../img/purple.jpg')";
        canvas.style.width = 0;
        canvas.style.height = 0;
    }
}


// function setStyleSheet(href){
//     var doc_head = document.head;
//     // 找到所有的link标签
//     var link_list = document.getElementsByTagName("link");
//     if ( link_list ){
//         for ( var i=0;i<link_list.length;i++ ){
//             if ( link_list[i].getAttribute("type") === "theme" ){
//                 doc_head.removeChild(link_list[i]);
//             }
//         }
//     }
//     var link_style = document.createElement("link");
//     link_style.setAttribute("rel","stylesheet");
//     link_style.setAttribute("type","text/css");
//     link_style.setAttribute("href",title);
//     link_style.setAttribute("type","theme");
//     doc_head.appendChild(link_style);
// }
