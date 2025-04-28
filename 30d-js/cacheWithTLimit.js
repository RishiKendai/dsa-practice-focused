var TimeLimitedCache = function () {
    this.cache = new Map();
    this.timerRef = new Map();

};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
    // Check If Exists
    const existed = this.cache.has(key);
    // Iƒ exists => clear timeout
    if (existed) clearTimeout(this.timerRef.get(key));
    // Set new value and timeout
    this.cache.set(key, value);
    this.timerRef.set(key, setTimeout(() => this.cache.delete(key), duration));
    return existed;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {

};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {

};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */