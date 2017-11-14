#! /usr/bin/env python

def f(cc,rr):
    if len(rr) == 1:
        print cc
        print rr 
        return cc + rr
    if len(rr) > 1:
        p(rr)

def p(w):
    for cc in w:
         rr = w.replace(cc,'')
         answer = cc + f(cc,rr) 
         print('\n')

print ('hi')
p('hi')
