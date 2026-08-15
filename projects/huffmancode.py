import os

class Node:
    def __init__(self, char=None, freq=0, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right

    def is_leaf(self):
        return self.left is None and self.right is None


def count_frequencies(text):
    freq = {}

    for char in text:
        freq[char] = freq.get(char, 0) + 1

    return freq


def build_huffman_tree(freq):
    nodes = [Node(char, f) for char, f in freq.items()]

    if len(nodes) == 1:
        return nodes[0]

    while len(nodes) > 1:
        nodes.sort(key=lambda n: n.freq)

        left = nodes.pop(0)
        right = nodes.pop(0)

        merged = Node(
            None,
            left.freq + right.freq,
            left,
            right
        )

        nodes.append(merged)

    return nodes[0]


def build_codes(node, current_code="", codes=None):
    if codes is None:
        codes = {}

    if node.is_leaf():
        codes[node.char] = current_code if current_code else "0"
        return codes

    build_codes(node.left, current_code + "0", codes)
    build_codes(node.right, current_code + "1", codes)

    return codes


def text_to_bits(text, codes):
    return "".join(codes[char] for char in text)


def bits_to_bytes(bits):
    padding = (8 - len(bits) % 8) % 8

    bits += "0" * padding

    byte_array = bytearray()

    for i in range(0, len(bits), 8):
        byte_array.append(
            int(bits[i:i + 8], 2)
        )

    return byte_array, padding


def bytes_to_bits(data, padding):
    bits = "".join(
        format(byte, "08b")
        for byte in data
    )

    if padding > 0:
        bits = bits[:-padding]

    return bits


def decode_bits(bits, root):
    if root.is_leaf():
        return root.char * len(bits)

    result = []
    current = root

    for bit in bits:

        if bit == "0":
            current = current.left
        else:
            current = current.right

        if current.is_leaf():
            result.append(current.char)
            current = root

    return "".join(result)


def compress(
    text,
    output_path="compressed.bin",
    encoded_path="encoded.txt"
):
    freq = count_frequencies(text)

    tree = build_huffman_tree(freq)

    codes = build_codes(tree)

    print("\nHuffman Binary Codes:")
    print("---------------------")

    for char, code in codes.items():

        if char == " ":
            display_char = "SPACE"
        elif char == "\n":
            display_char = "NEWLINE"
        elif char == "\t":
            display_char = "TAB"
        else:
            display_char = char

        print(f"{display_char!r} -> {code}")

    bits = text_to_bits(text, codes)

    print("\nEncoded Binary:")
    print("----------------")
    print(bits)

    with open(encoded_path, "w") as f:
        f.write(bits)

    print(f"\nEncoded binary saved to {encoded_path}")

    byte_array, padding = bits_to_bytes(bits)

    with open(output_path, "wb") as f:
        f.write(byte_array)

    print(f"Compressed file saved to {output_path}")

    return tree, padding


def decompress(
    compressed_path,
    output_path,
    tree,
    padding
):
    with open(compressed_path, "rb") as f:
        compressed_data = f.read()

    bits = bytes_to_bits(
        compressed_data,
        padding
    )

    text = decode_bits(
        bits,
        tree
    )

    with open(
        output_path,
        "w",
        encoding="utf-8"
    ) as f:
        f.write(text)

    print(
        f"Decompressed file saved to {output_path}"
    )


if __name__ == "__main__":

    user_text = input("Enter the text: ")

    with open(
        "input.txt",
        "w",
        encoding="utf-8"
    ) as f:
        f.write(user_text)

    print("Text saved to input.txt")

    tree, padding = compress(
        user_text,
        "compressed.bin",
        "encoded.txt"
    )

    original_size = os.path.getsize(
        "input.txt"
    )

    compressed_size = os.path.getsize(
        "compressed.bin"
    )

    print(f"\nOriginal size:   {original_size} bytes")
    print(f"Compressed size: {compressed_size} bytes")

    if compressed_size < original_size:
        print("File size reduced!")
    else:
        print("Compressed data is not smaller.")

    decompress(
        "compressed.bin",
        "output.txt",
        tree,
        padding
    )