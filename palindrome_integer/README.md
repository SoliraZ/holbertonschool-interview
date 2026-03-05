## Palindrome Integer

This project implements a function that checks whether a given unsigned integer is a palindrome.

### Function Prototype

```c
int is_palindrome(unsigned long n);
```

### Requirements

- Given an unsigned long integer `n`, the function determines whether it is a palindrome.
- The function returns `1` if `n` reads the same forwards and backwards; `0` otherwise.
- **You are not allowed to allocate memory dynamically** (no use of `malloc`, `calloc`, etc).

### Example

| Input         | Output | Reasoning                                        |
|---------------|--------|--------------------------------------------------|
| `121`         | `1`    | 121 reversed is 121                              |
| `12321`       | `1`    | 12321 reversed is 12321                          |
| `123`         | `0`    | 123 reversed is 321, not the same as original    |
| `0`           | `1`    | 0 reversed is 0                                  |
| `1221`        | `1`    | 1221 reversed is 1221                            |
| `10`          | `0`    | 10 reversed is 01, which is 1                    |

### Constraints

- No dynamic memory allocation is allowed.
- The implementation must only use basic language features.
