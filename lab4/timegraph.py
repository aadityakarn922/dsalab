import matplotlib.pyplot as plt

size = ["10", "100", "1000", "10000", "100000","200000","400000"]

bubble = [0, 0, 0, 0, 36,164,659]
selection = [0,0,0,0,13,61,208]
insertion = [0,0,0,0,2,9,40]
quick = [0,0,0,0,0,0,0]
merge = [0,0,0,0,0,0,0]
plt.figure(figsize=(8,6))


plt.plot(size, bubble, label="Bubble Sort",color='purple')
plt.plot(size, selection, label="Selection Sort",color='purple')
plt.plot(size, insertion, label="Insertion Sort",color='purple')
plt.plot(size, quick, label="Quick Sort",color='green')
plt.plot(size, merge, label="Merge Sort",color='blue')

plt.xlabel("Input Size")
plt.ylabel("Time Taken in seconds")
plt.title("Sorting Algorithm Time Complexity Comparison")
plt.axhline(0, color="black")
plt.axvline(0, color="black")

plt.legend()
plt.grid(True)

plt.show()