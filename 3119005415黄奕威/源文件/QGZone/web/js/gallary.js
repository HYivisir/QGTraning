
let unlogin = this.document.getElementById("unlogin");
let logined = this.document.getElementById("logined");
let skims = document.getElementById("img-skim");
let right = document.getElementById("right-space");
// 判断是否登录
if(email == null){
    unlogin.style.display = "block";
    logined.style.display = "none";
    skims.style.display = "none";
    right.style.display = "none";
}else{
    unlogin.style.display = "none";
    logined.style.display = "block";
    skims.style.display = "block";
    right.style.display = "block";
}


var gallary = document.getElementById("gallary");
var imgs = document.getElementsByClassName("g-skim");
// 给每个缩略图放大
for(var i=0;i<imgs.length;i++){
    imgs[i].onclick = function (){
        gallary.src = this.getAttribute('real_src');            
    }
}

// 图片懒加载
// 获取图片路径
function setSrc(img){
    var temp = new Image();
    temp.src = img.getAttribute('real_src');
    temp.onload = function(){
        img.src = img.getAttribute('real_src');
    }
}
function lazyload(pics){
    // 可视区
    let skims_h = skims.clientHeight;
    // 滚动区
    let skims_s = skims.scrollTop;
    for(var i=0;i<pics.length;i++){
        // 顶部区域小于可视区加滚动区
        if((skims_h + skims_s)>pics[i].offsetTop){
            // 延时
            setTimeout(setSrc(pics[i]),5000);    
        }
    }
}
lazyload(imgs);
skims.onscroll = function (){
    lazyload(imgs);
}

// 大图
gallary.src = imgs[0].getAttribute('real_src');
// 轮播
let LBtn = document.getElementById("pre");
let RBtn = document.getElementById("nex");
var pic_i = 0
LBtn.onclick = function (){
    if(pic_i==0){
        pic_i = imgs.length - 1;
        gallary.src = imgs[pic_i].getAttribute('real_src');
    }else{
        pic_i--;
        gallary.src = imgs[pic_i].getAttribute('real_src');
    }
}
RBtn.onclick = function (){
    if(pic_i == imgs.length -1){
        pic_i = 0;
        gallary.src = imgs[pic_i].getAttribute('real_src');
    }else{
        pic_i++;
        gallary.src = imgs[pic_i].getAttribute('real_src');
    }
}

// 按钮美化
let fileBtn = this.document.getElementById("file-upload");
let show = document.getElementById("show")
fileBtn.onchange = function(){
    let fname=this.files[0].name;
    show.innerHTML = "已选择" + fname + "等文件";
};


// 上传图像
// 获取图片地址
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
let uploadBtn = document.getElementById("up-btn");

uploadBtn.onclick = function (){
    if(fileBtn.files[0] == undefined){
        alert("请选择文件，老哥");
    }else{
        let url = "http://localhost:8080/web_war_exploded/controller/PhotoServlet";
        let data = {
            email : email,
            imgUrl : getObjectURL(fileBtn.files[0]),
        }
        Pajax(url,data,function (res){
            res = JSON.parse(res);
            alert(res.msgs);
            location.reload();
        })
    }
    
}

// 获取所有图片
function getAllPhotos(){
    let url2 = "";
    let data2 = {
        email : email,
    }
    Pajax(url2,data2,function (res){
        let arr = res.split(" ");
        for(let i=0;i<arr.length;i++){
            json = JSON.parse(arr[i]);
            let img = document.createAttribute("img");
            let imgSkim = document.getElementById("img-skim");
            img.setAttribute("class","g-skim");
            img.setAttribute("src","/web/img/default_img.jpg");
            img.setAttribute("real_src",json.imgUrl);
            imgSkim.appendChild(img);
        }
    })
}

window.onload = function (){
    this.getAllPhotos();
}