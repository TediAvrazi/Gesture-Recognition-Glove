const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
  <html>
    <style>
    body {
  	background-image: url('https://imgur.com/K0lYq7I.jpg');
	}
    
    .container
    {
      display: flex;
      flex-flow: row wrap;
      justify-content: space-around;
      position:absolute;
  	  top: 0; bottom: 0; left: 0; right: 0;
  	  margin: auto;
      height: 550px;
    }
    
    .card
    {
       	min-width: 700px;
        min-height: 100px;
        max-width: 1200px;
        max-height: 400px;
        background: navy;
        padding: 40px;
        color: #FFF;
        border-radius: 5px;
        box-shadow: 0px 5px 25px -4px rgba(0,0,0,0.75);
        font-family: Garamond, serif;
        margin: 20px;
        float: none;
      }
      
      .center
      {
        text-align: center;
        font-size: 35px;
        font-family: Garamond, serif;
      }
      
      .page-header 
      {
      position: fixed;
      left: 0;
      top: 0;
      width: 100%;
      padding:10px 0;
      background-color: #4682B4;
      color: white;
      text-align: center;
      font-family: Garamond, serif;
      font-size: 30px;
      }
      
      .card-header 
      {
      text-align: center;
      color: white;
      font-family: Garamond, serif;
      font-size: 40px;
      }
      
      .card-footer
      {
        position: fixed;
        left: 0;
        bottom: 0;
        width: 100%;
        padding:10px 0;
        background-color: #4682B4;
        color: white;
        text-align: center;
        font-size: 30px;
        font-family: Garamond, serif;
      }
        
    </style>
    
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link rel = "icon" href = "https://imgur.com/CxwyZr6.png" type = "image/x-icon">
      <link rel="stylesheet" href="https://imgur.com/CxwyZr6.png">
      <title>ESP32 Web Sever</title>
    </head>
    
    <body>
    	<div class="page-header">ESP32 Monitor</div>
        
      	<div class="container">
        	<div class="card">
          		<h3 class="card-header">Gesture Recognition Glove</h4><br>
          		<h5 class="center">Translated Gesture: <span id="gestureReadings"></span></h1>
           </div>
       </div>   
        
        <div class="card-footer"> 
        Created and designed by Tedi Avrazi
        </div>
    </body>
    
 <script>

setInterval(function() 
{
  // Call a function repetatively with half a second interval
  getData();
}, 500); //500 mSeconds update rate

function getData() 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() 
  {
    if (this.readyState == 4 && this.status == 200) 
    {
      document.getElementById("gestureReadings").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "read_gesture", true);
  xhttp.send();
}
  </script>
</html>
)rawliteral";