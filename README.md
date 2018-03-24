# StringCompression
AUTHOR:SHRIHARI SHETTY
DATE:24/03/2018
# PROBLEM
*GIVEN A STRING IN LOWER CASE OR UPPERCASE, MAY OR MAY NOT HAVE REPEATED CHARACTERS IN 
CONTINUOUS ORDER,WRITE A PROGRAM WHICH COMPRESSES THE STRING AND OUTPUTS THE SINGLE OCCURANCE
AND ITS FREQUENCY IN ORIGINAL STRING.*
# NOTE
### CONSECUTIVE OCCURENCE OF A CHARACTER WILL BE NOT MORE THAN 9.

> INPUT:abcd</br>    
> OUTPUT:a1b1c1d1  

> INPUT:aaabbc</br>
> OUTPUT:a3b2c1

> INPUT:a</br>
> OUTPUT:a1

# Constraints
## TimeComplexity:O(n)</br>
## SpaceComplexity:1</br>
## Language:C

## Compilation Linux
> cc stringcompression24032018.c -o tringcompression24032018
# OR
> gcc stringcompression24032018.c -o stringcompression24032018

## Execution Linux
> $ ./demo

# OUTPUT RESULT

aaaaaaaaabbbbbbbbbcccccccccddddddddeeeeeeeeefffffffffggggggggghhhhhhhhhjjjjjjjjjkkkkkkkkklllllllllpppppppppiiiiiiiiiyyyyyyyyy</br>
a9b9c9d8e9f9g9h9j9k9l9p9i9y9

Time to Execute is:0.000000

