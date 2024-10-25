def splitClases(entry):
    paso1 = entry.replace("class", "").replace(" ", "").split(":")
    name = paso1[0]
    classPart = paso1[1].split("-")
    result = [name]

    for i in range(len(classPart)):
        result.append(classPart[i])
    
    while len(result) < 11:  
        result.append("middle")
    
    return result

def compare_classes(class1, class2):
    for i in range(1, 11):  # Empezamos desde el índice 1, ya que 0 es el nombre
        if class1[i] != class2[i]:
            if class1[i] == "upper":
                return -1  # class1 es mayor
            elif class2[i] == "upper":
                return 1  # class2 es mayor
            elif class1[i] == "middle" and class2[i] == "lower":
                return -1  # middle > lower
            elif class1[i] == "lower" and class2[i] == "middle":
                return 1  # lower < middle
    return 0  # Si son iguales

# Leer la entrada
cases = int(input())
for i in range(cases):
    numPeople = int(input())

    # Agrega las clases a una lista
    clases = []
    for j in range(numPeople):
        clases.append(input())
    
    # Separa las clases en listas separadas
    results = list(map(splitClases, clases))

    # Lista de nombres ordenados por clase
    names = []
    
    # Mientras haya personas en results
    while results:
        # Busca la persona con la clase más alta
        highest = results[0]
        highest_index = 0

        # Comparar con el resto
        for i in range(1, len(results)):
            comparison = compare_classes(results[i], highest)
            if comparison == -1:  # Si results[i] es mayor
                highest = results[i]
                highest_index = i
        
        # Añadir el nombre de la persona con la clase más alta
        names.append(highest[0])
        
        # Eliminar esa persona de la lista de resultados
        results.pop(highest_index)
    
    # Imprimir el resultado de esta prueba
    for name in names:
        print(name)
    print("=" * 30)
