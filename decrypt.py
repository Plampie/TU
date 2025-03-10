import base64

# Given encoded flag (you can replace this with the actual encoded flag if needed)
encoded_flag = "\024\347\335\360i\030\366\375\357!Y\243\070\367V\b\263\267\361!\b\353\070\302%Yo\035\300!U\307\030\275+U("

# Step 1: Convert the string into bytes
encoded_bytes = encoded_flag.encode()

# Step 2: Add padding to the base64 string
# Calculate the padding needed
padding = len(encoded_bytes) % 4
if padding != 0:
    encoded_bytes += b'=' * (4 - padding)

# Step 3: Try Base64 decoding (handle errors gracefully)
try:
    decoded_flag = base64.b64decode(encoded_bytes)
    print(f"Base64 Decoded Flag: {decoded_flag}")
except Exception as e:
    print(f"Error decoding: {e}")
    decoded_flag = None  # Set it to None in case of error

# Step 4: If decoding succeeds, apply character shifts
if decoded_flag:
    # Define a function to apply shifts to the byte sequence (e.g., XOR or rotations)
    def apply_shifts(byte_sequence, shift_value):
        shifted_bytes = bytearray()
        for byte in byte_sequence:
            shifted_bytes.append(byte + shift_value)  # Example shift (adjust based on logic)
        return bytes(shifted_bytes)

    # Apply a shift of 1 as an example
    shifted_flag = apply_shifts(decoded_flag, 1)
    print(f"Shifted Flag (Shift +1): {shifted_flag}")

    # Convert the shifted byte sequence to a readable string (if applicable)
    shifted_flag_str = ''.join(chr(byte) for byte in shifted_flag if 32 <= byte <= 126)  # Printable ASCII characters
    print(f"Shifted Flag (Readable): {shifted_flag_str}")
else:
    print("Base64 decoding failed, skipping shift operation.")
