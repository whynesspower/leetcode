```
Return a promise from the then handler that waits:
​
.then(() => new Promise(resolve => setTimeout(resolve, 1000)))
If you want to "pass through" the value of the promise, then
​
.then(x => new Promise(resolve => setTimeout(() => resolve(x), 1000)))
To avoid this boilerplate everywhere, write a utility function:
​
function sleeper(ms) {
return function(x) {
return new Promise(resolve => setTimeout(() => resolve(x), ms));
};
}
then use it as in
​
.then(sleeper(1000)).then(...)
```