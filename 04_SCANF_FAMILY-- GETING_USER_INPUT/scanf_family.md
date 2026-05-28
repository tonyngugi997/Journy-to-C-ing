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