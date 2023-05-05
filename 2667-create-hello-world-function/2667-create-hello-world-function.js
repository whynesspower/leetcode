/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(...args) {
        var s= "Hello World";
        return s;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */