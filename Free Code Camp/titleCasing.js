function titleCase(str) {

  //reduce the string to lower case
  str = str.toLowerCase();
  
  //split the string into an array so we can run an equation on each key
  var array = str.split(" ");
  
  //iterating through the array
  for (i=0; i < array.length; i++) 
  {
      
    //store a capitalized version of the first char in the word
      var z = array[i].charAt(0).toUpperCase();
    
    //replace the first char of the word with X
    array[i] = array[i].replace(array[i].charAt(0), z);
  }
  
  //join each word in the array into a single string
  str = array.join(' ');
  
  return str;
                   
}

titleCase("I'm a little tea pot");