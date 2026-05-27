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

From [`01_declaring_variables.c`](../VARIABLES/01_declaring_variables.c):

```c
char username[50] = "Tony";
char password[50] = "IloveC";
int age = 50;
char gender[1] = "M";
```
**The pattern:**

```c
type     name      = value;
```

| Variable | Data Type | What it stores |
|----------|-----------|----------------|
| `username` | `char[50]` | A string up to 49 chars + null terminator |
| `password` | `char[50]` | A string up to 49 chars + null terminator |
| `age` | `int` | A whole number |
| `gender` | `char[1]` | A single character as a string |

> **Note:** `gender` should really be `char gender = 'M';` (single char, no array). Using `"M"` (string) instead of `'M'` (char) wastes space.

---

## Format Specifiers — How to Print Different Types

When you print with `printf`, you must tell it what type to expect using **format specifiers**.

### Common Format Specifiers

| Specifier | Data Type | What it prints | Example |
|-----------|-----------|----------------|---------|
| `%d` or `%i` | `int` | Signed integer | `printf("%d", age);` |
| `%f` | `float` | Decimal number | `printf("%f", price);` |
| `%.2f` | `float` | Decimal with 2 places | `printf("%.2f", price);` |
| `%c` | `char` | Single character | `printf("%c", grade);` |
| `%s` | `char[]` | Text string | `printf("%s", name);` |
| `%p` | Pointer | Memory address | `printf("%p", &age);` |
| `%x` | `int` | Hexadecimal | `printf("%x", num);` |
| `%%` | None | Prints a percent sign | `printf("50%%");` |


| Concept | What it means |
|---------|----------------|
| Data type | Tells the computer how to interpret a variable's memory |
| `int` | Whole numbers (no decimals) |
| `float` / `double` | Decimal numbers |
| `char` | Single character (uses single quotes) |
| `char[]` | String of characters (uses double quotes) |
| Format specifier | Tells `printf` what type to expect |

**Your takeaway:**

> **A variable is *where*. A data type is *what*.**  
> **Use the right type, or printf will lie to you.**

---

## Quick Quiz

Match the variable with the correct format specifier:

| Variable | Specifier (a-e) |
|----------|-----------------|
| `int count = 10;` | a) `%f` |
| `float price = 5.99;` | b) `%c` |
| `char letter = 'Z';` | c) `%d` |
| `char name[20] = "Zoe";` | d) `%s` |
| `double pi = 3.141592;` | e) `%lf` |

**Answers:**

- `int` → c (`%d`)
- `float` → a (`%f`)
- `char` → b (`%c`)
- `char[]` → d (`%s`)
- `double` → e (`%lf`)

---

### Which Specifiers We Used in Lesson 1

| Line of Code | Specifier | Correct? |
|--------------|-----------|----------|
| `printf("the username is %s\n", username);` | `%s` | ✅ Correct |
| `printf("the age is %d\n", age);` | `%d` | ✅ Correct |
| `printf("the password is %s\n", password);` | `%s` | ✅ Correct |
| `printf("the gender is %d\n", gender);` | `%d` | ❌ Wrong |

## Common Mistakes

| Wrong | Correct | Why |
|-------|---------|-----|
| `char name[] = "Tony";`<br>`printf("%c", name);` | `printf("%s", name);` | `%c` is for single chars, `%s` for strings |
| `int age = "twenty";` | `int age = 20;` | Strings can't be stored in `int` |
| `float pi = 3.14;`<br>`printf("%d", pi);` | `printf("%f", pi);` | `%d` is for integers, `%f` for floats |
| `char grade = "A";` | `char grade = 'A';` | Double quotes for strings, single quotes for chars |

---

## Summary Table: Type + Specifier + Example

| Data Type | Format Specifier | Declaration | Print |
|-----------|------------------|-------------|-------|
| `int` | `%d` | `int x = 42;` | `printf("%d", x);` |
| `float` | `%f` | `float y = 3.14;` | `printf("%f", y);` |
| `double` | `%lf` | `double z = 3.14159;` | `printf("%lf", z);` |
| `char` | `%c` | `char c = 'M';` | `printf("%c", c);` |
| `char[]` | `%s` | `char s[10] = "Hi";` | `printf("%s", s);` |

---

## The Dark Truth

Data types are a *lie we tell the compiler*.

At the hardware level, memory is just bytes. A byte doesn't know if it's an `int`, a `char`, or part of a `float`. The type is a *contract* between you and the compiler:

> *"Trust me, compiler. Treat these 4 bytes as an integer."*

Break that contract, and you get **undefined behavior** — garbage output, crashes, or silent corruption.

```c
int x = 65;
printf("%c", x);  // Prints 'A' (ASCII 65) — works, but is it a good idea?
```

Just because you *can* doesn't mean you *should*.

Now that you've understood datatypes, try solving the [`test.md`](../VARIABLES/test.md) quiz.

---

