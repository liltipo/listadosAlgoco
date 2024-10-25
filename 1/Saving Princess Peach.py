numObstacles, numFound = map(int, input().split()) # Convierte los 2 enteros de entrada en lista y luego mapea cada uno a una variable

foundSet = set()  # Obstáculos encontrados por Mario

for _ in range(numFound):
    foundObstacle = int(input())
    foundSet.add(foundObstacle)

for i in range(numObstacles):
    if i not in foundSet:
        print(i)

print(f"Mario got {len(foundSet)} of the dangerous obstacles.")