//GitHub username = maazm007
//Aim = This program is used to find out the leap year
//Date = 05/10/22//GitHub username = maazm007


def is_leap(year):
  if(year % 4 == 0):
    if(year % 100 == 0):
      if(year % 400 == 0):
        return True
      else:
        return False
    else:
      return True
  else:
    return False
