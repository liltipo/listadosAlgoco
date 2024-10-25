import itertools
import sys

# Leer toda la entrada de una vez
input = sys.stdin.read()
wordsList = input.split()
compoundWords = []

# Generar todas las permutaciones posibles
for perm in itertools.permutations(wordsList, 2):
    # Unir cada permutación en una sola cadena
    compound = ''.join(perm)
    if compound not in compoundWords:
        compoundWords.append(compound)

compoundWords = sorted(compoundWords)
for word in compoundWords:
    print(word)
