/**
 * @param {number} n
 * @return {Function} counter
 */
// let cnt=0;
var createCounter = function(n) {
    
    return function() {
        // let cnt;
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */