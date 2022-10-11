# Github username: Sonucoder
# Aim: Draw a square using python
# Date: 11/10/2022
import turtle
x=turtle.Turtle()
def square(circle):
    x.forward(100)
    x.right(circle)
    x.forward(100)
    x.right(circle)
    x.forward(100)
    x.right(circle)
    x.forward(100)
    x.right(circle+10)
for i in range(36):
    square(90)    
