# 🌳 Red-Black Tree – C Project

## 🚀 Overview

The **Red-Black Tree** project is a command-line application developed in **C** that implements a **self-balancing binary search tree**.

Unlike a normal BST, the tree maintains balance using **color properties and rotations**, ensuring efficient operations.

It stores data as:

```
Sorted Binary Tree with Balance Guarantees
```

This structure is widely used in:

- STL `map` / `set`
- Database indexing
- Operating systems (Linux kernel RB-tree)
- Memory management systems

---

## 🎯 Features

### 🌱 Insertion

- Insert nodes using BST logic
- Maintain balance using Red-Black properties
- Handle LL, RR, LR, RL rotations
- Automatic recoloring and rotations

### ❌ Deletion

- Delete nodes (leaf, one child, two children)
- Maintain tree balance after deletion
- Handle double-black cases
- Uses recoloring and rotations

### 📊 Display

- Inorder traversal (sorted output)
- Display node colors (RED / BLACK)

### 🔧 Rotations

- Left Rotation
- Right Rotation
- Proper parent-child updates

---

## 🧠 Concepts Used

- Red-Black Tree Properties
- Binary Search Tree (BST)
- Tree Rotations
- Dynamic Memory Allocation (`malloc`, `free`)
- Pointer Manipulation

---

## ⚙️ Technologies Used

- Language: C  
- Platform: Linux / Windows  
- Compiler: GCC  

---

## 🏗️ Project Structure

```
Red_Black_Tree/
│── main.c
│── insert.c
│── delete.c
│── rotations.c
│── rb_fixup.c
│── bst_delete.c
│── display.c
│── rb_tree.h
```

---

## ▶️ How to Run

### Compile
```
gcc *.c -o rbtree
```

### Run
```
./rbtree
```

---

## 📋 Menu Options

```
1. Insert Node
2. Delete Node
3. Display Tree
4. Exit
```

---

## 💻 Sample Output

```
Insert: 10 5 15 1 7

Tree (Inorder with color):
1(R) 5(B) 7(R) 10(B) 15(B)

After Deleting 5:
1(B) 7(R) 10(B) 15(B)
```

---

## ⚠️ Limitations

- No GUI (CLI only)
- No duplicate key support
- Manual input only

---

## 🔮 Future Enhancements

- Tree visualization (ASCII / GUI)
- File-based input/output
- Duplicate handling
- Performance analysis

---

## 🧩 Challenges Faced

- Pointer handling
- Rotation correctness
- Deletion fix-up complexity
- Avoiding segmentation faults

---

## 📚 Learning Outcomes

- Understanding of self-balancing trees
- Practical RB-tree implementation
- Strong pointer and memory management skills

---

## 📌 Author

Shubham Chaudhari
