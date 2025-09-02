# Graphing Calculator (C++/SFML)

A desktop graphing calculator built in C++ that:
- Parses mathematical expressions with the Shunting Yard algorithm
- Converts to and evaluates Reverse Polish Notation (RPN)
- Uses custom linked-list Stack and Queue data structures
- Renders plots in real time with SFML

This project showcases algorithmic problem solving (tokenization, parsing, evaluation), data structures (linked lists, stacks, queues), and graphics programming (coordinate transforms, event loop, rendering) in a cohesive, interactive application.

Demo:
https://youtu.be/RbQpmkbzOAI

## Key features
- Plot y = f(x) using a custom expression engine (no heavyweight parser frameworks)
- Tokenizer → Shunting Yard (infix → RPN) → Stack-based RPN evaluator
- Custom Stack and Queue implemented via linked lists
- Real-time drawing with SFML (axes, grid, function curve)
- Clear separation between parsing/evaluation and rendering
- Basic error handling for malformed expressions (invalid tokens, mismatched parentheses)

Note: Exact operators/functions depend on the current code. Commonly supported examples include:
- Operators: +, −, ×, ÷, ^ with standard precedence
- Parentheses: ()
- Functions: sin, cos, tan, exp, ln, sqrt
- Constants/variables: e, pi, x

Please adjust this section to match the current implementation if it differs.

## How it works

1. Tokenization
   - Scans the input string and emits tokens (numbers, identifiers, operators, parentheses).
   - Validates numeric formats and identifiers.

2. Parsing (Shunting Yard)
   - Converts infix tokens to RPN using operator precedence and associativity.
   - Manages parentheses and function arity.

3. Evaluation (RPN)
   - Uses a stack to evaluate RPN efficiently.
   - Applies unary/binary operators and functions to numeric operands.

4. Plotting (SFML)
   - Samples f(x) across the visible domain.
   - Transforms math coordinates to screen coordinates.
   - Renders axes, grid, and polyline of sampled points.

5. Data Structures
   - Custom linked-list-based Stack and Queue power the parser and evaluator (demonstrating manual memory management and pointer-safe operations).

## Tech stack
- Language: C++
- Graphics: SFML (Simple and Fast Multimedia Library)
- Build: Any C++ toolchain that can link against SFML (gcc/clang/MSVC)

## Getting started

Prerequisites
- C++ compiler (e.g., g++/clang++/MSVC)
- SFML 2.5+ (graphics, window, system)

Install SFML
- macOS (Homebrew): `brew install sfml`
- Ubuntu/Debian: `sudo apt-get install libsfml-dev`
- Windows: Download binaries from https://www.sfml-dev.org/download.php and configure your compiler/IDE to include and link SFML.

Build (generic example)
If the project doesn’t include a CMake/Makefile, you can compile the sources and link SFML directly. Adjust paths and source file names as needed:

- Linux/macOS:
  g++ -std=c++17 -O2 -I/usr/local/include -L/usr/local/lib \
    src/*.cpp -o GraphingCalculator \
    -lsfml-graphics -lsfml-window -lsfml-system

- Windows (MSYS2 MinGW example):
  g++ -std=c++17 -O2 src\\*.cpp -o GraphingCalculator.exe \
    -IC:\\Path\\to\\SFML\\include -LC:\\Path\\to\\SFML\\lib \
    -lsfml-graphics -lsfml-window -lsfml-system

If the repository contains a CMakeLists.txt or a specific project file, prefer that:
- CMake:
  mkdir -p build && cd build
  cmake ..
  cmake --build . --config Release

Run
- macOS/Linux: `./GraphingCalculator`
- Windows: `GraphingCalculator.exe`

Ensure SFML shared libraries are discoverable at runtime (on Windows, copy SFML .dlls next to the executable, or add them to PATH).

## Usage (typical flow)
- Start the application.
- Enter an expression in terms of x (example: `sin(x) + 0.5*x`).
- Plot will appear across the current viewport.
- Use available input controls (keyboard/mouse) for navigation (pan/zoom) if implemented.

Tip: For steep functions or large magnitudes, reduce the step size (sampling increment) or zoom in for smoother curves.

## Design highlights
- Deterministic parsing and evaluation: No recursion-heavy parsing; uses proven Shunting Yard + RPN with explicit stacks.
- Custom data structures: Demonstrates linked-list Stack/Queue rather than relying solely on STL, highlighting low-level data manipulation.
- Separation of concerns: Parsing/evaluation modules are decoupled from rendering, making it easier to extend either side independently.
- Extensibility: New functions or operators can be added by extending the tokenizer, operator table, and evaluator.

## Roadmap ideas
- Multiple simultaneous plots and color legend
- Configurable sampling density and adaptive step size
- Better error messages with token positions
- Support for piecewise functions and parameter sliders
- Export to image (PNG) or data (CSV)
- Derivatives and numerical integration overlays

## Project status
Actively maintained as a learning and demonstration project. Issues and PRs are welcome.

## License
No LICENSE file is currently present. Consider adding one (MIT/Apache-2.0/BSD-3-Clause) to enable broader use.

## Credits
- SFML: https://www.sfml-dev.org/
- Shunting Yard algorithm by Edsger W. Dijkstra
- Reverse Polish Notation (RPN) evaluation
