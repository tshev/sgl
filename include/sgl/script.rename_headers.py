import os
from shutil import copyfile, move

def rename(x):
    return "sgl.v1." + ".".join(x.split("_", 1))

def keep(x):
    return (x.startswith("class_") or x.startswith("function_") or x.startswith("struct_")) and x.endswith(".h")

headers = [move(x, rename(x)) for x in os.listdir() if keep(x)]

