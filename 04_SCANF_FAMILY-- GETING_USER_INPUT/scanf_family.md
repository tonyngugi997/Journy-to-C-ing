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
