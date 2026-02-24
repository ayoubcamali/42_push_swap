*This project has been created as part of the 42 curriculum by ameirif*

# Push_swap

## Description

Push_swap is an algorithmic project from the 42 curriculum focused on sorting data
under strict constraints.

The goal is to sort a stack of integers using:

- Two stacks (A and B)
- A restricted set of operations
- The minimum possible number of moves

The program must:
- Validate all inputs
- Detect duplicates and integer overflow
- Use only authorized operations
- Print only the list of operations to standard output
- Print `Error` to standard error in case of invalid input
- Respect 42 Norminette coding standards

This project emphasizes:

- Algorithm design
- Optimization techniques
- Time/operation complexity reduction
- Linked list manipulation
- Defensive programming
- Memory management

---

## Instructions

### Compilation
Build the project:

```bash
make
```
## Clean object files:
```bash
make clean
```
## Remove all compiled files:
```bash
make fclean
```
## Recompile everything:
```bash
make re
```
## Usage
```bash
./push_swap 2 1 3 6 5 8
```
## Example output:
```
pb
ra
sa
pa
```
The program must not print anything except valid operations.

---
## Allowed Operations

### Swap
- `sa` — swap the first two elements of stack A  
- `sb` — swap the first two elements of stack B  
- `ss` — perform `sa` and `sb` simultaneously  

### Push
- `pa` — push the top element from B to A  
- `pb` — push the top element from A to B  

### Rotate
- `ra` — rotate stack A upwards  
- `rb` — rotate stack B upwards  
- `rr` — perform `ra` and `rb` simultaneously  

### Reverse Rotate
- `rra` — reverse rotate stack A  
- `rrb` — reverse rotate stack B  
- `rrr` — perform `rra` and `rrb` simultaneously  

## Algorithm Strategy
1. Index Compression

All input numbers are converted into indexes (0 to n-1) based on their sorted order.

Example:
``````
Input:   42  5  100  -3
Sorted:  -3  5   42  100
Indexes:  2  1    3    0
``````
This simplifies comparisons and prevents overflow issues.

---
### Small Stack Strategy (≤ 5 elements)

For small inputs:

- Dedicated minimal-move logic  
- Pattern-based handling  
- Optimized for lowest number of operations  

---

### 3. Chunk / Butterfly Strategy (Large Inputs)

For larger inputs (100 and 500 numbers), a chunk-based approach is used.

#### Phase 1 — Push to B

- Elements are pushed from A to B in controlled index ranges  
- Smaller indexes are positioned deeper in stack B  
- Rotations are minimized  

#### Phase 2 — Push Back to A

- Always retrieve the largest index first  
- Rotate stack B using the shortest path  
- Reconstruct stack A in sorted order  

This significantly reduces total operations compared to naive algorithms.

---

## Performance

| Input Size   | Average Moves |
|--------------|--------------|
| 3 elements   | 2–3 moves |
| 5 elements   | < 12 moves |
| 100 numbers  | ~577 |
| 500 numbers  | ~5016 |

Project requirements:

- 100 numbers → less than 700 moves  
- 500 numbers → less than 5500 moves  

This implementation respects both limits.

---

## Input Validation

The program detects and rejects:

- Duplicate numbers  
- Invalid characters  
- Empty arguments  
- Integer overflow or underflow  
- Mixed invalid formatting  

On error, the program prints:

```text
Error
```

## Examples:
```
./push_swap 1 2 2
./push_swap 2147483648
./push_swap -2147483649
./push_swap ""
./push_swap 1 a 3
```
---
```
.
├── main.c
├── push_swap.h
├── parse.c
├── parse_utils.c
├── split.c
├── split_utils.c
├── stack.c
├── stack_utils.c
├── ops_swap.c
├── ops_push.c
├── ops_rotate.c
├── ops_rev_rotate.c
├── index.c
├── index_utils.c
├── sort_small.c
├── sort_chunk.c
├── sort_chunk_utils.c
└── Makefile
```
---
## Data Structure
```
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;
```
Stacks are implemented using singly linked lists for efficient push and pop operations.

