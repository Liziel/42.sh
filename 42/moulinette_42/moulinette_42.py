#!/usr/bin/python2.7
import os
from subprocess import *
import sys

DEBUG = 0

try:
    fd_file = ""
    fd_file = open(str(sys.argv[1]), 'r')
    mysh = "./" + str(sys.argv[2])
    try:
        sh = str(sys.argv[3])
    except: sh = "tcsh"
    try:
        if sys.argv[4] == "--debug":
            DEBUG = 1
    except: DEBUG = 0
    i = 1
    a = 0
    success = 0
    for line in fd_file.readlines():
        if line[0] != '#' and line[0] != '\n':
            str1 = os.popen("echo " + "\"" + line + "\"" + " | " + sh, "r").read()
            str2 = os.popen("echo " + "\"" + line + "\"" + " | " + mysh, "r").read()
            a += 1
            if str1 == str2:
                print 'Test {0} {1} :\tmatch \033[32m[ok]\033[37m'.format(a, line)
                success += 1
            elif str1 != str2:
                print 'Test {0} {1} :\tmatch \033[31m[fail]\033[37m'.format(a, line)
            if DEBUG == 1:
                print "-----------------{0}-----------------".format(sh)
                print str1
                print "-----------------{0}-----------------".format(mysh)
                print str2
                print "-------------------------------------"
        elif line[0] == '#':
            print line
        i += 1
    fd_file.close()
    print "Resultat: {0:.0f} % des test reussi.".format(float(float(success) / float(a)) * 100)
except: print "Error\nUsage ./moulinette_42.py [FILE : fichier de test] [EXECUTABLE: celui de votre shell] [SHELL : shell de comparaison] [--debug]", exit(1)
