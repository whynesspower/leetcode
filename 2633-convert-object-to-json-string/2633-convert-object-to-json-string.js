var jsonStringify = function(object) {
  // Check if the object is a string
  if (typeof object === 'string') {
    // Add double quotes around the string and escape special characters
    return '"' + object.replace(/"/g, '\\"') + '"';
  }
  // Check if the object is a number, boolean, or null
  else if (typeof object === 'number' || typeof object === 'boolean' || object === null) {
    // Convert the value to a string and return it
    return String(object);
  }
  // Check if the object is an array
  else if (Array.isArray(object)) {
    var arr = [];
    // Iterate over the array elements
    for (var i = 0; i < object.length; i++) {
      // Recursively call jsonStringify on each element and add it to the array
      arr.push(jsonStringify(object[i]));
    }
    // Join the array elements with commas and enclose them in square brackets
    return '[' + arr.join(',') + ']';
  }
  // Check if the object is a regular object
  else if (typeof object === 'object') {
    var keys = Object.keys(object);
    var obj = [];
    // Iterate over the object properties
    for (var i = 0; i < keys.length; i++) {
      var key = keys[i];
      var value = jsonStringify(object[key]);
      // Enclose the key and value in double quotes and add them to the object
      obj.push('"' + key + '":' + value);
    }
    // Join the object properties with commas and enclose them in curly braces
    return '{' + obj.join(',') + '}';
  }
};
