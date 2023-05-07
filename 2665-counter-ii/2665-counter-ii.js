/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var cnt=init||0;
    // var ini=init;
    var increment = ()=>{
        return ++cnt;
    };
    var decrement = ()=>{
        return --cnt;
    };
    var reset = ()=>{
        cnt=init||0;
        return cnt;
    };
    return {increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */