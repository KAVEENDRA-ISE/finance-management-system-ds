# 💰 Finance Management System (Data Structures Project)

## 📌 Overview
This project is a **Finance Management System implemented in C** that demonstrates the use of multiple **data structures** to manage financial activities.  
It allows tracking of **transactions, budgets, recurring payments, savings goals, and investments**, while showcasing the strengths of **Linked Lists, Stacks, Queues, Hashmaps, Heaps, and Binary Search Trees (BSTs)**.

---

## 🎯 Objectives
- Demonstrate practical applications of **fundamental data structures** in solving real-world problems.
- Build an efficient and scalable system for managing personal or organizational finance.
- Provide modular functionality with **transaction history, undo/redo, recurring payments, budgeting, investments, and savings goals**.

---

## 🛠 Tech Stack
- **Language:** C  
- **Concepts:** Data Structures (Linked List, Stack, Queue, Hashmap, Heap, BST)  
- **Compiler:** GCC / MinGW / Turbo C (for academics)  

---

## 📂 Features & Data Structures Used
1. **Linked List – Transaction History**  
   - Stores income/expense records dynamically.  
   - Operations: `addTransaction()`  

2. **Stack – Undo/Redo Functionality**  
   - Tracks user actions for rollback.  
   - Operations: `pushAction()`, `popAction()`  

3. **Queue – Recurring Payments**  
   - Manages payments like subscriptions (FIFO order).  
   - Operations: `enqueueRecurring()`, `dequeueRecurring()`  

4. **Hashmap – Budget Categories**  
   - Categorizes expenses/income with O(1) updates.  
   - Operations: `updateBudget()`, `hash()`  

5. **Heap – Investment Portfolio**  
   - Maintains top-performing investments in a max-heap.  
   - Operations: `insertInvestment()`  

6. **Binary Search Tree (BST) – Savings Goals**  
   - Stores savings goals in sorted order by amount.  
   - Operations: `addGoal()`, `displayGoals()`  

---

## 📂 Project Structure
finance-management-system-ds/
│── finance_system.c # Main C program
│── README.md # Documentation
## ⚙️ How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/finance-management-system-ds.git
   cd finance-management-system-ds
2. Compile the programm:
  gcc finance_system.c -o finance_system
3.Run the programm
  ./finance_system