
var TimeLimitedCache = function() {
    this.cache= new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    var findkey= this.cache.has(key);
    if(findkey){
        const [, timer] = this.cache.get(key);
        clearTimeout(timer);
    }
    var timeout= setTimeout(()=>{this.cache.delete(key);}, duration);
    this.cache.set(key, [value, timeout]);
    return findkey;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    var findkey= this.cache.has(key);
    if(!findkey){
        return -1;
    }
    const [ans, ]= this.cache.get(key);
    return ans;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */