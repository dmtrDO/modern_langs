
# 4. Згенерувати 1000 випадкових чисел (діапазон 0-100), 
# відфільтрувати усі елементи, що більші за середнє значення масиву.

import random
import time
import tracemalloc

NUM_OF_ALGORITHMS = 10_000

START_RANGE = 0
END_RANGE = 100
NUM_OF_NUMBERS = 1000

def run_algorithm() -> list:
    arr = []
    for _ in range(NUM_OF_NUMBERS):
        arr.append(random.randint(START_RANGE, END_RANGE))

    sorted_arr = []
    avg_value = int(sum(arr) / NUM_OF_NUMBERS)

    for i in range(NUM_OF_NUMBERS):
        if arr[i] > avg_value:
            sorted_arr.append(arr[i])

    return sorted_arr

if __name__ == "__main__":
    tracemalloc.start()
    start = time.time()

    # for _ in range(NUM_OF_ALGORITHMS):
        # run_algorithm()
    run_algorithm()

    print(f"{tracemalloc.get_traced_memory()[1] / 2**10} KiB")
    # print(f"time: {time.time() - start:.2f} s.")


