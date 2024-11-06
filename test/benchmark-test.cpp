// tests/benchmark_test.cpp
#include <benchmark/benchmark.h>
#include "hashmap_sharedptr.h"
#include <unordered_map>

void custom_init_int_int() {
    SharedPtr::Hashmap<int, int> hashmap;
    return;
}

void default_init_int_int() {
    std::unordered_map<int, int> hashmap;
    return;
}

void custom_insert_int_int(SharedPtr::Hashmap<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        hashmap.insert(i, i);
    }
    return;
}

void default_subscript_int_int(std::unordered_map<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        hashmap[i] = i;
    }
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

static void InsertDefaultHashmap(benchmark::State& state) {
    std::unordered_map<int, int> hashmap;
    int num_items = state.range(0);
    for (auto _: state) {
        default_subscript_int_int(hashmap, num_items);
    }
}

static void InsertCustomHashmap(benchmark::State& state) {
    SharedPtr::Hashmap<int, int> hashmap;
    int num_items = state.range(0);
    for (auto _: state) {
        custom_insert_int_int(hashmap, num_items);
    }
}

BENCHMARK(InitDefaultHashmap);
BENCHMARK(InitCustomHashmap);
BENCHMARK(InsertDefaultHashmap) -> Arg(1) -> Arg(16) -> Arg(64) -> Arg(256) -> Arg(1024);
BENCHMARK(InsertCustomHashmap) -> Arg(1) -> Arg(16) -> Arg(64) -> Arg(256) -> Arg(1024);

BENCHMARK_MAIN();
