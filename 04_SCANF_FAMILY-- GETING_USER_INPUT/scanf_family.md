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