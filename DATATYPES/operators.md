# Chapter 3: Operators — The *Do*

## Ask yourself: *How do I make my variables do something?*

So you've got these fancy variables, right? Little labeled boxes sitting in memory. `age = 25`. `score = 100`. `temperature = 36.6`.

They just... sit there.

Looking at you.

Waiting.

**Kinda boring, aren't they?**

Variables without operators are like an audi with no engine or no rings(then what good is it?). Beautiful to look at. Completely useless.

Operators are what make things *happen*. They're the verbs. The action. The *oomph*.

> **Variables are nouns. Operators are verbs.**
> 
> *"The score increased by 10"* — that's an operator.
> *"Is the temperature greater than 37?"* — that's an operator.
> *"Did the user enter the correct password?"* — that's operators all the way down.

---
## The Cast of Characters

Before we dive in, let me tell you something that confused me for weeks:

Every operator works on **operands**. Operands are just fancy programmer-speak for "the things the operator touches."

```c
int sum = 5 + 3;
```

- `5` and `3` are **operands** (the poor souls being operated on)
- `+` is the **operator** (the bully doing the operation)
- `sum` is the **result** (the aftermath)

Simple, right? Now let me blow your mind:

**Some operators work on ONE operand. Some work on TWO. ONE works on THREE.**

| Type | Number of Operands | Nickname | Examples |
|------|-------------------|----------|----------|
| Unary | 1 | "The Loners" | `++`, `--`, `!`, `-` |
| Binary | 2 | "The Couples" | `+`, `-`, `*`, `/`, `%`, `=`, `==`, `<`, `>` |
| Ternary | 3 | "The Love Triangle" | `? :` (the only one) |

```c
int x = 5;     // Binary: = works on x AND 5 (a couple)
x++;           // Unary: ++ works on JUST x (a loner)
int max = (a > b) ? a : b;  // Ternary: THREE operands (drama)
```

> **Fun fact:** The ternary operator `?:` is the only operator in C that needs three operands. It's like that one friend who can't make a decision without consulting two other people.

---



## The Six Families of Operators

C has six types of operators. Think of them as six different toolboxes:

| Family | Job Description | Everyday Analogy |
|--------|----------------|------------------|
| **Arithmetic** | Do math | Your calculator |
| **Relational** | Compare things | The judge in a boxing match |
| **Logical** | Combine true/false | The bouncer at a club ("you need ID AND a ticket") |
| **Bitwise** | Mess with individual bits | A surgeon working on bones instead of the whole body |
| **Assignment** | Give values to variables | Putting groceries in your fridge |
| **Other** | The weird cousins | `sizeof`, `&`, `*`, `?:`, `,`, cast |

We'll cover ALL of them. But first, let's start with the ones you'll use every single day.

---


```c
int a = 7;
int b = 3;
int c = a / b;   // c = 2. Not 2.333. Just 2.

printf("%d", 5 / 2);  // Prints 2
printf("%d", 9 / 4);  // Prints 2 (2.25 becomes 2)
printf("%d", 1 / 2);  // Prints 0 (0.5 becomes 0... sad, isn't it?)
```

**"But that's wrong!"** you say.

I know. It feels wrong. But C is old. Really old. Like, "born in 1972" old. And on old computers, decimals were expensive. So C said: "If you want decimals, you have to ask nicely."

**How to get decimals?** Use `float` or `double`:

```c
float a = 7.0;
float b = 3.0;
float c = a / b;   // c = 2.333333

// Or mix them:
printf("%f", 7 / 3.0);   // 2.333333 (3.0 is float, so result is float)
printf("%f", 7.0 / 3);   // 2.333333 (7.0 is float)
```


## Family 1: Arithmetic Operators (The Mathletes)

These are your basic math operations. You've been using them since first grade. But C adds a few twists.

### The Classics

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `+` | Addition | `7 + 3` | `10` |
| `-` | Subtraction | `7 - 3` | `4` |
| `*` | Multiplication | `7 * 3` | `21` |
| `/` | Division | `7 / 3` | `2` (⚠️ WAIT, WHAT?) |
| `%` | Modulo (remainder) | `7 % 3` | `1` |

See that division? `7 / 3 = 2`? Not `2.333...`?

**Welcome to the first trap of C programming.**

### The Division Trap (Read This Twice)

