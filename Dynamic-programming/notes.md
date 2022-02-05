# What is Dynamic Programming?

DP is a way of solving problems where you look for a possible solutions.

Characteristics of a DP problem:
* It can be broken down into smaller problems and these subproblems need to overlap i.e. one subproblems solution can be used to solve another. (talks about reusing subproblems' solution)
* It should have optimal substructure &rarr; optimal solution can be formed from smaller optimal solutions (which are solutions to subproblems)

Best example to understand DP is fibonacci sequence.

Difference between DP and greedy, greedy has optimal substructure but the subproblems don't overlap like DP.

Difference between DP and Divide and Conquer, D/C break problem into subproblems but the subproblems don't overlap.

# Top down and Bottom Up approaches
Bottom up aka tabulation

Top down aka memoization

### Bottom-up method
Here we calculate/find solution of the initial problem starting from the bottom or the base cases.

For example, in fibonacci sequence problem the base cases are f(0) = 0 and f(1) = 1 and we use these values to compute f(2) = f(1)+f(0) and then use f(2) to build till f(n) nth term. So here we are starting from zeroth and first term to build all the other times.

```
// pseudocode of fibonacci
f = array of elements
f(0) = 0
f(1) = 1
for i from 2 to n:
	f(i) = f(i-1) + f(i-2)
```

### Top-down method
Nothing but recursive approach where we start at the initial problem and then try to find values to subproblem until we reach a subproblem to which we know the solution (base cases).

Memoization is a simple way of just storing whatever results we have computed during recursion so that when we get the same subproblem we can retrieve the value rather than re-computing it.

```
//Pseudocode for top down
memoize = hashmap

Function f(integer i):
	if i is 0 or 1:
		return i
	if i is not in memoize:
		memoize[i] = F(i-1) + F(i-2)
	return memoize[i]
```

Bottom-up has faster runtime but top-down is easier to write

# When to use DP?
Use it where you need an optimal solution (something like min, max, least, largest etc) and you have to use recursion.

Based on characteristics that a dp problem has that is mentioned above, optimum solution is something that is generally common to dp problems like min, max, longest string etc but greedy problems also ask something like this.

Sometimes future "decisions" depend on earlier decisions and this is what differentiates a greedy and a dp problem.

To figure this out try out an example that works with greedy and give a counter example to show that greedy doesn't work then probably dp is the way to go.
