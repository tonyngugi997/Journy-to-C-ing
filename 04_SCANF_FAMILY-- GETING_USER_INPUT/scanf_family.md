```

**Who said the user is 45?**  
**Who said their name is Tony?**  
**Who said they live in Nakuru?**

*You did.*

You decided. You guessed. You *assumed*.

That's not a program. That's a **hostage situation** — your user has no choice but to be Tony from Nakuru who's 45 years old.

What if the user is 19? What if their name is "Alex"? What if they live in "Mombasa"?

> **Hardcoding = Rigid. Input = Flexible.**
>
> *A program that doesn't take input isn't interactive — it's a monologue.*

---

## The Solution: `scanf()` — The Listener

`scanf()` is the opposite of `printf()`.

| Function | Direction | Job |
|----------|-----------|-----|
| `printf()` | Program → User | *"Here's some data"* |
| `scanf()` | User → Program | *"Give me some data"* |

**Basic usage:**

```c
int age;
printf("Enter your age: ");
scanf("%d", &age);   // Program STOPS and WAITS for user input
printf("You are %d years old\n", age);
```

When your program hits `scanf()`, it **freezes**. It sits there. Staring. Waiting for the user to type something and press Enter.

**That's interactivity.**

---



## The Mysterious `&` Symbol (Address-of)

Here's something that confuses every beginner:

```c
scanf("%d", &age);   // Why the &?
printf("%d", age);   // Why no & here?
```

**The short answer:**

- `printf()` needs the **value** of `age` (what's inside the box)
- `scanf()` needs the **location** of `age` (where the box is kept)

`&` means *"address of"*. It tells `scanf()`: *"Hey, the variable `age` lives at memory address 0x7ffd8a9b3c. Go put the user's input there."*

**The long answer (for later):** This is your first taste of **pointers**. `scanf()` needs to modify the original variable, not a copy. `&` gives it access to the original.

**The golden rule you'll memorize:**

> **`printf()` takes VALUES. `scanf()` takes ADDRESSES (`&`).**

**Exception to the rule:** Strings (`char[]`) don't need `&` because the array name *is* an address.

```c
char name[50];
scanf("%s", name);   // NO & before name (name IS an address)
scanf("%d", &age);   // YES & before age (age is NOT an address)
```

---



# Chapter 4: The scanf Family — Let the User Talk

## Ask yourself: *Why am I hardcoding everything like it's 1985?*

Look at what we've been doing:

```c
int age = 45;
char username[50] = "Tony";
char city[50] = "Nakuru";


## Format Specifiers for `scanf()` (Slightly Different from `printf()`)

Most specifiers are the same, but there's one trap:

| Specifier | What it reads | Example |
|-----------|--------------|---------|
| `%d` | Integer | `scanf("%d", &num);` |
| `%f` | Float | `scanf("%f", &price);` |
| `%lf` | Double (⚠️ NOT `%f`!) | `scanf("%lf", &bigNum);` |
| `%c` | Single character | `scanf("%c", &letter);` |
| `%s` | String (no spaces!) | `scanf("%s", name);` |

**THE DOUBLE TRAP:**

```c
// WRONG for double:
double pi;
scanf("%f", &pi);   // WRONG! %f is for float, not double

// CORRECT for double:
double pi;
scanf("%lf", &pi);  // %lf = long float = double
```

`printf()` uses `%f` for both `float` and `double`.  
`scanf()` is picky: `%f` for `float`, `%lf` for `double`.

---

## Multiple Inputs in One Line

You can read several values at once:

```c
int day, month, year;
printf("Enter date (DD MM YYYY): ");
scanf("%d %d %d", &day, &month, &year);
printf("You entered: %d/%d/%d\n", day, month, year);
```

User types: `25 12 2024` → Program reads all three.

**Whitespace is the separator.** Space, tab, or Enter — all work.

---

## The `scanf` Family (Three Functions, One Purpose)

`scanf()` has two siblings you'll use constantly:

| Function | Reads From | Real-world use |
|----------|-----------|----------------|
| `scanf()` | Keyboard (`stdin`) | Getting user input right now |
| `sscanf()` | String (in memory) | Parsing text you already have |
| `fscanf()` | File | Loading saved data from disk |

### 1. `scanf()` — From Keyboard

```c
int age;
scanf("%d", &age);
```

### 2. `sscanf()` — From String (Convert Text to Numbers)

This is **incredibly useful**. You'll use this more than `scanf()` in real programs.

```c
char userInput[] = "42";
int answer;
sscanf(userInput, "%d", &answer);  // "42" (text) → 42 (number)
printf("The answer is %d\n", answer);
```

**Why is this useful?** Because `scanf()` has issues with spaces and newlines. The safe pattern is:

```c
char buffer[100];
printf("Enter your age: ");
fgets(buffer, 100, stdin);     // Safe: gets entire line
sscanf(buffer, "%d", &age);    // Parse it
```

> **Pro tip:** Real C programmers often avoid `scanf()` and use `fgets()` + `sscanf()` instead. It's safer and more predictable.
### 3. `fscanf()` — From File

```c
FILE *file = fopen("saved_data.txt", "r");
int savedAge;
fscanf(file, "%d", &savedAge);  // Reads from file, not keyboard
fclose(file);
printf("Loaded from file: %d\n", savedAge);
```

---

## The Return Value of `scanf()` (Error Checking)

`scanf()` returns the **number of successful conversions**.