Here's the deal: When you divide two **integers**, C gives you back an **integer**. It doesn't round. It doesn't give you decimals. It **truncates** — it chops off the decimal part like a guillotine.

> **The Golden Rule of Division:**
> - `int / int` = `int` (decimals get CHOPPED OFF, not rounded)
> - `float / anything` = `float`
> - `anything / float` = `float`

### The Modulo Operator (`%`) — The One Nobody Understands at First

Modulo gives you the **remainder** after division. That's it. But it's INCREDIBLY useful.

```c
10 % 3 = 1   // 3 goes into 10 three times (9), left with 1
7 % 5 = 2    // 5 goes into 7 once (5), left with 2
8 % 2 = 0    // 2 goes into 8 four times (8), left with 0
17 % 5 = 2   // 5 goes into 17 three times (15), left with 2
```

**Think of it like this:** You have 10 cookies. You want to put them in boxes of 3. You fill 3 boxes (9 cookies). You have 1 cookie left. That leftover? That's the modulo.

```c
int cookies = 10;
int boxSize = 3;
int fullBoxes = cookies / boxSize;   // 3 full boxes
int leftover = cookies % boxSize;     // 1 cookie left (so sad)

printf("You have %d full boxes and %d lonely cookies.\n", fullBoxes, leftover);
```

**Real-world uses of modulo (this is where it gets cool):**

| Use Case | Code | Why it works |
|----------|------|--------------|
| Is a number even? | `if (num % 2 == 0)` | Even numbers divide by 2 with no remainder |
| Is a number odd? | `if (num % 2 != 0)` | Odd numbers always have remainder 1 |
| Get last digit of a number | `int last = num % 10;` | `1234 % 10 = 4` |
| Wrap around an array | `index = (index + 1) % maxSize` | When you reach the end, go back to 0 |
| Convert seconds to minutes | `int secondsLeft = totalSeconds % 60;` | Remainder after taking out full minutes |


```c
// Check if a number is even or odd
int num = 17;
if (num % 2 == 0) {
    printf("%d is even\n", num);
} else {
    printf("%d is odd\n", num);  // This runs
}
```

> **Warning:** `%` ONLY works with integers. You can't do `5.5 % 2`. C will yell at you.

### Unary Arithmetic (One Operand Wonders)

So far, all our operators worked on two things. But some operators work on ONE thing.

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `+` (unary) | Positive value | `+5` | `5` (useless, honestly) |
| `-` (unary) | Negative value | `-5` | `-5` (actually useful) |

```c
int x = 5;
int y = -x;   // y = -5
int z = +x;   // z = 5 (why would you do this?)
```

The unary `-` is great for flipping signs. The unary `+` exists just to make the compiler happy. Don't overthink it.

### Increment and Decrement (`++` and `--`) — The Most Confusing Operators in C

These operators add or subtract 1 from a variable. Simple, right?


```c
int counter = 0;
counter++;    // counter becomes 1
counter++;    // counter becomes 2
counter--;    // counter becomes 1
```

**So why do people get confused?**

Because there are TWO versions:

| Version | Name | What it does |
|---------|------|--------------|
| `x++` | Post-increment | Use x, THEN increase it |
| `++x` | Pre-increment | Increase x, THEN use it |

**This matters. A lot.**

```c
int x = 5;
int y = x++;   // y gets 5, THEN x becomes 6
// After this line: x = 6, y = 5

int a = 5;
int b = ++a;   // a becomes 6, THEN b gets 6
// After this line: a = 6, b = 6
```


## Family 1: Arithmetic Operators (The Mathletes)

These are your basic math operations. You've been using them since first grade. But C adds a few twists.

### The Classics

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `+` | Addition | `7 + 3` | `10` |
| `-` | Subtraction | `7 - 3` | `4` |
| `*` | Multiplication | `7 * 3` | `21` |
| `/` | Division | `7 / 3` | `2` (⚠️ WAIT, WHAT?) |
| `%` | Modulo (remainder) | `7 % 3` | `1` |

See that division? `7 / 3 = 2`? Not `2.333...`?

**Welcome to the first trap of C programming.**

### The Division Trap (Read This Twice)

Here's the deal: When you divide two **integers**, C gives you back an **integer**. It doesn't round. It doesn't give you decimals. It **truncates** — it chops off the decimal part like a guillotine.

