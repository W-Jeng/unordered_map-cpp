// tests/benchmark_test.cpp
#include <benchmark/benchmark.h>
#include "hashmap_sharedptr.h"
#include "hashmap_rawptr.h"
#include <unordered_map>
#include <vector>
#include <string>

const std::vector<std::string> create_strings(int num_elements) {
    std::vector<std::string> temp;
    for (int i = 0; i < num_elements; ++i) {
        temp.push_back(std::to_string(i));
    }
    return temp;
}

void init_rawptr_hashmap() {
    RawPtr::Hashmap<int, int> hashmap;
    return;
}

void init_sharedptr_hashmap() {
    SharedPtr::Hashmap<int, int> hashmap;
    return;
}

void init_unordered_map() {
    std::unordered_map<int, int> hashmap;
    return;
}

void insert_int_rawptr_hashmap(RawPtr::Hashmap<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        hashmap.insert(i, i);
    }
    return;
}

void insert_int_sharedptr_hashmap(SharedPtr::Hashmap<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        hashmap.insert(i, i);
    }
    return;
}

void insert_int_unordered_map(std::unordered_map<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        hashmap[i] = i;
    }
    return;
}

void insert_string_rawptr_hashmap(RawPtr::Hashmap<std::string, std::string>& hashmap,
    const std::vector<std::string>& strings) {

    for (int i = 0; i < strings.size(); ++i) {
        hashmap.insert(strings[i], strings[i]);
    }
    return;
}

void insert_string_sharedptr_hashmap(SharedPtr::Hashmap<std::string, std::string>& hashmap,
    const std::vector<std::string>& strings) {

    for (int i = 0; i < strings.size(); ++i) {
        hashmap.insert(strings[i], strings[i]);
    }
    return;
}

void insert_string_unordered_map(std::unordered_map<std::string, std::string>& hashmap,
    const std::vector<std::string>& strings) {

    for (int i = 0; i < strings.size(); ++i) {
        hashmap[strings[i]] = strings[i];
    }
    return;
}

void lookup_int_unordered_map(const std::unordered_map<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        auto it = hashmap.find(i);
        benchmark::DoNotOptimize(it);
    }
}

void lookup_int_rawptr_hashmap(RawPtr::Hashmap<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        auto it = hashmap.at(i);
        benchmark::DoNotOptimize(it);
    }
}

void lookup_int_sharedptr_hashmap(SharedPtr::Hashmap<int, int>& hashmap, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        auto it = hashmap.at(i);
        benchmark::DoNotOptimize(it);
    }
}

static void rawptr_hashmap_init(benchmark::State& state) {
    for (auto _ : state) {
        init_rawptr_hashmap();
    }
}

static void sharedptr_hashmap_init(benchmark::State& state) {
    for (auto _ : state) {
        init_sharedptr_hashmap();
    }
}

static void unordered_map_init(benchmark::State& state) {
    for (auto _ : state) {
        init_unordered_map();
    }
}

static void unordered_map_insert_int(benchmark::State& state) {
    std::unordered_map<int, int> hashmap;
    int num_items = state.range(0);
    for (auto _: state) {
        insert_int_unordered_map(hashmap, num_items);
    }
}

static void rawptr_hashmap_insert_int(benchmark::State& state) {
    RawPtr::Hashmap<int, int> hashmap;
    int num_items = state.range(0);
    for (auto _: state) {
        insert_int_rawptr_hashmap(hashmap, num_items);
    }
}

static void sharedptr_hashmap_insert_int(benchmark::State& state) {
    SharedPtr::Hashmap<int, int> hashmap;
    int num_items = state.range(0);
    for (auto _: state) {
        insert_int_sharedptr_hashmap(hashmap, num_items);
    }
}

static void unordered_map_insert_string(benchmark::State& state) {
    std::unordered_map<std::string, std::string> hashmap;
    int num_items = state.range(0);
    const std::vector<std::string> temp = create_strings(num_items);
    for (auto _: state) {
        insert_string_unordered_map(hashmap, temp);
    }
}

static void rawptr_hashmap_insert_string(benchmark::State& state) {
    RawPtr::Hashmap<std::string, std::string> hashmap;
    int num_items = state.range(0);
    const std::vector<std::string> temp = create_strings(num_items);
    for (auto _: state) {
        insert_string_rawptr_hashmap(hashmap, temp);
    }
}

static void sharedptr_hashmap_insert_string(benchmark::State& state) {
    SharedPtr::Hashmap<std::string, std::string> hashmap;
    int num_items = state.range(0);
    const std::vector<std::string> temp = create_strings(num_items);
    for (auto _: state) {
        insert_string_sharedptr_hashmap(hashmap, temp);
    }
}

static void unordered_map_lookup(benchmark::State& state) {
    std::unordered_map<int, int> hashmap;
    int num_items = state.range(0);
    for (int i = 0; i < num_items; ++i) {
        hashmap[i] = i;
    }

    for (auto _ : state) {
        lookup_int_unordered_map(hashmap, num_items);
    }
}

static void rawptr_hashmap_lookup(benchmark::State& state) {
    RawPtr::Hashmap<int, int> hashmap;
    int num_items = state.range(0);
    for (int i = 0; i < num_items; ++i) {
        hashmap.insert(i, i);
    }

    for (auto _ : state) {
        lookup_int_rawptr_hashmap(hashmap, num_items);
    }
}

// Benchmark for SharedPtr hashmap lookup
static void sharedptr_hashmap_lookup(benchmark::State& state) {
    SharedPtr::Hashmap<int, int> hashmap;
    int num_items = state.range(0);
    for (int i = 0; i < num_items; ++i) {
        hashmap.insert(i, i);
    }
    for (auto _ : state) {
        lookup_int_sharedptr_hashmap(hashmap, num_items);
    }
}

BENCHMARK(unordered_map_init);

BENCHMARK(rawptr_hashmap_init);

BENCHMARK(sharedptr_hashmap_init);

BENCHMARK(unordered_map_insert_int) -> Arg(1) -> Arg(16) -> Arg(256) -> Arg(4096);

BENCHMARK(rawptr_hashmap_insert_int) -> Arg(1) -> Arg(16) -> Arg(256) -> Arg(4096);

BENCHMARK(sharedptr_hashmap_insert_int) -> Arg(1) -> Arg(16) -> Arg(256) -> Arg(4096);

BENCHMARK(unordered_map_lookup) -> Arg(1) -> Arg(16) -> Arg(256) -> Arg(4096);

BENCHMARK(rawptr_hashmap_lookup) -> Arg(1) -> Arg(16) -> Arg(256) -> Arg(4096);

BENCHMARK(sharedptr_hashmap_lookup) -> Arg(1) -> Arg(16) -> Arg(256) -> Arg(4096);


/*
BENCHMARK(unordered_map_insert_string) -> Arg(1) -> Arg(16) -> Arg(64) ->
    Arg(256) -> Arg(1024) -> Arg(4096);
BENCHMARK(rawptr_hashmap_insert_string) -> Arg(1) -> Arg(16) -> Arg(64) ->
    Arg(256) -> Arg(1024) -> Arg(4096);
BENCHMARK(sharedptr_hashmap_insert_string) -> Arg(1) -> Arg(16) -> Arg(64) ->
    Arg(256) -> Arg(1024) -> Arg(4096);
*/

BENCHMARK_MAIN();
