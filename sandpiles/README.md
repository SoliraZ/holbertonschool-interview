## Sandpiles

This project implements the **Abelian sandpile model** operations on a 3x3 grid.

You are given two 3x3 integer grids representing sandpiles. Each cell contains a number of grains.

- A sandpile is **stable** if none of its cells contains more than 3 grains.
- The allowed operation is **toppling**: any cell with more than 3 grains loses 4 grains and
  distributes 1 grain to each of its (up to 4) orthogonal neighbors.

### Function

- **Prototype**: `void sandpiles_sum(int grid1[3][3], int grid2[3][3]);`
- `grid1` and `grid2` are assumed to be individually stable on entry.
- The function:
  - Adds `grid2` into `grid1` cell by cell.
  - Repeatedly topples `grid1` until it becomes stable.
  - Prints `grid1` **before each toppling round** when it is unstable, with a leading `=` line,
    matching the provided examples.
  - Stores the final stable sandpile in `grid1`.

No dynamic memory allocation is used; all operations work directly on fixed-size arrays.