```c
int age;
int result = scanf("%d", &age);

if (result == 1) {
    printf("Success! Age = %d\n", age);
} else {
    printf("Failed! You didn't enter a number.\n");
}
```

**Multiple inputs:**

```c
int x, y;
int count = scanf("%d %d", &x, &y);

if (count == 2) {
    printf("Got both: %d and %d\n", x, y);
} else if (count == 1) {
    printf("Only got x = %d, missing y\n", x);
} else {
    printf("Failed to read anything\n");
}
```

---
## Common Pitfalls 

### Pitfall 1: Forgetting `&`

```c
int age;
scanf("%d", age);   // MISSING & — CRASH or WEIRD BEHAVIOR
```

`scanf()` thinks `age` contains an address. It doesn't. It contains garbage. It writes to random memory. **Your program crashes or corrupts data.**

### Pitfall 2: Using `&` with Strings

```c
char name[50];
scanf("%s", &name);   // EXTRA & — WRONG (but might SEEM to work)
```

`name` already IS an address. `&name` is the address of the address. It might appear to work, but it's wrong.

**Correct:** `scanf("%s", name);`

### Pitfall 3: Mixing `scanf()` with `fgets()`

```c
int age;
char name[50];

printf("Enter age: ");
scanf("%d", &age);    // User types 25 and presses Enter

printf("Enter name: ");
fgets(name, 50, stdin);   // This gets an EMPTY line! The Enter from before!
```

**Why?** `scanf()` leaves the newline (`\n`) in the buffer. `fgets()` reads it immediately.

**Solution 1:** Use `fgets()` + `sscanf()` for everything:

```c
char buffer[100];
printf("Enter age: ");
fgets(buffer, 100, stdin);
sscanf(buffer, "%d", &age);

printf("Enter name: ");
fgets(name, 50, stdin);
// name now has the newline at the end though...
```

**Solution 2:** Eat the newline with `getchar()`:

```c
scanf("%d", &age);
getchar();  // Consumes the leftover newline
fgets(name, 50, stdin);
```

### Pitfall 4: `%s` Stops at Spaces

```c
char fullName[100];
printf("Enter your full name: ");
scanf("%s", fullName);
// User types: "Tony Ngugi"
// fullName gets: "Tony" — "Ngugi" is left in buffer!
```

`%s` stops at the first whitespace. Use `fgets()` for strings with spaces:
```c
char fullName[100];
printf("Enter your full name: ");
fgets(fullName, 100, stdin);  // Gets "Tony Stark\n"
```

### Pitfall 5: Buffer Overflow (Dangerous)

```c
char name[10];
scanf("%s", name);   // User types "AlexanderTheGreat" — 17 chars into 10-byte buffer
```

**CRASH. CORRUPTION. SECURITY VULNERABILITY.**

**Fix:** Limit the input length:

```c
char name[10];
scanf("%9s", name);   // Reads max 9 chars + null terminator
```

---
## Complete Example: Interactive User Profile

The full interactive profile example has been moved into source files. See [`interactive_profile.c`](interactive_profile.c) for the basic `scanf()` version, or [`interactive_profile_fgets.c`](interactive_profile_fgets.c) for the safer `fgets()` + `sscanf()` version.

---

## The Safe Pattern: `fgets()` + `sscanf()`

Real-world C code often avoids `scanf()` for user input. Here's the safer pattern:

```c
#include <stdio.h>

int main() {
    char buffer[100];
    int age;
    float salary;
    
    printf("Enter age and salary: ");
    fgets(buffer, sizeof(buffer), stdin);  // Read ENTIRE line safely
    
    if (sscanf(buffer, "%d %f", &age, &salary) == 2) {
        printf("Age: %d, Salary: %.2f\n", age, salary);
    } else {
        printf("Invalid input! Need age and salary.\n");
    }
    
    return 0;
}
```

**Why this is better:**

| `scanf()` alone | `fgets()` + `sscanf()` |
|----------------|------------------------|
| Leaves newline in buffer | Reads entire line, newline and all |
| Buffer overflow risk | Safe (you specify max length) |
| Hard to recover from bad input | You can try parsing differently |
| Mixed behavior with spaces | Predictable |

---

## Comparison Table: `printf()` vs `scanf()`

| Aspect | `printf()` | `scanf()` |
|--------|-----------|-----------|
| Direction | Program → User | User → Program |
| Needs `&`? | No (needs value) | Yes (needs address) |
| `%f` for double | Yes | No (needs `%lf`) |
| `%s` stops at space? | N/A (printing) | Yes (reading) |
| Returns | Number of chars printed | Number of items successfully read |
| Safety | Generally safe | Buffer overflow risk |

---
## Quick Reference: `scanf()` Format Specifiers

| Specifier | Variable Type | Needs `&`? |
|-----------|--------------|-----------|
| `%d` | `int` | Yes |
| `%f` | `float` | Yes |
| `%lf` | `double` | Yes |
| `%c` | `char` | Yes |
| `%s` | `char[]` | No |
| `%x` | `int` (hex) | Yes |
| `%o` | `int` (octal) | Yes |

---

## Practice Exercises

### Exercise 1: Basic Input

```c
#include <stdio.h>

int main() {
    int favoriteNumber;
    
    printf("What's your favorite number? ");
    scanf("%d", &favoriteNumber);
    
    printf("%d is a great number!\n", favoriteNumber);
    
    return 0;
}
```