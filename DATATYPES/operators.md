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