# Find-Decreasing-Sub-ranges-in-a-window-
N days of average home sale price data, and a fixed window size K are given . For each window of K days, from left to right, find the number of increasing subranges within the window minus the number of decreasing subranges within the window.

A window of days is defined as a contiguous range of days. Thus, there are exactly N-K+1 windows where this metric needs to be computed. An increasing subrange is defined as a contiguous range of indices [a,b], a < b , where each element is larger than the previous element. A decreasing subrange is similarly defined, except each element is smaller than the next.

Constraints

1 ≤ N ≤ 200,000 days
1 ≤ K ≤ N days

Output Format

Your solution should output one integer for each window’s result, with each integer on a separate line, to an output file or to the console.

Sample Input

5 3
188930 194123 201345 154243 154243

Sample Output

3
0
-1
