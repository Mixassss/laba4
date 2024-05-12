import random

N = int(input("Введите N: "))
array = [10 + i for i in range(N * 10)]

for i in range(N * 10):
    print(array[i], end=" ")
    if (i + 1) % 10 == 0:
        print()

n = 15
numbers = [random.randint(1, 100) for _ in range(n)]

print("Исходный массив:", end=" ")
for num in numbers:
    print(num, end=" ")

min_index = numbers.index(min(numbers))
max_index = numbers.index(max(numbers))

second_max_index = min_index
for i in range(n):
    if numbers[i] > numbers[second_max_index] and i != max_index:
        second_max_index = i

numbers[min_index], numbers[second_max_index] = numbers[second_max_index], numbers[min_index]

print("\nИзмененный массив:", end=" ")
for num in numbers:
    print(num, end=" ")
