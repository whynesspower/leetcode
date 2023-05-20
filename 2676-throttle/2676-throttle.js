/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
    var shouldCall=true;
    var prevArgs;
    
    function solve(){
        if(shouldCall && prevArgs){
            fn(...prevArgs);
            shouldCall=false;
            prevArgs=null;
            setTimeout(()=>{
                shouldCall=true;
                solve();
            }, t);
        }
    }
    
    
    return function(...args) {
        prevArgs=args;
        solve();
  }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */