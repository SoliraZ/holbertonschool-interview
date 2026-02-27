# Minimum Operations

This project implements a method that calculates the fewest number of operations needed to obtain exactly `n` `H` characters in a text file, starting from a single `H`.

The only allowed operations on the file are:

- **Copy All**: Copy all the characters in the file.
- **Paste**: Paste the copied characters at the end of the file.

The entry point is the function `minOperations(n)` defined in `0-minoperations.py`.

## Function Prototype

```python
def minOperations(n):
    """Returns the minimum number of operations needed to reach n H characters."""
```

## Constraints

- If `n` is impossible to achieve (e.g., `n < 2`), the function returns `0`.
- The solution is optimized by decomposing `n` into its prime factors to minimize the number of operations.

