## En yakındakine Sıçrar

## Introduction
This system simulates a game played on a game pitch where players join the game one by one. The pitch starts empty, and events dictate player movements between the game pitch and the player's bench.

## Description
You will be given `q` events describing the timeline of the game:
- `x`: Player with number `x` joins the game. If `x` has already joined the game, ignore this event. (A player in the game pitch or in the player's bench is considered to be in the game).
- `-`: The player who has spent the most amount of time in the game pitch goes to the player's bench. If no such player exists, ignore this event.
- `+`: The player who has spent the least amount of time in the player's bench returns to the game pitch. If no such player exists, ignore this event.

At the beginning of the game, both the game pitch and the player's bench are empty. Given the timeline of the game, print the player numbers of the players currently in the game pitch in increasing order of the amount of time they have spent in the game pitch. When a player goes to the player's bench, their time in the game pitch is reset to `0`.

## Input Format
The first line contains an integer `q` — the number of events.
The next `q` lines contain space-separated events — each of them is either `x`, `+`, or `-`.

## Output Format
Space-separated player numbers `x`, representing the players in the game pitch sorted in increasing order by the amount of time they have spent in the game pitch.

## Constraints
- 0 ≤ q ≤ 2 * 10^5
- 0 ≤ x ≤ 2 * 10^9

## Example
## Input
11
1 3 5 - 1 4 - 5 6 + +
## Output
1 3 6 4 5
