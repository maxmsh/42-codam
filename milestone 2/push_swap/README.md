# push_swap

A sorting algorithm visualization project that challenges you to sort a stack of integers using the smallest possible number of operations.

## Overview

push_swap is a algorithmic puzzle where you're given two stacks (a and b) and a limited set of operations to sort stack a in ascending order. The project tests your ability to develop efficient sorting strategies while working within strict operational constraints.

## The Challenge

You receive a random set of integers in stack a, while stack b starts empty. Your goal: sort stack a using the fewest moves possible. Sounds simple? The catch is you can only use these specific operations:

**Stack operations:**
- `sa` - swap the first two elements of stack a
- `sb` - swap the first two elements of stack b
- `ss` - sa and sb simultaneously
- `pa` - push top element from b to a
- `pb` - push top element from a to b
- `ra` - rotate stack a upward (first element becomes last)
- `rb` - rotate stack b upward
- `rr` - ra and rb simultaneously
- `rra` - reverse rotate stack a (last element becomes first)
- `rrb` - reverse rotate stack b
- `rrr` - rra and rrb simultaneously

## What Makes It Interesting

This isn't just about getting the stack sorted—it's about optimization. You need to develop smart algorithms that minimize the number of operations. Different input sizes require different strategies: what works for 5 numbers fails spectacularly for 500.

The project forces you to think about algorithmic complexity, implement efficient sorting strategies, and make intelligent decisions about when to use which operations.