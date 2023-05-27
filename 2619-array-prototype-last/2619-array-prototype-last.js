Array.prototype.last = function() {
    if(this.length===0){
        return -1;  
    } 
    else{
        var indx=this.length-1;
        return this[indx];
    }
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */