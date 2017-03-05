var express = require('express');
var app = express();

var port = process.env.PORT || 8080;
var status = false;
var secret_id = "segreto";

app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});

app.get('/', function (req, res) {
  res.send('Hello World, please use a GET /getState to see the current state of the library');
});

app.get('/getState', function (req, res) {
  res.send(JSON.parse(status));
});



app.post('/updateState', function (req, res) {
  var token = req.param('secret_id');
  var update = req.param('status');
  if (token==secret_id) {
    status = update;
    res.send("OK");
  }else {
    res.send("NO");
  }
  });


var server = app.listen(port, function () {
  var host = server.address().address;
  var port = server.address().port;
  console.log('Server listening at http://%s:%s', host, port);
});
