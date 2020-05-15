let audio = document.getElementById("audio");
let play = document.getElementById("play");
let flag = true;
play.onclick = function (){
    if(flag){
        audio.play();
        play.style.background = "url('../img/icon/pause.png') no-repeat";
        flag = false;
    }else{
        audio.pause();
        play.style.background = "url('../img/icon/play.png') no-repeat";
        flag = true;
    }
}

// 拖拽
let player = this.document.getElementById("player");
player.onmousedown = function (ev){
    var oevent = ev||event;
    var disx = oevent.clientX - player.offsetLeft;
    var disy = oevent.clientY - player.offsetTop;

    player.onmousemove = function (ev){
        var oevent = ev||event;
        var oleft = oevent.clientX - disx;
        var otop = oevent.clientY- disy;
        var bwidth = document.documentElement.clientWidth - player.offsetWidth;
        var bheight = document.documentElement.clientHeight - player.offsetHeight;
        if(oleft<0){
            oleft = 0;
        }
        else if(oleft>bwidth){
            oleft = bwidth;
        };
        if(otop<0){
            otop = 0;
        }
        else if(otop>bheight){
            otop = bheight;
        };
        player.style.left = oleft + 'px';
        player.style.top = otop  + 'px';
    };

    document.onmouseup = player.onmouseup = function (){
        player.onmousemove = null;
        player.onmouseup = null;
    }

};
