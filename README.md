# PasswordRequirements

A project that goes through rockyou.txt and determines if the password meets a set of requirements.

## Explanation

This was made for my cybersecurity class where we needed to go through the `rockyou.txt` files, which is included on Kraggle.com or with running `sudo apt-get install wordlists` on Kali linux, and check if they met certain password requirements. Then the percentage of passwords that met that requirement would be output to the standard output along with all the passwords that passed the check.

`rockyou.txt` was a set of leaked passwords from rockyou.com in 2009, which I'm not including on the github page, but I am including the results of this program running, as to show that it works.

## Running the program

Compiling this with any C++ compiler and then running the executable with the standard in and out streams set should work. 
Ex: ```./pass_match.out < rockyou.txt > results.txt```