# Enter your code here. Read input from STDIN. Print output to STDOUT

import cmath
import math

complexNumber = input()

print(abs(complex(complexNumber)))
print(cmath.phase(complex(complexNumber)))