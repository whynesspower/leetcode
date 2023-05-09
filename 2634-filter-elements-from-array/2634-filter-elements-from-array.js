/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var ans=[];
    for(var i=0;i<arr.length;i++){
        var res= fn(arr[i],i);
        if(res){
            ans.push(arr[i]);
        }
    }
    return ans;
};