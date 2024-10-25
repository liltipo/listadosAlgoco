commands= []
history = []

line = input().split()
cantStudents = int(line[0])
cantCommands = int(line[1])
line = input().split()

# crea la lista de comandos
i = 0 
while i < len(line):
    if line[i] == "undo" and i+1 < len(line):
        commands.append(line[i] + " " + line[i+1])
        i += 2
    else:
        commands.append(line[i])
        i += 1

# ejecuta los comandos
currentPosition = 0
for command in commands:
    if 'undo' in command:
        command = command.split()
        lastValues = history[-1*int(command[1]):] #retorna los ultimos x valores
        currentPosition += sum(lastValues)
        currentPosition = currentPosition % cantStudents
        history = history[:-1*int(command[1])] #elimina los ultimos x valores

    else:
        currentPosition += int(command)
        currentPosition = currentPosition % cantStudents
        history.append(int(command)*-1)
   
print(currentPosition)