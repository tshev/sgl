#!/usr/bin/python
import itertools
import os
import sys

COMPILER = os.environ.get("COMPILER", "g++ -O3 -std=c++17 -Wall")

__COMPILATION_ERROR = []

def compile(src, output=None, compiler=COMPILER):
    output = output or src + ".out"
    os.system("%s %s -o %s -I ../../include" % (compiler, src, output))
    return output


def is_test(src):
    return src.startswith("test") and src.endswith(".cpp")


def is_executeable(src):
    return src.endswith(".out")


def filter_files(src_walk, pred):
    for path, _, filenames in os.walk(src_walk):
        for filename in filenames:
            if pred(filename):
                yield os.path.join(path, filename)


def tests(src_walk):
    return filter_files(src_walk, is_test)


def tests_programs(src_walk):
    return filter_files(src_walk, is_executeable)


def bash_compile(argv):
    for x in tests(os.curdir):
        compile(x)
        print("Compiling %s" % x)


def bash_clean(argv):
    for x in tests_programs(os.curdir):
        os.remove(x)


def bash_run(argv):
    for x in tests_programs(os.curdir):
        print("## " + x)
        os.system(x)


def main(argv):
    if len(argv) == 1:
        print("Valid options:")
        for i, x in enumerate(sorted(x for x in globals() if x.startswith("bash_"))):
            print("%d. %s" % (i + 1, x[len("bash_"):]))
        sys.exit(-1)
    function = globals()
    for x in itertools.islice(argv, 1, len(argv)):
        print("# " + x)
        function["bash_%s" % x](argv)

main(sys.argv)
