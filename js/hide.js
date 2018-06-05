
hide();

function hide(){
  var password= document.getElementById("pwd");
  var checkOut =document.getElementById("confirm-pwd");
  var checked = document.getElementById("show-pwd");

  if(checked.checked==true){
    password.type="text";
    checkOut.type="text";
  }

  else{
    password.type="password";
    checkOut.type="password";
  }
}
