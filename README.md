# 42-push_swap

![plates](assets/imgs/plates.png)

## Table of contents

1. [The push_swap program](#push_swap)
2. [Advices](#advices)
3. [My first naive approach](#first-approach)

## The push_swap program <a name="push_swap"></a>

The goal of this project is to imagine  an algorithm to sort in ascending order a set of numbers passed in the program parameter.
We can only use a limited set of instruction, which made this project tricky.

You can implement a sorting algorithm or imagine / be inspired by another algorithm to make your own.

## Disclaimer & Advices <a name="advices"></a>

My first advices for this project is to **resist the temptation** of watching pre-existing *push_swap* project on Github.
For me, the main purpose of this school is to *let go all the fear* of failing from standard school of discovering something completly new.

On the other hand, i highly recommand you to talk with your peers about their project (even if they watched something on the web about *push_swap*).
This is far more interesting. Of course, looking on the web is also learning from your peers (if they're at 42), but i think you'll miss all the joy exchanging
with others in real life at school.

The web is amazing, but it made us lazy, and we're loosing the feeling of "the young Steve Jobs discovering something amazing in his garage.".

I'll allow myself on this project to look on the web and inspire from other's work (on Github for example) after a long research of my own and different explaination. 

Do whatever you want to do, but be aware of your own choices and their consequences, and your vision of **42**.

<u>**Now the real advices :**</u>


* The complexity of your algorithm is not computer-dependant : it's not the number of the instructions of the computer that matters, but the numbers of instructions of **your program** to sort a given list.
Your *push_swap* could be bruteforce, carry out billions of if statements and while loop, we simply don't care.
 What we do care is **how many *push_swap* instructions** your program used.


## My first naive approach <a name="first-approach"></a> 

This one is not effective at all.

I can sort a set of 10 000 numbers in **12451813** operations, and a set of 100 numbers in **1447** operations.

