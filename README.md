# Separate Chaining Hashmap

This repository contains an implementation of a **Separate Chaining Hashmap** with benchmarking and testing frameworks. The primary focus of this project is to compare the performance of a custom hashmap implementation using raw pointers and `std::shared_ptr` against the standard C++ `unordered_map`.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Performance Benchmarks](#performance-benchmarks)
- [Usage](#usage)
- [Installation](#installation)
- [Testing](#testing)

## Overview

This project implements a hashmap using **separate chaining** as a collision resolution technique. Three different hashmaps are compared:
1. **Standard C++ `unordered_map`** – A highly optimized, standard implementation.
2. **`RawPtr::Hashmap`** – A custom hashmap using raw pointers.
3. **`SharedPtr::Hashmap`** – A custom hashmap using `std::shared_ptr` for automatic memory management.

The performance of these implementations is evaluated using the **Google Benchmark** framework, and the project includes unit tests for functionality validation with **Google Test**.

## Features
- **Separate Chaining Hashmap** implementation using raw pointers and shared pointers.
- **Benchmarking** to compare the performance of different hashmap implementations.
- **Google Test** for unit testing of various hashmap operations such as insertions, lookups, and initialization.
- **Google Benchmark** for performance profiling.

## Performance Benchmarks

The performance benchmarks compare the following hashmap implementations:
- **Initialization**: Measures the time taken to initialize the hashmaps.
- **Insertion**: Measures the time taken to insert a varying number of elements.
- **Lookup**: Measures the time taken to look up elements in the hashmaps.

Benchmark results show how each hashmap scales with increasing data sizes (from 1 element to 4096 elements).

```bash
Running ./runbenchmark
Run on (12 X 2616.88 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 1280 KiB (x6)
  L3 Unified 18432 KiB (x1)
Load Average: 0.20, 0.35, 0.34
----------------------------------------------------------------------------
Benchmark                                  Time             CPU   Iterations
----------------------------------------------------------------------------
unordered_map_init                     0.000 ns        0.000 ns   1000000000000
rawptr_hashmap_init                     14.0 ns         14.0 ns     49703927
sharedptr_hashmap_init                  13.1 ns         13.1 ns     53452459
unordered_map_insert_int/1              2.29 ns         2.29 ns    301780987
unordered_map_insert_int/16             36.5 ns         36.5 ns     19155509
unordered_map_insert_int/256             585 ns          585 ns      1197761
unordered_map_insert_int/4096           9374 ns         9374 ns        74743
rawptr_hashmap_insert_int/1             2.37 ns         2.37 ns    295378893
rawptr_hashmap_insert_int/16            37.3 ns         37.3 ns     18693486
rawptr_hashmap_insert_int/256            607 ns          607 ns      1153211
rawptr_hashmap_insert_int/4096          9757 ns         9756 ns        71934
sharedptr_hashmap_insert_int/1          5.11 ns         5.11 ns    100000000
sharedptr_hashmap_insert_int/16         54.2 ns         54.2 ns     12948731
sharedptr_hashmap_insert_int/256         720 ns          720 ns       977874
sharedptr_hashmap_insert_int/4096      11746 ns        11745 ns        60569
unordered_map_lookup/1                  2.29 ns         2.29 ns    306575128
unordered_map_lookup/16                 36.6 ns         36.6 ns     19146450
unordered_map_lookup/256                 585 ns          585 ns      1196571
unordered_map_lookup/4096               9350 ns         9350 ns        74758
rawptr_hashmap_lookup/1                 2.29 ns         2.29 ns    304893271
rawptr_hashmap_lookup/16                36.5 ns         36.5 ns     19131036
rawptr_hashmap_lookup/256                585 ns          585 ns      1187820
rawptr_hashmap_lookup/4096              9407 ns         9406 ns        74847
sharedptr_hashmap_lookup/1              2.87 ns         2.87 ns    245741090
sharedptr_hashmap_lookup/16             39.4 ns         39.4 ns     18375738
sharedptr_hashmap_lookup/256             600 ns          600 ns      1078546
sharedptr_hashmap_lookup/4096          10029 ns        10028 ns        74411
```

### Relative Performance Analysis

#### **Initialization:**
- `RawPtr::Hashmap` is slower than `unordered_map`.
- `SharedPtr::Hashmap` is slower than `unordered_map`.

#### **Insertion Performance:**
- **Inserting 1 item:**
  - `RawPtr::Hashmap` is about **3.5%** slower than `unordered_map`.
  - `SharedPtr::Hashmap` is about **123%** slower than `unordered_map`.
  
- **Inserting 4096 items:**
  - `RawPtr::Hashmap` is about **4.1%** slower than `unordered_map`.
  - `SharedPtr::Hashmap` is about **25%** slower than `unordered_map`.

#### **Lookup Performance:**
- **Looking up 1 item:**
  - `RawPtr::Hashmap` is equivalent to `unordered_map` in terms of lookup speed.
  - `SharedPtr::Hashmap` is about **25%** slower than `unordered_map`.
  
- **Looking up 4096 items:**
  - `RawPtr::Hashmap` is about **0.6%** slower than `unordered_map`.
  - `SharedPtr::Hashmap` is about **7.3%** slower than `unordered_map`.

### Key Insights

- **`unordered_map`** is consistently the fastest across all operations, with negligible initialization overhead and highly optimized insertion and lookup times.
- **`RawPtr::Hashmap`** performs comparably to `unordered_map` in lookup and insertion times for smaller data sets but incurs additional overhead during initialization.
- **`SharedPtr::Hashmap`** shows a noticeable performance hit, especially in initialization and insertion, due to the additional overhead of shared pointer management.

These performance benchmarks demonstrate the trade-offs between pointer management strategies and their impact on hashmap operations (skill issue xD).


## Usage

To use the hashmaps in your own project, simply include the appropriate header file and link against the provided implementation.

```cpp
#include "rawptr_hashmap.h"
#include "sharedptr_hashmap.h"
#include <iostream>

int main() {
    RawPtr::Hashmap<int, int> raw_map;
    raw_map.insert(1, 10);
    std::cout << "Raw map lookup: " << raw_map.lookup(1) << std::endl;
    
    SharedPtr::Hashmap<int, int> shared_map;
    shared_map.insert(2, 20);
    std::cout << "Shared map lookup: " << shared_map.lookup(2) << std::endl;
    
    return 0;
}
```

## Installation

To build the project, follow these steps:
1. Clone the repository:
```bash
git clone https://github.com/W-Jeng/separate_chaining_hashmap.git
cd separate_chaining_hashmap
```

2. Create the build directory and compile the project:
```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

## Testing

Unit tests are implemented using **Google Test** to verify the correctness of each hashmap implementation. Benchmarks are implemented using **Google Benchmark** to verify the relative performance.

### Running Tests

To run the tests, run these:

```bash
cd build
./runtest
```

### Running Benchmark

To run the benchmarks, run these:

```bash
cd build
./runbenchmark
```

## Foreword

This project has been a fantastic learning journey for me. I've gained a deeper understanding of C++ by implementing custom hashmaps with both raw pointers and shared pointers. It's been a hands-on way to learn about memory management, pointer arithmetic, and the intricacies of C++ data structures. Additionally, working with CMake for the first time has given me practical experience in project configuration and build systems. Overall, this project has significantly expanded my skills and understanding of C++ and its application in real-world scenarios.