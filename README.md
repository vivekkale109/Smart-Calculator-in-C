# 🧠 Smart Calculator in C

A powerful **Smart Calculator** built in C that supports arithmetic expressions, scientific functions, unit conversions, and financial calculations — all in a single CLI application.

---

## 🚀 Features

### 🔢 Arithmetic (Stack-Based)

* Supports full expressions like:

  * `2 + 3 * (4 + 5)`
* Uses:

  * Infix → Postfix conversion
  * Stack-based evaluation

### 🔬 Scientific Functions

* Square root (`sqrt`)
* Trigonometry (`sin`, `cos`)
* Logarithm (`log10`)

### 🔄 Unit Conversion

* Kilometer ↔ Meter
* Inch → Centimeter

### 💰 Financial Calculator

* EMI (Loan Calculator)

### ⚖️ Health Tool

* BMI Calculator

---

## 🧱 Concepts Used

* Stack (Data Structure)
* Expression Parsing
* Operator Precedence
* Modular Programming
* Math Library (`math.h`)

---

## 📂 Project Structure

```bash
calculator.c   # Complete program (single file)
```

---

## ⚙️ Compilation & Run

```bash
gcc calculator.c -o calc -lm
./calc
```

> ⚠️ `-lm` is required for math functions like `pow()`, `sqrt()`

---

## 🖥️ Usage

```text
===== SMART CALCULATOR =====
1. Arithmetic (Expression)
2. Scientific
3. Unit Conversion
4. EMI Calculator
5. BMI Calculator
6. Exit
```

---

## 🧪 Example

```text
Enter choice: 1
Enter expression: 2+3*(4+5)

Result = 29.00
```

---

## ⚠️ Limitations

* Limited decimal handling in expressions
* No support for functions inside expressions (e.g., `sin(30)`)
* Basic UI (CLI only)

---

## 🔥 Future Improvements

* Add full decimal & negative number support
* Support expressions like `sin(30) + sqrt(16)`
* Add history (file storage)
* Improve UI (colors / Linux-style interface)
* Add matrix operations 

---

## 👨‍💻 Author

**Vivek Kale**
GitHub: https://github.com/vivekkale109

---

## ⭐ Contribute

Feel free to fork, improve, and submit pull requests!

---

## 📜 License

This project is open-source and available under the MIT License.
