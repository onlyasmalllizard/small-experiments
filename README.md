# small-experiments

This repository is for small programs written for me to practice programming.

txt.c
----
txt.c allows a user to write to a text file until they quit by pressing Ctrl-D. If the file they enter as an argument already exists, it start writing at the end of that file.

In making it, I wanted to try writing a program that would produce output that lasted after the program finished running and could be added to later. In CS50, I had used the read and write arguments for fopen only. I started my program by writing a conditional that would check if the second command line file existed, and, if not, create a named .txt file to work in. Once I completed this step, I read documentation about fopen and realised that there were other arguments that already did this. I ended up using the argument a+ and deleting my first block of code.

As I worked, I realised that all of the prompts for user input that I had used previously were in the CS50 header file, which contained functions such as get_char and get_string. I wanted to learn how to implement the same behaviour without relying on a header file designed to ease students into programming, so I went searching through documentation for stdio.h and learned how to use fgets().

The decision to allow the user to input 512 characters at a time was relatively arbitrary. I wanted the user to have enough space to write a short paragraph if desired. I had just completed the Recover assessment in CS50, in which you read in 512 byte-size blocks of data at a time. The number 512 was in my head, and it seemed like a reasonable amount for the functionality I wanted.

Finally, I wanted the end of the program to be determined by the user by pressing Ctrl-D. I had seen how to recognise this when the user was inputting integers, but I didn't know how this was recognised when accepting chars. I Googled the problem and saw people suggesting assigning fgets() to a variable and evaluating the variable to determine if it was NULL. I considered doing this, but I felt that it made the most sense to call fgets() in my while loop, and I didn't see how to implement the check that way with my design choice.

I kept searching, found a suggestion to use feof(stdin) to check Ctrl-D, tested it in my code, and it worked. I think I remember seeing discussions about CS50's Recover that warned against using feof, but I don't remember if that was for that particular program or if there are usage dangers in general to be aware of. I will need to look into this further.
