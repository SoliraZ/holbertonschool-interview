## Menger Sponge

This project draws a 2D Menger Sponge pattern for a given level.

### Files

- `menger.h`
- `0-menger.c`

### Prototype

```c
void menger(int level);
```

### Behavior

- If `level < 0`, the function does nothing.
- A level `0` sponge is one `#`.
- A level `N` sponge has size `3^N` and is built by removing the center square recursively.
- The output is printed line by line using `#` and spaces.

