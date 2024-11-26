import heapq

def merge_k_sorted_arrays(k, arrays):
    # Min priority queue (heap) to store the elements
    min_heap = []
    result = []

    # Step 1: Insert the first element from each array along with the array and element index
    for i in range(k):
        if arrays[i]:  # Only add if the array is not empty
            heapq.heappush(min_heap, (arrays[i][0], i, 0))

    # Step 2: Extract the smallest element and insert the next element from the same array
    while min_heap:
        val, arr_idx, elem_idx = heapq.heappop(min_heap)
        result.append(val)  # Add the smallest element to the result array

        # If there are more elements in the array, push the next element to the heap
        if elem_idx + 1 < len(arrays[arr_idx]):
            next_val = arrays[arr_idx][elem_idx + 1]
            heapq.heappush(min_heap, (next_val, arr_idx, elem_idx + 1))

    return result

# Input
k = int(input())  # Number of arrays
arrays = [list(map(int, input().split())) for _ in range(k)]

# Merging the arrays
merged_array = merge_k_sorted_arrays(k, arrays)

# Output
print("Merged Array:", merged_array)
