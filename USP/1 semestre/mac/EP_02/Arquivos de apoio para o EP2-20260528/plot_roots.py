#!/usr/bin/env python3
"""
plot_roots.py – Python translation of PlotRoots.java

Reads whitespace-separated (x, y) pairs from stdin (or a file piped in),
plots each pair as a black dot on a [-2, 2] x [-2, 2] canvas, and draws
a magenta unit circle as a reference.

Usage examples:
    echo "0.5 0.866  0.5 -0.866  -1 0" | python3 plot_roots.py
    python3 plot_roots.py < roots.txt
    python3 plot_roots.py            # then type pairs, finish with Ctrl-D
"""

import sys
import math
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.patches as patches


def read_pairs(source):
    """Yield (x, y) float pairs from a whitespace-tokenised stream."""
    tokens = []
    for line in source:
        tokens.extend(line.split())
    it = iter(tokens)
    for x_str in it:
        try:
            x = float(x_str)
            y = float(next(it))
            yield x, y
        except (StopIteration, ValueError):
            break


def main():
    # ── canvas setup ────────────────────────────────────────────────────
    fig, ax = plt.subplots(figsize=(7, 7))   # 700 px at 100 dpi
    ax.set_xlim(-2, 2)
    ax.set_ylim(-2, 2)
    ax.set_aspect("equal")
    ax.set_title("PlotRoots", fontsize=12)
    ax.set_xlabel("Re")
    ax.set_ylabel("Im")

    # light grid for readability (not in the original, but helpful)
    ax.axhline(0, color="gray", linewidth=0.5, linestyle="--")
    ax.axvline(0, color="gray", linewidth=0.5, linestyle="--")

    # ── magenta unit circle (pen radius 0.0025 → thin line) ─────────────
    unit_circle = patches.Circle(
        (0, 0), radius=1.0,
        edgecolor="magenta", facecolor="none",
        linewidth=0.875          # 0.0025 * 700 / 2  ≈ 0.875 pt
    )
    ax.add_patch(unit_circle)

    # ── read and plot points ─────────────────────────────────────────────
    xs, ys = [], []
    for x, y in read_pairs(sys.stdin):
        xs.append(x)
        ys.append(y)

    if xs:
        ax.scatter(xs, ys, color="black", s=7, linewidths=0)

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
