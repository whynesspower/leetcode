/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    var ans={};
    for(var i=0;i<this.length;i++){
        var a= fn(this[i]);
        if(typeof ans[a]==='undefined'){
            ans[a]=[this[i]];
        }
        else{
            ans[a].push(this[i]);
        }
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */