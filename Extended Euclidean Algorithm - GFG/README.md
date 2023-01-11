# Extended Euclidean Algorithm
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">We already know Basic Euclidean Algorithm. Now using the&nbsp;<a href="https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/">Extended Euclidean Algorithm</a>, given a&nbsp;and b calculate the <strong>GCD</strong> and integer coefficients <strong>x, y.</strong>&nbsp;Using the same. x and y must satisfy the equation<strong> </strong></span><strong><span style="font-size:18px">ax + by = gcd(a, b) .</span></strong><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
a = 35
b = 15
<strong>Output:</strong>
5 1 -2</span><span style="font-size:18px">
<strong>Explanation:</strong>
gcd(a,b) = 5
35*1 + 15*(-2) = 5</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
a = 30
b = 20
<strong>Output:</strong>
10 1 -1
<strong>Explanation:</strong>
gcd(30,20) = 10
</span><span style="font-size:18px">30*(1) + 20*(-1) = 10</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>gcd()</strong>&nbsp;which takes&nbsp;an integer <strong>N</strong>&nbsp;as input parameters&nbsp;and returns array of three numbers containing gcd, x, y in the same order.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(log max(a,b))<br>
<strong>Expected Space Complexity:</strong> O(1)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= a,b &lt;= 10<sup>6</sup></span></p>

<p>&nbsp;</p>
</div>