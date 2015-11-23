var mongo = require('mongodb').MongoClient;
var url = 'mongodb://localhost:27017/learnyoumongo';
var size = process.argv[2];
var match = {$match: {status: "A"}};
var group = 

mongo.connect(url, function(err, db) {
  var collection = db.collection("prices");
  collection.aggregate([
  	{$match: {size: size}},
  	{$group: {
  		_id: "total",
  		total:{
  			$avg: "$price"
  		}
  	}}]).toArray(function(err, results){
  		var res = results[0];
  		console.log(Number(res.total).toFixed(2));
  		db.close();
  	})
  });

//avg price for all documents in 'prices'