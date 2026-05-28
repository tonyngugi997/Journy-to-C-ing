# Chapter 1: Variables — The *Where*

## Ask yourself: *What is a variable?*

Think of a variable as a storage location in the computer's memory. A labeled box. A named address. A place to put things.

But then you stop and ask yourself:

> *"Storage… for *what*?"*

Fair question. The answer involves data types — and that's the next lesson.

For now, just hold this truth:

> **A variable is *where*.**  
> **A data type is *what kind*.**  
>
> You need both. But first, you need the container.

---

## 🧠 A Concrete Example

Imagine you're building a program that stores a user's data:

| Data | What is it? |
|------|-------------|
| `username` | A name, like "Coder42" |
| `password` | A secret string, like "hunter2" |
| `age` | A number, like 25 |
| `gender` | A single letter or word, like 'M' or 'F' |

The program needs to store each piece of information *somewhere*. That *somewhere* is a **variable**.

- `username` goes into a variable named `username`
- `age` goes into a variable named `age`
- `password` goes into a variable named `password`

**But here's the catch:** The computer needs to know *how much space* to reserve and *how to interpret* the bits it stores.

That's where data types come in. But again — that's the next lesson.

---

## 🔧 What You Can Do Right Now

Even without knowing data types deeply, you can already *declare* variables.

***QUIZ:* `Write a program that store: a username, age, password`

👉 **[See answer at:  `01_declaring_variables.c`](./01_declaring_variables.c)** — Variables as labeled containers.

Those `char`, `int`, `char` things you see in the file? **Those are data types (preview).**  
When declaring a variable, you must start with the datatype.
For now, just see the pattern:

> **Every variable has a name (`username`, `age`) and a type (`char[]`, `int`).**

### 🔡 Escape Sequences: `\n`, `\t`, and more

In C strings, a backslash `\` starts an escape sequence. That means the next character is not printed literally — it tells the computer to do something special.

- `\n` = newline (move to the next line)
- `\t` = tab (insert horizontal spacing)
- `\\` = backslash (print a literal `\`)
- `\"` = double quote (print `"` inside a string)

Example:
```c
printf("Hello\nWorld\t!\n");
```
This prints:
- `Hello`
- then a new line
- `World`
- then a tab
- then `!`

Escape sequences let you format output cleanly without extra text.

The name answers: *"Where do I put this?"*  
The type answers: *"How much space? What kind of value?"*

---

## 💀 The Dark Truth (For Later)

Right now, you think variables are simple.  
They are not.

A variable is a *lie we agree to tell the machine*. The machine only understands memory addresses and raw bits. A variable is a **human-friendly label** for a chunk of bytes.

👉 **See the address behind the name.**

That's the deal. You get names. The machine gets addresses. Everyone wins — until you forget that `age` is *just a label*.

---

## ✅ Summary for This Lesson

| Concept | What it means |
|---------|----------------|
| Variable | A named storage location in memory |
| Declaration | Telling the computer: "Reserve space for this variable" |
| Name | How you refer to that location in code |
| Type (preview) | How much space and what interpretation |

**Your takeaway:**  
> A variable is *where* you put things.  
> You don't need to know *what* things yet — just that they need a *where*.

---

## 🧪 Exercises

Try these yourself. No peeking at the solutions until you've struggled.

| Exercise | File |
|----------|------|
| Declare a variable for a student's ID number. Print its address. | `exercise1_your_solution.c` |
| Declare 3 different variables of different types. Print all their addresses. | `exercise2_your_solution.c` |
| What happens if you declare a variable but never use it? (Compile with `-Wall`) | `exercise3_your_solution.c` |

👉 Solutions (try first!): create a `solutions/` folder and add your answers there.

---

## 📚 Next Lesson

**Chapter 2: Data Types — The *What***  
Now that you have containers, what can you put inside them?

---