> **The Golden Rule of Division:**
> - `int / int` = `int` (decimals get CHOPPED OFF, not rounded)
> - `float / anything` = `float`
> - `anything / float` = `float`

### The Modulo Operator (`%`) — The One Nobody Understands at First

Modulo gives you the **remainder** after division. That's it. But it's INCREDIBLY useful.

```c
10 % 3 = 1   // 3 goes into 10 three times (9), left with 1
7 % 5 = 2    // 5 goes into 7 once (5), left with 2
8 % 2 = 0    // 2 goes into 8 four times (8), left with 0
17 % 5 = 2   // 5 goes into 17 three times (15), left with 2
```

**Think of it like this:** You have 10 cookies. You want to put them in boxes of 3. You fill 3 boxes (9 cookies). You have 1 cookie left. That leftover? That's the modulo.

```c
int cookies = 10;
int boxSize = 3;
int fullBoxes = cookies / boxSize;   // 3 full boxes
int leftover = cookies % boxSize;     // 1 cookie left (so sad)

printf("You have %d full boxes and %d lonely cookies.\n", fullBoxes, leftover);
```

**Real-world uses of modulo (this is where it gets cool):**

| Use Case | Code | Why it works |
|----------|------|--------------|
| Is a number even? | `if (num % 2 == 0)` | Even numbers divide by 2 with no remainder |
| Is a number odd? | `if (num % 2 != 0)` | Odd numbers always have remainder 1 |
| Get last digit of a number | `int last = num % 10;` | `1234 % 10 = 4` |
| Wrap around an array | `index = (index + 1) % maxSize` | When you reach the end, go back to 0 |
| Convert seconds to minutes | `int secondsLeft = totalSeconds % 60;` | Remainder after taking out full minutes |

```c
// Check if a number is even or odd
int num = 17;
if (num % 2 == 0) {
    printf("%d is even\n", num);
} else {
    printf("%d is odd\n", num);  // This runs
}
```

> **Warning:** `%` ONLY works with integers. You can't do `5.5 % 2`. C will yell at you.

### Unary Arithmetic (One Operand Wonders)

So far, all our operators worked on two things. But some operators work on ONE thing.

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `+` (unary) | Positive value | `+5` | `5` (useless, honestly) |
| `-` (unary) | Negative value | `-5` | `-5` (actually useful) |

```c
int x = 5;
int y = -x;   // y = -5
int z = +x;   // z = 5 (why would you do this?)
```

The unary `-` is great for flipping signs. The unary `+` exists just to make the compiler happy. Don't overthink it.

### Increment and Decrement (`++` and `--`) — The Most Confusing Operators in C

These operators add or subtract 1 from a variable. Simple, right?

```c
int counter = 0;
counter++;    // counter becomes 1
counter++;    // counter becomes 2
counter--;    // counter becomes 1
```

**So why do people get confused?**

Because there are TWO versions:

| Version | Name | What it does |
|---------|------|--------------|
| `x++` | Post-increment | Use x, THEN increase it |
| `++x` | Pre-increment | Increase x, THEN use it |

**This matters. A lot.**

```c
int x = 5;
int y = x++;   // y gets 5, THEN x becomes 6
// After this line: x = 6, y = 5

int a = 5;
int b = ++a;   // a becomes 6, THEN b gets 6
// After this line: a = 6, b = 6
```

**The Memory Trick:**

- **Post**-increment: The `++` comes **after** the variable. It says: "Use me now, party later."
- **Pre**-increment: The `++` comes **before** the variable. It says: "Party now, then use me."

```c
int i = 10;
printf("%d\n", i++);  // Prints 10, then i becomes 11
printf("%d\n", i);    // Prints 11

int j = 10;
printf("%d\n", ++j);  // j becomes 11, then prints 11
printf("%d\n", j);    // Prints 11
```

**When do you use each? Here's the rule of thumb:**

| Use Case | Use | Why |
|----------|-----|-----|
| Just want to add 1, don't care about the value | `x++` | It's what most people expect |
| Need the NEW value right away | `++x` | You want the value AFTER incrementing |
| Need the OLD value before incrementing | `x++` | You want to use the current value, then update |

