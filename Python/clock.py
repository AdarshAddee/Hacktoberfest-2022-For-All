import turtle
import time 

wndw = turtle.Screen()
wndw.bgcolor('white')
wndw.setup(width=600, height=600)
wndw.title('Analog clock')
wndw.tracer(0)

# create drawing pen 
pen = turtle.Turtle()
pen.hideturtle()
pen.speed(0)
pen.pensize(4)

def draw_clock(hr, mn, sec, pen): 
    # draw clock face 
    pen.up()
    pen.goto(0, 210)
    pen.setheading(180)
    pen.color('blue')
    pen.pendown()
    pen.circle(210)
    
    # draw hour hashes 
    pen.up()
    pen.goto(0, 0)
    pen.setheading(90)
    
    for _ in range(12): 
        pen.fd(190)
        pen.pendown()
        pen.fd(20)
        pen.penup()
        pen.goto(0, 0)
        pen.rt(30)
        
    hands = [('green', 80, 12), ('blue', 150, 60), ('red', 110, 60)]
    time_set = (hr, mn, sec)
    
    for hand in hands: 
        time_part = time_set[hands.index(hand)]
        angle = (time_part/hand[2])*360
        pen.penup()
        pen.goto(0,0)
        pen.color(hand[0])
        pen.setheading(90)
        pen.rt(angle)
        pen.pendown()
        pen.fd(hand[1])
        
while True: 
    hr = int(time.strftime('%I'))
    mn = int(time.strftime('%M'))
    sec = int(time.strftime('%S'))

    draw_clock(hr, mn, sec, pen)
    wndw.update()
    time.sleep(1)
    pen.clear()
    
wndw.mainloop()

// Github username: shopie14
// Aim: contribustion hacktoberfest 2022
// Date: 05/10/2022

// start coding
