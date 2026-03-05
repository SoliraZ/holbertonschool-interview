## UTF-8 Validation

This project implements a function that checks whether a given data set represents a valid UTF-8 encoding.

### Function

- **File**: `0-validate_utf8.py`
- **Prototype**:

```python
def validUTF8(data):
    """Return True if data is a valid UTF-8 encoding, else False."""
```

### Description

- `data` is a list of integers, each representing one byte.
- Only the 8 least significant bits of each integer are considered.
- A UTF-8 character can be 1 to 4 bytes long:
  - 1-byte: `0xxxxxxx`
  - 2-byte: `110xxxxx 10xxxxxx`
  - 3-byte: `1110xxxx 10xxxxxx 10xxxxxx`
  - 4-byte: `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`
- The function iterates through the list and:
  - Determines how many continuation bytes are expected from the leading byte.
  - Verifies that each continuation byte has the `10xxxxxx` pattern.
  - Returns `False` immediately on any invalid pattern.
  - Returns `True` only if all bytes are consumed in valid UTF-8 sequences.

