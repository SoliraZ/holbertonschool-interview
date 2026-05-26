# Count It

This project implements a recursive function that queries the Reddit API, parses hot post titles, and prints a sorted count of requested keywords.

## Prototype

```python
def count_words(subreddit, word_list)
```

## Behavior

- Counts keywords case-insensitively.
- Handles duplicates in `word_list` by summing occurrences.
- Uses Reddit hot listing pagination recursively (`after` token).
- Prints results sorted by:
  1. Count (descending)
  2. Keyword (alphabetical ascending) for ties
- Skips keywords with zero matches.
- Prints nothing for invalid subreddits or no matches.
- Does not follow redirects.

