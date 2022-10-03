# Github username: Asadaaaaa
# Aim: https://github.com/Asadaaaaa/Hacktoberfest-2022-For-All/blob/main/Python/ipHostname.py
# Date: 10/03/22

# start coding


import socket

host = socket.gethostname()
ip = socket.gethostbyname(hostname)

print(f"Hostname: {host}")
print(f"IP Address: {ip}")
