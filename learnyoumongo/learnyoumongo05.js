var mongo = require('mongodb').MongoClient
var firstName = process.argv[2]
var lastName = process.argv[3]
var param = {
  firstName: firstName
, lastName: lastName
}

var url = 'mongodb://localhost:27017/learnyoumongo'
mongo.connect(url, function(err, db) {
  var collection = db.collection('docs')
  collection.insert(doc, function(err, data) {
    console.log(JSON.stringify(doc))
    db.close()
  })
})