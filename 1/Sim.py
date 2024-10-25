numTests = int(input())

for _ in range(numTests):
    output = []
    pos = 0
    line = input()

    for caracter in line:
        if caracter == '<':
            if pos-1 >= 0 and output:  # Comprueba que output no esté vacío
                output.pop(pos-1)
                pos -= 1
            continue

        elif caracter == '[':
            pos = 0
            continue

        elif caracter == ']':
            pos = len(output)

        else:
            output.insert(pos, caracter)
            pos += 1

    output = ''.join(output)
    print(output)


""" from collections import deque

numTests = int(input())

for _ in range(numTests):
    left = deque()
    right = deque()
    
    line = input()

    for caracter in line:
        if caracter == '<':
            if left:
                left.pop()
        elif caracter == '[':
            if left:
                right.extendleft(reversed(left))
                left.clear()
        elif caracter == ']':
            if right:
                left.extend(right)
                right.clear()
        else:
            left.append(caracter)

    left.extend(right)
    print(''.join(left)) """