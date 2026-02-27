## Log Parsing

This project implements a script that reads HTTP access logs from standard input and computes simple metrics.

### Script

- **File**: `0-stats.py`
- **Usage**: `./0-generator.py | ./0-stats.py`

The script:

- Reads input line by line from `stdin`.
- Expects lines in the format:
  `IP - [date] "GET /projects/260 HTTP/1.1" <status code> <file size>`
- Skips lines that do not match this structure well enough to extract a numeric file size.
- Maintains:
  - Total sum of all `<file size>` values.
  - Count of occurrences for status codes:
    `200, 301, 400, 401, 403, 404, 405, 500`.
- Prints statistics:
  - After every 10 lines processed.
  - On keyboard interruption (`CTRL + C`).
  - Once more at normal end of input.

The code is guarded with `if __name__ == "__main__":` so it does not execute when imported as a module.

