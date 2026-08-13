
char_binary_mapping = {}

class Huffmancode:
    def __init__(self, freq, data, left, right):
        self.freq = freq
        self.data = data
        self.left = left
        self.right = right


def generate_tree(mapping):
    keyset = mapping.keys()
    priorityQ = []

    for c in keyset:
        node = Huffmancode(mapping[c], c, None, None)
        priorityQ.append(node)

    priorityQ = sorted(priorityQ, key=lambda x: x.freq)

    while len(priorityQ) > 1:
        first = priorityQ.pop(0)
        second = priorityQ.pop(0)

        merge_node = Huffmancode(
            first.freq + second.freq,
            '-',
            first,
            second
        )

        priorityQ.append(merge_node)
        priorityQ = sorted(priorityQ, key=lambda x: x.freq)

    return priorityQ.pop()


def set_binary_code(node, code):
    if node is not None:

        if node.left is None and node.right is None:
            char_binary_mapping[node.data] = code

        set_binary_code(node.left, code + '0')
        set_binary_code(node.right, code + '1')


def encode(text):
    mapping = {}

    for c in text:
        if c not in mapping:
            mapping[c] = 1
        else:
            mapping[c] += 1

    root = generate_tree(mapping)

    set_binary_code(root, '')

    encoded_text = ""

    for c in text:
        encoded_text += char_binary_mapping[c]

    return encoded_text



text = input("Enter the text: ")


with open("input.txt", "w") as file:
    file.write(text)

print("\nText saved to input.txt")



with open("input.txt", "r") as file:
    text = file.read()



encoded_text = encode(text)



print("\nCharacter Binary Mapping:")

for c in char_binary_mapping:
    print(repr(c), ":", char_binary_mapping[c])



print("\nEncoded text:")
print(encoded_text)


with open("compressed.txt", "w") as file:
    file.write(encoded_text)

print("\nEncoded text saved to compressed.txt")