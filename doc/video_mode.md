# Video Mode Reference

Mode | BG0 | BG1 | BG2 | BG3 | Scroll     | Transform | Object VRAM
:---:|:---:|:---:|:---:|:---:|:-----------|:----------|:-----------
0    | ✔️  | ✔️  | ✔️   | ✔️  | ✔️          | ❌        | 32K
1    | ✔️  | ✔️  | ✔️   | ❌  | ✔️ BG0, BG1 | ✔️ BG2    | 32K
2    | ❌  | ❌  | ✔️   | ✔️  | ❌          | ✔️        | 32K
3    | ❌  | ❌  | ✔️   | ❌  | ❌          | ✔️        | 16K
4    | ❌  | ❌  | ✔️   | ❌  | ❌          | ✔️        | 16K
5    | ❌  | ❌  | ✔️   | ❌  | ❌          | ✔️        | 16K
6    | ❌  | ❌  | ❌   | ❌  | ❌          | ❌        | 16K?
7    | ❌  | ❌  | ❌   | ❌  | ❌          | ❌        | 16K?

Objects, blending, mosaic and windows are always available.

Modes 6 and 7 are not intended to be used and only display objects.
