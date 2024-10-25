heights = []
maxJump = 0

mountains = int(input())
heights = input().split()

if mountains < 3 or len(heights) < 3:
    print(0)
    exit()

izq = int(heights[0])
between = int(heights[1])
der = int(heights[2])

for i in range(1, mountains):
    if izq < int(heights[i]):
        if i + 2 < len(heights): 
            der = int(heights[i+2])

        izq = int(heights[i]) 
        if i + 1 < len(heights):
            between = int(heights[i+1])
        else:
            between = 999999999999
        continue

    if int(heights[i]) < between:
        between = int(heights[i])

    if between < izq and between < der:
        possibleJump = min(izq - between, der - between)
        maxJump = max(maxJump, possibleJump)

    if i + 2 < len(heights): 
        der = int(heights[i+2])

print(maxJump)