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
2. **`RawPtr::Hashmap`** –  A custom hashmap using raw pointers, where memory management is handled manually but with a careful approach to ensure **RAII** (Resource Acquisition Is Initialization).
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
rawptr_hashmap_init                     14.3 ns         14.3 ns     48454911
sharedptr_hashmap_init                  13.2 ns         13.2 ns     52547254
unordered_map_insert_int/1              2.28 ns         2.28 ns    306534208
unordered_map_insert_int/16             36.6 ns         36.6 ns     19137819
unordered_map_insert_int/256             585 ns          584 ns      1197457
unordered_map_insert_int/4096           9353 ns         9352 ns        74599
rawptr_hashmap_insert_int/1             2.37 ns         2.37 ns    294093496
rawptr_hashmap_insert_int/16            37.3 ns         37.3 ns     18776098
rawptr_hashmap_insert_int/256            599 ns          599 ns      1168680
rawptr_hashmap_insert_int/4096          9678 ns         9677 ns        72320
sharedptr_hashmap_insert_int/1          2.69 ns         2.69 ns    259201552
sharedptr_hashmap_insert_int/16         48.3 ns         48.3 ns     14451438
sharedptr_hashmap_insert_int/256         670 ns          670 ns      1053645
sharedptr_hashmap_insert_int/4096      10692 ns        10692 ns        65508
unordered_map_lookup/1                  2.28 ns         2.28 ns    305743553
unordered_map_lookup/16                 36.5 ns         36.5 ns     19176529
unordered_map_lookup/256                 584 ns          584 ns      1197246
unordered_map_lookup/4096               9415 ns         9415 ns        74842
rawptr_hashmap_lookup/1                 2.29 ns         2.29 ns    306528311 
rawptr_hashmap_lookup/16                37.0 ns         37.0 ns     19100412
rawptr_hashmap_lookup/256                639 ns          639 ns      1138191
rawptr_hashmap_lookup/4096              9383 ns         9382 ns        68811
sharedptr_hashmap_lookup/1              2.98 ns         2.98 ns    244706802
sharedptr_hashmap_lookup/16             36.9 ns         36.9 ns     18987722
sharedptr_hashmap_lookup/256             586 ns          586 ns      1195728
sharedptr_hashmap_lookup/4096           9459 ns         9458 ns        73889
unordered_map_erase/1                   1.26 ns         1.25 ns    557909935
unordered_map_erase/16                  4.85 ns         4.85 ns    144236113
unordered_map_erase/256                 72.5 ns         72.5 ns      9570752
unordered_map_erase/4096                 949 ns          949 ns       737685
rawptr_hashmap_erase/1                  2.28 ns         2.28 ns    304978187
rawptr_hashmap_erase/16                 36.6 ns         36.6 ns     19148018
rawptr_hashmap_erase/256                 584 ns          584 ns      1196994
rawptr_hashmap_erase/4096               9342 ns         9341 ns        74930
sharedptr_hashmap_erase/1               2.28 ns         2.28 ns    306821989
sharedptr_hashmap_erase/16              36.5 ns         36.5 ns     19185301
sharedptr_hashmap_erase/256              584 ns          584 ns      1197598
sharedptr_hashmap_erase/4096            9343 ns         9342 ns        74930
```

### Relative Performance Analysis

#### **Initialization:**
- `RawPtr::Hashmap` is slower than `unordered_map`.
- `SharedPtr::Hashmap` is slower than `unordered_map`.

#### **Insertion Performance:**
- **Inserting 1 item:**
  - `RawPtr::Hashmap` is about **3.9%** slower than `unordered_map`.
  - `SharedPtr::Hashmap` is about **18%** slower than `unordered_map`.
  
- **Inserting 4096 items:**
  - `RawPtr::Hashmap` is about **1.3%** slower than `unordered_map`.
  - `SharedPtr::Hashmap` is about **14%** slower than `unordered_map`.

#### **Lookup Performance:**
- **Looking up 1 item:**
  - `RawPtr::Hashmap` is equivalent to `unordered_map` in terms of lookup speed.
  - `SharedPtr::Hashmap` is about **30%** slower than `unordered_map`.
  
- **Looking up 4096 items:**
  - `RawPtr::Hashmap` is about **0.4%** faster than `unordered_map` (almost the same)!.
  - `SharedPtr::Hashmap` is about **0.5%** slower than `unordered_map` (almost the same again)!`.

#### **Erase Performance:**
- **Erasing up 1 items:**
  - `RawPtr::Hashmap` is about **81%** slower than `unordered_map`.
  - `SharedPtr::Hashmap` is about **81%** slower than `unordered_map`.

- **Erasing up 4096 items:**
  - `RawPtr::Hashmap` is about **884%** slower than `unordered_map`.
  - `SharedPtr::Hashmap` is about **885%** slower than `unordered_map`.

### Key Insights

- **`unordered_map`** is consistently the fastest across all operations, with negligible initialization overhead and highly optimized insertion, lookup and erase times.
- **`RawPtr::Hashmap`** performs comparably to `unordered_map` in lookup and insertion times for smaller data sets but incurs additional overhead during initialization. Erase function seems to be implemented a different method from mine, the performance difference is significant!
- **`SharedPtr::Hashmap`** shows a noticeable performance hit, especially in initialization and insertion, due to the additional overhead of shared pointer management. Erase function seems to be implemented a different method from mine, the performance difference is significant! How do they do it??? It might be due to cache misses, one particular solution is to create a pool allocator.

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
    std::cout << "Raw map lookup: " << raw_map.at(1) << std::endl;
    
    SharedPtr::Hashmap<int, int> shared_map;
    shared_map.insert(2, 20);
    std::cout << "Shared map lookup: " << shared_map.at(2) << std::endl;
    
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

## Lessons Learned

This project has been a great way to dive deeper into C++. Implementing custom hashmaps with raw and shared pointers has definitely given me a better grip on memory management, pointer math, and C++ data structures. Plus, figuring out CMake for the first time was a whole new adventure in build systems. All in all, it’s been a solid learning experience, and I’ve walked away with a better understanding of C++ and how it works in real projects.