import binascii

tokens = [
    "747970653d726567756c61723b65787069726174696f6e3d313734313530393036352e3237303030373fdd62647ebed499af095512c6ddc346",
    "747970653d726567756c61723b65787069726174696f6e3d313734313530393036362e35313234313534b6a6f0a5cd599a64fb42043650690306",
    "747970653d726567756c61723b65787069726174696f6e3d313734313530393036372e37323732313433e8f1a1d171adff381abcc487d6ab10e7",
    "747970653d726567756c61723b65787069726174696f6e3d313734313530393036382e39353438323733f8ea5723524c1280348cbad0e258ea89",
    "747970653d726567756c61723b65787069726174696f6e3d313734313530393037302e313730303237332d7a85a15206a5ef0048f08c9ffb9506"
]

for token in tokens:
    hex_data = binascii.unhexlify(token)
    plaintext = hex_data[:-16]  # Extract token data
    mac = hex_data[-16:]  # Extract MAC
    print(f"Token Data: {plaintext}\nMAC: {mac.hex()}\n")

# Further analysis can be added here to detect patterns.