""" lenA, mediaB = map(int, input().split())
seqA = input().split()

if lenA == 0:    
    print(0)
    exit()

if lenA == 1:    
    print(1)
    exit()

if lenA == 2:
    print(1)
    exit()      

result = 0
iter = 1
goodCases = []

while iter <= lenA:
    subSeq = []
    for i in range(len(seqA) - iter + 1):
        contigua = seqA[i:i + iter]  # Obtener sublista de tamaño iter
        subSeq.append(contigua)  # Añadir la sublista a la lista de resultados

    for sub in subSeq:
        sub = sorted(sub)
        if int(sub[iter//2]) == mediaB and sub not in goodCases:
            goodCases.append(sub)
            result += 1

    iter += 2

print(result) """

lenA, mediaB = map(int, input().split())
seqA = list(map(int, input().split()))

result = 0

# Diccionario para almacenar las diferencias entre contadores
counter = {0: 1}  # Inicializa con 0, ya que una subsecuencia vacía tiene diferencia 0
balance = 0

# Variable para verificar si se encontró B
foundB = False

# Recorremos la lista
for number in seqA:
    if number == mediaB:
        foundB = True
    elif number > mediaB:
        balance += 1
    else:
        balance -= 1

    # Si encontramos B, contamos los subsecuencias
    if foundB:
        result += counter.get(balance, 0) # Si no existe la llave, regresa 0
    else:
        counter[balance] = counter.get(balance, 0) + 1 # Si no existe la llave, regresa 0 y le suma 1

print(result)