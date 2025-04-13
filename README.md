# 🧠 Philosophers

This is a 42 project that revisits the classic **Dining Philosophers** problem — a fundamental exercise in concurrent programming and thread synchronization. The goal is to handle multiple processes accessing shared resources without deadlocks or starvation.

## 🛠 Technologies & Concepts

- **Language:** C
- **Platform:** Linux
- **Threading:** POSIX threads (`pthreads`)
- **Concurrency:** Mutexes for thread synchronization
- **Memory Management:** Manual allocation and deallocation
- **Process Coordination:** Shared resource access, deadlock prevention

## 🚀 Objectives

- Implement a simulation where philosophers alternate between thinking, eating, and sleeping.
- Prevent race conditions and ensure no deadlocks occur.
- Manage time constraints (e.g., philosophers must eat within a time limit or they "die").
- Use mutexes to manage access to shared forks (resources).
- Respect the rules of concurrent execution with minimal resource usage.

## 📦 Features

- Dynamic input parsing: number of philosophers, time to die, time to eat, time to sleep, and optional meals per philosopher.
- Logging system to track each philosopher’s status with timestamps.
- Detection of philosopher death to terminate the simulation properly.
- Optional bonus version with **processes**, **semaphores**, or additional concurrency challenges.

## 🧪 Skills Gained

- Multithreaded programming and synchronization
- Critical section management
- Deadlock and starvation prevention strategies
- Debugging concurrent applications
- Efficient use of system resources

## 🔗 Related Concepts

- [Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- Mutexes vs. Semaphores
- Concurrency in Operating Systems

---

👀 If you’re interested in how operating system principles apply to real-time systems or multithreaded applications, this project offers a hands-on perspective!

