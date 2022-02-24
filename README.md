# It is not ready for the prime-time

# SGL

0. Let no-one ignorant of geometry enter here.
1. Let no-one ignorant of algorithms enter here.

The library is in active development. Don't use it, because i will:
- use git push -f
- completely change contracts for some algorithms and contains
- all containers have bugs, and I'll rewrite them at some point.

# Code of conduct
Read it [here](.github/CODE_OF_CONDUCT.md)

## connection between regular type and resources
1. There is no such thing as a resource, everything must have an implementation of a copy constructor. std::move is an external function, which optimizes some operations for some particular types.
2. Move is as fundamental as copy, but there are movable but non-copyable type (boost io service and other garbage from boost, std::unique_ptr, std::thread, etc)
TotallyOrdered -> TotallyOrderedResource
     ↓                    ↓ 
  Regular      ->   RegularResource
     ↓                    ↓
Semiregular    ->     Resource

According to the extention procedure:
1. Semiregular type is a resource
2. Regular type is a Regualr resource
3. TotallyOrdered type is a TotallyOrderedResource
So, we've got a parallel hierachy, which has the cross-level dependecies with the initial hierarchy of concepts.

1 VS 2

# TODO: think about
- hide memory latency with async operations
- functors for composable SIMD instructions
- SIMD and 2D iterators
- Word hashing without collisions (also, save as many operations as possible)
  - Obtain a vocabulary of all the words
  - ensure we can encode all the words and character-level ngrams without collisions
- async B+ tree, which is optimized for a fast in-order traversal


# ROADMAP (Release checkpoints)

## Checks
1. Rewrite argparser and containers.
2. Add tests for every algorithms
    2.1. Make sure it works with containers from a standard library according the algorithm requirements
    2.2. Check whether algorithm works for every concept within the hirerachy.
    2.3. Add a specialization for input iterators.
    2.4. Add tests for conrner values from a Set of Depature.
    2.5. Add tests for every built-in types
3. Make sure everything `works without exceptions`.
4. Add fuzzing for parsers.
5. Make sure every algorithm has an implementation in terms `actions` and in terms of `transformations`
6. Categorize algorithms and containers
7. Describe the properties of operations.
8. Make sure there are no binary operations between different types.
9. Check the conventions: `gcd_stein and gcd_euclid` vs `stein_gcd and euclid_gcd`, `insertion_sort` vs `sort_insertion`.
    9.1. Prefer well-established terminology
    9.2. Use uniform naming conventions, where we don't have a well-established terminology.
    9.3. Use name aliases????
    9.4. Look at naming conventions in Chemistry and adjust the decisions.
10. Define the principles for vectorized expressions. {Optional}
11. Composition of SIMD operations {Optional}
12. Partial C++98 compatibility, full c++14 compatibility (except for concepts).

## Requires features 
### Strcat
```
    std::string s0 = "s0";
    std::string s1 = "s1";
    sgl::v1::concatenation concatenation(
        "good morning",
        sgl::v1::format_precision<float>(4.12345, 2),
        sgl::v1::format_decimal<int>(13, 2, 0),
        ",",
        100,
        " ",
        std::string("good morning"),
        std::move(s0),
        s1
    );

    std::string result0(concatenation.size());
    sgl::v1::copy(concatenation.begin(), concatenation.end(), std::begin(result0));

    std::string result1(concatenation.size());
    concatenation.copy(std::begin(result1));
    
    auto result2 = concatenation(std::string());

    std::string result2(concatenation.size());
    sgl::v1::strcat(std::begin(concatenation), concatenation);
```

## Desired features 
TODO:
- `sgl.v1.class.adaptive_hash.h`
- `sgl.v1.class.cuckoo_hash.h`
- `sgl.v1.class.lri_cache.h`
- `sgl.v1.class.adaptive_cache.h`
- `sgl.v1.class.lru_cache.h`

# Concepts
## Fundamental building blocks
TotallyOrderd -> TotallyOrderdResorce
    ↓                   ↓
 Regular      ->   RegularResource
    ↓                   ↓
Semiregular   ->     Resource


## Documentation Tips and Tricks
01. Describe Domain and Codomain.
02. Provide non-obvious and obvious examples of wrong domains.
03. Say whether the function is partial.
04. Describe Set of Departure.
05. Provide non-obvious and obvious examples for of a Set of Depature.
06. Describe the predicates, which check the Set of Depature, and specify which checks would be ignored.
07. Describe when the function allocates memory.
08. Describe the thread safety (all functions should not modify non-syncronised external state unless there is a good reason for doing it (yet to be discovered), but you should specify the presence of synchronization and whether we need it, especially for containers and functors).
09. Describe the modification of the arguments.
10. Keep saying "unless your implementation of a concept have an external state / allocates memory / violates signal safety / has a syncronisation".
11. Describe whether it uses and external state or depends on external values.
12. Describe the preprocessor dependecies.
13. Add perofrmance curves.
14. Describe the algorithmic complexity as precisely as possible.


## Search Engine Design Doc

Modern Search Engines don't respect the hardware. Two the most popular search engines (Solr and ElasticSearch) are built on top of Lucene, which has a storage model entirely based on memory-mapped files. MMAP does not take advantage of NVME SSDs and does not give you control over caching and page faults, because the page fault cost is too high. It gives you unpredictable performance. But the IO implementation is not the only problem. These search engines are written in Java. Java neither gives you performance, nor control over hardware, nor zero-cost abstractions. The entire hardware infrastructure is asynchronous. In modern systems, even the main memory behaves like a disk drive. Random Access Memory no longer exists: the performance of your system entirely depends on data access patterns.

The entire database world uses SQL. Some vendors use JSON as a query language, but it is a road to nowhere because everybody must learn a new language, which is very specific to a single system, and then you hit into a set of limitations of your language. The only reason for non-SQL syntax for query language is the simplicity of initial implementation, but such decisions stay forever and ever.

Design Goals:
- Don't pay for what you don't use
- Make data as close to your algorithms as possible
- Process data as fast as hardware can.
- Support Horizontal and vertical scaling.
- No side effects (Unlike ElasticSearch, the query result should not depend on shard id)

Usage Area
- Search
- Recommender systems
- Chat-Bots
- Question-Answering
- Serving your PyTorch models with as low latency as possible on CPUs and GPUs.

Highlights:
- Entirely asynchronous execution pipeline
- Built-in torch-script support via user-defined functions (upload your neural nets and run them)
- Built-in CatBoost support
- SQL-like syntax
- Run and Analyse your AB tests
- CPU and GPU execution
- Fully async disk and network IO
- Parallel and Partitioned Data Access
- Data and index Compression, ultra-fast delta encoding algorithms for posting lists
- Scalable KNN search
- Built-in models for language identification
- Built-in Clickhouse and Kafka Logging
- Hardware monitoring, Prometheus metrics
- Ultrafast performance counters
- HTTP Protocol
- Access Control and Account Management via User accounts, roles, row policies, quota limits for resource usage
- Async Background queries to Analytical RDBMS

Engineering Goals
- Full hardware utilization
- Linearly scalable with the number of cores and replicas
- Low latency and high throughput
- Full tests coverage
- Minimal number of dynamic memory allocations
- Memory adaptive execution pipeline


Implementation highlights:
- C++ is the language of choice.
- Fully asynchronous codebase.
- Cache-friendly algorithms.
- Full utilization of SIMD instructions.
- Fast Compression Libraries (LZ4, ZSTD, FastPFOR)
- Zero sharing , sophisticated task steeling.
- Sampling-based profiler.
- Compile the source code with all kinds of sanitizers
