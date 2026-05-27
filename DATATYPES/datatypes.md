# Chapter 2: Data Types — The *What*

## Ask yourself: *What kind of data am I storing?*

Now that you understand the *where* (variables), it's time to understand *what*.

A data type tells the computer:

| Question | Answer |
|----------|--------|
| **How much space?** | 1 byte? 4 bytes? 8 bytes? |
| **How to interpret?** | A number? A letter? A decimal? |
| **What operations?** | Add? Compare? Concatenate? |

> **A variable without a type is just a raw chunk of memory.**  
> **A type gives that memory *meaning*.**

---

## The Basic Data Types in C

| Type | What it stores | Size (typical) | Example |
|------|----------------|----------------|---------|
| `int` | Whole numbers | 4 bytes | `42`, `-7`, `1000` |
| `float` | Decimal numbers | 4 bytes | `3.14`, `-0.5`, `99.9` |
| `double` | Decimal numbers (more precision) | 8 bytes | `3.14159265359` |
| `char` | Single character | 1 byte | `'A'`, `'9'`, `'$'` |
| `char[]` | String (text) | varies | `"Hello"`, `"Tony"` |

---

## What We Used in the Last Lesson

From `01_declaring_variables.c`:

```c
char username[50] = "Tony";
char password[50] = "IloveC";
int age = 50;
char gender[1] = "M";
```
