//判断是否登录
let unlogin = this.document.getElementById("unlogin");
let logined = this.document.getElementById("logined");
let diarySearch = document.getElementById("diary-search");
let diaryList = document.getElementById("diary-panel");
let right = document.getElementById("right-space");
if(email == null){
    unlogin.style.display = "block";
    logined.style.display = "none";
    diarySearch.style.display = "none";
    right.style.display = "none";
}else{
    unlogin.style.display = "none";
    logined.style.display = "block";
    diarySearch.style.display = "block";
    right.style.display = "block";
}

// 获取日志
let url1 = "http://localhost:8080/web_war_exploded/controller/GetAllDiary";
let data1 = {
    email : email,
}
Pajax(url1,data1,function (res){
    let arr = res.split(" ");
    for(let i=0;i<arr.length;i++){
        let json = JSON.parse(arr[i]);
        let allDiary = document.getElementById("all-diary");
        let liDiary = document.createElement("li");
        let liName = document.createElement("a");
        let liTag = document.createElement("a");
        let liDate = document.createElement("a");
        liDiary.setAttribute("class","diary");
        liName.setAttribute("class","diary-name");
        liTag.setAttribute("class","diary-tag");
        liDate.setAttribute("class","diary-date");
        liName.innerHTML = json.d_name;
        liTag.innerHTML = json.d_tag;
        liDate.innerHTML = json.d_date;
        liDiary.setAttribute("context",json.d_text);
        liDiary.appendChild(liName);
        liDiary.appendChild(liTag);
        liDiary.appendChild(liDate);
        allDiary.appendChild(liDiary);
    }
    
})



// 写日志
let addBtn = document.getElementById("add-diary");
let editPanel = document.getElementById("edit-panel");
let editSave = document.getElementById("edit-save");
addBtn.onclick = function (){
    diaryList.style.display = "none";
    diarySearch.style.display = "none";
    editPanel.style.display = "block";
    editSave.style.display = "block";
}

// 上传日志
let saveName = document.getElementById("diary-name");
let saveTag = document.getElementById("diary-tag");
let date = new Date();
let saveContext = document.getElementById("diary-context");
let saveBtn = document.getElementById("save-btn");
// 获取日期
if(date.getDate()<10){
    if(date.getMonth()+1 < 10){
        var saveDate =  "" + date.getFullYear() + "0" + (date.getMonth()+1) + "0" + date.getDate();
    }else{
        var saveDate =  "" + date.getFullYear() + (date.getMonth()+1) + "0" + date.getDate();
    }
}else{
    var saveDate =  "" + date.getFullYear() + "0" +(date.getMonth()+1) + date.getDate();
}

saveBtn.onclick = function (){
    if(saveName.value == ""){
        alert("日志名不能为空！");
    }else{
        let data = {
            email : email,
            d_name : saveName.value,
            d_date : saveDate,
            d_text : saveContext.value,
            d_tag : saveTag.value,
        }
        let url = "http://localhost:8080/web_war_exploded/controller/DiaryServlet";
        Pajax(url,data,function (res){
            res = JSON.parse(res);
            if(res.code == 1){
                alert(res.msgs);
                location.reload();
            }else{
                alert("网络连接错误");
            }
        })
    }    
}
// 取消编辑
let quitBtn = document.getElementById("quit-btn");
let msgbox = document.getElementById("msg");
let msg_yes = document.getElementById("msg_btn");
let msg_no = document.getElementById("cancel_btn");
quitBtn.onclick = function (){
    msgbox.style.display = "block";
    msg_yes.onclick = function (){
        diaryList.style.display = "block";
        diarySearch.style.display = "block";
        editPanel.style.display = "none";
        editSave.style.display = "none";
        msgbox.style.display = "none";
    }
    msg_no.onclick = function (){
        msgbox.style.display = "none";
    }
}

