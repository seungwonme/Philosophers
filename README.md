# Philosophers
The `Philosophers` project is part of the 42 school curriculum, challenging students to implement the dining philosophers problem using both mutexes and semaphores. This project aims to enhance understanding of parallel programming, synchronization, and resource sharing in a multi-threaded environment.

## Overview
The project is divided into two parts:

### Philo
The `philo` directory implements the dining philosophers problem using mutexes for locking. Key features include:

- **Philosopher simulation**: Simulates the dining philosophers scenario with a specified number of philosophers, forks, and time constraints.
- **Mutex locking**: Ensures thread-safe access to shared resources such as forks and the display.

### Philo_bonus
The `philo_bonus` directory implements the same dining philosophers problem but uses semaphores for locking. Key features include:

- **Philosopher simulation**: Simulates the dining philosophers scenario with a specified number of philosophers, forks, and time constraints.
- **Semaphore locking**: Ensures thread-safe access to shared resources such as forks and the display.

## Usage
1. Clone the repository:
```bash
git clone https://github.com/seungwonme/Philosophers.git
```

2. Navigate to the project directory:
```bash
cd philosophers
```

3. Compile the philo or philo_bonus executable:
```bash
make
```

4. Run the program with appropriate arguments:
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

Example:
```bash
./philo 5 800 200 200
```

- To clean up object files:
```bash
make clean
```

- To delete all build files:
```bash
make fclean
```

- To clean and rebuild the executable:
```bash
make re
```
