def binary_search(arr, key, search_first):
    low = 0
    high = len(arr) - 1
    result = -1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == key:
            result = mid

            if search_first:
                high = mid - 1    # Search on the left side
            else:
                low = mid + 1     # Search on the right side

        elif key < arr[mid]:
            high = mid - 1

        else:
            low = mid + 1

    return result


A = [1, 2, 2, 4, 5, 6, 6, 6, 7, 7, 8]

x = int(input("Enter the number: "))

first_index = binary_search(A, x, True)

if first_index == -1:
    print(f"Number of duplicates of {x} is 0")
else:
    last_index = binary_search(A, x, False)
    print(f"Number of duplicates of {x} is {last_index - first_index + 1}")