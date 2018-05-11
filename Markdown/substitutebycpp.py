#!/bin/python

import sys
import re

f = sys.argv[1]

def open_hpp(name):
    filename = "../include/" + name + ".hpp"
    with open(filename,'r') as myhpp:
        hppcode = myhpp.read()
        hppcode = hppcode.replace("#pragma once","")
        hppcode = hppcode.replace("inline ","")
        hppcode = hppcode.replace("std::int64_t","long")
    return hppcode
    
def open_cpp(name):
    filename = "../src/" + name + ".cpp"
    header = name + ".hpp"
    with open(filename,'r') as mycpp:
        cppcode = mycpp.read()
        cppcode = cppcode.replace("#include \"" + header + "\"", "")
    return cppcode
    

def replace_include_by_file(txt):
    match = re.split(r"(((.*)\n)*)\%\%INCLUDE\((.*)\)(((.*)\n)*)",txt)
    if (len(match) < 6):
        return txt
    try:
        L = match[4].split('.')
        name_no_ext = L[0]
        ext = L[1]
        #print("Name without ext: ", name_no_ext)
        #print("ext: ", ext)
        txt = match[1]
        txt += open_hpp(name_no_ext)
        #print("EVERYTHING FINE UNTIL NOW")
        if (ext == "cpp"):
            txt += open_cpp(name_no_ext)
            #print("MANAGED TO GET CPP WORKING!")
        txt += match[5]
        return txt
    except:
        print("ERROR in file " + f)
    return ""


with open(f,'r') as mymd:
    txt = mymd.read()
    txt = replace_include_by_file(txt)
    print(txt)
    

    
    
