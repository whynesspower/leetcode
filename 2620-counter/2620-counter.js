/**
 * @param {number} n
 * @return {Function} counter
 */
// let cnt=0;
var createCounter = function(n) {
    var count=n;
    return function() {
        // let cnt;
        var currcnt= count;
        count= count+1;
        return currcnt;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */