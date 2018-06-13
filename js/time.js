setInterval(ajaxRequest, 1000, 'GET', 'php/time.php', displayClock);


function displayClock(ajaxResponse)
{
  var time;

  time = JSON.parse(ajaxResponse);

  $('#time').html(time[0].minutes + ":" + time[0].seconds);