```c
// Real example: copying an array
int source[3] = {10, 20, 30};
int dest[3];
int i = 0;

// Post-increment: use i, THEN increase it
dest[i++] = source[i];  // Wait... this is actually WRONG! Let me explain.

// Better example:
int index = 0;
dest[index] = source[index];
index++;  // Separate increment is clearer for beginners
```

> **My advice:** When you're starting, just use `x++` by itself on its own line. Don't get fancy. Later, when you're comfortable, play with the difference.

---

## Family 2: Relational Operators (The Judges)

These operators **compare** things. They answer questions like: "Is 5 greater than 3?" "Is the password correct?"

The answer is always **1 (true)** or **0 (false)**.

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `<` | Less than | `5 < 3` | `0` (false) |
| `>` | Greater than | `5 > 3` | `1` (true) |
| `<=` | Less than or equal | `5 <= 5` | `1` (true) |
| `>=` | Greater than or equal | `5 >= 7` | `0` (false) |
| `==` | Equal to (DOUBLE equals!) | `5 == 5` | `1` (true) |
| `!=` | Not equal to | `5 != 3` | `1` (true) |

**THE MOST COMMON BUG IN C HISTORY:**

```c
// This is WRONG:
if (x = 5) {   // SINGLE equals is ASSIGNMENT, not comparison!
    printf("x is 5");
}

// This is CORRECT:
if (x == 5) {  // DOUBLE equals is COMPARISON
    printf("x is 5");
}
```

**Why is this a bug?** Because `if (x = 5)` works! It assigns 5 to x, then checks if 5 is true (non-zero = true). So it's ALWAYS true. Your program will run but be completely wrong.

> **The Golden Rule:** Use `=` for assignment. Use `==` for comparison. Mix them up, and your program will lie to you.

```c
#include <stdio.h>

int main() {
    int a = 25, b = 5;
    
    printf("Is a less than b? %d\n", a < b);     // 0 (false)
    printf("Is a greater than b? %d\n", a > b);  // 1 (true)
    printf("Is a equal to b? %d\n", a == b);     // 0 (false)
    printf("Is a not equal to b? %d\n", a != b); // 1 (true)
    
    return 0;
}
```

**Output:**
```
Is a less than b? 0
Is a greater than b? 1
Is a equal to b? 0
Is a not equal to b? 1
```

Notice: 0 means NO (false). 1 means YES (true). Any non-zero number is considered true, but comparisons always return exactly 1 for true.

---

## Family 3: Logical Operators (The Bouncers)

Logical operators combine **true/false** values. They're like a bouncer at a club:

- **AND (`&&`)** : "You need BOTH an ID AND a ticket to enter."
- **OR (`||`)** : "You need EITHER a VIP pass OR a hand stamp to enter."
- **NOT (`!`)** : "You are NOT on the blacklist? Come in."

| Operator | Meaning | Truth | Example |
|----------|---------|-------|---------|
| `&&` | AND | True if BOTH are true | `(age >= 18) && (hasTicket)` |
| `\|\|` | OR | True if AT LEAST ONE is true | `(isVip) \|\| (hasStamp)` |
| `!` | NOT | True if false, false if true | `!isBlocked` |

### The Truth Table (Memorize This)

| a | b | a && b | a \|\| b | !a |
|---|---|--------|---------|----|
| 0 (false) | 0 (false) | 0 | 0 | 1 |
| 0 (false) | 1 (true) | 0 | 1 | 1 |
| 1 (true) | 0 (false) | 0 | 1 | 0 |
| 1 (true) | 1 (true) | 1 | 1 | 0 |

```c
#include <stdio.h>

int main() {
    int age = 20;
    int hasLicense = 1;  // 1 = true
    int isDrunk = 0;     // 0 = false
    
    // Can they drive? Need age >= 16 AND license AND not drunk
    int canDrive = (age >= 16) && hasLicense && !isDrunk;
    printf("Can drive? %d\n", canDrive);  // 1 (true)
    
    // Club entry: age >= 18 OR with parent
    int hasParent = 0;
    int canEnter = (age >= 18) || hasParent;
    printf("Can enter club? %d\n", canEnter);  // 1 (true)
    
    return 0;
}
```

### Short-Circuit Evaluation (A Cool Quirk)

C is lazy. Really lazy. When evaluating logical operators, it stops as soon as it knows the answer.