---
## Testing
Random 100 numbers (macOS):
```
ARG="$(jot 100 0 99 | sort -R | tr '\n' ' ')"
./push_swap $ARG | wc -l
```
Random 500 numbers:
```
ARG="$(jot 500 0 499 | sort -R | tr '\n' ' ')"
./push_swap $ARG | wc -l
```
Stress test:
```
for i in {1..10}; do
  ARG="$(jot 500 0 499 | sort -R | tr '\n' ' ')"
  ./push_swap $ARG | wc -l
done
```
## Concepts Used

- Linked Lists  
- Stack manipulation  
- Sorting strategies  
- Chunk-based optimization  
- Index compression  
- Memory management  
- Defensive programming  
- Performance optimization  
- Norminette compliance  

---

## Conclusion

Push_swap is not simply about sorting numbers.

It is about:

- Designing efficient algorithms  
- Working under strict constraints  
- Minimizing operations  
- Writing clean and structured C code  
- Respecting 42 coding standards  

This implementation achieves:

- Correctness  
- Efficiency  
- Clean architecture  
- Full Norm compliance  

---
## Bonus – Checker

The bonus part of this project implements a program named `checker`.

The purpose of `checker` is to verify whether a given sequence of operations correctly sorts a stack.

---

### Program Name

checker

---

### How It Works

1. The program receives the stack values as arguments.
2. It reads instructions from standard input (stdin).
3. Each instruction is applied to the stacks.
4. After executing all instructions:
   - If stack A is sorted in ascending order AND stack B is empty → prints `OK`
   - Otherwise → prints `KO`
   - If an invalid instruction or invalid input is detected → prints `Error`

---

### Supported Instructions

The checker supports all mandatory operations:

- sa  
- sb  
- ss  
- pa  
- pb  
- ra  
- rb  
- rr  
- rra  
- rrb  
- rrr  

Each instruction must be followed by a newline.

---

### Compilation

To compile the bonus program:

```bash
make bonus
```
This generates the executable:
```
./checker
```
### Usage Examples
Valid Case (OK)
```
ARG="3 2 1 0"
./push_swap $ARG | ./checker $ARG
```
### Output:
```
OK
```
### Invalid Sorting (KO)
```
printf "sa\n" | ./checker 1 2 3
```
### Output:
```
KO
```
## Invalid Instruction (Error)
```
printf "rx\n" | ./checker 1 2 3
```
### Output:
```
Error
```
## Implementation Details

The checker reuses:

- The same parsing system as `push_swap`
- The same stack structure (linked lists)
- The same operation functions (without printing)
- Defensive input validation
- Proper memory management

The program reads input dynamically from `stdin` and safely applies each operation.

---

## Design Goals

- Reuse existing logic from the mandatory part  
- Avoid code duplication  
- Maintain full Norminette compliance  
- Ensure robust error handling  
- Guarantee correct memory cleanup  

---

The bonus confirms the correctness of the sorting algorithm by simulating the execution of operations exactly as required by the subject.
## Resources

### Documentation & References

- 42 Subject: Push_swap  
- GNU C Documentation  
- Linked List data structures (classic computer science references)  
- Stack-based sorting strategies  
- Radix sort theory  
- Algorithm complexity analysis (Big-O notation)  

### Recommended Reading

- *Introduction to Algorithms* — Cormen, Leiserson, Rivest, Stein  
- GeeksforGeeks (algorithm explanations)  
- StackOverflow (technical discussions)  

---

## AI Usage Disclosure

AI tools were used for:

- Concept clarification regarding sorting strategies (chunk logic, optimization ideas)  
- Reviewing algorithm efficiency approaches  
- README structure formatting and documentation refinement  
- Explaining theoretical concepts (index compression, stack rotations)  

AI was **not** used to generate the core algorithm implementation.  
All C source code, data structures, parsing logic, and sorting logic were implemented manually and validated according to 42 standards.