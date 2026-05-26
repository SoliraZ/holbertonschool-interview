#!/usr/bin/python3
"""Recursive Reddit keyword counter."""

import requests


def count_words(subreddit, word_list, counts=None, after=None,
                words_count=None):
    """
    Recursively query Reddit hot posts and print keyword counts.

    Args:
        subreddit (str): Subreddit name.
        word_list (list): List of keywords to count.
        counts (dict): Internal running totals.
        after (str): Internal Reddit pagination token.
        words_count (dict): Internal keyword multiplicity map.
    """
    if counts is None:
        counts = {}
    if words_count is None:
        words_count = {}
        for word in word_list:
            key = word.lower()
            words_count[key] = words_count.get(key, 0) + 1
            counts[key] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    params = {"limit": 100, "after": after}
    headers = {"User-Agent": "linux:count_it:v1.0 (by /u/holberton-bot)"}

    try:
        response = requests.get(
            url,
            params=params,
            headers=headers,
            allow_redirects=False,
            timeout=10
        )
    except requests.RequestException:
        return

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    children = data.get("children", [])

    for post in children:
        title = post.get("data", {}).get("title", "").lower()
        for token in title.split():
            if token in words_count:
                counts[token] += words_count[token]

    next_after = data.get("after")
    if next_after is not None:
        return count_words(
            subreddit, word_list, counts, next_after, words_count
        )

    ordered = sorted(
        [(word, total) for word, total in counts.items() if total > 0],
        key=lambda item: (-item[1], item[0])
    )
    for word, total in ordered:
        print("{}: {}".format(word, total))
