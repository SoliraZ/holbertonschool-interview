# Regex

This project implements a function that checks whether a given regular expression pattern matches a given string.

## Files

- `regex.c`
- `regex.h`

## Prototype

```c
int regex_match(char const *str, char const *pattern);
```

## Description

- `str` is the string to scan. It can be empty and cannot contain `.` or `*`.
- `pattern` is the regular expression. It can be empty and can contain `.` and `*`.
- Returns `1` if the pattern matches the string.
- Returns `0` otherwise.

## Supported Operators

- `.` matches any single character
- `*` matches zero or more of the preceding character

## Approach

The solution uses recursive backtracking:

- If the pattern is empty, the string must also be empty.
- If the next pattern character is `*`:
  - Try matching zero occurrences: advance the pattern by 2.
  - Try matching one or more occurrences: consume matching characters from the string.
- Otherwise, if the current characters match (or the pattern has `.`), advance both pointers.
- Return `0` when no valid match is found.

Time complexity: exponential in the worst case  
Space complexity: `O(n)` (recursion depth)

## Example

```c
regex_match("HH", "H*");        /* returns 1 */
regex_match("Holberton", ".*"); /* returns 1 */
regex_match("Holberton", "holberton"); /* returns 0 */
```
