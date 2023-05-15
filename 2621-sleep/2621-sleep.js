/**
 * @param {number} millis
 */
async function sleep(millis) {
    const myPromise = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve();
  }, millis);
});
    return myPromise;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */