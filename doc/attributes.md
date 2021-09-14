# seven\_attributes.h

[Link to header](../inc/seven_attributes.h)

## Synopsis

This header provides various commonly used attributes.

Attributes that take an identifier, like `IWRAM_FUNC`, are used as follows:

```c
// Declare a function called `function_in_iwram`.
void IWRAM_FUNC(function_in_iwram)(void);
```

## Function Attributes

### NORETURN

Marks the function as never returning.

Expands to `__attribute__((__noreturn__))`.

### NOINLINE

Prevents the function from being inlined.

Expands to `__attribute__((noinline))`.

### ARM\_CODE

Causes the function to be compiled as ARM code regardless of compilatier flags.

Expands to `__attribute__((target("arm")))`.

### THUMB\_CODE

Causes the function to be compiled as THUMB code regardless of compiler flags.

Expands to `__attribute__((target("arm")))`.

### IWRAM\_FUNC(name)

Causes the function `name` to be placed in IWRAM. Disables inlining.

Expands to `__attribute__((section(".iwram." #name), noinline)) name`.

### EWRAM\_FUNC(name)

Causes the function `name` to be placed in EWRAM. Disables inlining.

Expands to `__attribute__((section(".ewram." #name, noinline))) name`.

---

## Variable Attributes

### ALIGN(n)

Aligns the variable to `n` bytes.

Expands to `__attribute__((aligned(n)))`.

### IWRAM\_DATA(name)

Causes the variable `name` to be placed in IWRAM.
Included for parity with `EWRAM_DATA`.

Expands to `__attribute__((section(".iwram." #name))) name`.

### IWRAM\_BSS(name)

Causes the variable `name` to be placed in zero-initialized IWRAM.
Included for partiy with `EWRAM_BSS`.

Expands to `__attribute__((section(".bss." #name))) name`.

### EWRAM\_DATA(name)

Causes the variable `name` to be placed in EWRAM.

Expands to `__attribute__((section(".ewram." #name))) name`.

### EWRAM\_BSS(name)

Causes the variable `name` to be placed in zero-initialized EWRAM.

Expands to `__attribute__((section(".sbss." #name))) name`.

---

## Type Attributes

### ALIGN(n)

Causes the type to always be aligned to `n` bytes.

Expands to `__attribute__((aligned(n)))`.
