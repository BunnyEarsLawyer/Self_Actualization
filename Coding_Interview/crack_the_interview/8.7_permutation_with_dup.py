#! /usr/bin/env python

def call(w):
    cc = w[0]
    rr = w[1:]
    print('->',cc) 
    print('->',rr) 
    p(cc,rr)

def p(c,w):
    if len(w) == 1:
        print(w)
        print('\n')
    if len(w) > 1:
        for cc in w:
             print(cc)
             rr = w.replace(cc,'')
             p(cc,rr)

print ('->hi')

p('','123')
#call('123')
