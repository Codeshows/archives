# Codeshows Contest 3 Editorial

## Coding Problems
### Paparazzi
#### Approach
We need to notice that we decide to stay on the day `D`, all the people whose range includes this point will be happy on this day.
Consider a single range `[L, R]`, any `X` days from `L` to `R` if included will increase the total happiness by `X`. 
So we can take an `M` sized array and for each range, add 1 to all positions in the range `[L, R]` signifying that if some day `D` is included, the total happiness will increase by the number of people that will be happy if this day is included.

To understand this visually, take the sample
```
3 7 3
1 2
6 7
4 5
```

Take 7 days, initially have all 0  
Then for each range add 1 in the range `[L, R]`
```
1 2 3 4 5 6 7
0 0 0 0 0 0 0 - Initially
1 1 0 0 0 0 0 - [1, 2]
1 1 0 0 0 1 1 - [6, 7]
1 1 0 1 1 1 1 - [4, 5]
```

If we pick the days [2, 4], we can get a happiness of 2, we recieve 1 happiness from person 1, and 1 from person 3.
If we pick the days [4, 6], we can get a happiness of 3, we recieve 2 happiness from person 2, and 1 from person 3.

Then we can try to pick all `K` consecutive days and pick the one with maximum total happiness.
What is the happiness in a range? The sum of the happiness on all the individiual days in that range.

#### Implementation
How to build the required array?  

Trivially this can be done by simple looping but that will time out.  
We can use the concept of a difference array which will help us update a range in constant time.  
For each range, we can `increment A[L]` and `decrement A[R + 1]`.  
Then build a prefix sum of this array to build the required array.

How to find the total happiness of a selected range?

We need to know what is the happiness in range `[i, i + K - 1]`.  
We know it is equal to the total sum of the numbers in that range.  
So once again we can build a prefix sum of this array.  
Then, `sum[L, R] = sum[1, R] - sum[1, L-1]`

Overall the problem can thus be solved in `O(M)` time.

### Chef Troubles 
#### Approach
Try to solve this problem for a single ingredient first.  
Suppose we want to make a dish with quality `at least X`, this means the ingredient must have a quality `at least X`. And out of all the shops that sell the ingredient with quality `at least X` we must pick the shop that sells it at the `least price P`. 

Let us see what happens if we try to make a dish with quality at least,

- `X' such that X' > X`  
The new price of the dish will be, `P'>= P`
- `X' such that X' < X`  
The new price of the dish will be, `P'<= P`

This means we can apply `Binary Search` to find the `largest X`, such that `P <= Budget`

If `P > Budget`, we need to find a `smaller X`  
If `P <= Budget`, we need to find a `larger X`

We can apply this same idea for multiple ingredients.  
We pick a quality `X`, for each ingredient we buy from the shop, that sells the ingredient at `quality at least X` and has the `least price`.

The running time of this approach is `O(N * M * log(maxQ))`, where maxQ is the maximum quality present.

### An Endless Cycle
#### Approach
The PIN only consist of **4** digit numbers. So we can loop through all 4 digit numbers.  
Then check how many of these numbers can be the PIN.  
To be a valid PIN, it must satisfy all the guesses, i.e. when matched against all the guesses, it must produce the correct amount of the green flickers `x` and yellow flickers `y`.  

If the number of PINs that satisfy all guesses are,
- `0`, this means the information is incorrect
- `> 1`, then we need to more more guesses
- `1`, there is only one valid PIN, it is the required answer

It can be implemented as a naive brute force in `O(10^4 * N * D^2)`, where D are the number of digits, in this case D = 4.  
Giving us an order of roughly `O(10^6)`.

## MCQs
### Ques 1
![Q1](/mcq/1.jpg)

Since sum of digits is 3 the number is divisible by 3 so there exists no number other than 3 which is prime.

### Ques 2
![Q2](/mcq/2.jpg)

We can choose any of two h,a,d;  
2c1 * 2c1 * 2c1 = 8

### Ques 3
![Q3](/mcq/3.jpg)

For any prime number p (p-1)!%p=p-1. We know 1e9+7 is a prime number so answer will be 1e9+6.

### Ques 4
![Q4](/mcq/4.jpg)

We can divide 200 people into 2 groups of 196 people and 4 people.  
One of those 4 people can communicate with 196 so he has message of himself and 196 people.  
Now in 4 round these 4 people can share the message among themselves (How?)
Figure out.  
Now one of those 4 people can communicate with 196 people to share the message of those 4 people.

### Ques 5
![Q5](/mcq/5.jpg)

Since i is added 1 at first time 2 at first time how many steps does it take to reach n?  
Let us assume it takes x steps we know  
1+2+... x= x * (x+1)/2  
This must be approximately equal to n  
x * (x+1)/2=n;  
x * (x+1)=2 * n  
x^2 +x =2 * n  
x is proptional to (n)^(½)  

### Ques 6
![Q6](/mcq/6.jpg)

If there is one cycle there will be infinite because graph has reached same node again.  
Since this process will always result in making an power of 4 so you will never get an loop.  
You can write this code and it will never TLE for feasible n so you can get a verification.  
EX:  
3->10->5->16->8->2->1  

### Ques 7
![Q7](/mcq/7.jpg)

Answer is 0 because any number raised to power 4 mod 16 is either 0 or 1.  
So there are 10 elements so SUMMATION(a[i])%16 can be in range [0,10] but,  
65532%16=12 so there is no way to reach there.  

### Ques 8
![Q8](/mcq/8.jpg)

There is no such triplet.

### Ques 9
![Q9](/mcq/9.jpg)

First number is divisible by 3.  
Second is divisible by 11 as difference between sum of elements at even and odd indices is k * 11.  
45 is divisible by 3.

### Ques 10
![Q10](/mcq/10.jpg)

1 2 3  
1 2 6  
1 5 6  
4 5 6  
There four subsequences form string “ans”.  