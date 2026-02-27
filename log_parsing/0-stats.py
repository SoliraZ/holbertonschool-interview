#!/usr/bin/python3
"""Reads stdin line by line and computes HTTP log metrics."""

import sys


def print_stats(total_size, status_counts):
    """Prints the accumulated statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys(), key=int):
        count = status_counts[code]
        if count:
            print("{}: {}".format(code, count))


def main():
    """Main entry: process stdin and compute metrics."""
    valid_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    status_counts = {code: 0 for code in valid_codes}
    total_size = 0
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) < 2:
                continue

            # File size is expected to be the last field
            try:
                file_size = int(parts[-1])
            except (ValueError, TypeError):
                continue
            total_size += file_size

            # Status code is expected to be the second to last field
            status_code = parts[-2]
            if status_code in status_counts:
                status_counts[status_code] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise

    print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()

