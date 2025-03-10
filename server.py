import os
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import time

KEY = os.urandom(16)

def xor(a, b):
    return bytes(x^y for x, y in zip(a, b))

def mac(data):
    data = pad(data, 16)
    blocks = [data[i:i+16] for i in range(0, len(data), 16)]
    tag = bytes(16)
    aes = AES.new(KEY, AES.MODE_ECB)
    for block in blocks:
        tag = aes.encrypt(xor(tag, block))
    return tag

def encrypt(data):
    data = pad(data, 16)
    aes = AES.new(KEY, AES.MODE_CBC)
    return aes.IV + aes.encrypt(data)

def decrypt(data):
    aes = AES.new(KEY, AES.MODE_CBC, iv=data[:16])
    data = data[16:]
    data = aes.decrypt(data)
    return unpad(data, 16)

def create_token(user):
    token = []
    for k, v in user.items():
        token.append((k+"="+v).encode())
    token = b";".join(token)
    return token + mac(token)

def parse_token(token):
    tag = token[-16:]
    token = token[:-16]
    assert tag == mac(token)
    token = token.split(b";")
    user = {}
    for kv in token:
        k, v = kv.split(b"=", 1)
        user[k.decode("utf-8")] = v.decode("L1")
    return user

user = {}
while True:
    print("1. create user")
    print("2. login")
    print("3. encrypt note")
    print("4. decrypt note")
    print("5. get flag")
    match int(input("> ")):
        case 1:
            user = {"type": "regular", "expiration": str(time.time() + 3600)}
            tag = create_token(user)
            print(tag.hex())
        case 2:
            token = bytes.fromhex(input("token> "))
            user = parse_token(token)
            assert float(user["expiration"]) >= time.time()
        case 3:
            assert user["type"] in ["regular", "premium"]
            note = bytes.fromhex(input("note> "))
            print(encrypt(note).hex())
        case 4:
            assert user["type"] in ["regular", "premium"]
            ct = bytes.fromhex(input("ciphertext> "))
            print(decrypt(ct).hex())
        case 5:
            assert user["type"] == "premium"
            print(os.environ.get("FLAG", "flag unavailable"))
