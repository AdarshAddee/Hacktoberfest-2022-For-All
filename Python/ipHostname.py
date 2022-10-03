# Github username: Asadaaaaa
# Aim: Print a ip address and hostname of your device
# Date: 10/03/22

# start coding


import socket

host = socket.gethostname()
ip = socket.gethostbyname(hostname)

print(f"Hostname: {host}")
print(f"IP Address: {ip}")
