## Island Perimeter

This project implements a function that calculates the perimeter of an island described in a 2D grid.

### Prototype

```python
def island_perimeter(grid):
```

### Input

- `grid`: list of lists of integers
  - `0` represents water
  - `1` represents land
- Each cell is a square with side length of 1
- Cells are connected horizontally or vertically (not diagonally)
- The grid is rectangular, with width and height not exceeding 100
- The grid is completely surrounded by water
- There is only one island (or nothing)
- The island does not contain lakes (no enclosed water disconnected from the surrounding water)

### Output

- Returns an integer equal to the perimeter of the island
- Returns `0` for an empty grid or a grid with no land

### Approach

For each land cell (`1`), count how many of its four sides border water or the edge of the grid. Each exposed side contributes 1 to the perimeter.

The algorithm iterates over every cell in the grid:

- If the cell is land, check its four neighbors (top, bottom, left, right)
- If a neighbor is out of bounds or contains water (`0`), increment the perimeter by 1

Time complexity: `O(rows × cols)`  
Space complexity: `O(1)`

### Example

```python
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]

island_perimeter(grid)  # returns 12
```
