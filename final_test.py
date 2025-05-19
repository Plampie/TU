import binascii
import socket
import time

def get_token():
    s = socket.create_connection(("ultrasecure.520566ba.ctfbazaar.com", 5003))
    s.recv(1024)  # Receive menu
    s.sendall(b"1\n")  # Create user
    data = s.recv(1024).decode()
    s.close()
    return data.strip().split("\n")[0]  # Extract token

def modify_token(token):
    hex_data = binascii.unhexlify(token)
    plaintext = hex_data[:-16]  # Extract token data
    mac = hex_data[-16:]  # Extract MAC
    
    # Replace "regular" with "premium" while keeping length the same
    modified_plaintext = plaintext.replace(b"regular", b"premium")
    
    # Construct modified token (keeping MAC unchanged for testing)
    forged_token = binascii.hexlify(modified_plaintext + mac).decode()
    return forged_token

def try_forged_token(forged_token):
    s = socket.create_connection(("ultrasecure.520566ba.ctfbazaar.com", 5003))
    s.recv(1024)  # Receive menu
    s.sendall(b"2\n")  # Login
    s.recv(1024)  # Prompt for token
    s.sendall(forged_token.encode() + b"\n")
    response = s.recv(1024).decode()
    s.close()
    return response

# Get a valid token
token = get_token()
print("Original Token:", token)

# Modify it to become premium
forged_token = modify_token(token)
print("Forged Token:", forged_token)

# Try using the forged token
response = try_forged_token(forged_token)
print("Server Response:", response)
