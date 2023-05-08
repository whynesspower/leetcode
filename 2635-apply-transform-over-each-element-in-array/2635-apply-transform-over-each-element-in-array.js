/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    var ans=[];
    for(var i=0;i<arr.length;i++){
        var a = fn(arr[i], i);
        ans.push(a)
    }
    return ans;
};