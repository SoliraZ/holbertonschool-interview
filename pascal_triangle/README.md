## Pascal Triangle

This project implements a function that returns Pascal's triangle as a list of lists of integers.

### Prototype

```python
def pascal_triangle(n):
```

### Input

- `n`: integer representing the number of rows in the triangle

### Output

- Returns a list of lists of integers representing Pascal's triangle of `n`
- Returns an empty list if `n <= 0`

### Approach

The triangle is built row by row:

- The first row is always `[1]`
- Each subsequent row starts and ends with `1`
- Interior values are the sum of the two values directly above them in the previous row

Time complexity: `O(n^2)`  
Space complexity: `O(n^2)`

### Example

```python
pascal_triangle(5)

# [
#   [1],
#   [1, 1],
#   [1, 2, 1],
#   [1, 3, 3, 1],
#   [1, 4, 6, 4, 1]
# ]
```
