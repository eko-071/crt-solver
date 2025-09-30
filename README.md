# Chinese Remainder Theorem Solver

A C implementation of the **Chinese Remainder Theorem** using the **Extended Euclidean algorithm** to compute modular inverses.

This program takes a system of simultaneous congruences of the form:

```
x ≡ a₁ (mod m₁)
x ≡ a₂ (mod m₂)
...
x ≡ aₙ (mod mₙ)
```

and finds the smallest positive integer x such that all the congruences are satisfied.

## Features

- Implements the **Extended Euclidean Algorithm** to compute GCD and Bézout coefficients.
- Computes **modular inverses** when they exist.
- Uses **CRT** to combine the congruences.

## Usage

1. Clone the repository and change current directory to it:

```bash
git clone https://github.com/eko-071/crt-solver.git
cd crt-solver
```

2. Compile using `gcc`:

```bash
gcc solver.c -o solver
```

3. Run:

```bash
./solver
```

## Notes

- This solver does not extend to the generalized CRT, so it only works when all the moduli are pairwise coprime.