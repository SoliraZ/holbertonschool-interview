#!/usr/bin/python3
"""Minimum operations to get n 'H' characters."""


def minOperations(n):
    """
    Calculate the fewest number of operations needed to result
    in exactly n 'H' characters in the file.

    Args:
        n (int): Desired number of 'H' characters.

    Returns:
        int: Minimum number of operations, or 0 if impossible.
    """
    if not isinstance(n, int) or n < 2:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
