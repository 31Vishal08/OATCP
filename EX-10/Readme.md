The total Hamming distance is constructed bit by bit in this approach.

Let's take a series of number: a1, a2, a3,..., an

Just think about all the Least Significant Bit (LSB) of a(k) (1 ≤ k ≤ n).

How many Hamming distance will they bring to the total?

1. If a pair of number has same LSB, the total distance will get 0.

2. If a pair of number has different LSB, the total distance will get 1.

For all number a1, a2, a3,..., a(n), if there are p numbers have 0 as LSB (put in set M), and q numbers have 1 for LSB (put in set N).

There are 2 situations:

Situation 1. If the 2 number in a pair both comes from M (or N), the total will get 0.

Situation 2. If the 1 number in a pair comes from M, the other comes from N, the total will get 1.

Since Situation 1 will add NOTHING to the total, we only need to think about Situation 2

How many pairs are there in Situation 2?

We choose 1 number from M (p possibilities), and 1 number from N (q possibilities).

The total possibilities is p × q = pq, which means

The total Hamming distance will get pq from LSB.
If we remove the LSB of all numbers (right logical shift), the same idea can be used again and again until all numbers becomes zero

Time complexity
In each loop, we need to visit all numbers in nums to calculate how many numbers has 0 (or 1) as LSB.

If the biggest number in nums[] is K, the total number of loop is [logK] + 1.

So, the total time complexity of this approach is O(n).

