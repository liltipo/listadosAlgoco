def splitClases(entry):
    paso1 = entry.replace("class", "").strip().split(":")
    name = paso1[0].strip()
    classPart = paso1[1].strip().split("-")
    result = [name]

    for i in range(len(classPart)):
        result.append(classPart[i])
    
    # Rellenar con "middle" hasta tener 10 niveles de clase
    while len(result) < 11:  
        result.append("middle")
    
    return result

# Leer la entrada
cases = int(input())
for _ in range(cases):
    numPeople = int(input())

    # Agrega las clases a una lista
    clases = []
    for _ in range(numPeople):
        clases.append(input())
    
    # Separa las clases en listas separadas
    results = list(map(splitClases, clases))

    # Ordenamos utilizando el criterio de comparación y orden alfabético en caso de empate
    results.sort(key=lambda x: (list(map(lambda y: {"upper": 1, "middle": 2, "lower": 3}[y], x[1:])), x[0]))

    # Imprimir el resultado de esta prueba
    for person in results:
        print(person[0])
    print("=" * 30)
