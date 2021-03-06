# 42-push_swap

[![42](https://img.shields.io/badge/42-common_core-green.svg)](https://shields.io/)
[![Vim](https://img.shields.io/badge/--019733?logo=vim)](https://www.vim.org/)
[![42](https://img.shields.io/badge/Made%20in%20-C-blue.svg)](https://shields.io/)
[![42](https://img.shields.io/badge/Made%20with%20-GNU%20Make-red.svg)](https://shields.io/)

[![made-with-Markdown](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](http://commonmark.org)
[![Ask Me Anything !](https://img.shields.io/badge/Ask%20me-anything-1abc9c.svg)](https://GitHub.com/Naereen/ama)

<p align="left">
  <img src="assets/imgs/plates.png" />
</p>
<p align="right">
  <img src="assets/imgs/plates.png" />
</p>

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

* That being said, you can imagine a thousand way to make your *push_swap* faster. What about indexing your stack ? What about making groups of pre-sorted numbers ? The only limit is your creativity.

* Learn about [sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm). I can recommand you an author : **Thomas H. Cormen**.

This is a usefull bash script in order to generate random permutation of a sequence of numbers (require **GNU binutils**, you probably have it) :

  ```
  #!/bin/bash
  
  # If the numbers of arguments ($#) is not (-ne) 2, display usage and
  # exit with err code 1.
  
  if [ $# -ne 2 ]; then
      echo "Invalid number of arguments."
      echo "Usage : ./randomizer.sh <a> <b>."
      echo "Where a-b is the range."
      exit 1
  fi

  # Using seq to generate a sequence of numbers, shuf to permute lines randomly,
  # tr to replace new line by space, and sed to remove the space at the end.
  # Use it on your push swap like so :
  #
  #     ./push_swap $(./randomizer.sh 0 10)
  
  seq $1 $2 | shuf | tr '\n' ' ' | sed -r 's/.$//'
  ```

## My first naive approach <a name="first-approach"></a> 

This one is not effective at all.

I can sort a set of 10 000 numbers in **12451813** operations, and a set of 100 numbers in **1447** operations.

