function ajaxRequest(type, request, callback, data = null)
{
  var xhr;

  // Create XML HTTP request.
  xhr = new XMLHttpRequest();
  if (type == 'GET' && data != null)
    request += '?' + data;
  xhr.open(type, request, true);

  // Add the onload function.
  xhr.onload = function(){
    switch (xhr.status){

      case 200:
      case 201:
        callback(xhr.responseText);
        break;
    }
  };

  // Send XML HTTP request.
  xhr.send(data);
}