var mongo = require('mongodb').MongoClient;
var age = process.argv[2];

var url = 'mongodb://localhost:27017/learnyoumongo';

mongo.connect(url, function(err, db) {
  var parrots = db.collection('parrots');
  parrots.find({
    age: {
      $gt: +age
    }
  }).toArray(function(err, data) {
    console.log(data);
    db.close();
  });
});