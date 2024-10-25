lenA, mediaB = map(int, input().split())
seqA = input().split()

if lenA == 1:
    print(1)
    exit()

if lenA == 2:
    print(0)
    exit()

subSeq = []
result = 1
start = 3

# Media al final
if mediaB == int(seqA[-1]):
    while start <= lenA: 
        subSeq = seqA[-start:]
        subSeq = sorted(subSeq)

        if int(subSeq[start//2]) == mediaB:
            result += 1

        start += 2
    print(result)
    exit()

# Media al principio
if mediaB == int(seqA[0]):
    while start <= lenA: 
        subSeq = seqA[:start]
        subSeq = sorted(subSeq)

        if int(subSeq[start//2]) == mediaB:
            result += 1

        start += 2
    print(result)
    exit()

# Media en otro lugar
goodCases = []
indexMedia = seqA.index(str(mediaB))
# Caso 1: Agregar datos de la izquierda
start = 2

while indexMedia - start >= -1:
    if indexMedia - start == -1:
        subSeq = seqA[:indexMedia+2]
        subSeq = sorted(subSeq)

        if int(subSeq[start//2]) == mediaB and subSeq not in goodCases:
            goodCases.append(subSeq)
            result += 1
        break

    subSeq = seqA[indexMedia-start:indexMedia+1]
    subSeq = sorted(subSeq)

    if int(subSeq[start//2]) == mediaB and subSeq not in goodCases:
        goodCases.append(subSeq)
        result += 1

    start += 2

# Caso 2: Agregar datos de la derecha
start = 3

while indexMedia + start <= lenA+1:
    if indexMedia + start == lenA+1:
        subSeq = seqA[indexMedia-1:]
        subSeq = sorted(subSeq)

        if int(subSeq[start//2]) == mediaB and subSeq not in goodCases:
            goodCases.append(subSeq)
            result += 1
        break

    subSeq = seqA[indexMedia:indexMedia+start]
    subSeq = sorted(subSeq)

    if int(subSeq[start//2]) == mediaB and subSeq not in goodCases:
        goodCases.append(subSeq)
        result += 1

    start += 2

# Caso 3: Agregar datos de ambos lados
start = 1

while indexMedia - start >= 0 and indexMedia + start < lenA:
    subSeq = seqA[indexMedia-start:indexMedia+start+1]
    subSeq = sorted(subSeq)

    if int(subSeq[len(subSeq)//2]) == mediaB and subSeq not in goodCases:
        goodCases.append(subSeq)
        result += 1

    start += 1

if indexMedia - start < 0:
    sum = 2
    while indexMedia + sum < lenA:
        subSeq = seqA[:indexMedia+sum]
        subSeq = sorted(subSeq)

        if int(subSeq[len(subSeq)//2]) == mediaB and subSeq not in goodCases:
            goodCases.append(subSeq)
            result += 1
        sum += 2

if indexMedia + start >= lenA:
    sum = 1
    while indexMedia - sum >= 0:
        subSeq = seqA[indexMedia-sum:]
        subSeq = sorted(subSeq)

        if int(subSeq[len(subSeq)//2]) == mediaB and subSeq not in goodCases:
            goodCases.append(subSeq)
            result += 1
        sum += 2

print(result)