// 阅读日志
let diarys = document.getElementsByClassName("diary");
let readerPanel = document.getElementById("reader-panel");
let returnBtn = document.getElementById("return-btn");
let diaryName = document.getElementsByClassName("diary-name");
let diaryTag = document.getElementsByClassName("diary-tag");
let diaryDate = document.getElementsByClassName("diary-date");
let readerName = document.getElementById("reader-name");
let readerTag = document.getElementById("reader-tag");
let readerDate = document.getElementById("reader-date");
let tip = document.getElementById("tip");
let rightSpace = document.getElementById("right-space");
function clickDiarys(){
    let diarys = document.getElementsByClassName("diary");
    let readerPanel = document.getElementById("reader-panel");
    let diaryName = document.getElementsByClassName("diary-name");
    let diaryTag = document.getElementsByClassName("diary-tag");
    let diaryDate = document.getElementsByClassName("diary-date");
    let readerName = document.getElementById("reader-name");
    let readerTag = document.getElementById("reader-tag");
    let readerDate = document.getElementById("reader-date");
    let readerContext = document.getElementById("reader-context");
    for(var i=0;i<diarys.length;i++){
        let index = i;
        diarys[i].onclick = function (){
            this.style.animation = "click 1s ease"
            setTimeout(() => {
                readerPanel.style.display = "block";
                diaryList.style.display = "none";
                diarySearch.style.display = "none";
                rightSpace.style.display = "none";
                tip.style.display = "none";
                readerName.value = diaryName[index].innerHTML;
                readerTag.value = diaryTag[index].innerHTML;
                readerDate.value = diaryDate[index].innerHTML; 
                readerContext.value = this.getAttribute("context");
            }, 1000);
        }
    }
}

returnBtn.onclick = function (){
    for(let i=0;i<diarys.length;i++){
        diarys[i].style.animation = "";
    }
    readerPanel.style.display = "none";
    diaryList.style.display = "block";
    diarySearch.style.display = "block";
    rightSpace.style.display = "block";
    tip.style.display = "block";
} 


// 搜索日志
let inputSearch = document.getElementById("input-tag");
let inputBtn = document.getElementById("input-btn");

inputBtn.onclick = function (){
    let target = inputSearch.value;
    let keyword = target.split(' ');
    for(var i=0;i<diaryName.length;i++){
        diarys[i].style.display = "none";
        for(var j=0;j<keyword.length;j++){
            if(!diaryName[i].innerHTML.search(keyword[j])){
                diarys[i].style.display = "inline-flex";
                break;
            }
        }
        
    }
}

// 建立分类日志
function buildTags(){
    let diaryTag = document.getElementsByClassName("diary-tag");
    let tagList = document.getElementById("tag-list");
    let tagArr = new Array();
    for(var i=0;i<diaryTag.length;i++){
        tagArr.push(diaryTag[i].innerHTML);
    }
    tagArr.sort();
    let newArr = [tagArr[0]];
    let j = 1;
    for(var i=1;i<tagArr.length;i++){
        if(newArr[j-1] != tagArr[i]){
            j++;
            newArr.push(tagArr[i]);
        }
    };
    for(var i=0;i<newArr.length;i++){
        let tag = document.createElement("li");
        tag.setAttribute("class","tag-op");
        tag.innerHTML = newArr[i];
        tagList.appendChild(tag);
    }

}

// 分类日志
function classifyTag(){
    let tags = document.getElementsByClassName("tag-op");
    let diarys = document.getElementsByClassName("diary");
    let tagName = document.getElementsByClassName("diary-tag");
    for(let i=0;i<tags.length;i++){
        tags[i].onclick = function (){
            for(var k=0;k<diarys.length;k++){
                diarys[k].style.display = "none";
                if(this.innerHTML == tagName[k].innerHTML){
                    diarys[k].style.display = "inline-flex";
                }
            }
        }
    }
}
window.onload = function (){
    clickDiarys();
    setTimeout(buildTags(),1000);
    setTimeout(classifyTag(),1000);
}

