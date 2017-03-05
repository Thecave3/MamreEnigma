$(document).ready(function(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
       document.getElementById("state").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET", "http://www.andrealacava.com:3002/getState", true);
    xhttp.send();
});
