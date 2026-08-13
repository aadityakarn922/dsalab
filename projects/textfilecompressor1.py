import os
class Node:
    def __init__(self, char, freq, left=None, right=None):
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

    while len(nodes) > 1:
        
        nodes.sort(key=lambda n: n.freq)

        left = nodes.pop(0)
        right = nodes.pop(0)

        merged = Node(char=None, freq=left.freq + right.freq,
                      left=left, right=right)
        nodes.append(merged)

    return nodes[0]  



def build_codes(node, current_code="", codes=None):
    if codes is None:
        codes = {}

    if node is None:
        return codes

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
        byte_array.append(int(bits[i:i + 8], 2))

    return byte_array, padding


def save_compressed_file(path, byte_array, padding, freq):
    with open(path, "wb") as f:
        f.write(bytes([padding]))
        f.write(len(freq).to_bytes(2, "big"))

        for char, count in freq.items():
            char_bytes = char.encode("utf-8")
            f.write(len(char_bytes).to_bytes(1, "big"))
            f.write(char_bytes)
            f.write(count.to_bytes(4, "big"))

        f.write(byte_array)



def load_compressed_file(path):
    with open(path, "rb") as f:
        padding = int.from_bytes(f.read(1), "big")
        num_chars = int.from_bytes(f.read(2), "big")

        freq = {}
        for _ in range(num_chars):
            char_len = int.from_bytes(f.read(1), "big")
            char = f.read(char_len).decode("utf-8")
            count = int.from_bytes(f.read(4), "big")
            freq[char] = count

        compressed_data = f.read()

    return padding, freq, compressed_data


def bytes_to_bits(data, padding):
    bits = "".join(format(byte, "08b") for byte in data)
    if padding > 0:
        bits = bits[:-padding]
    return bits


def decode_bits(bits, root):

    if root.is_leaf():
        return root.char * root.freq

    decoded = []
    current = root

    for bit in bits:
        current = current.left if bit == "0" else current.right
        if current.is_leaf():
            decoded.append(current.char)
            current = root

    return "".join(decoded)


def compress(input_text_path="input.txt", output_path="compressed.bin"):
    with open(input_text_path, "r") as f:
        text = f.read()

    if not text:
        print("empty file")
    freq = count_frequencies(text)
    tree = build_huffman_tree(freq)
    codes = build_codes(tree)

    print("\nCharacter -> Code:")
    for char, code in codes.items():
        print(f"  {char!r}: {code}")

    bits = text_to_bits(text, codes)
    byte_array, padding = bits_to_bytes(bits)
    save_compressed_file(output_path, byte_array, padding, freq)

    original_size = os.path.getsize(input_text_path)
    compressed_size = os.path.getsize(output_path)

    print(f"\nOriginal size:   {original_size} bytes")
    print(f"Compressed size: {compressed_size} bytes")
    if compressed_size < original_size:
        print("File compressed successfully!")
        print("File size reduced.")
        return True
    else:
        print("The file is too small or has data that does not compress well.")
        return False


def decompress(compressed_path="compressed.bin", output_path="output.txt"):
    padding, freq, compressed_data = load_compressed_file(compressed_path)
    tree = build_huffman_tree(freq)
    bits = bytes_to_bits(compressed_data, padding)
    text = decode_bits(bits, tree)

    with open(output_path, "w") as f:
        f.write(text)

    print(f"\ndecompressed file saved to {output_path}")


if __name__ == "__main__":
    user_text = input("Enter the text: ")

    with open("input.txt", "w") as f:
        f.write(user_text)
    print("Text saved to input.txt")
    compressed = compress()


    if compressed:
        decompress()
    else:
        print("decompression skipped because compression did not reduce the file size.")