#! /usr/bin/env python

def p(c,w):
    if len(w) == 1:
        print(w) 
        print('\n')
    if len(w) > 1:
        for cc in w:
             print cc
             rr = w.replace(cc,'')
             p(cc,rr)

print ('->hi')

p('','her')
