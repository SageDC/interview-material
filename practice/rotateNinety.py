def rotate_clockwise(matrix):
    n = len(matrix)
    # use n // 2 because results are different for an odd or even matrix
    for layer in range(n // 2):
        first = layer # first holds 0 then 1
        last = n - layer - 1 # last holds 3 then 2
        for i in range(first, last): # i is 0,1,2 when (first = 0, last = 3) and 1 when (first = 1, last = 2)
            top = matrix[layer][i] # hold 0,1,2 first pass, just 1 second pass
            matrix[layer][i] = matrix[-i-1][layer] # left is all 0's at layer 0, 1 at layer 1
            matrix[-i-1][layer] = matrix[-layer-1][-i-1]
            matrix[-layer-1][-i-1] = matrix[i][-layer - 1]
            matrix[i][-layer-1] = top
    return matrix  

def main():
    matrix = [[i for i in range(4)] for j in range(4)]
    result = rotate_clockwise(matrix)
    print(result)

if __name__ == '__main__':
    main()