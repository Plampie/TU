import os
import time
import binascii
import socket

def get_token():
    s = socket.create_connection(("ultrasecure.520566ba.ctfbazaar.com", 5003))
    s.recv(1024)  # Receive initial menu
    s.sendall(b"1\n")  # Create user
    data = s.recv(1024).decode()
    token = data.strip().split("\n")[0]  # Extract token from response
    s.close()
    return token

# Collect multiple valid tokens
tokens = []
for _ in range(5):
    token = get_token()
    print("Token:", token)
    tokens.append(token)
    time.sleep(1)  # Ensure different timestamps

# Save tokens for analysis
with open("tokens.txt", "w") as f:
    for token in tokens:
        f.write(token + "\n")

print("Tokens saved. Analyze them for MAC patterns.")