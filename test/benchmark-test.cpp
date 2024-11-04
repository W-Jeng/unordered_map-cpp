// tests/benchmark_test.cpp
#include <benchmark/benchmark.h>
#include "separate_chaining_hashmap.h"
#include <unordered_map>

void custom_init_int_int() {
    SeparateChainingHashMap<int, int> hashmap;
    return;
}

void default_init_int_int() {
    std::unordered_map<int, int> hashmap;
    return;
}

void custom_insert_int_int(SeparateChainingHashMap<int, int>& hashmap) {
    hashmap.insert(1, 1);
    return;
}

void default_emplace_int_int(std::unordered_map<int, int>& hashmap) {
    hashmap.emplace(1, 1);
    return;
}

void default_subscript_int_int(std::unordered_map<int, int>& hashmap) {
    hashmap[1] = 1;
    return;
}

// Benchmark for add function
static void InitCustomHashmap(benchmark::State& state) {
    for (auto _ : state) {
        custom_init_int_int();
    }
}

static void InitDefaultHashmap(benchmark::State& state) {
    for (auto _ : state) {
        default_init_int_int();
    }
}

static void EmplaceDefaultHashmap(benchmark::State& state) {
    std::unordered_map<int, int> hashmap;
    for (auto _: state) {
        default_emplace_int_int(hashmap);
    }
}

static void SubscriptDefaultHashmap(benchmark::State& state) {
    std::unordered_map<int, int> hashmap;
    for (auto _: state) {
        default_subscript_int_int(hashmap);
    }
}

static void InsertCustomHashmap(benchmark::State& state) {
    SeparateChainingHashMap<int, int> hashmap;
    for (auto _: state) {
        custom_insert_int_int(hashmap);
    }
}

BENCHMARK(InitDefaultHashmap);
BENCHMARK(InitCustomHashmap);
BENCHMARK(EmplaceDefaultHashmap);
BENCHMARK(SubscriptDefaultHashmap);
BENCHMARK(InsertCustomHashmap);


BENCHMARK_MAIN();
