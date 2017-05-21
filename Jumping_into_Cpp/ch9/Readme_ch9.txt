---What if you can't figure out what to do---

The most difficult part, but also the most fun and rewarding part, is designing a program.

(It's magical, there is nothing like seeting a difficult problem become easy 
and seeing your program come to life.)

1. Break your problem into small finger-sized sandwich bites


Vocab
Algorithm = The series of steps required to solve a problem

Even when you have the algorithm, turning into code may be hard so here are some tools:

----------Breaking down your problem into small sandwiches ----------------

Come up with steps that are already simpler than the ones you already have.

E.g. Print all primes from 0 to 100

1. Go over all numbers from 1 to 100
2. For each number, test if it's a prime
3. If the number is a prime, print it

pg. 124-125 has a good run through.

Basically you put 'helper functions' that you will write later. 
For each of those functions you think of what steps to take.

e.g. bool isPrime(int my_number);
e.g. bool isDivisible(int my_number);


--------- Efficiency and security ----------------------------------------

- The first algorithm you come up with may not be the most efficient one.
In the previous example we had a small amount of numbers to check so it did not matter.

(O.O)

E.g. The RSA algorithm for public key cryptography is used in most bank and ecommerce websites.
It is also used to secure sensitive data and it RELIES ON THE ABILITY TO MAKE LARGE PRIME NUMBERS.

If you wanted to create many RSA encryption keys you want a fast and efficient prime number generator!

- Sometimes you will find that solving sub-problems are impossible for some reason.
- Designing a program is not always easy! If it were you'd have more bored software engineers.
- If you find yourself having trouble breaking the problem down, try taking a  step back and 
coming up with ANOTHER way to break down the problem.

Vocab
- Top-down design = the approach of breaking down big problems into smaller bite-size problems.
- Bottom-up design = the approach of figuring out 'helper functions' first and then using them to solve a problem.
-----------------------------------------------------
***Bottom-up design***
CON:
- You may make helper functions you don't need at all.
- Writing the details may obscure the big picture
PRO:
- Makes it easy to start
-----------------------------------------------------
***Top-down design***
PRO
- Good for a beginnger (Don't let that stop you from trying the other approach though!)
- Optimized to write the functions you need exactly
CON
- :p May get stuck
-----------------------------------------------------

- You don't have to write code :D you can make these designs on a whiteboard.
(you skip the syntax and compiler errors)
- It's ok if you try to write down each step of the process and break down each step into a 
smaller series of steps.
- Something that helps is practice, practice, practice


--------- Efficiency and security --------------------------------------------
   
What if you don't know the algorithm?

In the primes example it was easy b/c the algorithm was practically part of the definition.
Most of the time it's not as simple.

E.g. Write an algorithm that can display the English name for a number, like 1204.
(If English isn't your first language you may have an advantage in solving this problem)

- Understand the pattern in the data so you can come up with an algorithm.

- A good technique is to write out a bunch of examples and find the patterns.

Solution: 1-19 have to be hard coded. Everything else has a pattern.



























 














































 

