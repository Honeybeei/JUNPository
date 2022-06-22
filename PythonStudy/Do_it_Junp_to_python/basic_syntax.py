# Hello world!
print("Hello world!")

# This python script is a note about basic syntax of python. 

# I. Datatype & Operators
# I.A Numeric datatype
a = 1.2
b = -3.33
c = 1.443e3  # 1.443 * 10 ^ 3
d = 4.15e-5  # E or e, both are okay
e = 0o123  # Octal expressions use 0o or 0O
f = 0x123  # Hexadecimal expressions use 0x
g = 1 + 2j
print(g.real)  # .real returns the real number of the complex number
print(g.imag)  # .imag returns the TODO
print(g.conjugate())  # .conjurgate() returns the TODO
print(abs(a))  # abs() returns the absolute value of its parameter

# I.B Operators for Numeric datatype
h = 3 ** 4  # 3 ^ 4
print(123 / 7)  # 17.571428571428573
print(123 % 7)  # 4
print(123 // 7)  # 17

# I.C String datatype
# 4 ways to make string
s1 = "Hello'' \nworld"  # \n, \\ .... those are excape code
s2 = 'Hello" world!'
s3 = """Helll 'w'orld!!"""
s4 = '''Heeeel'lllooo'''
print(s1)
print(s2)
print(s3)
print(s4)

# I.D Operator for string datatype

# I.D.1 add
s1 = "Hello"
s2 = " world!"
print(s1 + s2)  # Hello world!
print(s1 * 3)  # HelloHelloHello

# I.D.2 indexing and slicing
s3 = "Hello my name is Seojun Yoo."
print(s3[1])  # string indexing
print(s3[3:8])  # string slicing
print(s3[:4])
print(s3[10:])
# s3[1] = 'o'
# string is immutable datatype so error will be occured

# I.D.3 type specifier
count = 3
date = "yesterday"
s4 = "I had %d apples %s"
print(s4 %(count, date))
s5 = "success rate : %d%%" %98  # how to use % in string

# I.D.4 functions for string
s6 = "Hobby"
print(s6.count('b'))  # counts character in the string and returns the count of the character
s7 = "abcdefg"
print(s7.find('c'))  # returns the index of the character
print(s7.find('z'))  # if parameter doesnt exit, it returns -1
print(s7.index('z'))  # error occurs
s8 = "AbCdEfG"
print(s8.upper())  # ABCDEFG
print(s8.lower())  # abcdefg
s9 = "   left spaced"
print(s9.lstrip())  # left spaced
s10 = "right spaced     "
print(s10.rstrip())  # right spaced
s11 = "  space on left and right    "
print(s11.strip()) # space on left and right
s12 = "let's meet today"
print(s12.replace("today", "tomorrow"))  # let's meet tomorrow
s13 = "I miss you so bad jenni"
print(s13.split())  # ['I', 'miss', 'you', 'so', 'bad', 'jenni']
s14 = "Hello world!"
print(s14.split('l'))  # ['He', '', 'o wor', 'd!']
# google the rest of functions related to string. 

# I.E list data type

list1 = [1, 2, 3, 4, 5]
print(list1[0])
matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(matrix1[0])
print(matrix1[1])
print(matrix1[2])

list2 = [10, 20, 30, 40]
list2[1:2] = [1, 2, 3, 4, 5]
print(list2)
list2[1] = ['a', 'b', 'c']  # [1:2] and [1] is different!!
print(list2)

list3 = [1, 2, 3, 4, 5]
del list3[1]
print(list3)

# there are various functions for list. ex : append, sort, reverse, index, instert, remove, pop, count, extend.... etc
# google it when you need those functions

# I.F tuple data type
