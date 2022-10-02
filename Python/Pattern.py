# Github username: ajeyprasand
# Aim: Creates a Pattern starting with 1 to n number of stars in a right angled triangle shape
# Date: 3/10/22

def pattern(n):
  if n==0:
    return
  pattern(n-1)
  print("*"*n)
 
n=int(input())
pattern(n)
