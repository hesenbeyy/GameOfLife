# Conway's Game of Life (SDL2)

A classic implementation of John Conway's Game of Life written in **C** using the **SDL2** library. This project simulates cellular automata where cells live, die, or multiply based on a set of mathematical rules.

## 🚀 Quick Start (Release)

If you just want to see the simulation in action without compiling the code:

1. Go to the **Releases** section on the right side of the GitHub page.
2. Download the latest `.zip` file.
3. Extract and run the `.exe`.
* *Note: Ensure the included SDL2 DLLs are in the same folder as the executable.*



## 📽️ Simulation Preview


https://github.com/user-attachments/assets/801f8c84-91cd-46dc-805c-785182b649f9


---

## 🛠️ How to Build (Visual Studio)

This project was developed using **Visual Studio 2022**. To get it running from source, you need to link the SDL2 development libraries:

1. **Download SDL2**: Get the `SDL2-devel-VC.zip` from the [official SDL website](https://github.com/libsdl-org/SDL/releases).
2. **Include Directories**: In your project properties, go to `VC++ Directories` -> `Include Directories` and add the path to the `SDL2/include` folder.
3. **Library Directories**: Add the path to `SDL2/lib/x64` (or x86) to the `Library Directories`.
4. **Linker Input**: Under `Linker` -> `Input`, add `SDL2.lib` and `SDL2main.lib` to the **Additional Dependencies**.
5. **DLL**: Copy `SDL2.dll` from the library folder into your project's output directory (where the `.exe` is generated).

---

## ⚙️ Customization (Macros)

You can easily modify the behavior and appearance of the simulation by editing `macros.h`. This allows you to "play" with the game's physics and scale:

| Macro | Description |
| --- | --- |
| `WIDTH` / `HEIGHT` | Adjust the window resolution. |
| `CELL_SIZE` | Change the size of individual cells (lower = more cells, higher = bigger blocks). |
| `WHITE_COLOR` | The color of living cells (RGBA). |
| `GREY_COLOR` | The color of the grid lines. |
| `NEIGHBOUR_SUM` | The logic used to count surrounding life—edit this to experiment with non-standard rules! |

---

## 🧠 The Logic

The core of the game resides in the `change_gens` function. It evaluates the 8 neighbors of every cell to determine its state in the next generation:

* **Underpopulation**: A living cell with fewer than 2 neighbors dies.
* **Stasis**: A living cell with 2 or 3 neighbors lives on.
* **Overpopulation**: A living cell with more than 3 neighbors dies.
* **Reproduction**: A dead cell with exactly 3 neighbors becomes alive.

---
