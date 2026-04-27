## Rain

This project implements a function that computes how much rainwater is retained between walls.

### Prototype

```python
def rain(walls):
```

### Input

- `walls`: list of non-negative integers (wall heights, width = 1 per wall)

### Output

- Returns an integer equal to the total trapped rainwater.
- Returns `0` for an empty list (or lists too short to trap water).

### Approach

The solution uses a two-pointer technique:

- Move pointers from both ends toward the center.
- Track `left_max` and `right_max`.
- Water at a position is the difference between current max boundary and wall height.

Time complexity: `O(n)`  
Space complexity: `O(1)`