```c
int x = 5;
int y = 0;

// In AND (&&), if the FIRST thing is false, it doesn't check the rest
if (y != 0 && x / y > 2) {
    // This will NEVER run the division because y != 0 is false
    // GOOD! Because dividing by zero would crash.
}

// In OR (||), if the FIRST thing is true, it doesn't check the rest
if (x > 0 || someExpensiveFunction()) {
    // If x > 0 is true, it never calls someExpensiveFunction()
    // This saves time!
}
```

**Why this matters:** You can write safer code by putting checks in the right order.

```c
// SAFE: Check if pointer exists BEFORE using it
if (ptr != NULL && ptr->value > 10) {
    // Only checks ptr->value if ptr is not NULL
}

// DANGEROUS: This could crash if ptr is NULL
if (ptr->value > 10 && ptr != NULL) {
    // Tries to access ptr->value BEFORE checking if ptr exists
}
```

---

## Family 4: Assignment Operators (The Givers)

These put values into variables. You already know the simple one:

```c
int x = 5;   // Assign 5 to x
```

But C has **compound assignment operators** that combine an operation with assignment:

| Operator | Means | Example |
|----------|-------|---------|
| `+=` | Add and assign | `x += 3` is `x = x + 3` |
| `-=` | Subtract and assign | `x -= 3` is `x = x - 3` |
| `*=` | Multiply and assign | `x *= 3` is `x = x * 3` |
| `/=` | Divide and assign | `x /= 3` is `x = x / 3` |
| `%=` | Modulo and assign | `x %= 3` is `x = x % 3` |

**Why use these?** They're shorter and sometimes clearer:

```c
// Long way
score = score + 10;
total = total * 2;
count = count + 1;

// Short way (same thing)
score += 10;
total *= 2;
count += 1;  // Or count++ if just adding 1
```

```c
#include <stdio.h>

int main() {
    int score = 100;
    
    printf("Starting score: %d\n", score);  // 100
    
    score += 50;   // score = 150
    printf("After bonus: %d\n", score);
    
    score -= 25;   // score = 125
    printf("After penalty: %d\n", score);
    
    score *= 2;    // score = 250
    printf("After doubling: %d\n", score);
    
    score /= 10;   // score = 25
    printf("After dividing: %d\n", score);
    
    return 0;
}
```

> **Pro tip:** Compound operators are especially useful in loops. You'll see them constantly in real code.

---

## Family 5: Bitwise Operators (The Bit Surgeons)

**Warning:** This section is more advanced. If your brain is full, skip it and come back later. You can write lots of C code without ever using bitwise operators.

But if you want to be a **real** C programmer, learn them. They're what make C fast.

Bitwise operators work on individual **bits** (0s and 1s). Every number in your computer is stored as bits.

```
Decimal 5 in binary (8 bits): 00000101
Decimal 3 in binary (8 bits): 00000011
```

| Operator | Name | What it does |
|----------|------|--------------|
| `&` | AND | Bit is 1 ONLY if BOTH bits are 1 |
| `\|` | OR | Bit is 1 if AT LEAST ONE bit is 1 |
| `^` | XOR | Bit is 1 if bits are DIFFERENT |
| `~` | NOT | Flips all bits (0 becomes 1, 1 becomes 0) |
| `<<` | Left shift | Shifts bits left (multiplies by 2 for each shift) |
| `>>` | Right shift | Shifts bits right (divides by 2 for each shift) |

### How They Work (With Examples)

**AND (`&`):** Both must be 1
```
  5: 00000101
& 3: 00000011
--------------
  1: 00000001   (only the last bit is 1 in both)
```

**OR (`|`):** At least one is 1
```
  5: 00000101
| 3: 00000011
--------------
  7: 00000111
```

**XOR (`^`):** Exactly one is 1 (different)
```
  5: 00000101
^ 3: 00000011
--------------
  6: 00000110
```

**NOT (`~`):** Flip everything
```
~5: 11111010  (which is -6 in two's complement)
```

**Left Shift (`<<`):** Move bits left (multiply by 2)
```
5 << 1 = 10   (00000101 becomes 00001010)
5 << 2 = 20   (00000101 becomes 00010100)
5 << 3 = 40
```

**Right Shift (`>>`):** Move bits right (divide by 2)
```
20 >> 1 = 10   (00010100 becomes 00001010)
20 >> 2 = 5    (00010100 becomes 00000101)

