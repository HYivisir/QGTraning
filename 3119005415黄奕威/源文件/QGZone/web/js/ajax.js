// ajax
function Pajax(url,data,succfn,faildfn){
    var oajax = new XMLHttpRequest(); 

    oajax.open("POST",url,true);  //连接服务器

    oajax.setRequestHeader("Content-type","application/json"); //设置请求头
    oajax.send(JSON.stringify(data)); //发送报文
    oajax.onreadystatechange = function (){
        if(oajax.readyState == 4 && oajax.status == 200){  //读取完成
            succfn(oajax.responseText);
        }  
        else{
            if(faildfn){
                faildfn(oajax.status);
            }
        };
    };
};