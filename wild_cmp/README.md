# Wild Compare

This project implements a function that compares two strings and returns whether they can be considered identical when the second string may contain the wildcard character `*`.

## Files

- `0-wildcmp.c`
- `holberton.h`

## Prototype

```c
int wildcmp(char *s1, char *s2);
```

## Description

- `s2` can contain the special character `*`.
- The special character `*` can replace any string, including an empty string.
- Returns `1` if the strings can be considered identical.
- Returns `0` otherwise.

## Approach

The solution uses recursion:

- If `s1` is empty:
  - If `s2` starts with `*`, skip the `*` and continue matching.
  - Otherwise, return `1` only if `s2` is also empty.
- If `s2` starts with `*`:
  - Try matching the `*` with zero characters: `wildcmp(s1, s2 + 1)`.
  - Try matching the `*` with one or more characters: `wildcmp(s1 + 1, s2)`.
- If the current characters match, advance both pointers.
- Otherwise, return `0`.

Time complexity: exponential in the worst case (backtracking through `*`)  
Space complexity: `O(n)` (recursion depth)

## Example

```c
wildcmp("main.c", "*.c");           /* returns 1 */
wildcmp("main.c", "m.*c");          /* returns 0 */
wildcmp("abc", "*b");               /* returns 0 */
```
