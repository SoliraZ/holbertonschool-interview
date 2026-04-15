## Slide Line

This project reproduces the 2048 slide-and-merge mechanic on a single horizontal line.

### Files

- `slide_line.h`
- `0-slide_line.c`

### Prototype

```c
int slide_line(int *line, size_t size, int direction);
```

### Behavior

- `direction` must be:
  - `SLIDE_LEFT`
  - `SLIDE_RIGHT`
- Returns `1` on success, `0` on failure.
- If `direction` is invalid, the function fails.
- The line is modified in place:
  - zeros are ignored while sliding
  - equal values merge once per move, in traversal order
  - merged values are doubled

### Constraints

- No dynamic memory allocation is used.

