# Modern C++ Multithreading & Concurrency

This repository tracks my progress through a comprehensive course on Modern C++ Multithreading, focusing on **C++20** and **C++23** standards. 

## 🚀 Project Overview

The goal is to master low-level system development and concurrent programming using modern standards. The project structure follows a bottom-up approach, starting from C++ basics to advanced synchronization primitives and thread management.

## 🛠 Tech Stack
* **Language:** C++20(Sometimes older)
* **Build System:** CMake
* **Tools:** MSVC / GCC / Clang (C++20 Modules support required)
* **Testing Framework:** Catch2(If Available in the project)

## 📅 Learning Roadmap

### Part 1: Modern C++ Revision
- [x] Basic syntax and RAII
*Includes exercises on smart pointers and memory management.*

### Part 2: Concurrency Introduction
- [x] Launching threads
- [x] Thread functions with arguments
- [x] Using **C++20 Modules** (`.ixx`) for clean interfaces

### Part 3: Getting Started with Threads
- [x] System Thread Interface
- [x] The `std::thread` class
- [x] Thread management (Join/Detach)
- [x] Identifying and fixing Data Races
- [x] Data Race Consequences

### Part 4: Advanced Concurrency (Planned)
- [ ] Mutexes and Locking
- [ ] Condition Variables & Promises
- [ ] Atomic Operations

## 📂 Repository Structure
* `/app`: Main application source files.
* `/inclusion`: Module interfaces (`.ixx`).
* `/tests`: Unit tests using Catch2.

## ⚙️ How to Build
1. Clone the repository.
2. Ensure you have a C++20 compatible compiler.
3. Run CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
